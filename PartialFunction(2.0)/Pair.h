#include <iostream>
#pragma once

class Pair{
    bool isDefined;
    int32_t value;
    
public:
    Pair(bool isDefined,int32_t value);
    int32_t getValue() const;
    bool getIsDefined() const;
    
    
};
