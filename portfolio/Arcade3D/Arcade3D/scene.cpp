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

void arc::scene::addObject(arc::object* objs)
{
	this->objects.push_back(*objs);
}

void arc::scene::setCamera(arc::camera * cam)
{
	this->mainCamera = cam;
}