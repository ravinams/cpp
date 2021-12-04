#include "maskbox.h"
#include <iostream>

char Maskbox::charAt(int row, int col, int tick) {
        char cTemp = asciiArt->charAt(row,col,tick); 
        if (cTemp != ' ') {
                if (row<=bottom && row >= top && col >= left && col <= right)
                        return c;
                else
                        return cTemp;
        }
        return ' ';
}

