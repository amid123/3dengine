#ifndef TEXT_HPP
#define TEXT_HPP

#include <SDL/SDL.h>
#include <string>
#include <vector>

namespace arc{

	//struct arc::colorRGB;
	struct textColor{
		char R;
		char G;
		char B;
	
	};

	class BMPSTRING{

		struct BMPCHAR
		{
			unsigned short character[8][8];
		};

		static BMPCHAR CharsDB[67];

	public:
		
		BMPSTRING(SDL_Surface *,int,int);
		void PutChar(int x,int y,char);
		void InsertString(int x,int y, std::string);
		void InsertString(int x,int y, int value);
		void SetFontSize(int f_size);
		void SetFontColor(int R, int G, int B);
	protected:

		void putPixel(int x, int y,textColor * color);
		int w,h;
		SDL_Surface *srf;

	private:
		unsigned short CharCounter;
		textColor col;
		void InitCharsData();

	};
}
#endif // TEXT_HPP
