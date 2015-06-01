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
		std::vector<MATRIX4X4> T;

		void addRotate(ROTATE_AX axis, float theta);
		void addScale(float scalar);
		void addTranslationLocal(float,float,float);

		transformation(char*);
		virtual ~transformation();
	};

	class object : public transformation
	{
		int objID;
		bool visible;

		// Kula otaczjaca obiekt do sprawdzania czy 
		// obiekt znajduje sie w ostroslupie widzenia
		float max_radius;
		float max_distance;
		void buildObjectSphere();

	public:

		arc::POINT3D* position();
		float pos_x();
		float pos_y();
		float pos_z();

		inline float sphereZeroPointDist()
		{
			return max_distance;
		}
		
		inline float sphereRadius()
		{
			return max_radius;
		}

		inline bool isVisible()
		{
			return visible;
		}

		object(char*);
		object(char*,float,float, float);
		void setPosition(float,float,float);
		virtual ~object();
	};
}


#endif // OBJECT