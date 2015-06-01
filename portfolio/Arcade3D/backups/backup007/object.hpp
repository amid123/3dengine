#ifndef OBJECT
#define OBJECT
#include <vector>
#include "mesh.hpp"
#include "math.hpp"

namespace arc
{

	enum ROTATE_AX{X,Y,Z};

	class transformation : public mesh
	{
	public:
		
		std::vector<MATRIX4X4> transformations;

		void addRotate(ROTATE_AX axis, float theta);
		void addScale(float scalar);
		void addTranslationLocal(float,float,float);
		void addTranslationGlobal(float,float,float);

		transformation(char*);
		virtual ~transformation();
	};


	class object : public transformation
	{
	private:
		int ID;
		int vertexNum;
		int faceNum;
		int edgeNum;
		bool visible;

	public:

		float pos_x();
		float pos_y();
		float pos_z();

		object(char*);
		object(char*,float,float, float);
		void setPosition(float,float,float);
		virtual ~object();

	protected:
	
	
	};
}


#endif // OBJECT