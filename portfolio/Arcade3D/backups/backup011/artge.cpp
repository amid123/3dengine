#include <windows.h>
#include <iostream>
#include <ctime>
#include <cmath>
#include "artge.hpp"
#include "object.hpp"


arc::arc3d::arc3d(int size_w,int size_h,int col_depth) : mainScene(0), 
														 infoSwitch(0),
														 firstFrameState(true),
														 n(0), 													
														 h(size_h),													
														 color_depth(col_depth),												
														 w(size_w),
														 FPS(0),
														 sleeper(30),
														 mouse_x(0),
														 mouse_y(0),
														 mouseBuf_x(0),
														 mouseBuf_y(0)
{
	// Inicjujemy SDL
	if(SDL_Init( SDL_INIT_VIDEO )<0)
	{
		std::cerr << "Blad inicjacji bibvlioteki SDL !! " << std::endl;
		exit(1);
	}
 
	// Ustawiamy tryb video
	srf = SDL_SetVideoMode(this->w, //szerokoœæ
				 this->h, //wysokoœæ
				 color_depth, //iloœæ bitów koloru 8,16,32, dla 0 sam ustala.
				 SDL_HWSURFACE | SDL_DOUBLEBUF); // flagi, o których szerzej poni¿ej.
 
	// Jesli wskaznik powierzchni ekranu ==  0 blad inicjacji sdl
	if(srf == NULL)
	{
		std::cerr << "Blad inicjacji biblioteki SDL !! " << std::endl;
		exit(1);
	}

	// Ustawiamy tytul okna
	SDL_WM_SetCaption("Arcade3D",0);

	col.R = 255;
	col.G = 255;
	col.B = 0;

	/*switch(color_depth)
	{
		case 8:
			putPixel = &arc::arc3d::putPixel8bit;
		break;
		case 16:
			putPixel = &arc::arc3d::putPixel16bit;
		break;
		case 24:
			putPixel = &arc::arc3d::putPixel24bit;
		break;
		case 32:
			putPixel = &arc::arc3d::putPixel32bit;
		break;
	}*/

	// Inicjacja zmiennych srodka ekranu
	this->scr_x_zero = this->w/2;	// ustalamy punkty sroda ekranu
	this->scr_y_zero = this->h/2;
	this->text = new arc::BMPSTRING(srf,w,h);
	this->viewMode = EDGE_VIEW;
}

void arc::arc3d::putPixel8bit(int x, int y, colRGB* color)
{
	// Jesli wykraczamy poza ekran - nie rysujemy
	if( (x >= 0) && (x < w) && (y >= 0) && (y < h) )
	{
	    Uint32 pixel = SDL_MapRGB(srf->format, color->R, color->G, color->B);
	    int bpp = srf->format->BytesPerPixel;
	    volatile Uint8 *p = (Uint8 *)srf->pixels + y * srf->pitch + x * bpp;
		*p = pixel;
	}
}

void arc::arc3d::putPixel16bit(int x, int y, colRGB* color)
{
	// Jesli wykraczamy poza ekran - nie rysujemy
	if( (x >= 0) && (x < w) && (y >= 0) && (y < h) )
	{
	    Uint32 pixel = SDL_MapRGB(srf->format, color->R, color->G, color->B);
	    int bpp = srf->format->BytesPerPixel;
	    volatile Uint8 *p = (Uint8 *)srf->pixels + y * srf->pitch + x * bpp;
		*(Uint16 *)p = pixel;
	}
}

void arc::arc3d::putPixel24bit(int x, int y, colRGB* color)
{
	// Jesli wykraczamy poza ekran - nie rysujemy
	if( (x >= 0) && (x < w) && (y >= 0) && (y < h) )
	{
	    Uint32 pixel = SDL_MapRGB(srf->format, color->R, color->G, color->B);
	    int bpp = srf->format->BytesPerPixel;
	    volatile Uint8 *p = (Uint8 *)srf->pixels + y * srf->pitch + x * bpp;
	    
		if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
	        p[0] = (pixel >> 16) & 0xff;
	        p[1] = (pixel >> 8) & 0xff;
	        p[2] = pixel & 0xff;
	    } 
		else 
		{
	        p[0] = pixel & 0xff;
	        p[1] = (pixel >> 8) & 0xff;
	        p[2] = (pixel >> 16) & 0xff;
	    }
	}
}

void arc::arc3d::putPixel32bit(int x, int y, colRGB* color)
{
	// Jesli wykraczamy poza ekran - nie rysujemy
	if( (x >= 0) && (x < w) && (y >= 0) && (y < h) )
	{
	    Uint32 pixel = SDL_MapRGB(srf->format, color->R, color->G, color->B);
	    int bpp = srf->format->BytesPerPixel;
	    volatile Uint8 *p = (Uint8 *)srf->pixels + y * srf->pitch + x * bpp;
		*(Uint32 *)p = pixel;
	}
}

void arc::arc3d::drawLine(int x1,int y1, int x2,int y2)
{	// implementacja algorytmu rasteryzacji B.
	if( (x1 >= -w) && (x1 < w*2) && (y1 >= -h) && (y1 < h*2) )
		if( (x2 >= -w) && (x2 < w*2) && (y2 >= -h) && (y2 < h*2) )
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
			 this->putPixel24bit(x, y,&col);
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
					 this->putPixel24bit(x, y,&col);
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
					 this->putPixel24bit(x, y,&col);
				}
			 }
		}
}

