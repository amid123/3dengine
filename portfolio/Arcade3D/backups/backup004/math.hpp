#ifndef MATH
#define MATH

#include <cmath>

namespace arc
{
	struct CARTESIAN_COORD3D
	{
		float x;
		float y;
		float z;
	};
	struct CARTESIAN_COORD2D
	{
		float x;
		float y;
	};

	// Struktury danych 
	// Struktury macierzy
	struct MATRIX4X4
	{
		float M[4][4];
	};
	struct MATRIX4X3
	{
		float M[4][3];
	};
	struct MATRIX4X2
	{
		float M[4][2];
	};
	struct MATRIX4X1
	{
		float M[4][1];
	};
	struct MATRIX3X3
	{
		float M[3][3];
	};
	struct MATRIX3X2
	{
		float M[3][2];
	};
	struct MATRIX3X1
	{
		float M[3][1];
	};
	struct MATRIX2X2
	{
		float M[2][2];
	};
	struct MATRIX2X1
	{
		float M[2][1];
	};
	// Struktury Vectorow
	typedef struct VECTOR2D
	{
		float V[2];
	}POINT2D;
	typedef struct VECTOR3D
	{
		float V[3];
	}POINT3D;
	typedef struct VECTOR4D
	{
		float V[4];
	}POINT4D;

