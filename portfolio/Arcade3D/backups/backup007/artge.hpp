#ifndef ARTGE_HPP
#define ARTHE_HPP

#include <SDL/SDL.h>
#include "text.hpp"
#include "scene.hpp"

// Transform modes
#define LOCAL_ONLY			0x01
#define GLOBAL_ONLY			0x02
#define LOCAL_TO_GLOBAL		0x03
#define GLOBAL_TO_CAMERA	0x04

// View modes
#define VERTEX_VIEW			0x01
#define EDGE_VIEW			0x02
#define POLY_VIEW			0x03

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
		void transformVertexByMatrix(arc::vertex3d*,arc::MATRIX4X4*,int atrb);
		void transformFaceByMatrix(arc::face*,arc::MATRIX4X4*,int atrb);

		void initVertex3dLocalByVector4d(vertex3d*,VECTOR4D*);
		void initVertex3dLocalByVector3d(vertex3d*,VECTOR3D*);
		void initVector4dByVertex3dLocal(VECTOR4D*,vertex3d*);
		void initVector4dByVertex3dLocal(VECTOR4D*,vertex3d*,float l);
		void initVector3dByVertex3dLocal(VECTOR3D*,vertex3d*);

		void initVertex3dGlobalByVector4d(vertex3d*,VECTOR4D*);
		void initVertex3dGlobalByVector3d(vertex3d*,VECTOR3D*);
		void initVector4dByVertex3dGlobal(VECTOR4D*,vertex3d*);
		void initVector4dByVertex3dGlobal(VECTOR4D*,vertex3d*,float l);
		void initVector3dByVertex3dGlobal(VECTOR3D*,vertex3d*);

		void initVertex3dCamByVector4d(vertex3d*,VECTOR4D*);
		void initVertex3dCamByVector3d(vertex3d*,VECTOR3D*);
		void initVector4dByVertex3dCam(VECTOR4D*,vertex3d*);
		void initVector4dByVertex3dCam(VECTOR4D*,vertex3d*,float l);
		void initVector3dByVertex3dCam(VECTOR3D*,vertex3d*);

		bool checkVisibleObject(unsigned int fov,arc::object*);

	public:

		inline void putPixel8bit(int, int, colRGB*);
		inline void putPixel16bit(int, int, colRGB*);
		void putPixel24bit(int, int, colRGB*);
		inline void putPixel32bit(int, int, colRGB*);
		void *putPixel(int,int,colRGB*);

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