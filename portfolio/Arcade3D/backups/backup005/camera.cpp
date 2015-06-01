#include <iostream>
#include <cmath>
#include "camera.hpp"

arc::camera::camera()
													
{

	
}

arc::camera::~camera()
{

}

void arc::camera::initCamera(int cam_attr, 
							 arc::POINT4D* cam_pos,
							 arc::VECTOR4D* cam_dir,
							 arc::POINT4D* target,
							 float near_clip_z,
							 float far_clip_z,
							 float fov,
							 float viewport_w,
							 float viewport_h)
{
	this->attr = cam_attr;

	arc::vct4dCoppy(cam_pos,&this->pos);
	arc::vct4dCoppy(cam_dir,&this->dir);

	arc::vct4d_init(&this->u,1,0,0,1);
	arc::vct4d_init(&this->u,0,1,0,1);
	arc::vct4d_init(&this->u,0,0,1,1);

	if(target!=false)
		this->target = *target;

	this->near_clip_z = near_clip_z;
	this->far_clip_z = far_clip_z;

	this->viewport_width = viewport_w;
	this->viewport_height = viewport_h;

	this->viewport_center_x = (viewport_w - 1) / 2;
	this->viewport_center_y = (viewport_h - 1) / 2;

	this->aspect_ratio = (float)viewport_w / (float)viewport_h;

	arc::buildIdentityMatrix4x4(&this->mcam);
	arc::buildIdentityMatrix4x4(&this->mper);
	arc::buildIdentityMatrix4x4(&this->mscr);


	this->fov = fov;

	this->viewplane_width	= 2.0;
	this->viewplane_height	= (float) 2.0 / this->aspect_ratio; 

	float tan_fov_div2 = tan((float)DEG_TO_RAD(fov/2));



	if (this->fov == 90.0)
    {
		arc::POINT3D pt_origin;

		arc::vct3d_init(&pt_origin,0,0,0);

	    arc::VECTOR3D vn;

	    arc::vct3d_init(&vn,1,0,-1); // x=z plane

		arc::plane3dInit(&this->rt_clip_plane, &pt_origin,  &vn);

	    arc::vct3d_init(&vn,-1,0,-1); // -x=z plane
	    arc::plane3dInit(&this->lt_clip_plane, &pt_origin,  &vn);

	    arc::vct3d_init(&vn,0,1,-1);
	    arc::plane3dInit(&this->tp_clip_plane, &pt_origin,  &vn);

	    arc::vct3d_init(&vn,0,-1,-1);
	    arc::plane3dInit(&this->bt_clip_plane, &pt_origin,  &vn);
    }
	else 
    {

      arc::POINT3D pt_origin;
      arc::vct3d_init(&pt_origin,0,0,0);

      arc::VECTOR3D vn;

      arc::vct3d_init(&vn,(float)this->view_dist,0,(float)-this->viewplane_width/2.0); 
      arc::plane3dInit(&this->rt_clip_plane, &pt_origin,  &vn);

      arc::vct3d_init(&vn,(float)-this->view_dist,0,(float)-this->viewplane_width / 2.0); 
      arc::plane3dInit(&this->lt_clip_plane, &pt_origin,  &vn);

      arc::vct3d_init(&vn,0,(float)this->view_dist,(float)-this->viewplane_width/2.0); 
      arc::plane3dInit(&this->tp_clip_plane, &pt_origin,  &vn);

      arc::vct3d_init(&vn,0,(float)-this->view_dist,(float)-this->viewplane_width/2.0); 
      arc::plane3dInit(&this->bt_clip_plane, &pt_origin,  &vn);
    }
}

