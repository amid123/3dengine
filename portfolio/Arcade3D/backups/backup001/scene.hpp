#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "object.hpp"
#include "camera.hpp"
#include "text.hpp"

namespace arc
{
	class scene{

	public:
		arc::camera *mainCamera;
		std::vector<arc::object> meshes;	// Lista siatek na scenie
		void addMesh(arc::object*);
		void setCamera(arc::camera*);

		arc::BMPSTRING tx;
		scene();
		virtual ~scene();

	protected:
	
	};
}

#endif //SCENE_HPP

