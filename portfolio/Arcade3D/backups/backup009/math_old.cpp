#include "math.hpp"

arc::matrix::matrix(int x, int y): sizeX(x), sizeY(y)
{
	// Tworzymy dynamicznie tablice NxM
	buffer = new float*[sizeX];
	M = new  float*[sizeX];

	for(int i = 0 ; i < sizeX ; i++)
	{
		M[i] = new  float[sizeY];
		buffer[i] = new float [sizeY];
	}
	// Zerujemy elementy macierzy
	for(int i = 0 ; i < sizeX ; i++)
		for(int j = 0 ; j < sizeY ; j++)
		{
			M[i][j] = 0;
			buffer[i][j] = 0;
		}
}

float * arc::matrix::operator[](int index)
{
	rowBuffer = *(M+index);
return rowBuffer;
}

void arc::matrix::operator=(float mtx[][4])
{
		for(int i = 0 ; i < sizeX ; i++)
			for(int j = 0 ; j < sizeY ; j++)
				M[i][j] = mtx[i][j];	
}

void arc::matrix::operator=(float mtx[][3])
{
		for(int i = 0 ; i < sizeX ; i++)
			for(int j = 0 ; j < sizeY ; j++)
				M[i][j] = mtx[i][j];	
}

void arc::matrix::operator=(float mtx[][2])
{
		for(int i = 0 ; i < sizeX ; i++)
			for(int j = 0 ; j < sizeY ; j++)
				M[i][j] = mtx[i][j];	
}

void arc::matrix::operator=(float mtx[][1])
{
		for(int i = 0 ; i < sizeX ; i++)
			for(int j = 0 ; j < sizeY ; j++)
				M[i][j] = mtx[i][j];	
}

arc::matrix::~matrix()
{
	for(int i = 0 ; i < sizeX ; i++)
		delete [] M[i];
}

void arc::matrix::mul(arc::matrix * mtx1,arc::matrix * mtx2 )
{
		// Mnorzymy macierz * macierz wynik zapisujemy w tym obiekcie
	if(mtx1->sizeX == mtx2->sizeY)	// Sprawdzamy czy ilosc kolumn
	{								//  mtx1 = ilosci wierszy w mtx2
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				M[i][j] = 0;
	            for (int k = 0; k < sizeY; k++)
					M[i][j] += mtx1->M[i][k] * mtx2->M[k][j];
			}
		}
	}
}

void arc::matrix::mul(arc::matrix * mtx1)
{
		// Mnorzymy lokaln¹ macierz * macierz mtx1 
		// operacja jest buforowana
	if(this->sizeX == mtx1->sizeY)	// Sprawdzamy czy ilosc kolumn
	{								//  this = ilosci wierszy w mtx1
		for(int i = 0 ; i < sizeX ; i++)
			for(int j = 0 ; j < sizeY ; j++)
				buffer[i][j] = M[i][j];

		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				M[i][j] = 0;
	            for (int k = 0; k < sizeY; k++)
					M[i][j] += buffer[i][k] * mtx1->M[k][j];
			}
		}
	}
}

void arc::matrix::scalarMul(float scalar)
{
		for(int i = 0 ; i < sizeX ; i++)
			for(int j = 0 ; j < sizeY ; j++)
				this->M[i][j] *= scalar;
}

void arc::matrix::add(arc::matrix * mtx1,arc::matrix * mtx2)
{
	if( (mtx1->sizeX == mtx2->sizeX) && (mtx1->sizeY == mtx2->sizeY) )
	{
		for(int i = 0 ; i < sizeX ; i++)
			for(int j = 0 ; j < sizeY ; j++)
				this->M[i][j] = mtx1->M[i][j] + mtx2->M[i][j];
	}
	else
	{
	// Blad nie mozna dodac macierzy o roznych rozmiarach
	}
}

void arc::matrix::add(arc::matrix * mtx1)
{
	if( (mtx1->sizeX == this->sizeX) && (mtx1->sizeY == this->sizeY) ){
	// Buforujemy macierz
		for(int i = 0 ; i < sizeX ; i++)
			for(int j = 0 ; j < sizeY ; j++)
				buffer[i][j] = M[i][j];

	// Dodajemy  macierz mtx1 do lokalnej macierzy
		for(int i = 0 ; i < sizeX ; i++)
			for(int j = 0 ; j < sizeY ; j++)
				M[i][j] = buffer[i][j] + mtx1->M[i][j];
	}
	else
	{
		/// blad nie mozna dodawac macierzy o roznych rozmiarach
	}

}

