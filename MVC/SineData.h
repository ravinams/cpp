#include <string>
#include <vector>
#include <memory>

#ifndef SINEDATA_H
#define SINEDATA_H

struct SineParams
{
   double amplitude ;
   std::string filename ;
   double frequency ;
   int NumberOfPoints ;

   double phase ;
   double samplingTime ;
  
  SineParams(double amp=0, double freq=0, double phas=0, double sampling=0, unsigned int points=0, std::string file=std::string())
  {
    amplitude = amp ;
    frequency = freq ;
    phase = phas ;
    samplingTime = sampling ;
    NumberOfPoints = points ;
    filename = file ;
  }

  
} ;

 typedef std::vector<std::shared_ptr<double>>  SineWaveData ;

#endif /* SINEDATA_H */