#include "decorator.h"
#include <iostream> 

class Blinkingbox : public Decorator {
public: 
        Blinkingbox(AsciiArt* aa, int t, int b, int l, int r, char ch) : Decorator(aa,t,b,l,r,ch) {}
        char charAt(int row, int col, int tick) override;
};

