#include <random>

#include "GaussianModel.h"
#include "GaussianData.h"


GaussianModel::GaussianModel(const GaussianParams &params) 
{
   randomParams = params ;
}

GaussianModel::~GaussianModel()
{
	
}

 void GaussianModel::GenerateData(void) 
 {
     std::default_random_engine generator;
     std::normal_distribution<double> distribution(randomParams.amplitude,randomParams.stdDev);

     for (int i=0; i<randomParams.NumberOfPoints; ++i) {
            double number = distribution(generator);
               randomData.push_back(std::make_shared<double>(number));
      }
      currentSamplePosition=0 ;
      currentValue = *randomData[currentSamplePosition] ;
      
  

 }    
 bool GaussianModel::NextData(double& value) 
 {
    if (currentSamplePosition == randomData.size()-1)  // at the end
    	return false ;

    currentValue = *randomData[++currentSamplePosition] ;
    value = currentValue ;
    return true ;
 }