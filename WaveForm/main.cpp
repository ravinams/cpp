#include <iostream>
#include <cstring>

#include "Clock.h"
#include "Signal.h"
#include "Channel.h"
#include "Analyser.h"

#define CHANNEL_SAMPLE_TOTAL 10

using namespace std;






int main ()
{
  cout << "Data Acquisition Simulator" << endl;

  double samples[CHANNEL_SAMPLE_TOTAL];

  Clock aClock(0, 0.00001);

  Signal_Type Square = Square;
  Signal_Type Sine = Sine;

  Waveform SquareWaveform (Square, 250);
  Waveform SineWaveform (Sine, 250, 10, 0);

  Signal Signal0 (SquareWaveform, &aClock);
  Signal Signal1 (SineWaveform, &aClock);

  Channel channel0( &Signal0, 300 );
  Channel channel1( &Signal1, 100 ); 
   
  Analyser myAnalyser(channel0, channel1);  

   myAnalyser.GetAllSampleValues(0, samples);
   myAnalyser.DisplayChannel();  
   myAnalyser.GetAllSampleValues(1, samples);
  myAnalyser.DisplayChannel();  
  

  return 0;
}

