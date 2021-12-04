#include "decorator.h"
#include <iostream>


class Maskbox: public Decorator {
public:
        Maskbox(AsciiArt* aa, int t, int b, int l, int r, char ch) : Decorator{aa,t,b,l,r,ch} {}
        char charAt(int row, int col, int tick);

};

