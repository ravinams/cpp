#ifndef DECORATOR_H
#define DECORATOR_H
#include "asciiart.h"
#include <iostream>

class Decorator: public AsciiArt {
public :
        int top, bottom, left, right;
        char c;

AsciiArt* asciiArt;
        Decorator(AsciiArt* aa, int t, int b, int l, int r, char ch) : asciiArt{aa} {
        top = t;
        bottom = b;
        left = l;
        right = r;
        c = ch;
        }
        virtual ~Decorator() {delete asciiArt;}
        char charAt(int row, int col, int tick) override;

};
#endif