		/* Funkcje inicjujace macierze i wektory*/

void mtx4x4_init(MATRIX4X4*,float,float,float,float,float,float,float,float,
							float,float,float,float,float,float,float,float);
void mtx4x3_init(MATRIX4X3*,float,float,float,float,float,float,float,float,
							float,float,float,float);
void mtx4x2_init(MATRIX4X2*,float,float,float,float,float,float,float,float);
void mtx4x1_init(MATRIX4X1*,float,float,float,float);
void mtx3x3_init(MATRIX3X3*,float,float,float,float,float,float,float,float,float);
void mtx3x2_init(MATRIX3X2*,float,float,float,float,float,float);
void mtx3x1_init(MATRIX3X1*,float,float,float);
void mtx2x2_init(MATRIX2X2*,float,float,float,float);
void mtx2x1_init(MATRIX2X1*,float,float);
void vct4d_init(VECTOR4D*,float,float,float,float);
void vct3d_init(VECTOR3D*,float,float,float);
void vct2d_init(VECTOR2D*,float,float);

// Operacje dodawania macierzr MxN
void mtx4x4add(MATRIX4X4*,MATRIX4X4*,MATRIX4X4*);
void mtx4x3add(MATRIX4X3*,MATRIX4X3*,MATRIX4X3*);
void mtx4x2add(MATRIX4X2*,MATRIX4X2*,MATRIX4X2*);
void mtx4x1add(MATRIX4X1*,MATRIX4X1*,MATRIX4X1*);
void mtx3x3add(MATRIX3X3*,MATRIX3X3*,MATRIX3X3*);
void mtx3x2add(MATRIX3X2*,MATRIX3X2*,MATRIX3X2*);
void mtx3x1add(MATRIX3X1*,MATRIX3X1*,MATRIX3X1*);
void mtx2x2add(MATRIX2X2*,MATRIX2X2*,MATRIX2X2*);
void mtx2x1add(MATRIX2X1*,MATRIX2X1*,MATRIX2X1*);

void mtx4x4add(MATRIX4X4*,MATRIX4X4*);
void mtx4x3add(MATRIX4X3*,MATRIX4X3*);
void mtx4x2add(MATRIX4X2*,MATRIX4X2*);
void mtx4x1add(MATRIX4X1*,MATRIX4X1*);
void mtx3x3add(MATRIX3X3*,MATRIX3X3*);
void mtx3x2add(MATRIX3X2*,MATRIX3X2*);
void mtx3x1add(MATRIX3X1*,MATRIX3X1*);
void mtx2x2add(MATRIX2X2*,MATRIX2X2*);
void mtx2x1add(MATRIX2X1*,MATRIX2X1*);

// Operacje odejmowania macierzr MxN
void mtx4x4sub(MATRIX4X4*,MATRIX4X4*,MATRIX4X4*);
void mtx4x3sub(MATRIX4X3*,MATRIX4X3*,MATRIX4X3*);
void mtx4x2sub(MATRIX4X2*,MATRIX4X2*,MATRIX4X2*);
void mtx4x1sub(MATRIX4X1*,MATRIX4X1*,MATRIX4X1*);
void mtx3x3sub(MATRIX3X3*,MATRIX3X3*,MATRIX3X3*);
void mtx3x2sub(MATRIX3X2*,MATRIX3X2*,MATRIX3X2*);
void mtx3x1sub(MATRIX3X1*,MATRIX3X1*,MATRIX3X1*);
void mtx2x2sub(MATRIX2X2*,MATRIX2X2*,MATRIX2X2*);
void mtx2x1sub(MATRIX2X1*,MATRIX2X1*,MATRIX2X1*);

void mtx4x4sub(MATRIX4X4*,MATRIX4X4*);
void mtx4x3sub(MATRIX4X3*,MATRIX4X3*);
void mtx4x2sub(MATRIX4X2*,MATRIX4X2*);
void mtx4x1sub(MATRIX4X1*,MATRIX4X1*);
void mtx3x3sub(MATRIX3X3*,MATRIX3X3*);
void mtx3x2sub(MATRIX3X2*,MATRIX3X2*);
void mtx3x1sub(MATRIX3X1*,MATRIX3X1*);
void mtx2x2sub(MATRIX2X2*,MATRIX2X2*);
void mtx2x1sub(MATRIX2X1*,MATRIX2X1*);

// Operacje mnozenia przez skalar MxN;
// Dla scalara typu double
void mtx4x4scalar_mul(MATRIX4X4*,float);
void mtx4x3scalar_mul(MATRIX4X3*,float);
void mtx4x2scalar_mul(MATRIX4X2*,float);
void mtx4x1scalar_mul(MATRIX4X1*,float);
void mtx3x3scalar_mul(MATRIX3X3*,float);
void mtx3x2scalar_mul(MATRIX3X2*,float);
void mtx3x1scalar_mul(MATRIX3X1*,float);
void mtx2x2scalar_mul(MATRIX2X2*,float);
void mtx2x1scalar_mul(MATRIX2X1*,float);

// Operacje mnozenia przez skalar MxN;
// Dla scalara typu double
void mtx4x4scalar_mul(MATRIX4X4*,MATRIX4X4*,float);
void mtx4x3scalar_mul(MATRIX4X3*,MATRIX4X3*,float);
void mtx4x2scalar_mul(MATRIX4X2*,MATRIX4X2*,float);
void mtx4x1scalar_mul(MATRIX4X1*,MATRIX4X1*,float);
void mtx3x3scalar_mul(MATRIX3X3*,MATRIX3X3*,float);
void mtx3x2scalar_mul(MATRIX3X2*,MATRIX3X2*,float);
void mtx3x1scalar_mul(MATRIX3X1*,MATRIX3X1*,float);
void mtx2x2scalar_mul(MATRIX2X2*,MATRIX2X2*,float);
void mtx2x1scalar_mul(MATRIX2X1*,MATRIX2X1*,float);


void mtx4x4mulmtx4x4(MATRIX4X4*,MATRIX4X4*,MATRIX4X4*);
void mtx3x3mulmtx3x3(MATRIX3X3*,MATRIX3X3*,MATRIX3X3*);
void mtx2x2mulmtx2x2(MATRIX2X2*,MATRIX2X2*,MATRIX2X2*);

void mtx4x4mulvct4d(MATRIX4X4*,VECTOR4D*,VECTOR4D*);
void mtx3x3mulvct3d(MATRIX3X3*,VECTOR3D*,VECTOR3D*);

float mtx3x3det(MATRIX3X3*);
float mtx2x2det(MATRIX2X2*);


void buildRotateMatrixAxisX(MATRIX4X4*,float);
void buildRotateMatrixAxisY(MATRIX4X4*,float);
void buildRotateMatrixAxisZ(MATRIX4X4*,float);

float vector2dLenght(VECTOR2D*);
float vector3dLenght(VECTOR3D*);
float vector4dLenght(VECTOR4D*);


void vectro2dScale(VECTOR2D*,float);
void vectro3dScale(VECTOR3D*,float);
void vectro4dScale(VECTOR4D*,float);

void vector2dNormalize(VECTOR2D*);
void vector2dNormalize(VECTOR2D*,VECTOR2D*);

void vector3dNormalize(VECTOR3D*);
void vector3dNormalize(VECTOR3D*,VECTOR3D*);

void vector4dNormalize(VECTOR4D*);
void vector4dNormalize(VECTOR4D*,VECTOR4D*);

void addVector2d(VECTOR2D*,VECTOR2D*);
void addVector2d(VECTOR2D*,VECTOR2D*,VECTOR2D*);

void addVector3d(VECTOR3D*,VECTOR3D*);
void addVector3d(VECTOR3D*,VECTOR3D*,VECTOR3D*);

void addVector4d(VECTOR4D*,VECTOR4D*);
void addVector4d(VECTOR4D*,VECTOR4D*,VECTOR4D*);

void subVector2d(VECTOR2D*,VECTOR2D*);
void subVector2d(VECTOR2D*,VECTOR2D*,VECTOR2D*);

void subVector3d(VECTOR3D*,VECTOR3D*);
void subVector3d(VECTOR3D*,VECTOR3D*,VECTOR3D*);

void subVector4d(VECTOR4D*,VECTOR4D*);
void subVector4d(VECTOR4D*,VECTOR4D*,VECTOR4D*);


}

#endif // MATH