#include "asciiart.h"
#include "blank.h"
#include "studio.h"
#include "filledbox.h"
#include "blinkingbox.h"
#include "maskbox.h"
#include "movingbox.h"
int main () {
  AsciiArt *canvas = new Blank;

  Studio s{canvas};

  std::string command;

  while (std::cin >> command) {
    if (command == "render" ) {
      s.render();
    }
    else if (command == "animate") {
      int n;
      std::cin >> n;
      s.animate(n);
    }
    else if (command == "reset") {
      s.reset();
    }

else if (command == "filledbox") {
      int top, bottom, left, right;
      char what;
      std::cin >> top >> bottom >> left >> right >> what;
      AsciiArt* fbCanvas = new filledbox(s.picture(),top,bottom,left,right, what);
      s.picture() = fbCanvas;
    }

    else if (command == "blinkingbox") {
      int top, bottom, left, right;
      char what;
      std::cin >> top >> bottom >> left >> right >> what;
      AsciiArt* bbCanvas = new Blinkingbox(s.picture(), top, bottom, left, right, what);
      s.picture() = bbCanvas;
        }
    else if (command == "movingbox") {
      int top, bottom, left, right;
      char what, dir;
      std::cin >> top >> bottom >> left >> right >> what >> dir;
      AsciiArt* mbCanvas = new Movingbox(s.picture(), top, bottom, left, right, what, dir);
      s.picture() = mbCanvas;
    }

    else if (command == "maskbox") {
      int top, bottom, left, right;
      char what;
      std::cin >> top >> bottom >> left >> right >> what;
      AsciiArt* maskbCanvas = new Maskbox(s.picture(), top, bottom, left, right, what);
      s.picture() = maskbCanvas;

    }
  }
}







