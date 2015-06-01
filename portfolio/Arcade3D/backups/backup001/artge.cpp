#include <ctime>
#include <cmath>
#include "artge.hpp"
#include "object.hpp"



arc::arc3d::arc3d() : mainScene(0), infoSwitch(0),firstFrameState(true),n(0)
{

}

void arc::arc3d::mainLoop()
{


int delay = 0;

this->mainScene->tx.SetFontColor(255,255,0);



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
					this->mainScene->meshes[n].addRotate(arc::X,-0.1);
				}
				if(event.key.keysym.sym == SDLK_UP)
				{	
					this->mainScene->meshes[n].addRotate(arc::X,0.1);
				}
				if(event.key.keysym.sym == SDLK_RIGHT)
				{
					this->mainScene->meshes[n].addRotate(arc::Y,-0.1);
				}
				if(event.key.keysym.sym == SDLK_LEFT)
				{
					this->mainScene->meshes[n].addRotate(arc::Y,0.1);
				}
				if(event.key.keysym.sym == SDLK_z)
				{
					this->mainScene->meshes[n].addRotate(arc::Z,0.1);
				}
				if(event.key.keysym.sym == SDLK_x)
				{
					this->mainScene->meshes[n].addRotate(arc::Z,-0.1);
				}

				if(event.key.keysym.sym == SDLK_c)
				{
					this->mainScene->meshes[n].addScale(1.1);
				}
				if(event.key.keysym.sym == SDLK_v)
				{
					this->mainScene->meshes[n].addScale(0.9);
				}


				if(event.key.keysym.sym == SDLK_w)
				{
					this->mainScene->mainCamera->addRotate(X,0.1);
				}
				if(event.key.keysym.sym == SDLK_a)
				{
					this->mainScene->mainCamera->addRotate(Y,-0.1);
				}

				if(event.key.keysym.sym == SDLK_d)
				{
					this->mainScene->mainCamera->addRotate(Y,0.1);
				}
				if(event.key.keysym.sym == SDLK_s)
				{
					this->mainScene->mainCamera->addRotate(X,-0.1);
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
					this->mainScene->mainCamera->moveBy(0,0,0.1);
				}
				if(event.key.keysym.sym == SDLK_g)
				{
					this->mainScene->mainCamera->moveBy(0,0,-0.1);
				}

				if(event.key.keysym.sym == SDLK_f)
				{
					this->mainScene->mainCamera->moveBy(0.1,0,0);
				}
				if(event.key.keysym.sym == SDLK_h)
				{
					this->mainScene->mainCamera->moveBy(-0.1,0,0);
				}
				
				if(event.key.keysym.sym == SDLK_n)
				{
					n++;
					if(n == this->mainScene->meshes.size())
						n = 0;
				}

	        }
	    }

		this->render();
	}
}

