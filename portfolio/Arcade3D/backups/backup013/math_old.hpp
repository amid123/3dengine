#ifndef MATH_HPP
#define MATH_HPP

#include <math.h>

#define PI			3,1415926535897932384626433832795
#define PI_DIV2		1,5707963267948966192313216916398

namespace arc
{

	class matrix
	{

	private:

		int sizeX, sizeY;
		float ** M;
		float ** buffer;
		float *rowBuffer;

	public:

		void scalarMul(float);
		void mul(matrix * mtx1, matrix * mtx2 );
		void mul(matrix * mtx1);
		void add(matrix *, matrix *);
		void add(matrix *);
		void sub(matrix *, matrix *);
		void sub(matrix *);
		void trs(matrix *);
	
		matrix(int x, int y);

		void operator=(float [][4]);
		void operator=(float [][3]);
		void operator=(float [][2]);
		void operator=(float [][1]);
	
		float * operator[](int index);
		virtual ~matrix();
	};

	class vector{

	private:
		float * V;
		
	public:
		int size;

		bool operator==(vector*);
		vector & operator*(int);
		vector & operator*(float);
		vector & operator*(double);
		float operator*(vector*);
		vector & operator+(vector*);
		vector & operator-(vector*);
		

		vector(float x, float y);
		vector(float x, float y, float z);
		vector(float x, float y, float z, float w);

		virtual ~vector();

		float lenght();
		void normalize();
		void invert();
		vector & mul(vector*);
	};

}
#endif // MATH_HPP


