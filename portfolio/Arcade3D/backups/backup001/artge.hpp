#ifndef ARTGE_HPP
#define ARTHE_HPP

#include "scene.hpp"

namespace arc
{
	class arc3d
	{
	private:
		
		arc::MATRIX4X4 projMtx;
		arc::MATRIX4X4 viewMtx;
		

		int n;

		bool firstFrameState;
		int crsPosX;
		int crsPosY;

		bool infoSwitch;

		void localToGlobal();
		void globalToCamera();
		void perspective();

	public:

		void render();
		void showInfo();
		//void fullScreen();
		arc3d();
		void mainLoop();
		virtual ~arc3d();

		arc::scene * mainScene;

		void setScene(arc::scene *);
	};

}

#endif