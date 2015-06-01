#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SDL/SDL.h>
#include <vector>
#include "object.hpp"
#include "math.hpp"


namespace arc
{
	typedef struct colorRGB{
		char R;
		char G;
		char B;
	
	}colRGB, *colRGB_ptr;

	class camera
	{
	private:

		SDL_Surface *srf;
		
		int color_depth;
		void drawLine(int x1,int y1, int x2,int y2);



	public:

		float pos_x;
		float pos_y;
		float pos_z;
		int w,h;

		std::vector<MATRIX4X4> transformations;

		unsigned int scr_x_zero;
		unsigned int scr_y_zero;

		void putPixel(int, int, colRGB*);
		SDL_Surface * returnSurfacePtr();
	private:
		std::vector<arc::object> *meshes;
		colRGB col;				/// tymczasowy kolorek do testow
	public:
		camera();
		camera(int,int,int,float,float,float);
		virtual ~camera();
		void drawScene();
		void setMeshList(std::vector<object>*);


		void addRotate(ROTATE_AX axis, float theta);
		void moveBy(float,float,float);
	
	};
}

#endif // CAMERA_HPP
