#ifndef CODEWORD_H
#define CODEWORD_H

#include "Mint.h"
#include <iostream>

using namespace std;

template <typename  T>
class Codeword {
private:

    int numOfSymbols;
    int cnt = 0;
    T *symbols;

public:
    
    Codeword();
    Codeword(int l ); 
    ~Codeword();
    int addSymbol(T value) ;
    int Weight() const;
    int Distance(const Codeword &cw);
    void Display();
};
#endif
