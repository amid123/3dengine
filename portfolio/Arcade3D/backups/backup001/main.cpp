#include <iostream>
#include "artge.hpp"
#undef main
void main()
{
	arc::arc3d engine;

	arc::scene sc1;

	arc::camera cam1(800,600,24,1,0,-10);
	engine.setScene(&sc1);


	arc::object sh1("plane.obj",0,0,0);
	
	//arc::object sh2("nurbs_surface.obj",0,0,0);
	//arc::object lol("lol.obj",1,1,0);
	//arc::object lol2("cube.obj",1,1,0);

	sc1.addMesh(&sh1);
	//sc1.addMesh(&sh2);
	//sc1.addMesh(&lol);
	//sc1.addMesh(&lol2);

	sc1.setCamera(&cam1);

	engine.mainLoop();
}