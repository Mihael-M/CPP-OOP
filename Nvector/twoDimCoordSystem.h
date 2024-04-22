#pragma once
#include "NVector.h"
constexpr int SIZE = 2;
class twoDimCoordSystem {
	NVector basis[2] = {NVector(0),NVector(0)};


public:
	twoDimCoordSystem() = default;
	twoDimCoordSystem(const NVector& v1, const NVector& v2);
	NVector& getVectorByCoordinates(int first, int second);
	int* getCoordinatesByVector(const NVector& vector);

};