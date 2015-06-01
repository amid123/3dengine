#include "math.hpp"


void arc::mtx4x4_init(MATRIX4X4* m1,float M00,float M01,float M02,float M03,
									float M10,float M11,float M12,float M13,
									float M20,float M21,float M22,float M23,
									float M30,float M31,float M32,float M33)
{
	m1->M[0][0] = M00;
	m1->M[0][1] = M01;
	m1->M[0][2] = M02;
	m1->M[0][3] = M03;
	m1->M[1][0] = M10;
	m1->M[1][1] = M11;
	m1->M[1][2] = M12;
	m1->M[1][3] = M13;
	m1->M[2][0] = M20;
	m1->M[2][1] = M21;
	m1->M[2][2] = M22;
	m1->M[2][3] = M23;
	m1->M[3][0] = M30;
	m1->M[3][1] = M31;
	m1->M[3][2] = M32;
	m1->M[3][3] = M33;
}

void arc::mtx4x3_init(MATRIX4X3* m1,float M00,float M01,float M02,
									float M10,float M11,float M12,
									float M20,float M21,float M22,
									float M30,float M31,float M32)
{
	m1->M[0][0] = M00;
	m1->M[0][1] = M01;
	m1->M[0][2] = M02;
	m1->M[1][0] = M10;
	m1->M[1][1] = M11;
	m1->M[1][2] = M12;
	m1->M[2][0] = M20;
	m1->M[2][1] = M21;
	m1->M[2][2] = M22;
	m1->M[3][0] = M30;
	m1->M[3][1] = M31;
	m1->M[3][2] = M32;
}

void arc::mtx4x2_init(MATRIX4X2* m1,float M00,float M01,
									float M10,float M11,
									float M20,float M21,
									float M30,float M31)
{
	m1->M[0][0] = M00;
	m1->M[0][1] = M01;
	m1->M[1][0] = M10;
	m1->M[1][1] = M11;
	m1->M[2][0] = M20;
	m1->M[2][1] = M21;
	m1->M[3][0] = M30;
	m1->M[3][1] = M31;
}

void arc::mtx4x1_init(MATRIX4X1* m1,float M00,
									float M10,
									float M20,
									float M30)
{
	m1->M[0][0] = M00;
	m1->M[1][0] = M10;
	m1->M[2][0] = M20;
	m1->M[3][0] = M30;
}
void arc::mtx3x3_init(MATRIX3X3* m1,float M00,float M01,float M02,
									float M10,float M11,float M12,
									float M20,float M21,float M22)
{
	m1->M[0][0] = M00;
	m1->M[0][1] = M01;
	m1->M[0][2] = M02;
	m1->M[1][0] = M10;
	m1->M[1][1] = M11;
	m1->M[1][2] = M12;
	m1->M[2][0] = M20;
	m1->M[2][1] = M21;
	m1->M[2][2] = M22;
}


void arc::mtx3x2_init(MATRIX3X2* m1,float M00,float M01,float M02,
									float M10,float M11,float M12)
{
	m1->M[0][0] = M00;
	m1->M[0][1] = M01;
	m1->M[0][2] = M02;
	m1->M[1][0] = M10;
	m1->M[1][1] = M11;
	m1->M[1][2] = M12;
}
void arc::mtx3x1_init(MATRIX3X1* m1,float M00,float M01,float M02)						
{
	m1->M[0][0] = M00;
	m1->M[0][1] = M01;
	m1->M[0][2] = M02;
}

void arc::mtx2x2_init(MATRIX2X2* m1,float M00,float M01,
									float M10,float M11)									
{
	m1->M[0][0] = M00;
	m1->M[0][1] = M01;
	m1->M[1][0] = M10;
	m1->M[1][1] = M11;
}
void arc::mtx2x1_init(MATRIX2X1* m1,float M00,float M01)
{
	m1->M[0][0] = M00;
	m1->M[0][1] = M01;
}

void arc::vct4d_init(VECTOR4D* v1, float x, float y, float z, float w)
{
	v1->V[0] = x;
	v1->V[1] = y;
	v1->V[2] = z;
	v1->V[3] = w;
}
void arc::vct3d_init(VECTOR3D* v1, float x, float y, float z)
{
	v1->V[0] = x;
	v1->V[1] = y;
	v1->V[2] = z;
}

void arc::vct2d_init(VECTOR2D* v1, float x, float y)
{
	v1->V[0] = x;
	v1->V[1] = y;
}
/**********************/
/* Dodawanie macierzy */
/**********************/
void arc::mtx4x4add(MATRIX4X4* m1,MATRIX4X4* m2,MATRIX4X4* m_dest)
{
	unsigned int m = 4;
	unsigned int n = 4;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m_dest->M[i][j] = m1->M[i][j] + m2->M[i][j];
}

