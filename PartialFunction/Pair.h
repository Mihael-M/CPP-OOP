#include <iostream>
#pragma once

class Pair{
private:
    bool isDefined = true;
    int value = 0;
public:
    
    Pair() = default;
    Pair(bool isDefined,int value);
    bool getIsDefined() const;
    int getValue() const;
    
    void setIsDefined(bool isDefined);
    void setValue(int value);
    
    friend std::ostream& operator<<(std::ostream& os,const Pair& obj);
    
    
};

