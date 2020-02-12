/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clock.h
 * Author: oracle
 *
 * Created on November 8, 2019, 10:01 AM
 */

#ifndef CLOCK_H
#define CLOCK_H
class Clock
{
  private:
      double increment;
      double microsecs;

    public:
      Clock ()
      {
        microsecs = 0.0;
        increment = 0.0000005;
      }
    
      Clock (double startPoint, double incrementValue)
      {
        microsecs = startPoint;
        increment = incrementValue;
      }
    
      void AdvanceTime (double muSecs)
      {
        if (muSecs != 0)
          microsecs = microsecs + muSecs;
        else
          microsecs = microsecs + increment;
      }
    
      double GetSimulationTime ()
      {
        double time = microsecs;
        AdvanceTime (0);
        return time;
      }
};


#endif /* CLOCK_H */