void arc::matrix::sub(arc::matrix * mtx1, arc::matrix * mtx2)
{
	if( (mtx1->sizeX == mtx2->sizeX) && (mtx1->sizeY == mtx2->sizeY) )
	{
		for(int i = 0 ; i < sizeX ; i++)
			for(int j = 0 ; j < sizeY ; j++)
				this->M[i][j] = mtx1->M[i][j] - mtx2->M[i][j];
	}
	else
	{
	// Blad nie mozna odjac macierzy o roznych rozmiarach
	}
}

void arc::matrix::sub(arc::matrix * mtx1)
{
	if( (mtx1->sizeX == this->sizeX) && (mtx1->sizeY == this->sizeY) ){
	// Buforujemy macierz
		for(int i = 0 ; i < sizeX ; i++)
			for(int j = 0 ; j < sizeY ; j++)
				buffer[i][j] = M[i][j];

	// Odejmujemy  macierz mtx1 do lokalnej macierzy
		for(int i = 0 ; i < sizeX ; i++)
			for(int j = 0 ; j < sizeY ; j++)
				M[i][j] = buffer[i][j] - mtx1->M[i][j];
	}
	else
	{
		/// blad nie mozna odjac macierzy o roznych rozmiarach
	}
}

void arc::matrix::trs(arc::matrix * mtx1)
{
	// Transpozycja macierzy
		for(int i = 0 ; i < sizeX ; i++)
			for(int j = 0 ; j < sizeY ; j++)
				M[i][j] = mtx1->M[j][i];
}


arc::vector::vector(float x, float y) : size(2)
{
	V = new float[size];

	V[0] = x;
	V[1] = y;
}

arc::vector::vector(float x, float y, float z) : size(3)
{
	V = new float[size];

	V[0] = x;
	V[1] = y;
	V[2] = z;
}

arc::vector::vector(float x, float y, float z, float w) : size(4)
{
	V = new float[size];

	V[0] = x;
	V[1] = y;
	V[2] = z;
	V[3] = w;
}

arc::vector::~vector()
{
	delete [size]V;
}


bool arc::vector::operator==(arc::vector* vct1)
{
		// Jesli wektory sa takie same  zwracamy prawde.
	if(size = vct1->size)
	{
		if(vct1->size == 2)
		{
			if( (vct1->V[0] == this->V[0])
						&& 
				(vct1->V[1] == this->V[1])) return true;
			else return false;
		}
		if(vct1->size == 3)
		{
			if( (vct1->V[0] == this->V[0])
						&& 
				(vct1->V[1] == this->V[1]) 
						&& 
				(vct1->V[2] == this->V[2])) return true;
			else return false;
		}
		if(vct1->size == 4)
		{
			if( (vct1->V[0] == this->V[0])
						&& 
				(vct1->V[1] == this->V[1]) 
						&& 
				(vct1->V[2] == this->V[2])
						&&
				(vct1->V[3] == this->V[3])) return true;
			else return false;
		}
	}
return false;
}

arc::vector & arc::vector::operator*(int scalar)
{
	// Mnorzenie wektora przez scalar int
	if(size== 2)
	{
		V[0] *= (float)scalar;
		V[1] *= (float)scalar;
	}
	if(size== 3)
	{
		V[0] *= (float)scalar;
		V[1] *= (float)scalar;
		V[2] *= (float)scalar;
	}
	if(size== 4)
	{
		V[0] *= (float)scalar;
		V[1] *= (float)scalar;
		V[2] *= (float)scalar;
		V[3] *= (float)scalar;
	}
return (*this);
}

arc::vector & arc::vector::operator*(float scalar)
{
	// Mnorzenie wektora przez scalar float
	if(size== 2)
	{
		V[0] *= (float)scalar;
		V[1] *= (float)scalar;
	}
	if(size== 3)
	{
		V[0] *= (float)scalar;
		V[1] *= (float)scalar;
		V[2] *= (float)scalar;
	}
	if(size== 4)
	{
		V[0] *= (float)scalar;
		V[1] *= (float)scalar;
		V[2] *= (float)scalar;
		V[3] *= (float)scalar;
	}
return (*this);
}

arc::vector & arc::vector::operator*(double scalar)
{
	// Mnorzenie wektora przez scalar double
	if(size== 2)
	{
		V[0] *= (float)scalar;
		V[1] *= (float)scalar;
	}
	if(size== 3)
	{
		V[0] *= (float)scalar;
		V[1] *= (float)scalar;
		V[2] *= (float)scalar;
	}
	if(size== 4)
	{
		V[0] *= (float)scalar;
		V[1] *= (float)scalar;
		V[2] *= (float)scalar;
		V[3] *= (float)scalar;
	}
return (*this);
}

