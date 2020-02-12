#include "Common.h"

#ifndef IMODEL_H
#define IMODEL_H

class IModel
{
   public :
       virtual void GenerateData(void)=0;
       virtual bool NextData(double&)=0;
} ;

 #endif /* IMODEL_H */