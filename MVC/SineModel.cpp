#include "SineModel.h"
#include <string>
#include <vector>

#define _USE_MATH_DEFINES
#include <math.h>

SineModel::SineModel(const SineParams& theData)
{
   waveformParams = theData ;
}

void SineModel::GenerateData(void)
{

    // AMPLITUDE * sin (2 * M_PI * 0.15 * t + 0) + ZERO_OFFSET;
    // the below formula needs double check 
     for (int i=0; i<waveformParams.NumberOfPoints; ++i) {
            double number = waveformParams.amplitude * sin (2 * M_PI * waveformParams.frequency * i + waveformParams.phase) / waveformParams.NumberOfPoints;
               sineData.push_back(std::make_shared<double>(number));
      }
      currentSamplePosition=0 ;
      currentValue = *sineData[currentSamplePosition] ;

}

bool SineModel::NextData(double &value)
{
    if (currentSamplePosition == sineData.size()-1)  // at the end
    	return false ;
        
    value = *sineData[currentSamplePosition++] ;
    currentValue = value ;
    return true ;
}
std::string SineModel::GetFileName(void)
{
  return waveformParams.filename ;
}

ostream &operator<<(ostream &stream, SineModel sineOb)
{
   double dataValue = 0;
   for (int i=0; i<sineOb.waveformParams.NumberOfPoints; ++i) {
   	   stream << *sineOb.sineData[i] << endl;
   }
  sineOb.currentSamplePosition=0 ;
  sineOb.currentValue = *sineOb.sineData[sineOb.currentSamplePosition] ;
  return stream;
}

istream &operator>>(istream &stream, SineModel &sineOb)
{
  double dataValue = 0;
  sineOb.sineData.clear();
  for (int i=0; i<sineOb.waveformParams.NumberOfPoints; ++i) {
  	 stream>>dataValue ;
     //sineOb.sineData[i] = make_shared<double>(dataValue);

     sineOb.sineData.push_back(make_shared<double>(dataValue));

     //cout<<dataValue<<endl ;
  }
  sineOb.currentSamplePosition=0 ;
  sineOb.currentValue = *sineOb.sineData[0] ;
  return stream ;
}

SineModel::~SineModel()
{

}