SDL_Surface * arc::arc3d::returnSurfacePtr()
{
	return this->srf;
}

void arc::arc3d::drawScene(int mode)
{
    /* Niektóre powierzchnie wymagaj¹ zablokowania,
       aby coœ na nich narysowaæ u¿ywaj¹c bezpoœredniego dostêpu
       do pamiêci i do tego s³u¿y ten kawa³ek kodu. */
    if ( SDL_MUSTLOCK(this->srf) )
        if ( SDL_LockSurface(this->srf) < 0 )
            return;
 
    /* Wype³niamy ca³y ekran dwoma kolorami */  
	/// Rysujemy tutaj;

	switch(mode)
	{
	case VERTEX_VIEW:
		for(unsigned int j = 0 ; j < this->mainScene->objects.size() ; j++)
		{
			//if(this->mainScene->objects[j].isVisible())
				for(unsigned int i = 0 ; i < this->mainScene->objects[j].vertexList.size ; i++)
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

					this->putPixel24bit((int)(scr_x_zero + (this->mainScene->objects[j].vertexList.indexList[i]->scr.x)),
										(int)(scr_y_zero + (this->mainScene->objects[j].vertexList.indexList[i]->scr.y)),&col);
				}
		}
	break;

	case EDGE_VIEW:

		for(unsigned int j = 0 ; j < this->mainScene->objects.size() ; j++)
		{
			//if( !this->mainScene->mainCamera->checkVisibleObject(90, &this->mainScene->objects[j]) )continue;
			//if(this->mainScene->objects[j].isVisible())
				for(unsigned int i = 0 ; i < this->mainScene->objects[j].faceList.size ; i++)
				{
					// jesli obiekt jest nie widoczny to continue;p
					if( !this->mainScene->mainCamera->checkVisibleFace(90,this->mainScene->objects[j].faceList.indexList[i]) ) continue;
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
					if(j == 4)
					{
						col.R = 255;
						col.G = 100;
						col.B = 90;
					}
					if(j == 5)
					{
						col.R = 34;
						col.G = 255;
						col.B = 115;
					}
					if(j == 6)
					{
						col.R = 255;
						col.G = 1;
						col.B = 150;
					}

					this->drawLine( (int)(scr_x_zero + (this->mainScene->objects[j].faceList.indexList[i]->v1->scr.x)),
									(int)(scr_y_zero + (this->mainScene->objects[j].faceList.indexList[i]->v1->scr.y)),
								    (int)(scr_x_zero + (this->mainScene->objects[j].faceList.indexList[i]->v2->scr.x)),
								    (int)(scr_y_zero + (this->mainScene->objects[j].faceList.indexList[i]->v2->scr.y)));
																													  
					this->drawLine( (int)(scr_x_zero + (this->mainScene->objects[j].faceList.indexList[i]->v2->scr.x)),
								    (int)(scr_y_zero + (this->mainScene->objects[j].faceList.indexList[i]->v2->scr.y)),
								    (int)(scr_x_zero + (this->mainScene->objects[j].faceList.indexList[i]->v3->scr.x)),
								    (int)(scr_y_zero + (this->mainScene->objects[j].faceList.indexList[i]->v3->scr.y)));
																													
					this->drawLine( (int)(scr_x_zero + (this->mainScene->objects[j].faceList.indexList[i]->v3->scr.x)),
								    (int)(scr_y_zero + (this->mainScene->objects[j].faceList.indexList[i]->v3->scr.y)),
								    (int)(scr_x_zero + (this->mainScene->objects[j].faceList.indexList[i]->v1->scr.x)),
								    (int)(scr_y_zero + (this->mainScene->objects[j].faceList.indexList[i]->v1->scr.y)));
				}
		}
	break;
	case POLY_VIEW:
		for(unsigned int j = 0 ; j < this->mainScene->objects.size() ; j++)
		{
			if( !this->mainScene->mainCamera->checkVisibleObject(90, &this->mainScene->objects[j]) )continue;
			if(this->mainScene->objects[j].isVisible())
			for(unsigned int i = 0 ; i < this->mainScene->objects[j].faceList.size ; i++)
			{
				this->fillTriangle(this->mainScene->objects[j].faceList.indexList[i]);
			}
		}
	break;

	}

    /* Odblokowujemy po rysowaniu */  
	if ( SDL_MUSTLOCK(this->srf) )
        SDL_UnlockSurface(this->srf);
 
    /* Podmieniamy obszar rysowania */    
    SDL_Flip(this->srf);
	SDL_FillRect(this->srf, NULL, SDL_MapRGB(this->srf->format, 0,0,0) );
}


