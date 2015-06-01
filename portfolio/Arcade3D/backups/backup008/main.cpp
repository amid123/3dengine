#include <iostream>
#include <cstdlib>
#include "artge.hpp"
#undef main
void main()
{
	arc::POINT3D cam_pos = {0,0,30};


	arc::arc3d engine(800,600,24);

	arc::scene sc1;

	//arc::camera cam1(cam_pos,90,800,600,0,0);
	engine.setScene(&sc1);

	arc::object t1("monkey_big.obj",0,0,0);
	//arc::object t2("cube.obj",0,0,100);
	//arc::object t3("cube.obj",0,0,100);
	//arc::object t4("cube.obj",0,0,-100);

	sc1.addObject(&t1);
	//sc1.addObject(&t2);
	//sc1.addObject(&t3);
	//sc1.addObject(&t4);

	//sc1.setCamera(&cam1);

	engine.mainLoop();
}