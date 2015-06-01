/* 1.  Uzupelnic modol matematyczny i wprowadzic korekty optymalizacyjne
** 2.  Poprawic implementacje struktur danych 3D (vertexy,edges,polygons)
** 2.  Rozplanowac dokladnie potrk renderingu i przepisac go
** 3.  Zaimplementowac model kamery UVN
** 4.  Zaimplementowaæ model kamery eulerowskiej
** 5.  Zaimplementowac sprawna i optymalna obsluge perspektywy
** 6.  Zaimplementowac managera sceny pozwalajacego na latwy sposob
**     zarzadzania obiektami na scenie.
** 7.  Zaimplementowac wypelnianie powierzchni zwroconych przodem
** 8.  Zaimplementowac cieniowanie powierzchni
** 9.  Poprawic implementacje parsera *.obj
** 10. Zaimplementowac parser plikow MD2
** 11. Zaimplementowac obsluge animacji klatkowej
** 12. Zaimplementowac parser plikow MD5
** 13. Zaimplementowac obsluge animacji szkieletowej
*/

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
					  w(size_w)
{
	// Inicjujemy SDL
atexit(SDL_Quit);

	if(SDL_Init( SDL_INIT_VIDEO )<0){

		std::cerr << "Blad inicjacji bibvlioteki SDL !! " << std::endl;
 
		exit(1);
	}
 
	// Ustawiamy tryb video
	srf = SDL_SetVideoMode(this->w, //szerokoœæ
				 this->h, //wysokoœæ
				 color_depth, //iloœæ bitów koloru 8,16,32, dla 0 sam ustala.
				 SDL_HWSURFACE | SDL_DOUBLEBUF); // flagi, o których szerzej poni¿ej.
 
	// Jesli wskaznik powierzchni ekranu ==  0 blad inicjacji sdl
	if(srf == NULL){
		std::cerr << "Blad inicjacji biblioteki SDL !! " << std::endl;
		exit(1);
	}
	// Ustawiamy tytul okna
	SDL_WM_SetCaption("Arcade3D",0);

	col.R = 255;
	col.G = 255;
	col.B = 0;

	// Inicjacja zmiennych srodka ekranu
	this->scr_x_zero = this->w/2;	// ustalamy punkty sroda ekranu
	this->scr_y_zero = this->h/2;
	this->text = new arc::BMPSTRING(srf,w,h);
	this->viewMode = EDGE_VIEW;
}


