#include "decorator.h"
#include <iostream>

class filledbox : public Decorator {
 public:
  filledbox(AsciiArt* aa,int t, int b, int l, int r,char ch) : Decorator{aa,t,b,l,r,ch} {}
 ~filledbox() {}
 char charAt(int row, int col, int tick) override;

};