void arc::mtx4x3add(MATRIX4X3* m1,MATRIX4X3* m2,MATRIX4X3* m_dest)
{
	unsigned int m = 4;
	unsigned int n = 3;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m_dest->M[i][j] = m1->M[i][j] + m2->M[i][j];
}
void arc::mtx4x2add(MATRIX4X2* m1,MATRIX4X2* m2,MATRIX4X2* m_dest)
{
	unsigned int m = 4;
	unsigned int n = 2;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m_dest->M[i][j] = m1->M[i][j] + m2->M[i][j];
}
void arc::mtx4x1add(MATRIX4X1* m1,MATRIX4X1* m2,MATRIX4X1* m_dest)
{
	unsigned int m = 4;
	unsigned int n = 1;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m_dest->M[i][j] = m1->M[i][j] + m2->M[i][j];
}

void arc::mtx3x3add(MATRIX3X3* m1,MATRIX3X3* m2,MATRIX3X3* m_dest)
{
	unsigned int m = 3;
	unsigned int n = 3;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m_dest->M[i][j] = m1->M[i][j] + m2->M[i][j];
}

void arc::mtx3x2add(MATRIX3X2* m1,MATRIX3X2* m2,MATRIX3X2* m_dest)
{
	unsigned int m = 3;
	unsigned int n = 2;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m_dest->M[i][j] = m1->M[i][j] + m2->M[i][j];
}

void arc::mtx3x1add(MATRIX3X1* m1,MATRIX3X1* m2,MATRIX3X1* m_dest)
{
	unsigned int m = 3;
	unsigned int n = 1;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m_dest->M[i][j] = m1->M[i][j] + m2->M[i][j];
}

void arc::mtx2x2add(MATRIX2X2* m1,MATRIX2X2* m2,MATRIX2X2* m_dest)
{
	unsigned int m = 2;
	unsigned int n = 2;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m_dest->M[i][j] = m1->M[i][j] + m2->M[i][j];
}

void arc::mtx2x1add(MATRIX2X1* m1,MATRIX2X1* m2,MATRIX2X1* m_dest)
{
	unsigned int m = 2;
	unsigned int n = 1;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m_dest->M[i][j] = m1->M[i][j] + m2->M[i][j];
}

/**********************/
/* Dodawanie macierzy */
/**********************/
void arc::mtx4x4add(MATRIX4X4* m1,MATRIX4X4* m2)
{
	unsigned int m = 4;
	unsigned int n = 4;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] + m2->M[i][j];
}

void arc::mtx4x3add(MATRIX4X3* m1,MATRIX4X3* m2)
{
	unsigned int m = 4;
	unsigned int n = 3;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] + m2->M[i][j];
}
void arc::mtx4x2add(MATRIX4X2* m1,MATRIX4X2* m2)
{
	unsigned int m = 4;
	unsigned int n = 2;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] + m2->M[i][j];
}
void arc::mtx4x1add(MATRIX4X1* m1,MATRIX4X1* m2)
{
	unsigned int m = 4;
	unsigned int n = 1;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] + m2->M[i][j];
}

void arc::mtx3x3add(MATRIX3X3* m1,MATRIX3X3* m2)
{
	unsigned int m = 3;
	unsigned int n = 3;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] + m2->M[i][j];
}

void arc::mtx3x2add(MATRIX3X2* m1,MATRIX3X2* m2)
{
	unsigned int m = 3;
	unsigned int n = 2;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] + m2->M[i][j];
}

void arc::mtx3x1add(MATRIX3X1* m1,MATRIX3X1* m2)
{
	unsigned int m = 3;
	unsigned int n = 1;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] + m2->M[i][j];
}

void arc::mtx2x2add(MATRIX2X2* m1,MATRIX2X2* m2)
{
	unsigned int m = 2;
	unsigned int n = 2;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] + m2->M[i][j];
}

void arc::mtx2x1add(MATRIX2X1* m1,MATRIX2X1* m2)
{
	unsigned int m = 2;
	unsigned int n = 1;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] + m2->M[i][j];
}


/************************/
/* Odejmowanie macierzy */
/************************/


void arc::mtx4x4sub(MATRIX4X4* m1,MATRIX4X4* m2,MATRIX4X4* m_dest)
{
	unsigned int m = 4;
	unsigned int n = 4;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m_dest->M[i][j] = m1->M[i][j] - m2->M[i][j];
}

