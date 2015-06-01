#include <iostream>
#include <cstdlib>
#include "artge.hpp"
#undef main

void main()
{
	arc::POINT3D cam_pos = {1,1,-50};

	arc::arc3d engine(1024,768,24);

	arc::scene sc1;

	arc::camera cam1(cam_pos,90,1024,768,1,1);
	engine.setScene(&sc1);

	arc::object t1("female.obj",0,0,60);
	//arc::object t2("teren.obj",0,0,300);
	//arc::object t3("cube.obj",0,0,450);


	//sc1.addObject(&t1);
	sc1.addObject(&t1);
	//sc1.addObject(&t3);


	sc1.setCamera(&cam1);

	engine.mainLoop();
}