#include <string>
#include "SineData.h"
#include "Model.h"
#include <fstream>
#include <memory>

#ifndef SINEMODEL_H
#define SINEMODEL_H
using namespace std ;
class SineModel:public virtual Model
{
  private : 

      unsigned int currentSamplePosition ;
      double currentValue ;
      dblContainer dbl_pointers ;
      std::shared_ptr<double> sharedDblPtr ;
      SineWaveData sineData ;
      SineParams waveformParams ;
      

  public :
     SineModel(const SineParams& theData) ;
     void GenerateData(void) ;
     bool NextData(double &value) ;
     std::string GetFileName(void) ;
     friend std::ostream &operator<<(std::ostream &stream, SineModel sineOb);
     friend std::istream &operator>>(std::istream &stream, SineModel &sineOb);
     ~SineModel();

} ;

#endif /* SINEMODEL_H */