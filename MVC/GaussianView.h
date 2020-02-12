#include "View.h"
#include "Model.h"

#ifndef GAUSSIANVIEW_H
#define GAUSSIANVIEW_H

class GaussianView:public virtual View
{
   public :
       GaussianView(Model &m) ;
       ~GaussianView();
       void Render(unsigned int NoOfElements);
} ;
 #endif /* GAUSSIANVIEW_H */