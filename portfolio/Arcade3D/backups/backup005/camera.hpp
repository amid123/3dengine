#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <vector>
#include "math.hpp"
#include "object.hpp"

#define CAMERA_UVN_MODEL		0x01
#define CAMERA_EUL_MODEL		0x02

#define UVN_MODE_SPHERICAL		0x01
#define UVN_MODE_SIMPLE			0x02

#define CAM_ROT_SEQ_XYZ			0x01
#define CAM_ROT_SEQ_YXZ			0x02
#define CAM_ROT_SEQ_ZYX			0x03
#define CAM_ROT_SEQ_ZXY			0x04
#define CAM_ROT_SEQ_YZX			0x05
#define CAM_ROT_SEQ_XZY			0x06

namespace arc
{

	class camera
	{
	
	private:
		int state;
		int attr;

		arc::POINT4D pos;
		arc::VECTOR4D dir;


		arc::VECTOR4D u;
		arc::VECTOR4D v;
		arc::VECTOR4D n;

		arc::VECTOR4D target;

		
		float fov; // Pole widzenia dla osi pionowej oraz poziomej

		float near_clip_z;
		float far_clip_z;


		arc::PLANE3D rt_clip_plane;
		arc::PLANE3D lt_clip_plane;
		arc::PLANE3D tp_clip_plane;
		arc::PLANE3D bt_clip_plane;

		float viewplane_width;
		float viewplane_height;

		float viewport_width;
		float viewport_height;
		float viewport_center_x;
		float viewport_center_y;

		float aspect_ratio;

	public:

		float view_dist;
		arc::MATRIX4X4 mcam;
		arc::MATRIX4X4 mper;
		arc::MATRIX4X4 mscr;

		camera();
		virtual ~camera();

		void buildEulerCameraMtx(int);
		//void buildUVNCameraMtx(int);


		void initCamera(int cam_attr, 
						arc::POINT4D* cam_pos,
						arc::VECTOR4D* cam_dir,
						arc::POINT4D* target,
						float near_clip_z,
						float far_clip_z,
						float fov,
						float viewport_w,
						float viewport_h);
	
	};
}

#endif // CAMERA_HPP
