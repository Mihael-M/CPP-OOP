#include "twoDimCoordSystem.h"

twoDimCoordSystem::twoDimCoordSystem(const NVector& v1, const NVector& v2)
{
	basis[0] = v1;
	basis[1] = v2;	
}

NVector& twoDimCoordSystem::getVectorByCoordinates(int first, int second)
{
	
	for (size_t i = 0; i < SIZE; i++)
	{
		bool first = false;
		bool second = false;
		for (size_t j = 0; j < ~basis[i]; j++)
		{
			if (basis[i][j] == first)
				first = true;
			else if (basis[i][j] == second)
				second = true;
		}
		if (first && second)
			return basis[i];
	}
	throw "Not Found";
}

int* twoDimCoordSystem::getCoordinatesByVector(const NVector& vector)
{
	int data[2];
	for (size_t i = 0; i < SIZE; i++)
	{
		if (basis[i] == vector)
		{
			for (int j = 0; j < ~vector; j++)
			{
				data[j] = vector[j];
			}
		}
	}
	return data;
}
