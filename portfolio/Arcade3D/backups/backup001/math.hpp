#ifndef MATH
#define MATH

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
	struct VECTOR2D
	{
		float V[2];
	};
	struct VECTOR2D_NORMAL
	{
		float V[3];
	};
	struct VECTOR3D
	{
		float V[3];
	};
	struct VECTOR3D_NORMAL
	{
		float V[4];
	};

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
void vct3dn_init(VECTOR3D_NORMAL*,float,float,float,float);
void vct2dn_init(VECTOR2D_NORMAL*,float,float,float);
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

void mtx4x4mulvct3dn(MATRIX4X4*,VECTOR3D_NORMAL*,VECTOR3D_NORMAL*);
void mtx3x3mulvct3d(MATRIX3X3*,VECTOR3D*,VECTOR3D*);

float mtx3x3det(MATRIX3X3*);
float mtx2x2det(MATRIX2X2*);


/*
void mtx4x4mulmtx3x4(MATRIX4X4*,MATRIX3X4*);
void mtx4x4mulmtx2x4(MATRIX4X4*,MATRIX2X4*);
void mtx4x4mulmtx1x4(MATRIX4X4*,MATRIX1X4*);

void mtx4x3mulmtx3x4(MATRIX4X4*,MATRIX3X4*);
void mtx4x3mulmtx2x4(MATRIX4X4*,MATRIX2X4*);
void mtx4x3mulmtx1x4(MATRIX4X4*,MATRIX1X4*);
*/
}

#endif // MATH