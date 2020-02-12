#ifndef CODEBOOK_H
#define CODEBOOK_H

#include "Codeword.h"

template <typename T>
class Codebook
{
   private :
   
     int numOfCodewords , cnt;
     T *codeword ;
     int **distanceMtrix ;
     
   public :
       
   Codebook() ;
   Codebook(int n) ;
  ~Codebook() ;
   int addCodeword(const T &cw) ;
   int minimumWeight() ;
   void calcDistance() ;
   int minimumDistance() ;
   void Display() ;
    

} ;
#endif