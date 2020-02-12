#include "View.h"

View::View(Model &model) 
{
  this->model = &model ;
}

  void View::SetModel(Model &model)
 {
    this->model = &model ;
 }
 void View::Render(unsigned int NoOfElements)
{
   int i = 0 ; double value ;
   while(i++ < NoOfElements && model->NextData(value))
   {
     std::cout<<value<<std::endl ;
   }
}