void arc::camera::buildEulerCameraMtx(int cam_rot_seq)
{


arc::MATRIX4X4 mt_inv,  // inverse camera translation matrix
			   mx_inv,  // inverse camera x axis rotation matrix
			   my_inv,  // inverse camera y axis rotation matrix
			   mz_inv,  // inverse camera z axis rotation matrix
			   mrot,    // concatenated inverse rotation matrices
			   mtmp;    // temporary working matrix


// step 1: create the inverse translation matrix for the camera
// position
	arc::mtx4x4_init(&mt_inv, 1,    0,     0,     0,
							  0,    1,     0,     0,
							  0,    0,     1,     0,
							  -this->pos.V[0], -this->pos.V[1], -this->pos.V[2], 1);

// step 2: create the inverse rotation sequence for the camera
// rember either the transpose of the normal rotation matrix or
// plugging negative values into each of the rotations will result
// in an inverse matrix

// first compute all 3 rotation matrices

// extract out euler angles
float theta_x = this->dir.V[1];
float theta_y = this->dir.V[2];
float theta_z = this->dir.V[3];

// compute the sine and cosine of the angle x
float cos_theta = cos(theta_x);  // no change since cos(-x) = cos(x)
float sin_theta = -sin(theta_x); // sin(-x) = -sin(x)

// set the matrix up 
	arc::mtx4x4_init(&mx_inv, 1,    0,         0,         0,
							  0,    cos_theta, sin_theta, 0,
							  0,   -sin_theta, cos_theta, 0,
							  0,    0,         0,         1);

// compute the sine and cosine of the angle y
cos_theta = cos(theta_y);  // no change since cos(-x) = cos(x)
sin_theta = -sin(theta_y); // sin(-x) = -sin(x)

// set the matrix up 
	arc::mtx4x4_init(&my_inv,cos_theta, 0, -sin_theta, 0,  
							 0,         1,  0,         0,
							 sin_theta, 0,  cos_theta, 0,
							 0,         0,  0,         1);

// compute the sine and cosine of the angle z
cos_theta = cos(theta_z);  // no change since cos(-x) = cos(x)
sin_theta = -sin(theta_z); // sin(-x) = -sin(x)

// set the matrix up 
	arc::mtx4x4_init(&mz_inv, cos_theta, sin_theta, 0, 0,  
							 -sin_theta, cos_theta, 0, 0,
							  0,         0,         1, 0,
							  0,         0,         0, 1);

// now compute inverse camera rotation sequence
switch(cam_rot_seq)
      {
      case CAM_ROT_SEQ_XYZ:
      {
	  arc::mtx4x4mulmtx4x4(&mx_inv, &my_inv, &mtmp);
      arc::mtx4x4mulmtx4x4(&mtmp, &mz_inv, &mrot);
      } break;

      case CAM_ROT_SEQ_YXZ:
      {
      arc::mtx4x4mulmtx4x4(&my_inv, &mx_inv, &mtmp);
      arc::mtx4x4mulmtx4x4(&mtmp, &mz_inv, &mrot);
      } break;

      case CAM_ROT_SEQ_XZY:
      {
      arc::mtx4x4mulmtx4x4(&mx_inv, &mz_inv, &mtmp);
      arc::mtx4x4mulmtx4x4(&mtmp, &my_inv, &mrot);
      } break;

      case CAM_ROT_SEQ_YZX:
      {
      arc::mtx4x4mulmtx4x4(&my_inv, &mz_inv, &mtmp);
      arc::mtx4x4mulmtx4x4(&mtmp, &mx_inv, &mrot);
      } break;

      case CAM_ROT_SEQ_ZYX:
      {
      arc::mtx4x4mulmtx4x4(&mz_inv, &my_inv, &mtmp);
      arc::mtx4x4mulmtx4x4(&mtmp, &mx_inv, &mrot);
      } break;

      case CAM_ROT_SEQ_ZXY:
      {
      arc::mtx4x4mulmtx4x4(&mz_inv, &mx_inv, &mtmp);
      arc::mtx4x4mulmtx4x4(&mtmp, &my_inv, &mrot);

      } break;

      default: break;
      } // end switch

// now mrot holds the concatenated product of inverse rotation matrices
// multiply the inverse translation matrix against it and store in the 
// camera objects' camera transform matrix we are done!
arc::mtx4x4mulmtx4x4(&mt_inv, &mrot, &this->mcam);

} // end Build_CAM4DV1_Matrix_Euler


/*
void arc::camera::buildUVNCameraMtx(int mode)
{

	arc::MATRIX4X4 mt_inv,  // inverse camera translation matrix
				   mt_uvn,  // the final uvn matrix
				   mtmp;    // temporary working matrix

// step 1: create the inverse translation matrix for the camera
// position

	arc::mtx4x4_init(&mt_inv, 1,    0,     0,     0,
							  0,    1,     0,     0,
							  0,    0,     1,     0,
							  -this->pos.V[0], -this->pos.V[1], -this->pos.V[2], 1);



// step 2: determine how the target point will be computed
if (mode == UVN_MODE_SPHERICAL)
   {
   // use spherical construction
   // target needs to be recomputed

   // extract elevation and heading 
   float phi   = cam->dir.V[0]; // elevation
   float theta = cam->dir.V[1]; // heading

   // compute trig functions once
   float sin_phi = sin(phi);
   float cos_phi = cos(phi);

   float sin_theta = sin(theta);
   float cos_theta = cos(theta);

   // now compute the target point on a unit sphere x,y,z
   cam->target.V[0] = -1*sin_phi*sin_theta;
   cam->target.V[1] =  1*cos_phi;
   cam->target.V[2] =  1*sin_phi*cos_theta;
   } // end else

// at this point, we have the view reference point, the target and that's
// all we need to recompute u,v,n
// Step 1: n = <target position - view reference point>
VECTOR4D_Build(&cam->pos, &cam->target, &cam->n);

// Step 2: Let v = <0,1,0>
VECTOR4D_INITXYZ(&this->v,0,1,0);

// Step 3: u = (v x n)
VECTOR4D_Cross(&cam->v,&cam->n,&cam->u);

// Step 4: v = (n x u)
VECTOR4D_Cross(&cam->n,&cam->u,&cam->v);

// Step 5: normalize all vectors
VECTOR4D_Normalize(&cam->u);
VECTOR4D_Normalize(&cam->v);
VECTOR4D_Normalize(&cam->n);


// build the UVN matrix by placing u,v,n as the columns of the matrix
Mat_Init_4X4(&mt_uvn, cam->u.x,    cam->v.x,     cam->n.x,     0,
                      cam->u.y,    cam->v.y,     cam->n.y,     0,
                      cam->u.z,    cam->v.z,     cam->n.z,     0,
                      0,           0,            0,            1);

// now multiply the translation matrix and the uvn matrix and store in the 
// final camera matrix mcam
Mat_Mul_4X4(&mt_inv, &mt_uvn, &cam->mcam);

} // end Build_CAM4DV1_Matrix_UVN
*/