// glowna petla aplikacji z obsluga komunikatow
void arc::arc3d::mainLoop()
{

int delay = 0; // dla licznika fps


SDL_Event event;
SDL_EnableKeyRepeat(20,20);

int done = 1;

	while(done)
	{
	    while(SDL_PollEvent(&event))
	    {
			if(event.motion.type == SDL_MOUSEMOTION)
			{
				crsPosX = event.motion.x;
				crsPosY = event.motion.y;
				if(event.button.button == SDL_BUTTON_LEFT)
				{
					mouse_x = event.motion.x;
					mouse_y = event.motion.y;

					if(mouse_x < mouseBuf_x)
					{
						this->mainScene->mainCamera->set(0,0,0,0,(float)DEG_TO_RAD(-0.1),0);
						this->mainScene->mainCamera->build(YXZ);
					}
					if(mouse_x > mouseBuf_x)
					{
						this->mainScene->mainCamera->set(0,0,0,0,(float)DEG_TO_RAD(0.1),0);
						this->mainScene->mainCamera->build(YXZ);
					}	
					if(mouse_y < mouseBuf_y)
					{
						this->mainScene->mainCamera->set(0,0,0,(float)DEG_TO_RAD(-0.1),0,0);
						this->mainScene->mainCamera->build(YXZ);
					}
					if(mouse_y > mouseBuf_y)
					{
						this->mainScene->mainCamera->set(0,0,0,(float)DEG_TO_RAD(0.1),0,0);
						this->mainScene->mainCamera->build(YXZ);
					}
				 }

				mouseBuf_x = mouse_x;
				mouseBuf_y = mouse_y;
			}
	        if(event.type == SDL_QUIT)
	            done=0;
	        if(event.type == SDL_KEYDOWN)
			{
	            if(event.key.keysym.sym == SDLK_ESCAPE)
	                done=0;
				if(event.key.keysym.sym == SDLK_DOWN)
				{
					this->mainScene->mainCamera->set(0,0,0,(float)DEG_TO_RAD(-2),0,0);
					this->mainScene->mainCamera->build(YXZ);
				}
				if(event.key.keysym.sym == SDLK_UP)
				{	
					this->mainScene->mainCamera->set(0,0,0,(float)DEG_TO_RAD(2),0,0);
					this->mainScene->mainCamera->build(YXZ);
				}
				if(event.key.keysym.sym == SDLK_RIGHT)
				{
					this->mainScene->mainCamera->set(0,0,0,0,(float)DEG_TO_RAD(2),0);
					this->mainScene->mainCamera->build(YXZ);
				}
				if(event.key.keysym.sym == SDLK_LEFT)
				{
					this->mainScene->mainCamera->set(0,0,0,0,(float)DEG_TO_RAD(-2),0);
					this->mainScene->mainCamera->build(YXZ);
				}
				if(event.key.keysym.sym == SDLK_z)
				{
					this->mainScene->objects[n].addRotate(arc::Z,(float)DEG_TO_RAD(10));
				}
				if(event.key.keysym.sym == SDLK_x)
				{
					this->mainScene->objects[n].addRotate(arc::Z,(float)DEG_TO_RAD(-10));
				}
				if(event.key.keysym.sym == SDLK_o)
				{
					this->mainScene->objects[n].addRotate(arc::X,(float)DEG_TO_RAD(10));
				}
				if(event.key.keysym.sym == SDLK_p)
				{
					this->mainScene->objects[n].addRotate(arc::X,(float)DEG_TO_RAD(-10));
				}

				if(event.key.keysym.sym == SDLK_k)
				{
					this->mainScene->objects[n].addRotate(arc::Y,(float)DEG_TO_RAD(10));
				}
				if(event.key.keysym.sym == SDLK_l)
				{
					this->mainScene->objects[n].addRotate(arc::Y,(float)DEG_TO_RAD(-10));
				}
				if(event.key.keysym.sym == SDLK_c)
				{
					this->mainScene->objects[n].addScale((float)1.1);
				}
				if(event.key.keysym.sym == SDLK_v)
				{
					this->mainScene->objects[n].addScale((float)0.9);
				}
				if(event.key.keysym.sym == SDLK_w)
				{
					this->mainScene->mainCamera->set(0,0,2,0,0,0);
					this->mainScene->mainCamera->build(YXZ);
				}
				if(event.key.keysym.sym == SDLK_a)
				{
					this->mainScene->mainCamera->set(2,0,0,0,0,0);
					this->mainScene->mainCamera->build(YXZ);
				}
				if(event.key.keysym.sym == SDLK_d)
				{
					this->mainScene->mainCamera->set(-2,0,0,0,0,0);
					this->mainScene->mainCamera->build(YXZ);
				}
				if(event.key.keysym.sym == SDLK_s)
				{
					this->mainScene->mainCamera->set(0,0,-2,0,0,0);
					this->mainScene->mainCamera->build(YXZ);
				}
				if(event.key.keysym.sym == SDLK_q)
				{
					this->mainScene->mainCamera->set(0,-2,0,0,0,0);
					this->mainScene->mainCamera->build(YXZ);
				}
				if(event.key.keysym.sym == SDLK_e)
				{
					this->mainScene->mainCamera->set(0,2,0,0,0,0);
					this->mainScene->mainCamera->build(YXZ);
				}
				if(event.key.keysym.sym == SDLK_i)
				{
				// Opoznienie czasowe dla przycisku i od wyswietlania informacji
				    time_t nextSec = 0;
				    static time_t prevSec = 0;

				    nextSec = time(NULL);

				    if(nextSec - prevSec != 0)
				    {
				        prevSec = nextSec;
					
						if(infoSwitch)
						{
							this->infoSwitch = false;
						}
						else
						{
							if(!infoSwitch)
							this->infoSwitch = true;
						}
				    }
				}
				// Obsluga ruchu kamera
				if(event.key.keysym.sym == SDLK_t)
				{
					this->mainScene->mainCamera->set(0,0,1,0,0,0);
					this->mainScene->mainCamera->build(YXZ);
				}
				if(event.key.keysym.sym == SDLK_g)
				{
					this->mainScene->mainCamera->set(0,0,-1,0,0,0);
					this->mainScene->mainCamera->build(YXZ);
				}

				if(event.key.keysym.sym == SDLK_f)
				{
					this->mainScene->mainCamera->set(0,1,0,0,0,0);
					this->mainScene->mainCamera->build(YXZ);
				}
				if(event.key.keysym.sym == SDLK_h)
				{
					this->mainScene->mainCamera->set(0,-1,0,0,0,0);
					this->mainScene->mainCamera->build(YXZ);
				}
				if(event.key.keysym.sym == SDLK_n)
				{
					// Opoznienie czasowe dla przycisku i od wyswietlania informacji
				    time_t nextSec = 0;
				    static time_t prevSec = 0;

				    nextSec = time(NULL);

				    if(nextSec - prevSec != 0)
				    {
				        prevSec = nextSec;
						
						n++;
						if(n == this->mainScene->objects.size())
							n = 0;
				    }
				}

				if(event.key.keysym.sym == SDLK_m)
				{
					// Opoznienie czasowe dla przycisku i od wyswietlania informacji
				    time_t nextSec = 0;
				    static time_t prevSec = 0;
				    nextSec = time(NULL);

				    if(nextSec - prevSec != 0)
				    {
				        prevSec = nextSec;
						
						if(this->viewMode == VERTEX_VIEW) viewMode = EDGE_VIEW;
						else if(this->viewMode == EDGE_VIEW) viewMode = POLY_VIEW;
						else if(this->viewMode == POLY_VIEW) viewMode = VERTEX_VIEW;
						//else if(this->viewMode == VERTEX_VIEW) viewMode =
				    }
				}
	        }
	    }
		this->render();
		// poprawic implementacje funkcji stabilizujacej czas ramiki :D
		//this->frameTimeStabilise();
	}
}

