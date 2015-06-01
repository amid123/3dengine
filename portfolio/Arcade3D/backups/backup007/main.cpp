#include <iostream>
#include <cstdlib>
#include "artge.hpp"
#undef main
void main()
{
	arc::arc3d engine(800,600,24);

	arc::scene sc1;

	arc::camera cam1(0,0,0);
	engine.setScene(&sc1);

	arc::object t1("triangle.obj",0,0,0);

	sc1.addObject(&t1);

	sc1.setCamera(&cam1);

	engine.mainLoop();
}