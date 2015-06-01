#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <vector>
#include "math.hpp"
#include "object.hpp"
namespace arc
{

	class camera
	{
	public:

		float pos_x;
		float pos_y;
		float pos_z;

		int state;
		int attr;

		arc::POINT4D pos;
		arc::VECTOR4D dir;


		arc::VECTOR4D u;
		arc::VECTOR4D v;
		arc::VECTOR4D n;

		arc::VECTOR4D target;

		float view_dist;
		float fov; // Pole widzenia dla osi pionowej oraz poziomej

		float near_clip_z;
		float far_clip_z;



		std::vector<MATRIX4X4> transformations;

		camera();
		camera(float,float,float);
		virtual ~camera();

		void addRotate(ROTATE_AX axis, float theta);
		void moveBy(float,float,float);
	
	};
}

#endif // CAMERA_HPP
