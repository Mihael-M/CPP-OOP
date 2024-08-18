#include "BooleanIntepretation.h"
#include <stdio.h>

bool BooleanIntepretation::getValue(char symbol)const
{
    return symbolValues[symbol - 'a'];
}

void BooleanIntepretation::setValue(char symbol, bool value){
    
    symbolValues[symbol-'a']=value;
    
}

bool BooleanIntepretation::isValidVAriable(char variable)
{
    return variable >= 'a' && variable<='z';
}

BooleanIntepretation BooleanIntepretation::fromNumber(const bool *variablesIncluded, size_t size)
{
    BooleanIntepretation booleanIntepretation;
    
    for(int i =0;i<ALPHABET_SIZE;i++)
    {
        if(variablesIncluded[i]){
            bool value = (size % 2 == 1);
            size/=2;
            booleanIntepretation.setValue(i+'a', value);
            
        }
        if(size == 0) return booleanIntepretation;
    }
    return booleanIntepretation;
}
