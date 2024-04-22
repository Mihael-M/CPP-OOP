/* The task was done with the help of:
* - Hristo Partenov - No:0MI0700218
* - Dimitar Conev - No:72087
* - Victor Milanov - No:0MI0700270
* - Zhozhemir Kushev - No:8MI0700284
*/

#pragma once
#include <iostream>
class ExcludedPoints {
private:
    void copyFrom(const ExcludedPoints&);
    void free();
    void resize(unsigned);

    int16_t* excludedPoints;
    uint16_t capacity;
    uint16_t size;


public:
    ExcludedPoints();
    ExcludedPoints(const ExcludedPoints&);
    ExcludedPoints& operator=(const ExcludedPoints&);
    ~ExcludedPoints();
    void serialize(std::ofstream& ofs) const;
    void deserialize(std::ifstream& ifs);
    bool isExcluded(int16_t) const;
    unsigned getSize() const;
    void excludePoint(int16_t);


   

};
