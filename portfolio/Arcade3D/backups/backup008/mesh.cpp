#include "mesh.hpp"

#include <iostream>


arc::vertex3d::vertex3d() : next(0),
							buf(0),
							first(0),
							last(0),
							vertexNum(0),
							size(0)
{
	if(last==0)
		vertexNum = 0;
	else if(last != 0)
		this->vertexNum = last->vertexNum;
	
	if(last == 0)
	{
		first = this;
	}
}

arc::vertex3d::vertex3d(float x,
						float y,
						float z, 
						vertex3d *v1, 
						vertex3d *v2) : last(v1),
										next(0),
										buf(0),
										first(v2),
										vertexNum(0)
{
    local.x = x;
	local.y = y;
	local.z = z;




	//this->buf = first;
}

arc::vertex3d::~vertex3d()
{

}

arc::vertex3d * arc::vertex3d::retElement(int num)
{
	buf = first; /// bez next
		
		for(int i = 0 ; (i <= num) && (buf->next != 0) ; i++)
		{
				buf = buf->next;
		}
return buf;
}

void arc::vertex3d::reIndex()
{
	this->indexList = new vertex3d* [size+1] ;

	buf = first;
	for(unsigned int i = 0 ; (i < size) /*&& (buf->next->next != 0)*/ ; i++)
	{
		
		buf = buf->next;
		indexList[i] = buf;

		if(buf->next == 0)break;
	}
}


arc::edge * arc::edge::retElement(int num)
{
		buf = first;
		
		for(int i = 0 ; (i <= num) && (buf->next != 0) ; i++)
		{
				buf = buf->next;
		}
return buf;
}


arc::edge::edge() :	v1(0), v2(0), next(0), buf(0), first(0), last(0), edgeNum(0), size(0)
{
	if(last==0)
		edgeNum = 0;
	else if(last != 0)
		this->edgeNum = last->edgeNum;
	
	if(last == 0)
	{
		first = this;
	}
}

arc::edge::edge(vertex3d *vert1,vertex3d *vert2,edge *edl,edge *edf):	
				v1(vert1), v2(vert2), last(edl),next(0),buf(0),first(edf),edgeNum(0)
{

}


arc::edge::~edge()
{

}

void arc::edge::reIndex()
{
	this->indexList = new edge* [size+1] ;

	buf = first;
	for(unsigned int i = 0 ; (i < size) && (buf->next != 0) ; i++)
	{
		indexList[i] = buf->next;
		buf = buf->next;
	}
}

arc::face::face() :	v1(0), v2(0), v3(0), next(0), buf(0), first(0), last(0), faceNum(0), size(0)
{
	if(last==0)
		faceNum = 0;
	else if(last != 0)
		this->faceNum = last->faceNum;
	
	if(last == 0)
	{
		first = this;
	}
}

arc::face::face(vert3d *vert1, vert3d *vert2,vert3d *vert3, face *fcl, face *fcf): v1(vert1), v2(vert2), v3(vert3), last(fcl),next(0),buf(0),first(fcf),faceNum(0)
{

}


arc::face::~face()
{

}

arc::face * arc::face::retElement(int num)
{
		buf = first;
		
		for(int i = 0 ; (i <= num) && (buf->next != 0) ; i++)
		{
				buf = buf->next;
		}
return buf;
}

void arc::face::reIndex()
{
	this->indexList = new face* [size+1] ;

	buf = first;
	for(unsigned int i = 0 ; (i < size) && (buf->next != 0) ; i++)
	{
		indexList[i] = buf->next;
		buf = buf->next;
	}
}

arc::mesh::mesh() : x(0),y(0),z(0)
{

}

arc::mesh::mesh(char * filename) : x(0),y(0),z(0)
{
	file = new std::ifstream;
	file->open(filename);

	//// sprawdzamy ile linijek zaczyna sie od potrzebnych nam naglowkow
	///// teraz nastepuje wlasciwe wczytywanie pliku *.obj
	
if(file->is_open())
	while (!file->eof())
	{
		//std::cout << "laduje plik"; 
		*file >> linia;
		if (linia=="#") continue;
		else if (linia=="v")
		{
			*file >> x >> y >> z;
			i++;
			this->vertexList.addNew(x,y,z);
		}
		//else if (linia=="vn")
		//{
			//plik >> x >> y >> z;
			//j++;
			//this->vertexList.addNew(x,y,z);
		//}
		else if (linia=="f")
		{
			*file >> x >> y >> z;
			//j++;
			this->faceList.addNew(vertexList.retElement( (int)x-1) ,
								  vertexList.retElement( (int)y-1) ,
								  vertexList.retElement( (int)z-1) );
		}
	}
	/////------------------------------------------------------------
	file->close();
	
	delete file;
	linia.clear();

	this->vertexList.reIndex();		// przeindeksowujemy listy
	//this->edgeList.reIndex();
	this->faceList.reIndex();
}


arc::mesh::~mesh()
{

}


void arc::mesh::loadMesh(char *filename)
{
	std::cout << "laduje siatke" << std::endl;
	
	file = new std::ifstream;
	file->open(filename);

	//// sprawdzamy ile linijek zaczyna sie od potrzebnych nam naglowkow
	///// teraz nastepuje wlasciwe wczytywanie pliku *.obj
	
if(file->is_open())
	while (!file->eof())
	{
		//std::cout << "laduje plik"; 
		*file >> linia;
		if (linia=="#") continue;
		else if (linia=="v")
		{
			*file >> x >> y >> z;
			i++;
			this->vertexList.addNew(x,y,z);
		}
		//else if (linia=="vn")
		//{
			//plik >> x >> y >> z;
			//j++;
			//this->vertexList.addNew(x,y,z);
		//}
		else if (linia=="f")
		{
			*file >> x >> y >> z;
			//j++;
			this->faceList.addNew(vertexList.retElement( (int)x-1) ,
								  vertexList.retElement( (int)y-1) ,
								  vertexList.retElement( (int)z-1) );
		}
	}
	/////------------------------------------------------------------
	file->close();
	
	delete file;
	linia.clear();

	this->vertexList.reIndex();		// przeindeksowujemy listy
	//this->edgeList.reIndex();
	this->faceList.reIndex();
}