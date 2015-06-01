#ifndef ARTGE_HPP
#define ARTHE_HPP

#include <SDL/SDL.h>
#include "text.hpp"
#include "scene.hpp"


// Transform modes
#define LOCAL_ONLY			0x01
#define GLOBAL_ONLY			0x02
#define LOCAL_TO_GLOBAL		0x03

// View modes
#define VERTEX_VIEW			0x04
#define EDGE_VIEW			0x05
#define POLY_VIEW			0x06





namespace arc
{
	typedef struct colorRGB{
		unsigned char R;
		unsigned char G;
		unsigned char B;
	
	}colRGB, *colRGB_ptr;


	class arc3d
	{

		arc::BMPSTRING *text;
		SDL_Surface *srf;
		
		int color_depth;
		int w,h;

		std::vector<MATRIX4X4> transformations;

		unsigned int scr_x_zero;
		unsigned int scr_y_zero;

		void drawScene(int);

		SDL_Surface * returnSurfacePtr();
		colRGB col;				/// tymczasowy kolorek do testow

		void transformObjectByMatrix(arc::object*,arc::MATRIX4X4*,int atrb);
		void transformRendListByMatrix(std::vector<arc::object>*,arc::MATRIX4X4*,int atrb);
	public:
		void putPixel(int, int, colRGB*);
		void drawLine(int x1,int y1, int x2,int y2);
		void render();
		void showInfo();
		
	private:

		arc::MATRIX4X4 projMtx;
		arc::MATRIX4X4 viewMtx;
		int viewMode;
		int n;

		bool firstFrameState;
		int crsPosX;
		int crsPosY;

		bool infoSwitch;

	public:

		arc3d(int,int,int);
		void mainLoop();
		virtual ~arc3d();

		arc::scene * mainScene;

		void setScene(arc::scene *);
	};

}

#endif