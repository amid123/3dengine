#include <iostream>
#include <cmath>
#include "camera.hpp"

arc::camera::camera(float x,float y,float z)
{
	this->cam_pos.x = x;
	this->cam_pos.y = y;
	this->cam_pos.z = z;
	this->cam_pos.w = 1;

	arc::buildIdentityMatrix4x4(&this->camMtx);
	this->set(this->cam_pos.x, this->cam_pos.y, this->cam_pos.z, 0, 0, 0);
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

void arc::camera::build()
{
		arc::buildTranslateMatrixXYZ( &this->translationMtx,
									   this->cam_pos.x,
									   this->cam_pos.y,
									   this->cam_pos.z );

		arc::buildInvRotateMatrixAxisX(&this->rotateMtxX, this->dir.x);
		arc::buildInvRotateMatrixAxisY(&this->rotateMtxY, this->dir.y);
		arc::buildInvRotateMatrixAxisZ(&this->rotateMtxZ, this->dir.z);

	arc::integrate4mtx4x4Transformations(&this->translationMtx,
										 &this->rotateMtxX,
										 &this->rotateMtxY,
										 &this->rotateMtxZ,
										 &this->camtmp );

	arc::mtx4x4mulmtx4x4(&this->camtmp,&this->camMtx,&this->camMtx);
}
arc::POINT4D * arc::camera::cameraPosition()
{
	return &this->cam_pos;
}