void arc::mtx4x3sub(MATRIX4X3* m1,MATRIX4X3* m2,MATRIX4X3* m_dest)
{
	unsigned int m = 4;
	unsigned int n = 3;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m_dest->M[i][j] = m1->M[i][j] - m2->M[i][j];
}
void arc::mtx4x2sub(MATRIX4X2* m1,MATRIX4X2* m2,MATRIX4X2* m_dest)
{
	unsigned int m = 4;
	unsigned int n = 2;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m_dest->M[i][j] = m1->M[i][j] - m2->M[i][j];
}
void arc::mtx4x1sub(MATRIX4X1* m1,MATRIX4X1* m2,MATRIX4X1* m_dest)
{
	unsigned int m = 4;
	unsigned int n = 1;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m_dest->M[i][j] = m1->M[i][j] - m2->M[i][j];
}

void arc::mtx3x3sub(MATRIX3X3* m1,MATRIX3X3* m2,MATRIX3X3* m_dest)
{
	unsigned int m = 3;
	unsigned int n = 3;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m_dest->M[i][j] = m1->M[i][j] - m2->M[i][j];
}

void arc::mtx3x2sub(MATRIX3X2* m1,MATRIX3X2* m2,MATRIX3X2* m_dest)
{
	unsigned int m = 3;
	unsigned int n = 2;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m_dest->M[i][j] = m1->M[i][j] - m2->M[i][j];
}

void arc::mtx3x1sub(MATRIX3X1* m1,MATRIX3X1* m2,MATRIX3X1* m_dest)
{
	unsigned int m = 3;
	unsigned int n = 1;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m_dest->M[i][j] = m1->M[i][j] - m2->M[i][j];
}

void arc::mtx2x2sub(MATRIX2X2* m1,MATRIX2X2* m2,MATRIX2X2* m_dest)
{
	unsigned int m = 2;
	unsigned int n = 2;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m_dest->M[i][j] = m1->M[i][j] - m2->M[i][j];
}

void arc::mtx2x1sub(MATRIX2X1* m1,MATRIX2X1* m2,MATRIX2X1* m_dest)
{
	unsigned int m = 2;
	unsigned int n = 1;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m_dest->M[i][j] = m1->M[i][j] - m2->M[i][j];
}


void arc::mtx4x4sub(MATRIX4X4* m1,MATRIX4X4* m2)
{
	unsigned int m = 4;
	unsigned int n = 4;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] - m2->M[i][j];
}

void arc::mtx4x3sub(MATRIX4X3* m1,MATRIX4X3* m2)
{
	unsigned int m = 4;
	unsigned int n = 3;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] - m2->M[i][j];
}
void arc::mtx4x2sub(MATRIX4X2* m1,MATRIX4X2* m2)
{
	unsigned int m = 4;
	unsigned int n = 2;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] - m2->M[i][j];
}
void arc::mtx4x1sub(MATRIX4X1* m1,MATRIX4X1* m2)
{
	unsigned int m = 4;
	unsigned int n = 1;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] - m2->M[i][j];
}

void arc::mtx3x3sub(MATRIX3X3* m1,MATRIX3X3* m2)
{
	unsigned int m = 3;
	unsigned int n = 3;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] - m2->M[i][j];
}

void arc::mtx3x2sub(MATRIX3X2* m1,MATRIX3X2* m2)
{
	unsigned int m = 3;
	unsigned int n = 2;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] - m2->M[i][j];
}

void arc::mtx3x1sub(MATRIX3X1* m1,MATRIX3X1* m2)
{
	unsigned int m = 3;
	unsigned int n = 1;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] - m2->M[i][j];
}

void arc::mtx2x2sub(MATRIX2X2* m1,MATRIX2X2* m2)
{
	unsigned int m = 2;
	unsigned int n = 2;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] - m2->M[i][j];
}

void arc::mtx2x1sub(MATRIX2X1* m1,MATRIX2X1* m2)
{
	unsigned int m = 2;
	unsigned int n = 1;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] - m2->M[i][j];
}

//
// Mnozenie macierzy przez skalar
//
void arc::mtx4x4scalar_mul(MATRIX4X4* m1, float scalar)
{
	unsigned int m = 4;
	unsigned int n = 4;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] * scalar;
}

void arc::mtx4x3scalar_mul(MATRIX4X3* m1, float scalar)
{
	unsigned int m = 4;
	unsigned int n = 3;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] * scalar;
}

void arc::mtx4x2scalar_mul(MATRIX4X2* m1, float scalar)
{
	unsigned int m = 4;
	unsigned int n = 2;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] * scalar;
}

void arc::mtx4x1scalar_mul(MATRIX4X1* m1, float scalar)
{
	unsigned int m = 4;
	unsigned int n = 1;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] * scalar;
}

void arc::mtx3x3scalar_mul(MATRIX3X3* m1, float scalar)
{
	unsigned int m = 3;
	unsigned int n = 3;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] * scalar;
}

