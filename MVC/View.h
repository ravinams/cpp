#include "IView.h"
#include "Model.h"

#ifndef VIEW_H
#define VIEW_H

class View: public virtual IView
{
   protected :
           Model* model ;
   public :
           View( Model &model) ;
           virtual void SetModel(Model &model);
           virtual void Render(unsigned int NoOfElements);        
} ;
 #endif /* VIEW_H */