arc::arc3d::~arc3d()
{
	atexit(SDL_Quit);
	delete this->text;
}

void arc::arc3d::setScene(arc::scene *sc1)
{
	if(!mainScene)this->mainScene = sc1;
}

inline void arc::arc3d::showInfo()
{
	//Informacje
	if(this->infoSwitch)
	{
		if(this->viewMode == VERTEX_VIEW)
		{
			this->text->InsertString(10,550,"View mode. VERTEX-VIEW");
		}

		if(this->viewMode == EDGE_VIEW)
		{
			this->text->InsertString(10,550,"View mode. EDGE-VIEW");
		}

		if(this->viewMode == POLY_VIEW)
		{
			this->text->InsertString(10,550,"View mode. POLY-VIEW");
		}
		// Wyswietlamy informacje
		this->text->SetFontColor(255,255,255);
		this->text->InsertString(10,10,"Arcade 3D REAL-TIME GRAPHICS ENGINE (ARTGE)");
		this->text->InsertString(10,20,"Made by. Arkadiusz Gibes (ringo99)");

		// Numer zaznaczonego obiektu
		this->text->InsertString(10,560,"Nr zaznaczonego obiektu ");
		this->text->InsertString(200,560,this->n+1);

		// Wyswietlamy pozycje kursora
		this->text->InsertString(10,580,"PozycjaX ");
		this->text->InsertString(90,580,this->crsPosX);
		this->text->InsertString(10,590,"PozycjaY ");
		this->text->InsertString(90,590,this->crsPosY);

		// Licznik klatek na sekunde
		this->text->InsertString(10,570, "Licznik klatek (FPS) ");
		this->text->InsertString(180,570,FPS);
	}
}
void arc::arc3d::frameCounter()
{
	 time_t nextSec = 0;
	 static time_t prevSec = 0;

	 fps_buf++;
	 nextSec = time(NULL);

	 if(nextSec - prevSec != false)
	 {
	     prevSec = nextSec;
		 FPS = fps_buf;
	     fps_buf = 0;
	 }
}
 
/*  ########################################################
	################### POTOK RENDERINGU ###################
	########################################################
	########################################################
	# Tutaj rozpoczyna sie proces przetwarzania grafiki 3d #
	# Wykonywane sa przekszta³cenia z					   #
	# urzyciem zgromadzonych macierzy przeksztalcen.	   #
	########################################################
	########################################################
	########################################################
*/

