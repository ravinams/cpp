#include "movingbox.h"
#include <iostream>

char Movingbox::charAt(int row, int col, int tick) {
        int toptemp = top;
        int bottomtemp = bottom;
        int lefttemp = left;
        int righttemp = right;

        if (dir == 'u' && tick!=0) {
                toptemp--; 
                bottomtemp--;
        } else if (dir == 'd' && tick!=0) {
                toptemp++;
                bottomtemp++;
        } else if (dir == 'l' && tick!=0) {
                lefttemp--;
                righttemp--;
        } else if (dir == 'r' && tick!=0) {
                lefttemp++;
                righttemp++;
        }

        if (row == 9 && col == 9) {
                top = toptemp;
                bottom = bottomtemp;
                left = lefttemp;
                right = righttemp;
        }
        if (row <= bottomtemp && row >= toptemp && col >= lefttemp && col <= righttemp)
                return c;
        else 
                return ' ';
}