void arc::mtx3x2scalar_mul(MATRIX3X2* m1, float scalar)
{
	unsigned int m = 3;
	unsigned int n = 2;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] * scalar;
}

void arc::mtx3x1scalar_mul(MATRIX3X1* m1, float scalar)
{
	unsigned int m = 3;
	unsigned int n = 1;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] * scalar;
}

void arc::mtx2x2scalar_mul(MATRIX2X2* m1, float scalar)
{
	unsigned int m = 2;
	unsigned int n = 2;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] * scalar;
}

void arc::mtx2x1scalar_mul(MATRIX2X1* m1, float scalar)
{
	unsigned int m = 2;
	unsigned int n = 1;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			m1->M[i][j] = m1->M[i][j] * scalar;
}

void arc::mtx4x4scalar_mul(MATRIX4X4* m1, MATRIX4X4* dest, float scalar)
{
	unsigned int m = 4;
	unsigned int n = 4;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			dest->M[i][j] = m1->M[i][j] * scalar;
}

void arc::mtx4x3scalar_mul(MATRIX4X3* m1, MATRIX4X3* dest, float scalar)
{
	unsigned int m = 4;
	unsigned int n = 3;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			dest->M[i][j] = m1->M[i][j] * scalar;
}

void arc::mtx4x2scalar_mul(MATRIX4X2* m1, MATRIX4X2* dest, float scalar)
{
	unsigned int m = 4;
	unsigned int n = 2;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			dest->M[i][j] = m1->M[i][j] * scalar;
}

void arc::mtx4x1scalar_mul(MATRIX4X1* m1, MATRIX4X1* dest, float scalar)
{
	unsigned int m = 4;
	unsigned int n = 1;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			dest->M[i][j] = m1->M[i][j] * scalar;
}

void arc::mtx3x3scalar_mul(MATRIX3X3* m1, MATRIX3X3* dest, float scalar)
{
	unsigned int m = 3;
	unsigned int n = 3;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			dest->M[i][j] = m1->M[i][j] * scalar;
}

void arc::mtx3x2scalar_mul(MATRIX3X2* m1, MATRIX3X2* dest, float scalar)
{
	unsigned int m = 3;
	unsigned int n = 2;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			dest->M[i][j] = m1->M[i][j] * scalar;
}

void arc::mtx3x1scalar_mul(MATRIX3X1* m1, MATRIX3X1* dest, float scalar)
{
	unsigned int m = 3;
	unsigned int n = 1;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			dest->M[i][j] = m1->M[i][j] * scalar;
}

void arc::mtx2x2scalar_mul(MATRIX2X2* m1, MATRIX2X2* dest, float scalar)
{
	unsigned int m = 2;
	unsigned int n = 2;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			dest->M[i][j] = m1->M[i][j] * scalar;
}

void arc::mtx2x1scalar_mul(MATRIX2X1* m1, MATRIX2X1* dest, float scalar)
{
	unsigned int m = 2;
	unsigned int n = 1;
	for(unsigned int i = 0 ; i < m ; i++)
		for(unsigned int j = 0 ; j < n ; j++)
			dest->M[i][j] = m1->M[i][j] * scalar;
}

void arc::mtx4x4mulmtx4x4(MATRIX4X4 * mt1, MATRIX4X4 * mt2, MATRIX4X4 * dest)
{
	unsigned int m = 4;
	unsigned int n = 4;
	arc::MATRIX4X4 m1 = *mt1;
	arc::MATRIX4X4 m2 = *mt2;


	for (unsigned int i = 0; i < m; i++)
	{
		for (unsigned int j = 0; j < n; j++)
		{
			dest->M[i][j] = 0;
	        for (unsigned int k = 0; k < n; k++)
				dest->M[i][j] += m2.M[i][k] * m1.M[k][j];
		}
	}
}

void arc::mtx3x3mulmtx3x3(MATRIX3X3 * mt1, MATRIX3X3 * mt2, MATRIX3X3 * dest)
{
	unsigned int m = 3;
	unsigned int n = 3;
	arc::MATRIX3X3 m1 = *mt1;
	arc::MATRIX3X3 m2 = *mt2;


	for (unsigned int i = 0; i < m; i++)
	{
		for (unsigned int j = 0; j < n; j++)
		{
			dest->M[i][j] = 0;
	        for (unsigned int k = 0; k < n; k++)
				dest->M[i][j] += m2.M[i][k] * m1.M[k][j];
		}
	}
}

void arc::mtx2x2mulmtx2x2(MATRIX2X2 * mt1, MATRIX2X2 * mt2, MATRIX2X2 * dest)
{
	unsigned int m = 2;
	unsigned int n = 2;
	arc::MATRIX2X2 m1 = *mt1;
	arc::MATRIX2X2 m2 = *mt2;


	for (unsigned int i = 0; i < m; i++)
	{
		for (unsigned int j = 0; j < n; j++)
		{
			dest->M[i][j] = 0;
	        for (unsigned int k = 0; k < n; k++)
				dest->M[i][j] += m2.M[i][k] * m1.M[k][j];
		}
	}
}

