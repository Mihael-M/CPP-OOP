/* The task was done with the help of:
* - Hristo Partenov - No:0MI0700218
* - Dimitar Conev - No:72087
* - Victor Milanov - No:0MI0700270
* - Zhozhemir Kushev - No:8MI0700284
*/


#include <iostream>
#include <fstream>
#include "ExcludedPoints.h"


constexpr unsigned SIZE = UINT16_MAX; //65....
constexpr int START = INT16_MIN; // -32767
constexpr unsigned END = INT16_MAX; // 32768

class ModifiableIntegerFunction {
private:

    int16_t* modificatedResults;
    ExcludedPoints excludedPoints;

    void copyFrom(const ModifiableIntegerFunction& other);
    void free();

    static int16_t id(int16_t x);


public:

    ModifiableIntegerFunction();
    ModifiableIntegerFunction(int16_t(*base) (int16_t));
    ModifiableIntegerFunction(const ModifiableIntegerFunction& other);
    ModifiableIntegerFunction& operator=(const ModifiableIntegerFunction& other);
    ~ModifiableIntegerFunction();

    void setResult(int16_t value, int16_t result);
    void excludePoint(int16_t value);

    bool isExcluded(int16_t point) const;

    bool isInjective() const;
    bool isSurjective() const;
    bool isBijective() const;
    uint16_t getIndex(int16_t num) const;
    void changeResult(int16_t num, int16_t newValue);
    void print() const;
    void printGraph(int x1, int x2, int y1, int y2)const;
    void serialize(std::ofstream& ofs) const;
    void deserialize(std::ifstream& ifs);



    ModifiableIntegerFunction& operator+=(const ModifiableIntegerFunction& other);
    ModifiableIntegerFunction& operator-=(const ModifiableIntegerFunction& other);
    int16_t operator()(int16_t value) const;
    friend ModifiableIntegerFunction operator^(const ModifiableIntegerFunction& func, int times);
    friend ModifiableIntegerFunction operator*(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
    friend bool operator||(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);

    friend ModifiableIntegerFunction operator+(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
    friend ModifiableIntegerFunction operator-(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
    friend bool operator==(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
    friend bool operator!=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
    friend bool operator<=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
    friend bool operator>=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
    friend bool operator<(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
    friend bool operator>(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
    ModifiableIntegerFunction operator~() const;

    void serialize() const;
    void deserialize();

};