#ifndef MINT_H
#define MINT_H

#include <iostream>

class Mint {
private:

    int value;
    
   

public:
    
    static int modulas; 

    Mint();
    Mint(int v); //Parameterized constructor
    ~Mint(); // destructor 
    int getValue() const;
    void setValue(const int v);
    int operator-(const Mint &m1);
    friend std::ostream& operator<<(std::ostream& os, const Mint & input);
};



#endif

