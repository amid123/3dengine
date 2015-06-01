#include "object.hpp"
#include <cmath>

arc::transformation::transformation(char* filename): mesh(filename){return;}

void arc::transformation::addRotate(ROTATE_AX axis, float theta)
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

void arc::transformation::addScale(float scalar)
{
	arc::MATRIX4X4 scale;

	arc::mtx4x4_init(&scale,scalar,0,0,0,
							0,scalar,0,0,
							0,0,scalar,0,
							0,0,0	  ,1);

	this->transformations.push_back(scale);
}

void arc::transformation::addTranslation(float x,float y,float z)
{
	for(unsigned int i = 0 ; i < this->vertexList.size ; i++)
	{
		this->vertexList.indexList[i]->local_x += x;
		this->vertexList.indexList[i]->local_y += y;
		this->vertexList.indexList[i]->local_z += z;
	}
}

arc::transformation::~transformation(){}
arc::object::object(char* filename) : transformation(filename){return;}
arc::object::object(char* filename, float x,float y, float z) : transformation(filename)
{
	this->setPosition(x,y,z);
}

arc::object::~object(){}

void arc::object::setPosition(float x, float y , float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float arc::object::pos_x(){return this->x;}
float arc::object::pos_y(){return this->y;}
float arc::object::pos_z(){return this->z;}