void arc::arc3d::render()
{
	this->frameCounter();
	/// Potok renderingu;
	this->showInfo();

	float x_buf;
	float y_buf;
	float z_buf;
	float dist;
	float aspect;

	arc::MATRIX4X4 mtxBufLoc;

	for(unsigned int i = 0 ; i < this->mainScene->objects.size() ; i++)
	{
		if(this->mainScene->objects[i].T.size() != 0)
		{
			mtxBufLoc = this->mainScene->objects[i].T[0];
			for(unsigned int j = 1 ; j < this->mainScene->objects[i].T.size() ; j++)
			{
				arc::mtx4x4mulmtx4x4(&mtxBufLoc,&this->mainScene->objects[i].T[i],&mtxBufLoc);
			}
		}
		// Jesli sa przeksztalcenia, przeksztalcamy wspolrzedne lokalne
		for(unsigned int j = 0 ; j < this->mainScene->objects[i].vertexList.size ; j++)
		{
			if(this->mainScene->objects[i].T.size() != false)
			{
				this->transformVertexByMatrix(this->mainScene->objects[i].vertexList.indexList[j],&mtxBufLoc,LOCAL_ONLY);
			}
			// Ustawiamy buforujemy wspolrzedne lokalne;
			x_buf = this->mainScene->objects[i].vertexList.indexList[j]->local.x;
			y_buf = this->mainScene->objects[i].vertexList.indexList[j]->local.y;
			z_buf = this->mainScene->objects[i].vertexList.indexList[j]->local.z;

			// Ustawiamy wspolrzedne globalne punktu;
			this->mainScene->objects[i].vertexList.indexList[j]->global.x = x_buf + this->mainScene->objects[i].pos_x() + -this->mainScene->mainCamera->cameraPosition()->x;
			this->mainScene->objects[i].vertexList.indexList[j]->global.y = y_buf + this->mainScene->objects[i].pos_y() + -this->mainScene->mainCamera->cameraPosition()->y;
			this->mainScene->objects[i].vertexList.indexList[j]->global.z = z_buf + this->mainScene->objects[i].pos_z() + -this->mainScene->mainCamera->cameraPosition()->z;


			this->transformVertexByMatrix(this->mainScene->objects[i].vertexList.indexList[j],
										 &this->mainScene->mainCamera->camMtx,GLOBAL_TO_CAMERA);
			// Przekszta³camy wektor normalny dzielac przez w
			x_buf = this->mainScene->objects[i].vertexList.indexList[j]->cam.x;// /= this->mainScene->objects[i].vertexList.indexList[j]->cam.w;
			y_buf = this->mainScene->objects[i].vertexList.indexList[j]->cam.y;// /= this->mainScene->objects[i].vertexList.indexList[j]->cam.w;
			z_buf = this->mainScene->objects[i].vertexList.indexList[j]->cam.z;// /= this->mainScene->objects[i].vertexList.indexList[j]->cam.w;
			
			dist = this->mainScene->mainCamera->getDist();			// Pobieramy dystans obserwatora odplaszczyzny rzutowania
			aspect = this->mainScene->mainCamera->getAspectRatio(); // Pobieramy proporcje obrazu

			this->mainScene->objects[i].vertexList.indexList[j]->scr.x = x_buf * dist * x_buf / z_buf;
			this->mainScene->objects[i].vertexList.indexList[j]->scr.y = y_buf * dist* y_buf * aspect / z_buf;
		}
		// Czyscimy liste transformacji lokalnych dla kazdego obiektu osobno;
		this->mainScene->objects[i].T.clear();
	}
	
	// Jesli pierwsza klatka zmieniamy stan na nie pierwsza (koniec potoku)
	if(this->firstFrameState) firstFrameState = false;
	// Rysujemy scene
	this->drawScene(this->viewMode);
}

void arc::arc3d::transformObjectByMatrix(arc::object* obj,arc::MATRIX4X4*mtx,int atrb)
{
							// Bufory wektorow
arc::VECTOR4D vn1;
arc::VECTOR4D vn2;
							// Wybieramy tryb transformacji
	switch(atrb)
	{	
	case LOCAL_ONLY:		// Jesli transformacja na wspolrzednych lokalnych
		for(unsigned int i = 0 ; i < obj->vertexList.size ; i++)
		{
			arc::vct4d_init(&vn1, obj->vertexList.indexList[i]->local.x,
								  obj->vertexList.indexList[i]->local.y,
								  obj->vertexList.indexList[i]->local.z,
								  1);
			arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);

			obj->vertexList.indexList[i]->local.x = vn2.x;
			obj->vertexList.indexList[i]->local.y = vn2.y;
			obj->vertexList.indexList[i]->local.z = vn2.z;
		}
	break;
	case GLOBAL_ONLY:		// Jesli transformacja na wspolrzednych globalnych
		for(unsigned int i = 0 ; i < obj->vertexList.size ; i++)
		{
			arc::vct4d_init(&vn1, obj->vertexList.indexList[i]->global.x,
								  obj->vertexList.indexList[i]->global.y,
								  obj->vertexList.indexList[i]->global.z,
								  1);

			arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);

			obj->vertexList.indexList[i]->global.x = vn2.x;
			obj->vertexList.indexList[i]->global.y = vn2.y;
			obj->vertexList.indexList[i]->global.z = vn2.z;
		}
	break;
	case LOCAL_TO_GLOBAL:	// Jesli z lokalnych do globalnych
		for(unsigned int i = 0 ; i < obj->vertexList.size ; i++)
		{
			arc::vct4d_init(&vn1, obj->vertexList.indexList[i]->local.x,
								  obj->vertexList.indexList[i]->local.y,
								  obj->vertexList.indexList[i]->local.z,
								  1);

			arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);

			obj->vertexList.indexList[i]->global.x = vn2.V[0] + obj->pos_x();
			obj->vertexList.indexList[i]->global.y = vn2.V[1] + obj->pos_y();
			obj->vertexList.indexList[i]->global.z = vn2.V[2] + obj->pos_z();
		}
	break;
	case GLOBAL_TO_CAMERA:	// Jesli z lokalnych do globalnych
		for(unsigned int i = 0 ; i < obj->vertexList.size ; i++)
		{
			arc::vct4d_init(&vn1, obj->vertexList.indexList[i]->global.x,
								  obj->vertexList.indexList[i]->global.y,
								  obj->vertexList.indexList[i]->global.z,
								  1);

			arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);

			obj->vertexList.indexList[i]->cam.x = vn2.x;
			obj->vertexList.indexList[i]->cam.y = vn2.y;
			obj->vertexList.indexList[i]->cam.z = vn2.z;
		}
	break;
	default:
		return;
	}
}


