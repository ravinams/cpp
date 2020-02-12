/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Signal.h
 * Author: oracle
 *
 * Created on November 8, 2019, 10:01 AM
 */

#ifndef SIGNAL_H
#define SIGNAL_H


enum class Signal_Type { Sine, Square };


struct Waveform
{

  Signal_Type name;
  double frequency;
  double amplitude;
  double dcOffset;

  Waveform ():name ((Signal_Type) 0), frequency (0), amplitude (0),dcOffset (0){} // default Constructor
  Waveform (Signal_Type n, double f):name (n), frequency (f){}
  Waveform (Signal_Type n, double f, double a, double d):name (n),frequency (f), amplitude (a), dcOffset (d){} // parameter Constructor
  

};


class Signal
{

  private:
  
      Waveform aWaveform;
      Clock *clockSource = NULL;

    public:
    
      Signal (Waveform aType, Clock * aClock)
      {
        clockSource = aClock;
        aWaveform = aType;
      }
    
      double getSample()
      {
        if (clockSource !=NULL)
          return aWaveform.frequency * clockSource->GetSimulationTime(); // DONT KNOW correct formula
        else
          return  0 ;
      }

};


#endif /* SIGNAL_H */

