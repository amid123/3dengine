#include <iostream>
#include <cmath>
#include "camera.hpp"


arc::camera::~camera()
{

}

arc::camera::camera(float x,float y,float z) : pos_x(x),
											   pos_y(y),
											   pos_z(z)
{

}

void arc::camera::addRotate(arc::ROTATE_AX axis, float theta)
{
	arc::MATRIX4X4 rt;
	arc::MATRIX4X4 tr;
	
	arc::buildTranslateMatrixXYZ(&tr,-(this->pos_x),-(this->pos_y),-(this->pos_z));

	switch(axis)
	{
	case arc::X:
		arc::buildInvRotateMatrixAxisX(&rt,theta);
		this->transformations.push_back(tr);
		this->transformations.push_back(rt);
		//this->transformations.push_back(tr);
	break;
	case arc::Y:
		arc::buildInvRotateMatrixAxisY(&rt,theta);
		this->transformations.push_back(tr);
		this->transformations.push_back(rt);
		//this->transformations.push_back(tr);

	break;
	case arc::Z:
		arc::buildInvRotateMatrixAxisZ(&rt,theta);
		this->transformations.push_back(tr);
		this->transformations.push_back(rt);
		//this->transformations.push_back(tr);
	break;
	
	}
}

void arc::camera::moveBy(float x,float y,float z)
{
	this->pos_x += x;
	this->pos_y += y;
	this->pos_z += z;
}




