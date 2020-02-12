#include <iostream>

#include "IModel.h"

#ifndef MODEL_H
#define MODEL_H

class Model: public virtual IModel
{
   private :
      std::string fieldName ;
   public :
        void GenerateData(void)
        {

        }
        bool NextData(double& )
       {
         return true  ;
       }

} ;
 #endif /* MODEL_H */