void arc::mtx4x4mulvct4d(MATRIX4X4* m1,VECTOR4D* v1,VECTOR4D* dest)
{
	unsigned int m = 1;
	unsigned int n = 4;

	for (unsigned int i = 0; i < m; i++)
	{
		for (unsigned int j = 0; j < n; j++)
		{
			dest->V[j] = 0;
	        for (unsigned int k = 0; k < n; k++)
				dest->V[j] += m1->M[j][k] * v1->V[k];
		}
	}
}

void arc::mtx3x3mulvct3d(MATRIX3X3* m1,VECTOR3D* v1,VECTOR3D* dest)
{
	unsigned int m = 1;
	unsigned int n = 3;

	for (unsigned int i = 0; i < m; i++)
	{
		for (unsigned int j = 0; j < n; j++)
		{
			dest->V[j] = 0;
	        for (unsigned int k = 0; k < n; k++)
				dest->V[j] += m1->M[j][k] * v1->V[k];
		}
	}
}

float arc::mtx3x3det(MATRIX3X3* m1)
{
	float a,b,c,d,e,f;
	
	a = (m1->M[0][0]) * (m1->M[1][1]) * (m1->M[2][2]);
	b = (m1->M[0][1]) * (m1->M[1][2]) * (m1->M[2][0]);
	c = (m1->M[0][2]) * (m1->M[1][0]) * (m1->M[2][1]);
	d = (m1->M[0][2]) * (m1->M[1][1]) * (m1->M[2][1]);
	e = (m1->M[1][0]) * (m1->M[0][1]) * (m1->M[2][2]);
	f = (m1->M[0][0]) * (m1->M[1][2]) * (m1->M[2][1]);

	return (a + b + c - d - e - f);
}

float arc::mtx2x2det(MATRIX2X2* m1) // Sprawdzic wyznacznik;
{
	float a,b,c,d;

	a = m1->M[0][0];
	b = m1->M[1][0];
	c = m1->M[1][1];
	d = m1->M[0][1];

return (a*d-b*c);
}

void arc::mtx2x2Inverse(arc::MATRIX2X2* mtx1,arc::MATRIX2X2* mtx2)
{
	arc::MATRIX2X2 buf;
	float mtxDivider = 1 / arc::mtx2x2det(mtx1);
	
	buf.M[0][0] = mtx1->M[0][0];
	buf.M[1][0] = mtx1->M[1][0] * -1;
	buf.M[1][1] = mtx1->M[1][1];
	buf.M[0][1] = mtx1->M[0][1] * -1;

	arc::mtx2x2scalar_mul(&buf,mtx2,mtxDivider);
}


void arc::buildIdentityMatrix2x2(arc::MATRIX2X2* mtx)
{
	    arc::mtx2x2_init(mtx,1,0,
						     0,1);
}

void arc::buildIdentityMatrix3x3(arc::MATRIX3X3* mtx)
{
	    arc::mtx3x3_init(mtx,1,0,0,
						     0,1,0,
						     0,0,1);
}


void arc::buildIdentityMatrix4x4(arc::MATRIX4X4* mtx)
{
	    arc::mtx4x4_init(mtx,1,0,0,0,
						     0,1,0,0,
						     0,0,1,0,
						     0,0,0,1);

}


void arc::buildRotateMatrixAxisX(arc::MATRIX4X4* mtx,float theta)
{
	    arc::mtx4x4_init(mtx,1,0				,0				   ,0,
						     0,cos((float)theta),-sin((float)theta),0,
						     0,sin((float)theta), cos((float)theta),0,
						     0,0				,0 			       ,1);
}

void arc::buildRotateMatrixAxisY(arc::MATRIX4X4* mtx,float theta)
{
		arc::mtx4x4_init(mtx, cos((float)theta),0,sin((float)theta),0,
						      0				   ,1,0			       ,0,
							 -sin((float)theta),0,cos((float)theta),0,
						      0                ,0,0				   ,1);
}

void arc::buildRotateMatrixAxisZ(arc::MATRIX4X4* mtx,float theta)
{
		arc::mtx4x4_init(mtx,cos((float)theta),-sin((float)theta),0,0,
						     sin((float)theta), cos((float)theta),0,0,
						     0,					 0,				  1,0,
						     0,					 0,				  0,1);
}

void arc::buildInvRotateMatrixAxisX(arc::MATRIX4X4* mtx,float theta)
{
	    arc::mtx4x4_init(mtx,1,0				,0				   ,0,
						     0,cos((float)theta),sin((float)theta),0,
						     0,-sin((float)theta), cos((float)theta),0,
						     0,0				,0 			       ,1);
}