void arc::arc3d::putPixel(int x, int y,colRGB * color)
{
	// Jesli wykraczamy poza ekran - nie rysujemy
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

void arc::arc3d::drawLine(int x1,int y1, int x2,int y2)
{	// implementacja algorytmu rasteryzacji pana B.


	if( (x1 >= 0) && (x1 < w) && (y1 >= 0) && (y1 < h) )
		if( (x2 >= 0) && (x2 < w) && (y2 >= 0) && (y2 < h) )
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

				this->putPixel((int)(scr_x_zero + (this->mainScene->objects[j].vertexList.indexList[i]->scr_x * 50)),
							   (int)(scr_x_zero + (this->mainScene->objects[j].vertexList.indexList[i]->scr_y * 50)),&col);
				
			}
	break;

	case EDGE_VIEW:

		for(unsigned int j = 0 ; j < this->mainScene->objects.size() ; j++)
			for(unsigned int i = 0 ; i < this->mainScene->objects[j].faceList.size ; i++)
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

				
				this->drawLine( (int)(scr_x_zero + (this->mainScene->objects[j].faceList.indexList[i]->v1->scr_x * 50)),
								(int)(scr_y_zero + (this->mainScene->objects[j].faceList.indexList[i]->v1->scr_y * 50)),
							    (int)(scr_x_zero + (this->mainScene->objects[j].faceList.indexList[i]->v2->scr_x * 50)),
							    (int)(scr_y_zero + (this->mainScene->objects[j].faceList.indexList[i]->v2->scr_y * 50)));
																												  
				this->drawLine( (int)(scr_x_zero + (this->mainScene->objects[j].faceList.indexList[i]->v2->scr_x * 50)),
							    (int)(scr_y_zero + (this->mainScene->objects[j].faceList.indexList[i]->v2->scr_y * 50)),
							    (int)(scr_x_zero + (this->mainScene->objects[j].faceList.indexList[i]->v3->scr_x * 50)),
							    (int)(scr_y_zero + (this->mainScene->objects[j].faceList.indexList[i]->v3->scr_y * 50)));
																												  
				this->drawLine( (int)(scr_x_zero + (this->mainScene->objects[j].faceList.indexList[i]->v3->scr_x * 50)),
							    (int)(scr_y_zero + (this->mainScene->objects[j].faceList.indexList[i]->v3->scr_y * 50)),
							    (int)(scr_x_zero + (this->mainScene->objects[j].faceList.indexList[i]->v1->scr_x * 50)),
							    (int)(scr_y_zero + (this->mainScene->objects[j].faceList.indexList[i]->v1->scr_y * 50)));
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
			}
	        if(event.type == SDL_QUIT)
	            done=0;
	        if(event.type == SDL_KEYDOWN)
			{
				
	            if(event.key.keysym.sym == SDLK_ESCAPE)
	                done=0;
				if(event.key.keysym.sym == SDLK_DOWN)
				{
					this->mainScene->objects[n].addRotate(arc::X,(float)-0.1);
				}
				if(event.key.keysym.sym == SDLK_UP)
				{	
					this->mainScene->objects[n].addRotate(arc::X,(float)0.1);
				}
				if(event.key.keysym.sym == SDLK_RIGHT)
				{
					this->mainScene->objects[n].addRotate(arc::Y,(float)-0.1);
				}
				if(event.key.keysym.sym == SDLK_LEFT)
				{
					this->mainScene->objects[n].addRotate(arc::Y,(float)0.1);
				}
				if(event.key.keysym.sym == SDLK_z)
				{
					this->mainScene->objects[n].addRotate(arc::Z,(float)0.1);
				}
				if(event.key.keysym.sym == SDLK_x)
				{
					this->mainScene->objects[n].addRotate(arc::Z,(float)-0.1);
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
					this->mainScene->mainCamera->addRotate(X,(float)0.1);
				}
				if(event.key.keysym.sym == SDLK_a)
				{
					this->mainScene->mainCamera->addRotate(Y,(float)-0.1);
				}

				if(event.key.keysym.sym == SDLK_d)
				{
					this->mainScene->mainCamera->addRotate(Y,(float)0.1);
				}
				if(event.key.keysym.sym == SDLK_s)
				{
					this->mainScene->mainCamera->addRotate(X,(float)-0.1);
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
					this->mainScene->mainCamera->moveBy(0,0,1);
				}
				if(event.key.keysym.sym == SDLK_g)
				{
					this->mainScene->mainCamera->moveBy(0,0,-1);
				}

				if(event.key.keysym.sym == SDLK_f)
				{
					this->mainScene->mainCamera->moveBy((float)0.1,0,0);
				}
				if(event.key.keysym.sym == SDLK_h)
				{
					this->mainScene->mainCamera->moveBy((float)-0.1,0,0);
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
						else if(this->viewMode == EDGE_VIEW) viewMode = VERTEX_VIEW;
						//else if(this->viewMode == VERTEX_VIEW) viewMode =
				    }
				}
	        }
	    }
		this->render();
	}
}

arc::arc3d::~arc3d()
{
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
		this->text->InsertString(10,30,"Aby zakonczyc wcisnij ESC");

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
	    static int FPS = 0;
		static int fps_buf;
	    time_t nextSec = 0;
	    static time_t prevSec = 0;

	    FPS++;
	    nextSec = time(NULL);

	    if(nextSec - prevSec != false)
	    {
	        prevSec = nextSec;
			fps_buf = FPS;

	        FPS = 0;
	    }
		this->text->InsertString(180,570,fps_buf);
	}
}

