#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "object.hpp"
#include "camera.hpp"


namespace arc
{
	class scene{

	public:
		arc::camera *mainCamera;
		std::vector<arc::object> objects;	// Lista siatek na scenie
		void addObject(arc::object*);
		void setCamera(arc::camera*);
		
		scene();
		virtual ~scene();

	protected:
	
	};
}

#endif //SCENE_HPP

