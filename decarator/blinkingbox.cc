#include "blinkingbox.h"
#include <iostream>

char Blinkingbox::charAt(int row, int col, int tick) {
        char cTemp = asciiArt->charAt(row,col,tick);
        if (row<=bottom && row >=top && col >= left && col <= right && tick %2 == 0)
                return c;
        if (cTemp != ' ')
                return cTemp;
        else
                return ' ';
}


