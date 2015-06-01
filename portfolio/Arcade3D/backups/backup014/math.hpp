#ifndef MATH
#define MATH

#include <cmath>

#define PI         ((float)3.141592654f)
#define PI2        ((float)6.283185307f)
#define PI_DIV_2   ((float)1.570796327f)
#define PI_DIV_4   ((float)0.785398163f) 
#define PI_INV     ((float)0.318309886f) 

// Makrodefinicje konwersji radian/stopien i stopien/radian
#define DEG_TO_RAD(ang)((ang)*PI/180.0)
#define RAD_TO_DEG(rads)((rads)*180.0/PI)
// wartoœæ maksymalna i minimalna z dwóch zadanych
#define MIN(a, b)  (((a) < (b)) ? (a) : (b)) 
#define MAX(a, b)  (((a) > (b)) ? (a) : (b)) 

// zamiana elementów
#define SWAP(a,b,t) {t=a; a=b; b=t;}

namespace arc
{
	enum ERROR_CODE
	{
		NON,
		ZERO_DIV
	};

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
	struct POLAR_COORD2D
	{
		float r;
		float theta;
	};

	struct CYLINDRICAL_COORD3D
	{
		float r;
		float theta;
		float z;
	};

	struct SPHERICAL_COORD3D
	{
		float phej;
		float rho;
		float theta;
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
		union
		{
			float V[2];

			struct
			{
				float x;
				float y;
			};
		};
	}POINT2D;
	typedef struct VECTOR3D
	{
		union
		{
			float V[3];

			struct
			{
				float x;
				float y;
				float z;
			};
		};
		
	}POINT3D;

	typedef struct VECTOR4D
	{
		union
		{
			float V[4];

			struct
			{
				float x;
				float y;
				float z;
				float w;
			};
		};
	}POINT4D;

		/* Funkcje inicjujace macierze i wektory*/


	struct PLANE3D
	{
		POINT3D p0;
		VECTOR3D vn;
	};


	struct DELTA
	{
		float value;
		arc::ERROR_CODE err_code;
	};


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
	void vct2dCoppy(VECTOR2D*,VECTOR2D*);
	void vct3dCoppy(VECTOR3D*,VECTOR3D*);
	void vct4dCoppy(VECTOR4D*,VECTOR4D*);
	void plane3dInit(PLANE3D*,POINT3D*,VECTOR3D*);

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

	void mtx2x2Inverse(MATRIX2X2*,MATRIX2X2*);

	float mtx3x3det(MATRIX3X3*);
	float mtx2x2det(MATRIX2X2*);

	void buildIdentityMatrix2x2(MATRIX2X2*);
	void buildIdentityMatrix3x3(MATRIX3X3*);
	void buildIdentityMatrix4x4(MATRIX4X4*);


	void buildRotateMatrixAxisX(MATRIX4X4*,float);
	void buildRotateMatrixAxisY(MATRIX4X4*,float);
	void buildRotateMatrixAxisZ(MATRIX4X4*,float);
	void buildInvRotateMatrixAxisX(MATRIX4X4*,float);
	void buildInvRotateMatrixAxisY(MATRIX4X4*,float);
	void buildInvRotateMatrixAxisZ(MATRIX4X4*,float);


	void buildTranslateMatrixXYZ(MATRIX4X4*,float,float,float);
	void buildInvTranslateMatrixXYZ(MATRIX4X4*,float,float,float);
	void buildPerspectiveMatrix(arc::MATRIX4X4*,float,float);

	float vector2dLenght(VECTOR2D*);
	float vector3dLenght(VECTOR3D*);
	float vector4dLenght(VECTOR4D*);

	void vector2dScale(VECTOR2D*,float);
	void vector3dScale(VECTOR3D*,float);
	void vector4dScale(VECTOR4D*,float);

	float vector2dScalarMul(VECTOR2D*,VECTOR2D*);
	float vector3dScalarMul(VECTOR3D*,VECTOR3D*);
	float vector4dScalarMul(VECTOR4D*,VECTOR4D*);

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

	void cartesian2dToPolar2d(CARTESIAN_COORD2D*,POLAR_COORD2D*);
	void polar2dToCartesian2d(POLAR_COORD2D*,CARTESIAN_COORD2D*);

	void cartesian3dToCylindrical3d(CARTESIAN_COORD3D*,CYLINDRICAL_COORD3D*);
	void cylindrical3dToCartesian3d(CYLINDRICAL_COORD3D*,CARTESIAN_COORD3D*);

	void spherical3dToCartesian3d(SPHERICAL_COORD3D*,CARTESIAN_COORD3D*);
	void cartesian3dToSpherical3d(CARTESIAN_COORD3D*,SPHERICAL_COORD3D*);
	void rightCoordToLeftCoord(POINT3D*);

	void integrate3mtx4x4Transformations(MATRIX4X4*,MATRIX4X4*,MATRIX4X4*,MATRIX4X4*);
	void integrate4mtx4x4Transformations(MATRIX4X4*,MATRIX4X4*,MATRIX4X4*,MATRIX4X4*,MATRIX4X4*);
	void integrate5mtx4x4Transformations(MATRIX4X4*,MATRIX4X4*,MATRIX4X4*,MATRIX4X4*,MATRIX4X4*,MATRIX4X4*);

	void findDelta(arc::DELTA *d,arc::VECTOR2D *vert1,arc::VECTOR2D *vert2,arc::VECTOR2D *vert3,int vertexBegin,int vertexEnd);
/*	class trig
	{
		int trigTabSize;
		double *sinTab;
		double *cosTab;
		double *tgnTab;
		double *ctgTab;

	public:

		trig();
		trig(int);
		~trig();

		double sin(int);
		double sin(float);

		double cos(int);
		double cos(float);

		double tgn(int);
		double tgn(float);

		double ctg(int);
		double ctg(float);
	
	};*/

}

#endif // MATH