#ifndef TEXT_HPP
#define TEXT_HPP

#include <string>
#include <vector>
#include "camera.hpp"

namespace arc{
	class BMPSTRING{

		struct BMPCHAR
		{
			unsigned short character[8][8];
		};

		static BMPCHAR CharsDB[67];

	public:
		
		BMPSTRING();
		void setCamera(arc::camera*);
		void PutChar(int x,int y,char);
		void InsertString(int x,int y, std::string);
		void InsertString(int x,int y, int value);
		void SetFontSize(int f_size);
		void SetFontColor(int R, int G, int B);

	protected:
		arc::camera *mainCamera;

	private:
		unsigned short CharCounter;
		arc::colRGB col;
		void InitCharsData();

	};
}
#endif // TEXT_HPP
