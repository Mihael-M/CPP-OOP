/* The task was done with the help of:
* - Hristo Partenov - No:0MI0700218
* - Dimitar Conev - No:72087
* - Victor Milanov - No:0MI0700270
* - Zhozhemir Kushev - No:8MI0700284
*/

#include <stdio.h>
#include "ExcludedPoints.h"
#include <fstream>

ExcludedPoints::ExcludedPoints(const ExcludedPoints& other) {
    copyFrom(other);
}

ExcludedPoints::ExcludedPoints() : capacity(8), size(0) {
    excludedPoints = new int16_t[capacity]{ 0 };
}




ExcludedPoints& ExcludedPoints::operator=(const ExcludedPoints& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}
bool ExcludedPoints::isExcluded(int16_t num) const {
    for (size_t i = 0; i < size; i++) {
        if (num == excludedPoints[i]) {
            return true;
        }
    }
    return false;
}

ExcludedPoints::~ExcludedPoints() {
    free();
}


void ExcludedPoints::excludePoint(int16_t num) {
    if (size == capacity) {
        resize(capacity * 2);
    }

    excludedPoints[size] = num;
    size++;
}


unsigned ExcludedPoints::getSize() const {
    return size;
}

void ExcludedPoints::free() {
    delete[] excludedPoints;


    size = capacity = 0;
}
void ExcludedPoints::copyFrom(const ExcludedPoints& other) {
    capacity = other.capacity;
    size = other.size;
    excludedPoints = new int16_t[capacity];

    for (size_t i = 0; i < size; i++) {
        excludedPoints[i] = other.excludedPoints[i];
    }
}



void ExcludedPoints::resize(unsigned newCap) {
    capacity = newCap;
    int16_t* arr = new int16_t[capacity];
    for (size_t i = 0; i < size; i++) {
        arr[i] = excludedPoints[i];
    }
    delete[] excludedPoints;
    excludedPoints = arr;
}



void ExcludedPoints::serialize(std::ofstream& ofs) const {
    ofs.write((const char*)(&size), sizeof(size));
    ofs.write((const char*)(excludedPoints), size * sizeof(int16_t));
}

void ExcludedPoints::deserialize(std::ifstream& ifs) {


    ifs.read((char*)(&size), sizeof(size));


    capacity = 2 * size;
    delete[] excludedPoints;

    excludedPoints = new int16_t[capacity];
    ifs.read((char*)(excludedPoints), size * sizeof(uint16_t));
}
