#include <iostream>
#include "Model.h"
#include "GaussianData.h"
#include "Common.h"

#ifndef GAUSSIANMODEL_H
#define GAUSSIANMODEL_H

class GaussianModel: public virtual Model
{
   private :

      unsigned int currentSamplePosition ;
      double currentValue ;
      dblContainer dbl_pointers ;
      GaussianData randomData ;
      GaussianParams randomParams ;
      shared_ptr<double> sharedDblPtr ;
      
   public  :

    
      GaussianModel(const GaussianParams &params);
      ~GaussianModel();
      void GenerateData(void) ;     
      bool NextData(double& value) ;
} ;

  #endif /* GAUSSIANMODEL_H */