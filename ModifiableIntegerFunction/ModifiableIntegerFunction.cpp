/* The task was done with the help of:
* - Hristo Partenov - No:0MI0700218
* - Dimitar Conev - No:72087
* - Victor Milanov - No:0MI0700270
* - Zhozhemir Kushev - No:8MI0700284
*/

#include <stdio.h>
#include "ModifiableIntegerFunction.h"
#include <iostream>
#include <exception>



uint16_t ModifiableIntegerFunction::getIndex(int16_t num) const {
    return END + num;
}


void ModifiableIntegerFunction::changeResult(int16_t num, int16_t newValue) {
    modificatedResults[getIndex(num)] = newValue;
}

void ModifiableIntegerFunction::print() const {
    for (size_t i = 0; i < SIZE; i++) {
        std::cout << modificatedResults[i] << " ";
    }
}

ModifiableIntegerFunction ModifiableIntegerFunction::operator~() const {
    ModifiableIntegerFunction inverse;

    for (size_t i = 0; i < SIZE; i++) {
        try {
            inverse.changeResult(i, (*this)(i));
        }
        catch (const std::logic_error&) {
            inverse.excludePoint(i);
        }
    }
    return inverse;
}

void ModifiableIntegerFunction::copyFrom(const ModifiableIntegerFunction& other) {
    modificatedResults = new int16_t[SIZE];
    for (size_t i = 0; i < SIZE; i++) {
        modificatedResults[i] = other.modificatedResults[i];
    }
    excludedPoints = other.excludedPoints;
}
int16_t ModifiableIntegerFunction::id(int16_t x) {
    return x;
}

ModifiableIntegerFunction::ModifiableIntegerFunction() :
    ModifiableIntegerFunction(id) {}

void ModifiableIntegerFunction::free() {
    delete[] modificatedResults;
    modificatedResults = nullptr;

}



ModifiableIntegerFunction::ModifiableIntegerFunction(int16_t(*base) (int16_t)) {
    modificatedResults = new int16_t[SIZE]; //65...
    for (int i = 0; i < SIZE; i++) {
        modificatedResults[getIndex(i)] = base(i);
    }
}

ModifiableIntegerFunction::ModifiableIntegerFunction(const ModifiableIntegerFunction& other) {
    copyFrom(other);
}
ModifiableIntegerFunction::~ModifiableIntegerFunction() {
    free();
}

void ModifiableIntegerFunction::setResult(int16_t value, int16_t result) {
    modificatedResults[getIndex(value)] = result;
}

void ModifiableIntegerFunction::excludePoint(int16_t value) {
    excludedPoints.excludePoint(value);
    modificatedResults[getIndex(value)] = INT16_MIN;
}
ModifiableIntegerFunction& ModifiableIntegerFunction::operator=(const ModifiableIntegerFunction& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}



bool ModifiableIntegerFunction::isExcluded(int16_t point) const {
    return excludedPoints.isExcluded(point);
}


int16_t ModifiableIntegerFunction::operator()(int16_t value) const {

    int index = getIndex(value);

    if (excludedPoints.isExcluded(value)) {
        throw std::logic_error("Excluded value");
    }

    return modificatedResults[index];
}




ModifiableIntegerFunction& ModifiableIntegerFunction::operator-=(const ModifiableIntegerFunction& other) {
    for (int i = 0; i < SIZE; i++) {
        if (!other.excludedPoints.isExcluded(other.modificatedResults[i])) {
            modificatedResults[i] -= other.modificatedResults[i];
        }
    }

    return *this;
}
ModifiableIntegerFunction& ModifiableIntegerFunction::operator+=(const ModifiableIntegerFunction& other) {
    for (int i = 0; i < SIZE; i++) {
        if (!other.excludedPoints.isExcluded(other.modificatedResults[i])) {
            modificatedResults[i] += other.modificatedResults[i];
        }
    }

    return *this;
}
ModifiableIntegerFunction operator*(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs) {


    ModifiableIntegerFunction res(lhs);

    for (int i = 0; i < SIZE; i++) {
        int16_t lhsResult = lhs(rhs(i));
        res.setResult(i, lhsResult);
    }
    return res;
}