arc::arc3d::~arc3d()
{

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
		// Wyswietlamy informacje
		this->mainScene->tx.SetFontColor(255,255,255);
		this->mainScene->tx.InsertString(10,10,"Arcade 3D REAL-TIME GRAPHICS ENGINE (ARTGE)");
		this->mainScene->tx.InsertString(10,20,"Made by. Arkadiusz Gibes (ringo99)");
		this->mainScene->tx.InsertString(10,30,"Aby zakonczyc wcisnij ESC");

		// Numer zaznaczonego obiektu
		this->mainScene->tx.InsertString(10,560,"Nr zaznaczonego obiektu ");
		this->mainScene->tx.InsertString(200,560,this->n+1);

		// Wyswietlamy pozycje kursora
		this->mainScene->tx.InsertString(10,580,"PozycjaX ");
		this->mainScene->tx.InsertString(90,580,this->crsPosX);
		this->mainScene->tx.InsertString(10,590,"PozycjaY ");
		this->mainScene->tx.InsertString(90,590,this->crsPosY);


		// Licznik klatek na sekunde
		this->mainScene->tx.InsertString(10,570, "Licznik klatek (FPS) ");
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
		this->mainScene->tx.InsertString(180,570,fps_buf);
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


	arc::VECTOR3D_NORMAL vn1;
	arc::VECTOR3D_NORMAL vn2;

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

	for(unsigned int i = 0 ; i < this->mainScene->meshes.size() ; i++)
	{
		if(this->mainScene->meshes[i].transformations.size() != false)
		{
			mtxBufLoc = this->mainScene->meshes[i].transformations[0];
			for(unsigned int j = 1 ; j < this->mainScene->meshes[i].transformations.size() ; j++)
			{
				arc::mtx4x4mulmtx4x4(&mtxBufLoc,&this->mainScene->meshes[i].transformations[i],&mtxBufLoc);
			}
		}
		for(unsigned int j = 0 ; j < this->mainScene->meshes[i].vertexList.size ; j++)
		{
			if(this->mainScene->meshes[i].transformations.size() != false)
			{
				arc::vct3dn_init(&vn1, this->mainScene->meshes[i].vertexList.indexList[j]->local_x,
									   this->mainScene->meshes[i].vertexList.indexList[j]->local_y,
									   this->mainScene->meshes[i].vertexList.indexList[j]->local_z,
									   1);

				arc::mtx4x4mulvct3dn(&mtxBufLoc,&vn1,&vn2);
				
				// Ustawiamy przetransformowane wspolrzedne;
				this->mainScene->meshes[i].vertexList.indexList[j]->local_x = vn2.V[0];
				this->mainScene->meshes[i].vertexList.indexList[j]->local_y = vn2.V[1];
				this->mainScene->meshes[i].vertexList.indexList[j]->local_z = vn2.V[2];
			}
			// Ustawiamy buforujemy wspolrzedne lokalne;
			x_buf = this->mainScene->meshes[i].vertexList.indexList[j]->local_x;
			y_buf = this->mainScene->meshes[i].vertexList.indexList[j]->local_y;
			z_buf = this->mainScene->meshes[i].vertexList.indexList[j]->local_z;

			// Ustawiamy wspolrzedne globalne punktu;
			this->mainScene->meshes[i].vertexList.indexList[j]->global_x = x_buf + this->mainScene->meshes[i].pos_x();
			this->mainScene->meshes[i].vertexList.indexList[j]->global_y = y_buf + this->mainScene->meshes[i].pos_y();
			this->mainScene->meshes[i].vertexList.indexList[j]->global_z = z_buf + this->mainScene->meshes[i].pos_z();


			if(this->mainScene->mainCamera->transformations.size() == 0 && this->firstFrameState)
			{	// Jesli to pierwsza klatka i nie bylo zadnych przeksztalcen
				// Inicjujemy macierze widoku tak aby nie modyfikowaly nam pierwotnego widoku;
				arc::mtx4x4_init(&mtxBufCamLast,1,0,0,0,
												0,1,0,0,
												0,0,1,0,
												0,0,0,1);
			}

			// Inicjujemy wektor 4d wspolrzednymi aktualnie transformowanego punktu
			arc::vct3dn_init(&vn1, this->mainScene->meshes[i].vertexList.indexList[j]->global_x,
								   this->mainScene->meshes[i].vertexList.indexList[j]->global_y,
								   this->mainScene->meshes[i].vertexList.indexList[j]->global_z,
								   1);

			// Transformujemy punkt zapomoca macierzy przeksztalcen
			arc::mtx4x4mulvct3dn(&mtxBufCamLast,&vn1,&vn2);
			
			// Ustawiamy przetransformowane wspolrzedne;
			this->mainScene->meshes[i].vertexList.indexList[j]->cam_x = vn2.V[0] + this->mainScene->mainCamera->pos_x;
			this->mainScene->meshes[i].vertexList.indexList[j]->cam_y = vn2.V[1] + this->mainScene->mainCamera->pos_y;
			this->mainScene->meshes[i].vertexList.indexList[j]->cam_z = vn2.V[2] + this->mainScene->mainCamera->pos_z;

			x_buf = this->mainScene->meshes[i].vertexList.indexList[j]->cam_x;
			y_buf = this->mainScene->meshes[i].vertexList.indexList[j]->cam_y;
			z_buf = this->mainScene->meshes[i].vertexList.indexList[j]->cam_z;
			
			cam_dist = 8;
			prsv = z_buf / (z_buf + cam_dist);
			
			this->mainScene->meshes[i].vertexList.indexList[j]->scr_x = x_buf * prsv;
			this->mainScene->meshes[i].vertexList.indexList[j]->scr_y = y_buf * prsv;
		}

		// Czyscimy liste transformacji lokalnych dla kazdego obiektu osobno;
		this->mainScene->meshes[i].transformations.clear();
	}
	

	// Jesli pierwsza klatka zmieniamy stan na nie pierwsza (koniec potoku)
	if(this->firstFrameState)firstFrameState=false;
	// Czyscimy liste transformacji kamery
	this->mainScene->mainCamera->transformations.clear();
	// Rysujemy scene
	this->mainScene->mainCamera->drawScene();
}


void arc::arc3d::globalToCamera()
{



}

void arc::arc3d::perspective()
{


}
