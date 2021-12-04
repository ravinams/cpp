#include "filledbox.h"
#include <iostream>


char filledbox::charAt(int row,int col, int tick) {
        char cTemp = asciiArt->charAt(row,col,tick);
        if (row <= bottom && row>= top && col >= left && col <= right) 
                return c; 
        if (cTemp != ' ')
                return cTemp;
        else
                return ' ';
        
}

