#include <iostream>
#include <cmath>
#include "camera.hpp"



arc::camera::~camera()
{
//delete srf;
}


arc::camera::camera(int size_w,int size_h,int col_depth,float x,float y,float z) : w(size_w),
																				   h(size_h), 
																				   color_depth(col_depth),
																				   pos_x(x),
																				   pos_y(y),
																				   pos_z(z)
{
atexit(SDL_Quit);

	if(SDL_Init( SDL_INIT_VIDEO )<0){

		std::cerr << "Blad inicjacji bibvlioteki SDL !! " << std::endl;
 
		exit(1);
	}
 
	srf = SDL_SetVideoMode(this->w, //szerokoœæ
				 this->h, //wysokoœæ
				 color_depth, //iloœæ bitów koloru 8,16,32, dla 0 sam ustala.
				 SDL_HWSURFACE | SDL_DOUBLEBUF); // flagi, o których szerzej poni¿ej.
 
	if(srf == NULL){
		std::cerr << "Blad inicjacji biblioteki SDL !! " << std::endl;
		exit(1);
	}
	SDL_WM_SetCaption("Arcade3D",0);

	col.R = 255;
	col.G = 255;
	col.B = 0;

	this->scr_x_zero = this->w/2;	// ustalamy punkty sroda ekranu
	this->scr_y_zero = this->h/2;
	
}

void arc::camera::putPixel(int x, int y,colRGB * color)
{
	if( (x >= 0) && (x < w) && (y >= 0) && (y < h) )
	{
	    /* Zamieniamy poszczególne sk³adowe koloru na format koloru pixela */
	    Uint32 pixel = SDL_MapRGB(srf->format, color->R, color->G, color->B);
	 
	    /* Pobieramy informacji ile bajtów zajmuje jeden pixel */
	    int bpp = srf->format->BytesPerPixel;
	 
	    /* Obliczamy adres pixela */
	    volatile Uint8 *p = (Uint8 *)srf->pixels + y * srf->pitch + x * bpp;
	 
	    /* Ustawiamy wartoœæ pixela, w zale¿noœci od formatu powierzchni*/
	    switch(bpp)
	    {
	        case 1: //8-bit
	            *p = pixel;
	            break;
	 
	        case 2: //16-bit
	            *(Uint16 *)p = pixel;
	            break;
	 
	        case 3: //24-bit
	            if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
	                p[0] = (pixel >> 16) & 0xff;
	                p[1] = (pixel >> 8) & 0xff;
	                p[2] = pixel & 0xff;
	            } else {
	                p[0] = pixel & 0xff;
	                p[1] = (pixel >> 8) & 0xff;
	                p[2] = (pixel >> 16) & 0xff;
	            }
	            break;
	 
	        case 4: //32-bit
	            *(Uint32 *)p = pixel;
	            break;
	    }
	}
}

void arc::camera::drawScene()
{
    /* Niektóre powierzchnie wymagaj¹ zablokowania,
       aby coœ na nich narysowaæ u¿ywaj¹c bezpoœredniego dostêpu
       do pamiêci i do tego s³u¿y ten kawa³ek kodu. */
    if ( SDL_MUSTLOCK(this->srf) )
        if ( SDL_LockSurface(this->srf) < 0 )
            return;
 
    /* Wype³niamy ca³y ekran dwoma kolorami */  
	/// Rysujemy tutaj;

	for(unsigned int j = 0 ; j < meshes->size() ; j++)
		for(unsigned int i = 0 ; i < (*meshes)[j].faceList.size ; i++)
		{
			if(j == 0)
			{
				col.R = 255;
				col.G = 0;
				col.B = 0;
			}

			if(j == 1)
			{
				col.R = 255;
				col.G = 255;
				col.B = 0;
			}

			if(j == 2)
			{
				col.R = 255;
				col.G = 0;
				col.B = 255;
			}
			if(j == 3)
			{
				col.R = 255;
				col.G = 255;
				col.B = 255;
			}

			this->drawLine( scr_x_zero + (int)((*meshes)[j].faceList.indexList[i]->v1->cam_x * 15),
							scr_y_zero + (int)((*meshes)[j].faceList.indexList[i]->v1->cam_y * 15),
						    scr_x_zero + (int)((*meshes)[j].faceList.indexList[i]->v2->cam_x * 15),
						    scr_y_zero + (int)((*meshes)[j].faceList.indexList[i]->v2->cam_y* 15));
										  
			this->drawLine( scr_x_zero + (int)((*meshes)[j].faceList.indexList[i]->v2->cam_x * 15),
						    scr_y_zero + (int)((*meshes)[j].faceList.indexList[i]->v2->cam_y * 15),
						    scr_x_zero + (int)((*meshes)[j].faceList.indexList[i]->v3->cam_x * 15),
						    scr_y_zero + (int)((*meshes)[j].faceList.indexList[i]->v3->cam_y * 15));
										  
			this->drawLine( scr_x_zero + (int)((*meshes)[j].faceList.indexList[i]->v3->cam_x * 15),
						    scr_y_zero + (int)((*meshes)[j].faceList.indexList[i]->v3->cam_y * 15),
						    scr_x_zero + (int)((*meshes)[j].faceList.indexList[i]->v1->cam_x * 15),
						    scr_y_zero + (int)((*meshes)[j].faceList.indexList[i]->v1->cam_y * 15));
		}

    /* Odblokowujemy po rysowaniu */  
	if ( SDL_MUSTLOCK(this->srf) )
        SDL_UnlockSurface(this->srf);
 
    /* Podmieniamy obszar rysowania */    
    SDL_Flip(this->srf);
	SDL_FillRect(this->srf, NULL, SDL_MapRGB(this->srf->format, 0,0,0) );
}

