#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <vector>
#include "math.hpp"
#include "object.hpp"


namespace arc
{
	enum ROTATE_SEQUENCE { XYZ, XZY, YXZ, YZX, ZXY, ZYX };

	class camera
	{
		friend class arc3d;
	private:
		int camID;
		static int camsNum;
		arc::POINT4D cam_pos;

		arc::MATRIX4X4 translationMtx;
		arc::MATRIX4X4 rotateMtxX;
		arc::MATRIX4X4 rotateMtxY;
		arc::MATRIX4X4 rotateMtxZ;
		arc::MATRIX4X4 perspectiveMtx;

		arc::VECTOR3D dir;

		float fieldOfView;	// Kat widzenia
		float aspectRatio;	// Stosunek szerokosci do dlugosci plaszczyzny rzutu
		int scr_w, scr_h;	// rozmiar ekranu width , height
		float viewPlane_w;
		float viewPlane_h;

		// Plaszczyzny obcinajace
		float z_near;
		float z_far;
		arc::PLANE3D right;
		arc::PLANE3D left;
		arc::PLANE3D top;
		arc::PLANE3D bottom;

		float viewPlaneSizeX;
		float viewPlaneSizeY;

	public:

		int cameraID(){ return camID; }
		arc::MATRIX4X4 camtmp;
		arc::MATRIX4X4 camMtx;

		void build(ROTATE_SEQUENCE);
		void set(float tx,float ty,float tz,float rx,float ry,float rz);

		bool checkVisibleObject(unsigned int fov,arc::object*);
		
		inline arc::POINT4D * arc::camera::cameraPosition()
		{
			return &this->cam_pos;
		}

		camera();
		
		camera(float posX,float posY,float posZ, float fov);
		
		camera(arc::POINT3D pos, float fov, float scr_w, float scr_h, 
			   float viewPlane_w, float viewPlane_h);

		virtual ~camera();

	};
}

#endif // CAMERA_HPP