arc::vector & arc::vector::operator+(arc::vector* vct1)
{
	// Suma wektorow
	if(size = vct1->size)
	{
		if(size == 2)
		{
			V[0]+= vct1->V[0];
			V[1]+= vct1->V[1];
		}
		if(size == 3)
		{
			V[0]+= vct1->V[0];
			V[1]+= vct1->V[1];
			V[2]+= vct1->V[2];
		}
		if(size == 4)
		{
			V[0]+= vct1->V[0];
			V[1]+= vct1->V[1];
			V[2]+= vct1->V[2];
			V[3]+= vct1->V[3];
		}
	}
return (*this);
}

arc::vector & arc::vector::operator-(arc::vector* vct1)
{
	// Rorznica wektorow
	if(size = vct1->size)
	{
		if(size == 2)
		{
			V[0]-= vct1->V[0];
			V[1]-= vct1->V[1];
		}
		if(size == 3)
		{
			V[0]-= vct1->V[0];
			V[1]-= vct1->V[1];
			V[2]-= vct1->V[2];
		}
		if(size == 4)
		{
			V[0]-= vct1->V[0];
			V[1]-= vct1->V[1];
			V[2]-= vct1->V[2];
			V[3]-= vct1->V[3];
		}
	}
return (*this);
}

float arc::vector::operator*(arc::vector* vct1)
{
	// Iloczyn skalarny wektorow
	if(size = vct1->size)
	{
		if(size == 2)
		{
			return (this->V[0] * vct1->V[0]) + (this->V[1] * vct1->V[1]);
		}
		if(size == 3)
		{
			return (this->V[0] * vct1->V[0]) + (this->V[1] * vct1->V[1]) + (this->V[2] * vct1->V[2]);
		}
		if(size == 4)
		{
			return (this->V[0] * vct1->V[0]) + (this->V[1] * vct1->V[1]) + 
				   (this->V[2] * vct1->V[2]) + (this->V[3] * vct1->V[3]);
		}
	}
return 0;
}

arc::vector & arc::vector::mul(arc::vector* vct1)
{
	// Iloczyn wektorowy
	if(size = vct1->size)
	{
		if(size == 2)
		{
			V[0]*= vct1->V[0];
			V[1]*= vct1->V[1];
		}
		if(size == 3)
		{
			V[0]*= vct1->V[0];
			V[1]*= vct1->V[1];
			V[2]*= vct1->V[2];
		}
		if(size == 4)
		{
			V[0]*= vct1->V[0];
			V[1]*= vct1->V[1];
			V[2]*= vct1->V[2];
			V[3]*= vct1->V[3];
		}
	}
return (*this);

}


float arc::vector::lenght()
{
	// Dlugosc wektora
	if(size == 2)
	{
		return sqrt( (V[0]*V[0]) + (V[1]*V[1]) );
	}
	if(size == 3)
	{
		return sqrt( (V[0]*V[0]) + (V[1]*V[1]) + (V[2]*V[2]) );
	}
	if(size == 4)
	{
		return sqrt( (V[0]*V[0]) + (V[1]*V[1]) + (V[2]*V[2]) + (V[3]*V[3]) );
	}
return 0;
}

void arc::vector::normalize()
{
	// Normalizacja wektora
	if(size == 2){
		V[0] = V[0] / this->lenght();
		V[1] = V[1] / this->lenght();
	}
	if(size == 3){
		V[0] = V[0] / this->lenght();
		V[1] = V[1] / this->lenght();
		V[2] = V[2] / this->lenght();
	}
	if(size == 4){
		V[0] = V[0] / this->lenght();
		V[1] = V[1] / this->lenght();
		V[2] = V[2] / this->lenght();
		V[3] = V[3] / this->lenght();
	}
}

void arc::vector::invert()
{
	// Odwracanie (inversja) wektora
	if(size == 2)
	{
		V[0] *= (-1);
		V[1] *= (-1);
	}
	if(size == 3)
	{
		V[0] *= (-1);
		V[1] *= (-1);
		V[2] *= (-1);
	}
	if(size == 4)
	{
		V[0] *= (-1);
		V[1] *= (-1);
		V[2] *= (-1);
		V[3] *= (-1);
	}
}