void arc::arc3d::transformRendListByMatrix(std::vector<arc::object>* obj_list,arc::MATRIX4X4* mtx,int atrb)
{
arc::VECTOR4D vn1;
arc::VECTOR4D vn2;

	switch(atrb)
	{
	case LOCAL_ONLY:
		for(unsigned int i = 0 ; i < obj_list->size() ; i++)
			for(unsigned int j = 0 ; j < (*obj_list)[i].vertexList.size ; j++)
			{
				arc::vct4d_init(&vn1, (*obj_list)[i].vertexList.indexList[j]->local.x,
									  (*obj_list)[i].vertexList.indexList[j]->local.y,
									  (*obj_list)[i].vertexList.indexList[j]->local.z,
									  1);

				arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);

				(*obj_list)[i].vertexList.indexList[j]->local.x = vn2.x;
				(*obj_list)[i].vertexList.indexList[j]->local.y = vn2.y;
				(*obj_list)[i].vertexList.indexList[j]->local.z = vn2.z;
			}
	break;
	case GLOBAL_ONLY:
		for(unsigned int i = 0 ; i < obj_list->size() ; i++)
			for(unsigned int j = 0 ; j < (*obj_list)[i].vertexList.size ; j++)
			{
				arc::vct4d_init(&vn1, (*obj_list)[i].vertexList.indexList[j]->global.x,
									  (*obj_list)[i].vertexList.indexList[j]->global.y,
									  (*obj_list)[i].vertexList.indexList[j]->global.z,
									  1);

				arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);

				(*obj_list)[i].vertexList.indexList[j]->global.x = vn2.x;
				(*obj_list)[i].vertexList.indexList[j]->global.y = vn2.y;
				(*obj_list)[i].vertexList.indexList[j]->global.z = vn2.z;
			}
	break;
	case LOCAL_TO_GLOBAL:
		for(unsigned int i = 0 ; i < obj_list->size() ; i++)
			for(unsigned int j = 0 ; j < (*obj_list)[i].vertexList.size ; j++)
			{
				arc::vct4d_init(&vn1, (*obj_list)[i].vertexList.indexList[j]->local.x,
									  (*obj_list)[i].vertexList.indexList[j]->local.y,
									  (*obj_list)[i].vertexList.indexList[j]->local.z,
									  1);

				arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);

				(*obj_list)[i].vertexList.indexList[j]->global.x = vn2.x + (*obj_list)[i].pos_x();
				(*obj_list)[i].vertexList.indexList[j]->global.y = vn2.y + (*obj_list)[i].pos_y();
				(*obj_list)[i].vertexList.indexList[j]->global.z = vn2.z + (*obj_list)[i].pos_z();
			}
	break;
	case GLOBAL_TO_CAMERA:
		for(unsigned int i = 0 ; i < obj_list->size() ; i++)
			for(unsigned int j = 0 ; j < (*obj_list)[i].vertexList.size ; j++)
			{
				arc::vct4d_init(&vn1, (*obj_list)[i].vertexList.indexList[j]->global.x,
									  (*obj_list)[i].vertexList.indexList[j]->global.y,
									  (*obj_list)[i].vertexList.indexList[j]->global.z,
									  1);

				arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);

				(*obj_list)[i].vertexList.indexList[j]->cam.x = vn2.x;
				(*obj_list)[i].vertexList.indexList[j]->cam.y = vn2.y;
				(*obj_list)[i].vertexList.indexList[j]->cam.z = vn2.z;
			}
	break;
	default:
		return;
	}
}

void arc::arc3d::initVertex3dLocalByVector4d(arc::vertex3d * vert,arc::VECTOR4D * v)
{
	vert->local.x = v->x;
	vert->local.y = v->y;
	vert->local.z = v->z;
}

void arc::arc3d::initVertex3dLocalByVector3d(arc::vertex3d * vert,arc::VECTOR3D * v)
{
	vert->local.x = v->x;
	vert->local.y = v->y;
	vert->local.z = v->z;
}

void arc::arc3d::initVector4dByVertex3dLocal(arc::VECTOR4D * v,arc::vertex3d * vert)
{
	v->x = vert->local.x;
	v->y = vert->local.y;
	v->z = vert->local.z;
	v->w = vert->local.w;
}

void arc::arc3d::initVector4dByVertex3dLocal(arc::VECTOR4D * v,arc::vertex3d * vert,float l)
{
	v->x = vert->local.x;
	v->y = vert->local.y;
	v->z = vert->local.z;
	v->w = vert->local.w;
}

void arc::arc3d::initVector3dByVertex3dLocal(arc::VECTOR3D * v,arc::vertex3d * vert)
{
	v->x = vert->local.x;
	v->y = vert->local.y;
	v->z = vert->local.z;

}

void arc::arc3d::initVertex3dGlobalByVector4d(arc::vertex3d * vert,arc::VECTOR4D * v)
{
	vert->global.x = v->x;
	vert->global.y = v->y;
	vert->global.z = v->z;
}

