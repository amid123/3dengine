#include <iostream>
#include "artge.hpp"
#undef main
void main()
{
	arc::arc3d engine(800,600,24);

	arc::scene sc1;

	arc::camera cam1(1,0,-10);
	engine.setScene(&sc1);

	arc::object sh1("monkey.obj",0,0,0);
	
	//arc::object sh2("nurbs_surface.obj",0,0,0);
	arc::object lol("lol.obj",1,1,0);
	//arc::object lol2("cube.obj",1,1,0);

	sc1.addObject(&sh1);
	//sc1.addObject(&sh2);
	sc1.addObject(&lol);
	//sc1.addObject(&lol2);

	sc1.setCamera(&cam1);

	engine.mainLoop();
}