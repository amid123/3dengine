#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <vector>
#include "math.hpp"
#include "object.hpp"
namespace arc
{
	class camera
	{
	private:
		
		arc::POINT4D cam_pos;

		arc::MATRIX4X4 translationMtx;
		arc::MATRIX4X4 rotateMtxX;
		arc::MATRIX4X4 rotateMtxY;
		arc::MATRIX4X4 rotateMtxZ;

		arc::VECTOR3D dir;
		

	public:
		arc::MATRIX4X4 camtmp;
		arc::MATRIX4X4 camMtx;

		void build();
		void set(float tx,float ty,float tz,float rx,float ry,float rz);

		arc::POINT4D * cameraPosition();

		camera();
		camera(float,float,float);
		virtual ~camera();

	};
}

#endif // CAMERA_HPP
