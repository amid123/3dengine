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

		std::vector<MATRIX4X4> transformations;

		camera();
		camera(float,float,float);
		virtual ~camera();

		void addRotate(ROTATE_AX axis, float theta);
		void moveBy(float,float,float);
	};
}

#endif // CAMERA_HPP
