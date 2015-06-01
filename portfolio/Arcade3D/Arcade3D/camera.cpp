/* Napisac porzadne konstruktory przyjmuj¹ce wszystkie informacje o kamerze */

#include <iostream>
#include <cmath>
#include "camera.hpp"

int arc::camera::camsNum = 0;

arc::camera::camera(float x,float y,float z,float fov)
{
	this->cam_pos.x = x;
	this->cam_pos.y = y;
	this->cam_pos.z = z;
	this->cam_pos.w = 1;

	arc::buildIdentityMatrix4x4(&this->camMtx);
	this->set(0, 0, 0, 0, 0, 0);
}

arc::camera::camera(arc::POINT3D pos,
					float fov, 
					float scr_w,
					float scr_h,
					float viewPlane_w,
					float viewPlane_h) : camID(0)
{
	this->fieldOfView = fov;
	this->scr_w = (int)scr_w;
	this->scr_h = (int)scr_h;
	this->viewPlane_w = viewPlane_w;
	this->viewPlane_h = viewPlane_h;

	this->cam_pos.x = pos.x;
	this->cam_pos.y = pos.y;
	this->cam_pos.z = pos.z;
	this->cam_pos.w = 1;
	
	this->aspectRatio = (float)this->scr_w / this->scr_h;
	this->d = (float)(0.5) * this->scr_w * tan((float)this->fieldOfView/2);

	this->camsNum++;
	this->camID = this->camsNum;

	arc::buildIdentityMatrix4x4(&this->camMtx);
	this->set(0, 0, 0, 0, 0, 0);
}

arc::camera::~camera()
{

}

void arc::camera::set(float tx,float ty,float tz,float rx,float ry,float rz)
{
	this->cam_pos.x += tx;
	this->cam_pos.y += ty;
	this->cam_pos.z += tz;

	this->dir.x = rx;
	this->dir.y = ry;
	this->dir.z = rz;

	std::cout<< "Pozycja kamery x: " << this->cam_pos.x << std::endl;
	std::cout<< "Pozycja kamery y: " << this->cam_pos.y << std::endl;
	std::cout<< "Pozycja kamery z: " << this->cam_pos.z << std::endl << std::endl;
}

void arc::camera::build(ROTATE_SEQUENCE SEQ)
{
		arc::buildInvTranslateMatrixXYZ(&this->translationMtx,
									     this->cam_pos.x,
									     this->cam_pos.y,
									     this->cam_pos.z );
/*

		std::cout << this->translationMtx.M[0][0] << " "
				  << this->translationMtx.M[0][1] << " "
				  << this->translationMtx.M[0][2] << " "
				  << this->translationMtx.M[0][3] << " " << std::endl

				  << this->translationMtx.M[1][0] << " "
				  << this->translationMtx.M[1][1] << " "
				  << this->translationMtx.M[1][2] << " "
				  << this->translationMtx.M[1][3] << " " << std::endl

				  << this->translationMtx.M[2][0] << " "
				  << this->translationMtx.M[2][1] << " "
				  << this->translationMtx.M[2][2] << " "
				  << this->translationMtx.M[2][3] << " " << std::endl

				  << this->translationMtx.M[3][0] << " "
				  << this->translationMtx.M[3][1] << " "
				  << this->translationMtx.M[3][2] << " "
				  << this->translationMtx.M[3][3] << " " << std::endl<< std::endl;

*/
		arc::buildInvRotateMatrixAxisX(&this->rotateMtxX, this->dir.x);
		arc::buildInvRotateMatrixAxisY(&this->rotateMtxY, this->dir.y);
		arc::buildInvRotateMatrixAxisZ(&this->rotateMtxZ, this->dir.z);
		
		//arc::buildPerspectiveMatrix(&this->perspectiveMtx, this->d, this->aspectRatio);

		switch(SEQ)
		{
			case XYZ:

				arc::integrate4mtx4x4Transformations(&this->translationMtx,
													 &this->rotateMtxX,
													 &this->rotateMtxY,
													 &this->rotateMtxZ,
													 &this->camtmp );
			break;
			case XZY:

				arc::integrate4mtx4x4Transformations(&this->translationMtx,
													 &this->rotateMtxX,
													 &this->rotateMtxZ,
													 &this->rotateMtxY,
													 &this->camtmp );
			break;
			case YXZ:

				arc::integrate3mtx4x4Transformations(&this->rotateMtxY,
													 &this->rotateMtxX,
													 &this->rotateMtxZ,
													 &this->camtmp );
			break;
			case YZX:

				arc::integrate4mtx4x4Transformations(&this->translationMtx,
													 &this->rotateMtxY,
													 &this->rotateMtxZ,
													 &this->rotateMtxX,
													 &this->camtmp );
			break;
			case ZXY:

				arc::integrate4mtx4x4Transformations(&this->translationMtx,
													 &this->rotateMtxZ,
													 &this->rotateMtxX,
													 &this->rotateMtxY,
													 &this->camtmp );
			break;
			case ZYX:

				arc::integrate4mtx4x4Transformations(&this->translationMtx,
													 &this->rotateMtxZ,
													 &this->rotateMtxY,
													 &this->rotateMtxX,
													 &this->camtmp );
			break;
		}

	arc::mtx4x4mulmtx4x4(&this->camtmp,&this->camMtx,&this->camMtx);

	/*

		std::cout << this->camMtx.M[0][0] << " "
				  << this->camMtx.M[0][1] << " "
				  << this->camMtx.M[0][2] << " "
				  << this->camMtx.M[0][3] << " " << std::endl

				  << this->camMtx.M[1][0] << " "
				  << this->camMtx.M[1][1] << " "
				  << this->camMtx.M[1][2] << " "
				  << this->camMtx.M[1][3] << " " << std::endl

				  << this->camMtx.M[2][0] << " "
				  << this->camMtx.M[2][1] << " "
				  << this->camMtx.M[2][2] << " "
				  << this->camMtx.M[2][3] << " " << std::endl

				  << this->camMtx.M[3][0] << " "
				  << this->camMtx.M[3][1] << " "
				  << this->camMtx.M[3][2] << " "
				  << this->camMtx.M[3][3] << " " << std::endl<< std::endl;
*/
	//arc::mtx4x4mulmtx4x4(&this->camMtx,&this->perspectiveMtx,&this->camMtx);
}

