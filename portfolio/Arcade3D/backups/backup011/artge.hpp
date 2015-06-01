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
	typedef enum COORD_TYPE
	{
		OBJECT_COORD,
		WORLD_COORD,
		CAMERA_COORD,
		PRSV_COORD,
		SCR_COORD
	};

	enum AXIS
	{
		X_AXIS,
		Y_AXIS,
		Z_AXIS,
		ALL
	};

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

		unsigned int scr_x_zero;
		unsigned int scr_y_zero;
		int mouse_x, mouse_y, mouseBuf_x,mouseBuf_y;

		int FPS;
		int fps_buf;
		int sleeper;

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

	public:

		void putPixel8bit(int, int, colRGB*);
		void putPixel16bit(int, int, colRGB*);
		void putPixel24bit(int, int, colRGB*);
		void putPixel32bit(int, int, colRGB*);
		void *putPixel(int,int,colRGB);

		void drawLine(int x1,int y1, int x2,int y2);
		void fillTriangle(arc::face*);

		void render();
		void showInfo();

		void frameCounter();
		void frameTimeStabilise();

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
		
		void createNewCamera();
		void addCamera(arc::camera*);
		void deleteCamera(int cam_id);
		inline int cameraQuantity();
		
		void objectMoveToPoint(arc::object*,COORD_TYPE,arc::POINT3D*);
		void objectMoveBy(arc::object*,float,arc::COORD_TYPE,AXIS);
		void objectRotate(arc::object*,COORD_TYPE,float);
		void objectScale(arc::object*,float);

		void objectsMoveToPoint(std::vector<arc::object*>,COORD_TYPE,arc::POINT3D*);
		void objectsMoveBy(std::vector<arc::object*>,float,arc::COORD_TYPE,AXIS);
		void objectsRotate(std::vector<arc::object*>,COORD_TYPE,float);
		void objectsScale(std::vector<arc::object*>,float);
	};
}

#endif