void arc::arc3d::initVertex3dGlobalByVector3d(arc::vertex3d * vert,arc::VECTOR3D * v)
{
	vert->global.x = v->x;
	vert->global.y = v->y;
	vert->global.z = v->z;
}

void arc::arc3d::initVector4dByVertex3dGlobal(arc::VECTOR4D * v,arc::vertex3d * vert)
{
	v->x = vert->global.x;
	v->y = vert->global.y;
	v->z = vert->global.z;
	v->w = vert->global.w;;
}

void arc::arc3d::initVector4dByVertex3dGlobal(arc::VECTOR4D * v,arc::vertex3d * vert,float l)
{
	v->x = vert->global.x;
	v->y = vert->global.y;
	v->z = vert->global.z;
	v->w = vert->global.w;
}

void arc::arc3d::initVector3dByVertex3dGlobal(arc::VECTOR3D * v,arc::vertex3d * vert)
{
	v->x = vert->global.x;
	v->y = vert->global.y;
	v->z = vert->global.z;
}

void arc::arc3d::initVertex3dCamByVector4d(arc::vertex3d * vert,arc::VECTOR4D * v)
{
	vert->cam.x = v->x;
	vert->cam.y = v->y;
	vert->cam.z = v->z;
}

void arc::arc3d::initVertex3dCamByVector3d(arc::vertex3d * vert,arc::VECTOR3D * v)
{
	vert->cam.x = v->x;
	vert->cam.y = v->y;
	vert->cam.z = v->z;
}

void arc::arc3d::initVector4dByVertex3dCam(arc::VECTOR4D * v,arc::vertex3d * vert)
{
	v->x = vert->cam.x;
	v->y = vert->cam.y;
	v->z = vert->cam.z;
	v->w = vert->cam.w;
}

void arc::arc3d::initVector4dByVertex3dCam(arc::VECTOR4D * v,arc::vertex3d * vert,float l)
{
	v->x = vert->cam.x;
	v->y = vert->cam.y;
	v->z = vert->cam.z;
	v->w = vert->cam.w;
}

void arc::arc3d::initVector3dByVertex3dCam(arc::VECTOR3D * v,arc::vertex3d * vert)
{
	v->x = vert->cam.x;
	v->y = vert->cam.y;
	v->z = vert->cam.z;
}

void arc::arc3d::transformVertexByMatrix(arc::vertex3d *vert,arc::MATRIX4X4 *mtx,int atrb)
{
arc::VECTOR4D vn1;
arc::VECTOR4D vn2;

	switch(atrb)
	{
	case LOCAL_ONLY:

		this->initVector4dByVertex3dLocal(&vn1,vert);
		arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);
		this->initVertex3dLocalByVector4d(vert,&vn2);

	break;
	case GLOBAL_ONLY:

		this->initVector4dByVertex3dGlobal(&vn1,vert);
		arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);
		this->initVertex3dGlobalByVector4d(vert,&vn2);

	break;
	case LOCAL_TO_GLOBAL:

		this->initVector4dByVertex3dLocal(&vn1,vert);
		arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);
		this->initVertex3dGlobalByVector4d(vert,&vn2);

	break;
	case GLOBAL_TO_CAMERA:

		this->initVector4dByVertex3dGlobal(&vn1,vert);
		arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);
		this->initVertex3dCamByVector4d(vert,&vn2);

	break;
	default:
		return;
	}
}

void arc::arc3d::transformFaceByMatrix(arc::face* fc,arc::MATRIX4X4* mtx,int atrb)
{
arc::VECTOR4D vn1;
arc::VECTOR4D vn2;

	switch(atrb)
	{
	case LOCAL_ONLY:
		
		this->initVector4dByVertex3dLocal(&vn1,fc->v1);
		arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);
		this->initVertex3dLocalByVector4d(fc->v1,&vn2);

		this->initVector4dByVertex3dLocal(&vn1,fc->v2);
		arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);
		this->initVertex3dLocalByVector4d(fc->v2,&vn2);
			
		this->initVector4dByVertex3dLocal(&vn1,fc->v3);
		arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);
		this->initVertex3dLocalByVector4d(fc->v3,&vn2);

	break;
	case GLOBAL_ONLY:

		this->initVector4dByVertex3dGlobal(&vn1,fc->v1);
		arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);
		this->initVertex3dGlobalByVector4d(fc->v1,&vn2);

		this->initVector4dByVertex3dGlobal(&vn1,fc->v2);
		arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);
		this->initVertex3dGlobalByVector4d(fc->v2,&vn2);
			
		this->initVector4dByVertex3dGlobal(&vn1,fc->v3);
		arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);
		this->initVertex3dGlobalByVector4d(fc->v3,&vn2);

	break;
	case LOCAL_TO_GLOBAL:

		this->initVector4dByVertex3dLocal(&vn1,fc->v1);
		arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);
		this->initVertex3dGlobalByVector4d(fc->v1,&vn2);

		this->initVector4dByVertex3dLocal(&vn1,fc->v2);
		arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);
		this->initVertex3dGlobalByVector4d(fc->v2,&vn2);
			
		this->initVector4dByVertex3dLocal(&vn1,fc->v3);
		arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);
		this->initVertex3dGlobalByVector4d(fc->v3,&vn2);

	break;
	case GLOBAL_TO_CAMERA:

		this->initVector4dByVertex3dGlobal(&vn1,fc->v1);
		arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);
		this->initVertex3dCamByVector4d(fc->v1,&vn2);

		this->initVector4dByVertex3dGlobal(&vn1,fc->v2);
		arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);
		this->initVertex3dCamByVector4d(fc->v2,&vn2);
			
		this->initVector4dByVertex3dGlobal(&vn1,fc->v3);
		arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);
		this->initVertex3dCamByVector4d(fc->v3,&vn2);
	break;
	default:
		return;
	}
}

