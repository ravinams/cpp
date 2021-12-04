#include "decorator.h"
#include <iostream>

class Movingbox : public Decorator {
char dir;
public:
        Movingbox(AsciiArt* aa, int t, int b, int l, int r, char ch, char d) : Decorator{aa,t,b,l,r,ch} {
        dir = d;
        }
        char charAt(int row, int col, int tick);
};

