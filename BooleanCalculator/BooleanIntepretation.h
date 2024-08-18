#include <iostream>
#pragma once
constexpr int ALPHABET_SIZE = 26;
class BooleanIntepretation {
private:
    
    bool symbolValues[ALPHABET_SIZE]= {false};
    
public:
    
    bool getValue(char symbol)const;
    void setValue(char symbol, bool value);
    static bool isValidVAriable(char Variable);
    
    static BooleanIntepretation fromNumber(const bool* variablesIncluded,size_t size);
};