void arc::arc3d::frameTimeStabilise()
{
int i = 0;
		if(this->FPS > 30)
		{
			if(sleeper < 100)
			{
				++sleeper;
				Sleep(sleeper);
			}
		}
		if(this->FPS < 30 )
		{
			if(sleeper > 0)
			{
				--sleeper;
				Sleep(sleeper);
			}
		}
		if(this->FPS == 30) Sleep(sleeper);
}


void arc::arc3d::objectMoveToPoint(arc::object* obj, arc::COORD_TYPE coord, arc::POINT3D* pt)
{
	switch(coord)
	{
	case OBJECT_COORD:
		obj->addTranslationLocal(pt->x,pt->y,pt->z);
	break;

	case WORLD_COORD:
		obj->setPosition(pt->x,pt->y,pt->z);
	break;
	
	}
}

void arc::arc3d::objectMoveBy(arc::object* obj, float value, arc::COORD_TYPE coord, arc::AXIS ax)
{
	switch(coord)
	{
	case OBJECT_COORD:
		switch(ax)
		{
		case X:
			obj->addTranslationLocal(value,0,0);
			break;
		case Y:
			obj->addTranslationLocal(0,value,0);
			break;
		case Z:
			obj->addTranslationLocal(0,0,value);
			break;

		case ALL:
			obj->addTranslationLocal(value,value,value);
			break;
		}
	break;

	case WORLD_COORD:
		switch(ax)
		{
		case X:
			obj->setPosition( obj->pos_x() + value, 0, 0);
			break;
		case Y:
			obj->setPosition( 0, obj->pos_y() + value, 0);
			break;
		case Z:
			obj->setPosition( 0, 0, obj->pos_z() + value);
			break;

		case ALL:
			obj->setPosition( obj->pos_x() + value,
							  obj->pos_y() + value,
							  obj->pos_z() + value);
			break;
		}
	break;
	
	}
}

void arc::arc3d::objectRotate(arc::object* obj, arc::COORD_TYPE coord, float theta)
{
	switch(coord)
	{
	case OBJECT_COORD:
	
	break;

	case WORLD_COORD:
	
	break;
	
	}
}

void arc::arc3d::objectScale(arc::object* obj, float scalar)
{

}

void arc::arc3d::objectsMoveToPoint( std::vector<arc::object*> objList, arc::COORD_TYPE, arc::POINT3D*)
{

}

void arc::arc3d::objectsMoveBy( std::vector<arc::object*> objList, float,arc::COORD_TYPE, arc::AXIS)
{

}

void arc::arc3d::objectsRotate( std::vector<arc::object*> objList, arc::COORD_TYPE,float)
{

}

void arc::arc3d::objectsScale( std::vector<arc::object*> objList, float)
{

}

void arc::arc3d::createNewCamera()
{

}

void arc::arc3d::addCamera(arc::camera*)
{

}

void arc::arc3d::deleteCamera(int cam_id)
{

}

int arc::arc3d::cameraQuantity()
{
	return false;
}

void arc::arc3d::fillTriangle(arc::face* fc)
{

float buffer;

float x1 = fc->v1->scr.x;
float x2 = fc->v2->scr.x;
float x3 = fc->v3->scr.x;

float y1 = fc->v1->scr.y;
float y2 = fc->v2->scr.y;
float y3 = fc->v3->scr.y;

float delta_xl;	// Przyrost lewej krawedzi
float delta_xr; // Przyrost prawj krawedzi 

float xl, xr , x, y;

	// Sortujemy wierzcho³ki wzglêdem Y;
	if(y1 > y2)
		SWAP(y1,y2,buffer);
	if(y2 > y3)
	{
		SWAP(y2,y3,buffer);
		if(y1 > y2)
			SWAP(y1,y2,buffer);
	}

	//Jesli wierzcholek nr 2 znajduje sie po prawej
	if(x2 > x1) //Wierzcholek 2 znajduje sie po prawej;
	{
		delta_xl=(x3-x1)/(y3-y1);
		delta_xr=(x2-x1)/(y2-y1);
	}

	//Jesli wierzcholek nr 2 znajduje sie po lewej
	if(x2 < x1) //Wierzcholek 2 znajduje sie po lewej;
	{
		delta_xl=(x2-x1)/(y2-y1);
		delta_xr=(x3-x1)/(y3-y1);
	}

	xr = x1;
	xl = x1;
	// Najpierw pêtla poruszaj¹ca w pionie na osi OY
	for(y = y1 ; y < y2 ; y++)
	{
		x = xl;
		while(x < xr)
		{
			this->putPixel24bit((int)(x + scr_x_zero), (int)(y + scr_y_zero),&this->col);
			x++;
		}
		xr +=delta_xr;
		xl +=delta_xl;
	}
}