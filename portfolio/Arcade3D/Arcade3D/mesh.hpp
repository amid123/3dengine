#ifndef MESH_HPP
#define MESH_HPP

#include <string>
#include <fstream>
#include "math.hpp"

namespace arc
{
	typedef class vertex3d
	{
	private:

		arc::vertex3d * buf;
		arc::vertex3d * first;
		arc::vertex3d * next;
		arc::vertex3d * last;

	public:

		arc::POINT4D cam;
		arc::POINT4D local;
		arc::POINT4D global;
		arc::POINT2D scr;

		int vertexNum;

		arc::vertex3d * retElement(int num);
		vertex3d();
		vertex3d(float, float, float, vertex3d* l= 0, vertex3d* f= 0);

		unsigned int size;
		
		void reIndex();
		virtual ~vertex3d();
		
		inline void addNew(float x,float y,float z)
		{
			buf = first;

			while(buf->next != 0)
				buf = buf->next;

			buf->next = new vertex3d(x,y,z,this,first);
			
			if(this == first) 
				this->vertexNum = 0;

			buf->next->vertexNum = buf->vertexNum + 1;
			buf->next->first = this->first;

			if(this != first)
				buf->next->last = this;
			if(buf->next != first)
				size++;
		}

		inline void addVertex3d(vertex3d* v1)
		{
			buf = first;

			while(buf->next != 0)
				buf = buf->next;

			if(buf->next == 0)
				buf->next = v1;

			if(buf->next != first->next) /// Sprawdzic ta funkcje
				size++;
		}
		vertex3d **indexList;

	}vert3d ;

	typedef class edge
	{

	private:
		arc::edge * buf;
		arc::edge * first;
		arc::edge * next;
		arc::edge * last;
	public:

		int edgeNum;

		unsigned int size;

		arc::edge * retElement(int);
		edge();
		edge(vertex3d*,vertex3d*,edge *edl = 0,edge *edf = 0);
		virtual ~edge();

		void reIndex();
		inline void addNew(vert3d *vert1,vert3d *vert2)
		{
			buf = first;

			while(buf->next != 0)
				buf = buf->next;

			buf->next = new edge(vert1,vert2,this,first);
			
			if(this == first) 
				this->edgeNum = 0;

			buf->next->edgeNum = buf->edgeNum + 1;
			buf->next->first = this->first;

			if(this != first)
				buf->last = this;
			if(buf->next != first)
				size++;
		}
		vert3d *v1;
		vert3d *v2;
		edge **indexList;
	}eg,*eg_ptr;


	typedef class face
	{
	private:
		arc::face *buf;
		arc::face *first;
		arc::face *next;
		arc::face *last;
		arc::face *nextVisible;

		bool visible;

	public:

		face();
		face(vert3d*,vert3d*,vert3d*,face*,face*);
		virtual ~face();

		arc::face * retElement(int);

		unsigned int size;
		void reIndex();


		inline void setVisible()
		{
			visible = true;
		}
		
		inline void setInVisible()
		{
			visible = false;
		}

		inline bool isVisible()
		{
			return visible;
		}

		inline void addNew(vert3d *vert1, vert3d *vert2, vert3d *vert3)
		{
			
		buf = first;

			while(buf->next != 0)
				buf = buf->next;

			buf->next = new face(vert1,vert2,vert3,this,first);
			
			if(this == first) 
				this->faceNum = 0;

			buf->next->faceNum = buf->faceNum + 1;
			buf->next->first = this->first;

			if(this != first)
				buf->last = this;
			if(buf->next != first)
				size++;
		}

		int faceNum;
		vert3d *v1;
		vert3d *v2;
		vert3d *v3;
		arc::PLANE3D planeOfTriangle;		// Plaszczyzna trojkata

		face **indexList;
	}fc,*fc_ptr;

	class mesh
	{
	public:
		vert3d vertexList;
		edge edgeList;
		face faceList;

	protected:
		
		arc::POINT3D worldPos;

	private:
		float x, y, z;
		int i,j,k,l,m,t;
		std::ifstream * file;
		std::string linia,temp;

	public:

		mesh();
		mesh(char *filename);
		virtual ~mesh();

		void loadMesh(char *filename);

	protected:
	
	};
}
#endif