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
	static arc::MATRIX4X4 rt;

	switch(axis)
	{
	case arc::X:
		arc::buildRotateMatrixAxisX(&rt,theta);
		this->transformations.push_back(rt);
	break;
	case arc::Y:
		arc::buildRotateMatrixAxisY(&rt,theta);
		this->transformations.push_back(rt);

	break;
	case arc::Z:
		arc::buildRotateMatrixAxisZ(&rt,theta);
		this->transformations.push_back(rt);
	break;
	
	}
}

void arc::camera::moveBy(float x,float y,float z)
{
	this->pos_x += x;
	this->pos_y += y;
	this->pos_z += z;
}




