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

		arc::mtx4x4_init(&rt,1,0				 ,0					 ,0,
						     0,cos((float)theta),-sin((float)theta),0,
						     0,sin((float)theta), cos((float)theta),0,
						     0,0				 ,0 				 ,0);

		this->transformations.push_back(rt);

	break;

	case arc::Y:
		arc::mtx4x4_init(&rt, cos((float)theta),0,sin((float)theta),0,
						      0				    ,1,0				 ,0,
							 -sin((float)theta),0,cos((float)theta),0,
						      0                 ,0,0				 ,1);

		this->transformations.push_back(rt);

	break;
	
	case arc::Z:

		arc::mtx4x4_init(&rt,cos((float)theta),-sin((float)theta),0,0,
						     sin((float)theta), cos((float)theta),0,0,
						     0,					 0,					1,0,
						     0,					 0,					0,1);

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




