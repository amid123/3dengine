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

void arc::vct3dn_init(VECTOR3D_NORMAL* v1, float x, float y, float z, float w)
{
	v1->V[0] = x;
	v1->V[1] = y;
	v1->V[2] = z;
	v1->V[3] = w;
}
void arc::vct2dn_init(VECTOR2D_NORMAL* v1, float x, float y, float w)
{
	v1->V[0] = x;
	v1->V[1] = y;
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

void arc::mtx4x4mulvct3dn(MATRIX4X4* m1,VECTOR3D_NORMAL* v1,VECTOR3D_NORMAL* dest)
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