void arc::buildInvRotateMatrixAxisY(arc::MATRIX4X4* mtx,float theta)
{
		arc::mtx4x4_init(mtx, cos((float)theta),0,-sin((float)theta),0,
						      0				   ,1,0			       ,0,
							 sin((float)theta),0,cos((float)theta),0,
						      0                ,0,0				   ,1);
}

void arc::buildInvRotateMatrixAxisZ(arc::MATRIX4X4* mtx,float theta)
{
		arc::mtx4x4_init(mtx,cos((float)theta),sin((float)theta),0,0,
						     -sin((float)theta), cos((float)theta),0,0,
						     0,					 0,				  1,0,
						     0,					 0,				  0,1);
}



void arc::buildTranslateMatrixXYZ(arc::MATRIX4X4* mtx,float x,float y,float z)
{
		arc::mtx4x4_init(mtx,1,0,0,x,
						     0,1,0,y,
						     0,0,1,z,
						     0,0,0,1);
}

void arc::buildInvTranslateMatrixXYZ(arc::MATRIX4X4* mtx,float x,float y,float z)
{
		arc::mtx4x4_init(mtx, 1, 0, 0, -x,
						      0, 1, 0, -y,
						      0, 0, 1, -z,
						      0, 0, 0, 1);
}

void arc::buildPerspectiveMatrix(arc::MATRIX4X4* mtx,float d,float ar)
{
	arc::mtx4x4_init(mtx, d,0,0,0,
					      0,d*ar,0,0,
						  0,0,1,1,
						  0,0,0,0);
}

float arc::vector2dLenght(arc::VECTOR2D* vect)
{
	return sqrt( (float)((vect->V[0]*vect->V[0]) + (vect->V[1]*vect->V[1])) );
}

float arc::vector3dLenght(arc::VECTOR3D* vect)
{
return sqrt( (float)((vect->V[0]*vect->V[0]) + 
					 (vect->V[1]*vect->V[1]) + 
					 (vect->V[2]*vect->V[2])) );
}

float arc::vector4dLenght(arc::VECTOR4D* vect)
{
return sqrt( (float)((vect->V[0]*vect->V[0]) + 
					 (vect->V[1]*vect->V[1]) + 
					 (vect->V[2]*vect->V[2]) + 
					 (vect->V[3]*vect->V[3])) );
}

void arc::vector2dScale(arc::VECTOR2D* vect, float scalar)
{
	vect->V[0] *= scalar;
	vect->V[1] *= scalar;
}

void arc::vector3dScale(arc::VECTOR3D* vect, float scalar)
{
	vect->V[0] *= scalar;
	vect->V[1] *= scalar;
	vect->V[2] *= scalar;
}

void arc::vector4dScale(arc::VECTOR4D* vect, float scalar)
{
	vect->V[0] *= scalar;
	vect->V[1] *= scalar;
	vect->V[2] *= scalar;
	vect->V[3] *= scalar;
}

void arc::vector2dNormalize(arc::VECTOR2D* vect1)
{
	float vl = arc::vector2dLenght(vect1);
	vect1->V[0] /= vl;
	vect1->V[1] /= vl;
}

void arc::vector2dNormalize(arc::VECTOR2D* vect1,arc::VECTOR2D* vect2)
{
	float vl = arc::vector2dLenght(vect1);
	vect2->V[0] = vect1->V[0] / vl;
	vect2->V[1] = vect1->V[1] / vl;
}

void arc::vector3dNormalize(arc::VECTOR3D* vect1)
{
	float vl = arc::vector3dLenght(vect1);
	vect1->V[0] /= vl;
	vect1->V[1] /= vl;
	vect1->V[2] /= vl;
}

void arc::vector3dNormalize(arc::VECTOR3D* vect1,arc::VECTOR3D* vect2)
{
	float vl = arc::vector3dLenght(vect1);
	vect2->V[0] = vect1->V[0] / vl;
	vect2->V[1] = vect1->V[1] / vl;
	vect2->V[2] = vect1->V[2] / vl;
}

void arc::vector4dNormalize(arc::VECTOR4D* vect1)
{
	float vl = arc::vector4dLenght(vect1);
	vect1->V[0] /= vl;
	vect1->V[1] /= vl;
	vect1->V[2] /= vl;
	vect1->V[3] /= vl;
}

void arc::vector4dNormalize(arc::VECTOR4D* vect1,arc::VECTOR4D* vect2)
{
	float vl = arc::vector4dLenght(vect1);
	vect2->V[0] = vect1->V[0] / vl;
	vect2->V[1] = vect1->V[1] / vl;
	vect2->V[2] = vect1->V[2] / vl;
	vect2->V[3] = vect1->V[3] / vl;
}

