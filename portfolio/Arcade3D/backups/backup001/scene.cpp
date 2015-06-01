#include "scene.hpp"
#include <iostream>
#include <cmath>
#include "math.hpp"
arc::scene::scene()
{

}

arc::scene::~scene()
{

}

void arc::scene::addMesh(arc::object* msh1)
{
	this->meshes.push_back(*msh1);
}

void arc::scene::setCamera(arc::camera * cam)
{
	this->mainCamera = cam;
	this->mainCamera->setMeshList(&this->meshes);
	this->tx.setCamera(cam);
}