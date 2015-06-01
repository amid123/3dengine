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
		this->T.push_back(rt);
	break;
	case arc::Y:
		arc::buildRotateMatrixAxisY(&rt,theta);
		this->T.push_back(rt);

	break;
	case arc::Z:
		arc::buildRotateMatrixAxisZ(&rt,theta);
		this->T.push_back(rt);

	break;
	}
}

void arc::transformation::addScale(float scalar)
{
	arc::MATRIX4X4 scale;

	arc::mtx4x4_init(&scale,scalar,0	 ,0		,0,
							0	  ,scalar,0		,0,
							0	  ,		0,scalar,0,
							0	  ,0	 ,0		,1);

	this->T.push_back(scale);
}

void arc::transformation::addTranslationLocal(float x,float y,float z)
{
	arc::MATRIX4X4 translation;

	arc::buildTranslateMatrixXYZ(&translation,x,y,z);
	
	this->T.push_back(translation);
}

arc::transformation::~transformation(){}
arc::object::object(char* filename) : transformation(filename), visible(true)
{
	this->buildObjectSphere();
}
arc::object::object(char* filename, float x,float y, float z) : transformation(filename), visible(true)
{
	this->setPosition(x,y,z);
	this->buildObjectSphere();
}

arc::object::~object(){}

void arc::object::setPosition(float x, float y , float z)
{
	// Inicjujemy pozycje obiektu ( worldPos jest w klasie mesh )
	this->worldPos.x = x;
	this->worldPos.y = y;
	this->worldPos.z = z;
}


	// Zwracamy pozycje obiektu
float arc::object::pos_x(){return this->worldPos.x;}
float arc::object::pos_y(){return this->worldPos.y;}
float arc::object::pos_z(){return this->worldPos.z;}

arc::POINT3D* arc::object::position()
{
	return &this->worldPos;
}

void arc::object::buildObjectSphere()
{
this->max_radius = 0;
float current_radius;

	for(unsigned int vert = 0 ; vert < this->vertexList.size; vert++)
	{
		float x = this->vertexList.indexList[vert]->local.x;
		float y = this->vertexList.indexList[vert]->local.y;
		float z = this->vertexList.indexList[vert]->local.z;

		if(current_radius = (x*x + y*y +z*z) > this->max_radius)
			this->max_radius = current_radius;
	}
	this->max_distance = sqrt(this->max_radius);
}