SDL_Surface * arc::camera::returnSurfacePtr()
{
	return this->srf;
}

void arc::camera::setMeshList(std::vector<arc::object> * meshes_ptr)
{
	this->meshes = meshes_ptr;
}

void arc::camera::drawLine(int x1,int y1, int x2,int y2)
{
	 int d, dx, dy, ai, bi, xi, yi;
	 int x = x1, y = y1;

	 if (x1 < x2)
	 { 
		 xi = 1;
		 dx = x2 - x1;
	 } 
	 else
	 { 
		 xi = -1;
		 dx = x1 - x2;
	 }

	 if (y1 < y2)
	 { 
		 yi = 1;
		 dy = y2 - y1;
	 } 
	 else
	 { 
		 yi = -1;
		 dy = y1 - y2;
	 }
	 this->putPixel(x, y,&col);
	 if (dx > dy)
	 {
		 ai = (dy - dx) * 2;
		 bi = dy * 2;
		 d = bi - dx;
		 while (x != x2)
		 { 
			 if (d >= 0)
			 { 
				 x += xi;
				 y += yi;
				 d += ai;
			 } 
			 else
			 {
				 d += bi;
				 x += xi;
			 }
			 this->putPixel(x, y,&col);
		 }
	 } 
	 else
	 { 
		 ai = ( dx - dy ) * 2;
		 bi = dx * 2;
		 d = bi - dy;
		 while (y != y2)
		 { 
			 if (d >= 0)
			 { 
				 x += xi;
				 y += yi;
				 d += ai;
			 }
			 else
			 {
				 d += bi;
				 y += yi;
			 }
			 this->putPixel(x, y,&col);
		 }
	 }
}


void arc::camera::addRotate(ROTATE_AX axis, float theta)
{
	static arc::MATRIX4X4 rt;

	switch(axis)
	{
	case arc::X:

		arc::mtx4x4_init(&rt,1,0				 ,0					 ,0,
						     0,cos((float)theta),-sin((float)theta),0,
						     0,sin((float)theta), cos((float)theta),0,
						     0,0				 ,0 				 ,0);

		this->transformations.push_back(rt);

	break;

	case arc::Y:
		arc::mtx4x4_init(&rt, cos((float)theta),0,sin((float)theta),0,
						      0				    ,1,0				 ,0,
							 -sin((float)theta),0,cos((float)theta),0,
						      0                 ,0,0				 ,1);

		this->transformations.push_back(rt);

	break;
	
	case arc::Z:

		arc::mtx4x4_init(&rt,cos((float)theta),-sin((float)theta),0,0,
						     sin((float)theta), cos((float)theta),0,0,
						     0,					 0,					1,0,
						     0,					 0,					0,1);

		this->transformations.push_back(rt);

	break;
	
	}
}

void arc::camera::moveBy(float x,float y,float z)
{
	this->pos_x += x;
	this->pos_y += y;
	this->pos_z += z;
}