void arc::arc3d::render()
{
	/// G³owny potok renderingu;

	this->showInfo();

	float x_buf;
	float y_buf;
	float z_buf;

	float prsv;
	float cam_dist;

	arc::MATRIX4X4 mtxBufLoc;
	arc::MATRIX4X4 mtxBufCam;

	static arc::MATRIX4X4 mtxBufCamLast;


	arc::VECTOR4D vn1;
	arc::VECTOR4D vn2;

	/// Jesli sa przeksztalcenia widoku
	if(this->mainScene->mainCamera->transformations.size() > 0)
	{		// buforujemy pierwsza transformacje
			mtxBufCam = this->mainScene->mainCamera->transformations[0];
			for(unsigned int j = 1 ; j < this->mainScene->mainCamera->transformations.size() ; j++)
			{	// Mnozymy bufor transformacji[0] od razy nastepna transformacje++
				// wynik zapisujemy w buforze
				arc::mtx4x4mulmtx4x4(&mtxBufCam,&this->mainScene->mainCamera->transformations[j],&mtxBufCam);
			}
			// Jesli jest to pierwsza klatka to ustawiamy statyczny
			// bufor transformacji na zmienny bufor
			if(this->firstFrameState)
			{
				mtxBufCamLast = mtxBufCam;
			}
			else
			{
				// Jesli nie jest to pierwsza klatka skladamy poprzednie przeksztalcenia z nowymi w calosc;
				arc::mtx4x4mulmtx4x4(&mtxBufCamLast,&mtxBufCam,&mtxBufCamLast);
			}
	}

	for(unsigned int i = 0 ; i < this->mainScene->objects.size() ; i++)
	{
		if(this->mainScene->objects[i].transformations.size() != false)
		{
			mtxBufLoc = this->mainScene->objects[i].transformations[0];
			for(unsigned int j = 1 ; j < this->mainScene->objects[i].transformations.size() ; j++)
			{
				arc::mtx4x4mulmtx4x4(&mtxBufLoc,&this->mainScene->objects[i].transformations[i],&mtxBufLoc);
			}
		}
		// Jesli sa przeksztalcenia, przeksztalcamy wspolrzedne lokalne
		if(this->mainScene->objects[i].transformations.size() != false)
			this->transformObjectByMatrix(&this->mainScene->objects[i],&mtxBufLoc,LOCAL_ONLY);



		for(unsigned int j = 0 ; j < this->mainScene->objects[i].vertexList.size ; j++)
		{
			/*if(this->mainScene->objects[i].transformations.size() != false)
			{
				arc::vct4d_init(&vn1, this->mainScene->objects[i].vertexList.indexList[j]->local_x,
									   this->mainScene->objects[i].vertexList.indexList[j]->local_y,
									   this->mainScene->objects[i].vertexList.indexList[j]->local_z,
									   1);

				arc::mtx4x4mulvct4d(&mtxBufLoc,&vn1,&vn2);
				
				// Ustawiamy przetransformowane wspolrzedne;
				this->mainScene->objects[i].vertexList.indexList[j]->local_x = vn2.V[0];
				this->mainScene->objects[i].vertexList.indexList[j]->local_y = vn2.V[1];
				this->mainScene->objects[i].vertexList.indexList[j]->local_z = vn2.V[2];
			}*/
			// Ustawiamy buforujemy wspolrzedne lokalne;
			x_buf = this->mainScene->objects[i].vertexList.indexList[j]->local_x;
			y_buf = this->mainScene->objects[i].vertexList.indexList[j]->local_y;
			z_buf = this->mainScene->objects[i].vertexList.indexList[j]->local_z;

			// Ustawiamy wspolrzedne globalne punktu;
			this->mainScene->objects[i].vertexList.indexList[j]->global_x = x_buf + this->mainScene->objects[i].pos_x();
			this->mainScene->objects[i].vertexList.indexList[j]->global_y = y_buf + this->mainScene->objects[i].pos_y();
			this->mainScene->objects[i].vertexList.indexList[j]->global_z = z_buf + this->mainScene->objects[i].pos_z();


			if(this->mainScene->mainCamera->transformations.size() == 0 && this->firstFrameState)
			{	// Jesli to pierwsza klatka i nie bylo zadnych przeksztalcen
				// Inicjujemy macierze widoku tak aby nie modyfikowaly nam pierwotnego widoku;
				arc::mtx4x4_init(&mtxBufCamLast,1,0,0,0,
												0,1,0,0,
												0,0,1,0,
												0,0,0,1);
			}

			// Inicjujemy wektor 4d wspolrzednymi aktualnie transformowanego punktu
			arc::vct4d_init(&vn1, this->mainScene->objects[i].vertexList.indexList[j]->global_x,
								  this->mainScene->objects[i].vertexList.indexList[j]->global_y,
								  this->mainScene->objects[i].vertexList.indexList[j]->global_z,
								  1);

			// Transformujemy punkt zapomoca macierzy przeksztalcen
			arc::mtx4x4mulvct4d(&mtxBufCamLast,&vn1,&vn2);
			
			// Ustawiamy przetransformowane wspolrzedne;
			this->mainScene->objects[i].vertexList.indexList[j]->cam_x = vn2.V[0] + this->mainScene->mainCamera->pos_x;
			this->mainScene->objects[i].vertexList.indexList[j]->cam_y = vn2.V[1] + this->mainScene->mainCamera->pos_y;
			this->mainScene->objects[i].vertexList.indexList[j]->cam_z = vn2.V[2] + this->mainScene->mainCamera->pos_z;

			// Buforujemy wspolrzedne dla przeksztalcenia perspektywy
			x_buf = this->mainScene->objects[i].vertexList.indexList[j]->cam_x;
			y_buf = this->mainScene->objects[i].vertexList.indexList[j]->cam_y;
			z_buf = this->mainScene->objects[i].vertexList.indexList[j]->cam_z;
			
			// Obliczamy wspolczynnik perspektywy
			cam_dist = 1;
			prsv = z_buf / (z_buf + cam_dist);
			
			// Przeksztalcamy wspolrzedne kamery na wspolrzedne perspektywiczne
			this->mainScene->objects[i].vertexList.indexList[j]->scr_x = x_buf * prsv;
			this->mainScene->objects[i].vertexList.indexList[j]->scr_y = y_buf * prsv;
		}

		// Czyscimy liste transformacji lokalnych dla kazdego obiektu osobno;
		this->mainScene->objects[i].transformations.clear();
	}
	

	// Jesli pierwsza klatka zmieniamy stan na nie pierwsza (koniec potoku)
	if(this->firstFrameState)firstFrameState=false;
	// Czyscimy liste transformacji kamery
	this->mainScene->mainCamera->transformations.clear();
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
			arc::vct4d_init(&vn1, obj->vertexList.indexList[i]->local_x,
								  obj->vertexList.indexList[i]->local_y,
								  obj->vertexList.indexList[i]->local_z,
								  1);
			arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);

			obj->vertexList.indexList[i]->local_x = vn2.V[0];
			obj->vertexList.indexList[i]->local_y = vn2.V[1];
			obj->vertexList.indexList[i]->local_z = vn2.V[2];
		}
	break;
	case GLOBAL_ONLY:		// Jesli transformacja na wspolrzednych globalnych
		for(unsigned int i = 0 ; i < obj->vertexList.size ; i++)
		{
			arc::vct4d_init(&vn1, obj->vertexList.indexList[i]->global_x,
								  obj->vertexList.indexList[i]->global_y,
								  obj->vertexList.indexList[i]->global_z,
								  1);
			arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);

			obj->vertexList.indexList[i]->global_x = vn2.V[0];
			obj->vertexList.indexList[i]->global_y = vn2.V[1];
			obj->vertexList.indexList[i]->global_z = vn2.V[2];
		}
	break;
	case LOCAL_TO_GLOBAL:	// Jesli z logalnych do globalnych
		for(unsigned int i = 0 ; i < obj->vertexList.size ; i++)
		{
			arc::vct4d_init(&vn1, obj->vertexList.indexList[i]->local_x,
								  obj->vertexList.indexList[i]->local_y,
								  obj->vertexList.indexList[i]->local_z,
								  1);
			arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);

			obj->vertexList.indexList[i]->global_x = vn2.V[0] + obj->pos_x();
			obj->vertexList.indexList[i]->global_y = vn2.V[1] + obj->pos_y();
			obj->vertexList.indexList[i]->global_z = vn2.V[2] + obj->pos_z();
		}
	break;
	case GLOBAL_TO_CAMERA:	// Jesli z logalnych do globalnych
		for(unsigned int i = 0 ; i < obj->vertexList.size ; i++)
		{
			arc::vct4d_init(&vn1, obj->vertexList.indexList[i]->global_x,
								  obj->vertexList.indexList[i]->global_y,
								  obj->vertexList.indexList[i]->global_z,
								  1);
			arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);

			obj->vertexList.indexList[i]->cam_x = vn2.V[0];
			obj->vertexList.indexList[i]->cam_y = vn2.V[1];
			obj->vertexList.indexList[i]->cam_z = vn2.V[2];
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
				arc::vct4d_init(&vn1, (*obj_list)[i].vertexList.indexList[j]->local_x,
									  (*obj_list)[i].vertexList.indexList[j]->local_y,
									  (*obj_list)[i].vertexList.indexList[j]->local_z,
									  1);
				arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);

				(*obj_list)[i].vertexList.indexList[j]->local_x = vn2.V[0];
				(*obj_list)[i].vertexList.indexList[j]->local_y = vn2.V[1];
				(*obj_list)[i].vertexList.indexList[j]->local_z = vn2.V[2];
			}
	break;
	case GLOBAL_ONLY:
		for(unsigned int i = 0 ; i < obj_list->size() ; i++)
			for(unsigned int j = 0 ; j < (*obj_list)[i].vertexList.size ; j++)
			{
				arc::vct4d_init(&vn1, (*obj_list)[i].vertexList.indexList[j]->global_x,
									  (*obj_list)[i].vertexList.indexList[j]->global_y,
									  (*obj_list)[i].vertexList.indexList[j]->global_z,
									  1);
				arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);

				(*obj_list)[i].vertexList.indexList[j]->global_x = vn2.V[0];
				(*obj_list)[i].vertexList.indexList[j]->global_y = vn2.V[1];
				(*obj_list)[i].vertexList.indexList[j]->global_z = vn2.V[2];
			}
	break;
	case LOCAL_TO_GLOBAL:
		for(unsigned int i = 0 ; i < obj_list->size() ; i++)
			for(unsigned int j = 0 ; j < (*obj_list)[i].vertexList.size ; j++)
			{
				arc::vct4d_init(&vn1, (*obj_list)[i].vertexList.indexList[j]->local_x,
									  (*obj_list)[i].vertexList.indexList[j]->local_y,
									  (*obj_list)[i].vertexList.indexList[j]->local_z,
									  1);
				arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);

				(*obj_list)[i].vertexList.indexList[j]->global_x = vn2.V[0] + (*obj_list)[i].pos_x();
				(*obj_list)[i].vertexList.indexList[j]->global_y = vn2.V[1] + (*obj_list)[i].pos_y();
				(*obj_list)[i].vertexList.indexList[j]->global_z = vn2.V[2] + (*obj_list)[i].pos_z();
			}
	break;
	case GLOBAL_TO_CAMERA:
		for(unsigned int i = 0 ; i < obj_list->size() ; i++)
			for(unsigned int j = 0 ; j < (*obj_list)[i].vertexList.size ; j++)
			{
				arc::vct4d_init(&vn1, (*obj_list)[i].vertexList.indexList[j]->global_x,
									  (*obj_list)[i].vertexList.indexList[j]->global_y,
									  (*obj_list)[i].vertexList.indexList[j]->global_z,
									  1);
				arc::mtx4x4mulvct4d(mtx,&vn1,&vn2);

				(*obj_list)[i].vertexList.indexList[j]->cam_x = vn2.V[0];
				(*obj_list)[i].vertexList.indexList[j]->cam_y = vn2.V[1];
				(*obj_list)[i].vertexList.indexList[j]->cam_z = vn2.V[2];
			}
	break;
	default:
		return;
	}
}