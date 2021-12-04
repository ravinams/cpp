#include "decorator.h"
#include <iostream>

char Decorator::charAt(int row, int col, int tick) {
        return asciiArt->charAt(row,col,tick);
}

