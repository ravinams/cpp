#include <iostream>
#include <vector>
#include <memory>
using namespace std ;

#ifndef GAUSSIANDATA_H
#define GAUSSIANDATA_H

struct GaussianParams
{
   double amplitude ;
   double stdDev ;
   int NumberOfPoints ;
   std::string filename ;

   GaussianParams(double amp=0, double std=0, int num=0, std::string file="")
   {
      amplitude = amp ;
      stdDev = std ;
      NumberOfPoints = num ;
      filename = file ;
   }
} ;

 typedef std::vector<shared_ptr<double>>  GaussianData ;

  #endif /* GAUSSIANDATA_H */