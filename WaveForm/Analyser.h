/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Analyser.h
 * Author: oracle
 *
 * Created on November 8, 2019, 10:02 AM
 */

#ifndef ANALYSER_H
#define ANALYSER_H


#include <iostream>
using namespace std;

class Analyser
{
  private :
  
    Channel* channel[2] ;
    int numberOfChannels ;
    int numberOfSamples ;
    double timebase ;
    int VoltsPerDiv ;
    
 
  public :
  
   Analyser(int numOfChannels)
   {
      channel[0] = NULL ;
      channel[1] = NULL ;
      numberOfChannels = numOfChannels;
   }
  
   Analyser(Channel c0)
   {
       channel[0] = &c0 ;
       channel[1] = NULL ;
       numberOfChannels =1 ;
   }
   
   Analyser(Channel c0,Channel c1)
   {
       channel[0] = &c0 ;
       channel[1] = &c1 ;
       numberOfChannels = 2 ;
   }
   
   void DisplayChannel()
   {
       cout<<"Enter the channel number (0 or 1)"<<endl;
       int channelNumber ;
       cin>>channelNumber ;
       if (channelNumber < 0 || channelNumber > 1)
          {
              cout<<"Invalid channel number"<<endl ;
              exit(1) ;
          }
       double samples[CHANNEL_SAMPLE_TOTAL] ;
       GetAllSampleValues(channelNumber, samples) ;
     
       for(size_t t = 0 ; t < CHANNEL_SAMPLE_TOTAL ; t++)
          cout<<samples[t]<<"\n " ;
         
   }
   
   
   int GetAllSampleValues(int channelNumber, double* array2Populate)
   {
     
       Channel *c = NULL ;
      
       if (channelNumber == 0)
           c = channel[0] ;
      else if (channelNumber == 1)
           c= channel[1] ;
      
      if (c)     
       c-> getSamples(array2Populate);
       
   }
   
   bool GetChannelParameters(int channelNumber , double& VoltsPerDiv,double& timebase,int& channelSampleSize)
   {
       if (channelNumber == 0)
         {
             
          Channel *c0 = channel[0] ;
          c0->GetChannelParameters(channelSampleSize);
          timebase = this->timebase ;
          VoltsPerDiv = this->VoltsPerDiv;
         }
      else if (channelNumber == 1)
        {
          Channel *c1 = channel[1] ; 
          c1->GetChannelParameters(channelSampleSize);
          timebase = this->timebase ;
          VoltsPerDiv = this->VoltsPerDiv;
            
        }
       
   }
   double GetCurrentValue(int channelNumber) // There is proper definition
   {
        
    Channel *c ;
     if (channelNumber == 0)
         {
             
          c = channel[0] ;
          
        
         }
      else if (channelNumber == 1)
        {
          c = channel[1] ; 
        
        }
        
        c->GetChannelSize();
   }
   
    bool setChannelProperties(int channelNumber, Channel channelMetaData)
   {
       
       Channel *c ;
     if (channelNumber == 0)
         {
             
          c = channel[0] ;
          
        
         }
      else if (channelNumber == 1)
        {
          c = channel[1] ; 
        
        }
        
        c = &channelMetaData ;
        
   }
   
   void SetChannelSize(int channelNumber,int size)
   {
        Channel *c ;
     if (channelNumber == 0)
         {
             
          c = channel[0] ;
          
        
         }
      else if (channelNumber == 1)
        {
          c = channel[1] ; 
        
        }
        c->SetChannelSize(size) ;
       
   }
   
   void SetSize(int channelNumber,int size)
   {
         Channel *c ;
     if (channelNumber == 0)
         {
             
          c = channel[0] ;
          
        
         }
      else if (channelNumber == 1)
        {
          c = channel[1] ; 
        
        }
        c->SetChannelSize(size) ;
   }
 
};


#endif /* ANALYSER_H */