void arc::vct2dCoppy(arc::VECTOR2D* v1, arc::VECTOR2D* v2)
{
	v2->V[0] = v1->V[0];
	v2->V[1] = v1->V[1];
}

void arc::vct3dCoppy(arc::VECTOR3D* v1, arc::VECTOR3D* v2)
{
	v2->V[0] = v1->V[0];
	v2->V[1] = v1->V[1];
	v2->V[2] = v1->V[2];
}

void arc::vct4dCoppy(arc::VECTOR4D* v1, arc::VECTOR4D* v2)
{
	v2->V[0] = v1->V[0];
	v2->V[1] = v1->V[1];
	v2->V[2] = v1->V[2];
	v2->V[3] = v1->V[3];
}
float arc::vector2dScalarMul(arc::VECTOR2D* v1, arc::VECTOR2D* v2)
{
	return v1->V[0]*v2->V[0] + v1->V[1]*v2->V[1];
}

float arc::vector3dScalarMul(arc::VECTOR3D* v1, arc::VECTOR3D* v2)
{
	return v1->V[0]*v2->V[0] + v1->V[1]*v2->V[1] + v1->V[2]*v2->V[2];
}

float arc::vector4dScalarMul(arc::VECTOR4D* v1, arc::VECTOR4D* v2)
{
	return v1->V[0]*v2->V[0] + v1->V[1]*v2->V[1] + v1->V[2]*v2->V[2] + v1->V[3]*v2->V[3];
}

void arc::addVector2d(arc::VECTOR2D* v1,arc::VECTOR2D* v2,arc::VECTOR2D* v3)
{
	v3->V[0] = v1->V[0] + v2->V[0];
	v3->V[1] = v1->V[1] + v2->V[1];
}

void arc::addVector3d(arc::VECTOR3D* v1,arc::VECTOR3D* v2,arc::VECTOR3D* v3)
{
	v3->V[0] = v1->V[0] + v2->V[0];
	v3->V[1] = v1->V[1] + v2->V[1];
	v3->V[2] = v1->V[2] + v2->V[2];
}

void arc::addVector4d(arc::VECTOR4D* v1,arc::VECTOR4D* v2,arc::VECTOR4D* v3)
{
	v3->V[0] = v1->V[0] + v2->V[0];
	v3->V[1] = v1->V[1] + v2->V[1];
	v3->V[2] = v1->V[2] + v2->V[2];
	v3->V[3] = v1->V[3] + v2->V[3];
}

void arc::addVector2d(arc::VECTOR2D* v1,arc::VECTOR2D* v2)
{
	v1->V[0]+=v2->V[0];
	v1->V[1]+=v2->V[1];
}

void arc::addVector3d(arc::VECTOR3D* v1,arc::VECTOR3D* v2)
{
	v1->V[0]+=v2->V[0];
	v1->V[1]+=v2->V[1];
	v1->V[2]+=v2->V[2];
}

void arc::addVector4d(arc::VECTOR4D* v1,arc::VECTOR4D* v2)
{
	v1->V[0]+=v2->V[0];
	v1->V[1]+=v2->V[1];
	v1->V[2]+=v2->V[2];
	v1->V[3]+=v2->V[3];
}

void arc::subVector2d(arc::VECTOR2D* v1,arc::VECTOR2D* v2,arc::VECTOR2D* v3)
{
	v3->V[0] = v1->V[0] - v2->V[0];
	v3->V[1] = v1->V[1] - v2->V[1];
}

void arc::subVector3d(arc::VECTOR3D* v1,arc::VECTOR3D* v2,arc::VECTOR3D* v3)
{
	v3->V[0] = v1->V[0] - v2->V[0];
	v3->V[1] = v1->V[1] - v2->V[1];
	v3->V[2] = v1->V[2] - v2->V[2];
}

void arc::subVector4d(arc::VECTOR4D* v1,arc::VECTOR4D* v2,arc::VECTOR4D* v3)
{
	v3->V[0] = v1->V[0] - v2->V[0];
	v3->V[1] = v1->V[1] - v2->V[1];
	v3->V[2] = v1->V[2] - v2->V[2];
	v3->V[3] = v1->V[3] - v2->V[3];
}

void arc::subVector2d(arc::VECTOR2D* v1,arc::VECTOR2D* v2)
{
	v1->V[0]-=v2->V[0];
	v1->V[1]-=v2->V[1];
}

void arc::subVector3d(arc::VECTOR3D* v1,arc::VECTOR3D* v2)
{
	v1->V[0]-=v2->V[0];
	v1->V[1]-=v2->V[1];
	v1->V[2]-=v2->V[2];
}