bool arc::camera::checkVisibleObject(unsigned int fov ,arc::object* obj)
{
	arc::VECTOR4D spherePos = {obj->pos_x(),obj->pos_y(),obj->pos_z(),1};
	arc::mtx4x4mulvct4d(&this->camMtx,&spherePos,&spherePos);
	this->z_near = 0;
	this->z_far = 1200;

	if(fov == 90)
	{
		//Jesli punkt wspolrzedne x i y ma mniejsze niz z, to znajduje sie w obszaze widzenia
		if( spherePos.z < this->z_far || spherePos.z > this->z_near )
			if(spherePos.x < spherePos.z && spherePos.y < spherePos.z && (spherePos.z > this->z_near || spherePos.z > this->z_far) )
			{
				return true;
			}
		else return false;
	}
	return false;
}

bool arc::camera::checkVisibleFace(unsigned int fov,arc::face* fc)
{
	this->z_near = 0;
	this->z_far = 1200;

	if(fov == 90)
	{
		if( (fc->v1->cam.z > this->z_near)		&&
			(fc->v1->cam.z < this->z_far)		&&
			(fc->v1->cam.x < fc->v1->cam.z)		&&
			(fc->v1->cam.x > (-fc->v1->cam.z) ) &&
			(fc->v1->cam.y < fc->v1->cam.z)		&&
			(fc->v1->cam.y > (-fc->v1->cam.z) ) &&
			
			(fc->v2->cam.z > this->z_near)		&&
			(fc->v2->cam.z < this->z_far)		&&
			(fc->v2->cam.x < fc->v1->cam.z)		&&
			(fc->v2->cam.x > (-fc->v1->cam.z) ) &&
			(fc->v2->cam.y < fc->v1->cam.z)		&&
			(fc->v2->cam.y > (-fc->v1->cam.z) ) &&

			(fc->v3->cam.z > this->z_near)		&&
			(fc->v3->cam.z < this->z_far)		&&
			(fc->v3->cam.x < fc->v1->cam.z)		&&
			(fc->v3->cam.x > (-fc->v1->cam.z) ) &&
			(fc->v3->cam.y < fc->v1->cam.z)		&&
			(fc->v3->cam.y > (-fc->v1->cam.z) ) )
		{
			return true;
		}
		else return false;
	}
	else return false;
return false;
}