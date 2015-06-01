#include <iostream>
#include <cstdlib>
#include "artge.hpp"
#undef main
void main()
{
	arc::arc3d engine(800,600,24);

	arc::scene sc1;

	arc::camera cam1;
	engine.setScene(&sc1);

	arc::object t1("triangle.obj",1,-1,-1);
	arc::object t2("triangle.obj",2,-2,1);
	arc::object t3("triangle.obj",5,-1,3);
	arc::object t4("triangle.obj",1,2,-4);
	
	//arc::object sh2("nurbs_surface.obj",0,0,0);
	//arc::object lol("lol.obj",1,1,0);
	//arc::object lol2("cube.obj",1,1,0);

	sc1.addObject(&t1);
	sc1.addObject(&t2);
	sc1.addObject(&t3);
	sc1.addObject(&t4);
	//sc1.addObject(&sh2);
	//sc1.addObject(&lol);
	//sc1.addObject(&lol2);

	sc1.setCamera(&cam1);

	engine.mainLoop();

}