void arc::subVector4d(arc::VECTOR4D* v1,arc::VECTOR4D* v2)
{
	v1->V[0]-=v2->V[0];
	v1->V[1]-=v2->V[1];
	v1->V[2]-=v2->V[2];
	v1->V[3]-=v2->V[3];
}

void arc::cartesian2dToPolar2d(arc::CARTESIAN_COORD2D* cart, arc::POLAR_COORD2D* polar)
{
	polar->r		= sqrt( (cart->x * cart->x) + (cart->y * cart->y) );
	polar->theta	= 1 / tan(cart->y / cart->x);
}

void arc::polar2dToCartesian2d(arc::POLAR_COORD2D* polar, arc::CARTESIAN_COORD2D* cart)
{
	cart->x = polar->r * cos(polar->theta);
	cart->y = polar->r * sin(polar->theta);
}



void arc::cartesian3dToCylindrical3d(arc::CARTESIAN_COORD3D* cart, arc::CYLINDRICAL_COORD3D* cylind)
{
	cylind->r		= sqrt((cart->x * cart->x) + (cart->y * cart->y) );
	cylind->theta	= 1 / tan(cart->y / cart->x);
	cylind->z		= cart->z;
}

void arc::cylindrical3dToCartesian3d(arc::CYLINDRICAL_COORD3D* cylind, arc::CARTESIAN_COORD3D* cart)
{
	cart->x = cylind->r * cos(cylind->theta);
	cart->y = cylind->r * sin(cylind->theta);
	cart->z = cylind->z;
}


void arc::spherical3dToCartesian3d(arc::SPHERICAL_COORD3D* spher, arc::CARTESIAN_COORD3D* cart)
{
	cart->x = spher->rho * sin(spher->phej) * cos(spher->theta);
	cart->y = spher->rho * sin(spher->phej) * sin(spher->theta);
	cart->z = spher->rho * cos(spher->phej);
}

void arc::cartesian3dToSpherical3d(arc::CARTESIAN_COORD3D* cart, arc::SPHERICAL_COORD3D* spher)
{
	float x,y,z,r;
	
	x = cart->x;
	y = cart->y;
	z = cart->z;
	
	r = sqrt( x*x + y*y );

	spher->rho		= sqrt( x*x + y*y + z*z );
	spher->theta	= 1 / tan((float)y/x);
	spher->phej		= 1 / sin(z/spher->rho);
}

void arc::rightCoordToLeftCoord(arc::POINT3D* p)
{
	float a = p->V[0];
	float b = p->V[1];
	float c = p->V[2];

	p->V[0] = -b;
	p->V[1] =  c;
	p->V[2] =  a;
}

void arc::plane3dInit(PLANE3D* plane,POINT3D* point,VECTOR3D* vn)
{
	plane->p0 = *point;
	plane->vn = *vn; 
}


void arc::integrate3mtx4x4Transformations(arc::MATRIX4X4* mtx1,arc::MATRIX4X4* mtx2,arc::MATRIX4X4* mtx3,arc::MATRIX4X4* mtxDest)
{
	arc::MATRIX4X4 mtxtmp;

	arc::mtx4x4mulmtx4x4(mtx1,mtx2,&mtxtmp);
	arc::mtx4x4mulmtx4x4(&mtxtmp,mtx3,mtxDest);
}

void arc::integrate4mtx4x4Transformations(arc::MATRIX4X4* mtx1,arc::MATRIX4X4* mtx2,arc::MATRIX4X4* mtx3,arc::MATRIX4X4* mtx4,arc::MATRIX4X4* mtxDest)
{
	arc::MATRIX4X4 mtxtmp;

	arc::mtx4x4mulmtx4x4(mtx1,mtx2,&mtxtmp);
	arc::mtx4x4mulmtx4x4(&mtxtmp,mtx3,&mtxtmp);
	arc::mtx4x4mulmtx4x4(&mtxtmp,mtx4,mtxDest);
}

void arc::integrate5mtx4x4Transformations(arc::MATRIX4X4* mtx1,arc::MATRIX4X4* mtx2,arc::MATRIX4X4* mtx3,arc::MATRIX4X4* mtx4,arc::MATRIX4X4* mtx5,arc::MATRIX4X4* mtxDest)
{
	arc::MATRIX4X4 mtxtmp;

	arc::mtx4x4mulmtx4x4(mtx1,mtx2,&mtxtmp);
	arc::mtx4x4mulmtx4x4(&mtxtmp,mtx3,&mtxtmp);
	arc::mtx4x4mulmtx4x4(&mtxtmp,mtx4,&mtxtmp);
	arc::mtx4x4mulmtx4x4(&mtxtmp,mtx5,mtxDest);
}

