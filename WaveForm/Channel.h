/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Channel.h
 * Author: oracle
 *
 * Created on November 8, 2019, 10:02 AM
 */

#ifndef CHANNEL_H
#define CHANNEL_H

#define CHANNEL_SAMPLE_TOTAL 10

class Channel
{

  private:
  
      int numberOfSamples;
      Signal *theSignal;
      double values[CHANNEL_SAMPLE_TOTAL];
      void SetSize (int channelSize)
      {
        numberOfSamples = channelSize;
      }
      double bufferSize;
      double buffer[CHANNEL_SAMPLE_TOTAL];

public:

  Channel (Signal * aSignal, int numOfSamples)
  {
     theSignal = aSignal;
     numberOfSamples = numOfSamples;
     for(size_t t = 0 ; t < CHANNEL_SAMPLE_TOTAL; t++)
       values[t]=0 ;
  }

  void GetChannelParameters (int &numOfSamples)
  {
     numOfSamples = numberOfSamples;
  }

  void getSamples (double *samples)
  {
   
    double smpl ;
    for(int t = 0 ; t < CHANNEL_SAMPLE_TOTAL ; t++)
        { 
          samples[t] = 0 ;
          if (theSignal)
            smpl = theSignal->getSample() ;
          else
            smpl = 0 ;
            
          values[t] = smpl ;
          samples[t] = smpl ;
          buffer[t]  = smpl ;
        
        }
        
        
  }

  int GetChannelSize()
  {
    return bufferSize;
  }

  bool SetChannelSize (int bufferSize)
  {
    
    if (bufferSize < 0 && bufferSize < numberOfSamples) // verify valid value , not sure how to do 
       SetSize (bufferSize);
  }
};



#endif /* CHANNEL_H */