ModifiableIntegerFunction operator^(const ModifiableIntegerFunction& func, int times) { // f(g(x)) == f(f(x))

    ModifiableIntegerFunction obj(func);

    for (size_t i = 0; i < times - 1; i++) {
        obj = obj * func;
    }
    return obj;
}


bool operator||(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs) {


    int diff = 0;
    bool isInitialized = false;

    for (size_t i = 0; i < SIZE; i++) {
        try {
            int16_t left = lhs(i);
            int16_t right = rhs(i);

            int nDiff = left - right;

            if (isInitialized && diff != nDiff)
                return false;

            diff = nDiff;
            isInitialized = true;
        }
        catch (const std::logic_error&) {
            if (!(lhs.isExcluded(i) && rhs.isExcluded(i)))
                return false;
        }
    }
    return true;
}
ModifiableIntegerFunction operator-(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs) {
    ModifiableIntegerFunction result(lhs);

    for (int i = 0; i < SIZE; i++) {
        bool leftExcluded = lhs.isExcluded(i);
        bool rightExcluded = rhs.isExcluded(i);

        if (leftExcluded || rightExcluded)
            result.excludePoint(i);
        else
            result.setResult(i, result(i) - rhs(i));
    }

    return result;
}

ModifiableIntegerFunction operator+(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs) {

    ModifiableIntegerFunction result(lhs);

    for (int i = 0; i < SIZE; i++) {
        bool leftExcluded = lhs.isExcluded(i);
        bool rightExcluded = rhs.isExcluded(i);

        if (leftExcluded || rightExcluded)
            result.excludePoint(i);
        else
            result.setResult(i, result(i) + rhs(i));
    }

    return result;
}


bool ModifiableIntegerFunction::isInjective() const {
    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = i + 1; j < SIZE; j++) {
            if ((*this).excludedPoints.isExcluded(i) || (*this).excludedPoints.isExcluded(j)) {
                continue;
            }
            if ((*this)(i) == (*this)(j)) {
                return false;
            }
        }
    }

    return true;
}

bool ModifiableIntegerFunction::isSurjective() const {
    for (int i = 0; i < SIZE; i++) {
        if (excludedPoints.isExcluded(getIndex(modificatedResults[i]))) {
            return false;
        }
    }
    return true;
}

bool ModifiableIntegerFunction::isBijective() const {
    return isInjective() && isSurjective();
}

bool operator>(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs) {
    return !(lhs < rhs) && lhs != rhs;
}

bool operator<(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs) {
    for (int i = 0; i < SIZE; i++) {
        if (lhs.modificatedResults[i] >= rhs.modificatedResults[i])
            return false;
    }
    return true;
}

bool operator>=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs) {
    return (lhs > rhs) || (rhs == lhs);
}

bool operator<=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs) {
    return (lhs < rhs) || (lhs == rhs);
}

bool operator==(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs) {

    for (int i = 0; i < SIZE; i++) {
        if (lhs.excludedPoints.isExcluded(i) && !rhs.excludedPoints.isExcluded(i)) {
            return false;
        }
        else if (!lhs.excludedPoints.isExcluded(i) && rhs.excludedPoints.isExcluded(i)) {
            return false;
        }
        else if (!lhs.excludedPoints.isExcluded(i) && !rhs.excludedPoints.isExcluded(i)) {
            continue;
        }


        if (lhs(i) != rhs(i))
            return false;
    }
    return true;
}

bool operator!=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs) {
    return !(lhs == rhs);
}


void ModifiableIntegerFunction::printGraph(int x1, int x2, int y1, int y2) const {


    if (x2 - x1 != 20 || y2 - y1 != 20) {
        return;
    }


    for (int i = x1; i <= x2; i++) {
        int16_t y = (*this)(i);
        if (y >= y1 && y <= y2) {
            std::cout << "(" << i << ", " << y << ")" << std::endl;
        }
    }

}



void ModifiableIntegerFunction::serialize(std::ofstream& ofs) const {

    ofs.write((const char*)(modificatedResults), SIZE * sizeof(int16_t));
    excludedPoints.serialize(ofs);
}

void ModifiableIntegerFunction::deserialize(std::ifstream& ifs) {

    delete[] modificatedResults;
    modificatedResults = new int16_t[SIZE];
    ifs.read((char*)(modificatedResults), SIZE * sizeof(int16_t));
    excludedPoints.deserialize(ifs);
}
