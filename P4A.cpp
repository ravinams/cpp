#include <iostream>
#include <string>
#include <cstdlib>
using namespace std ;

// This function checks whether a string contains all digit or not 

bool allDigitsSame(string str)
{   
   for (int i = 1; i < str.length(); i++) 
    { 
        if (str.at(i) != str.at(i-1)) 
            return false;        
    } 
  return true ;
}
bool disgitsInAscendingOrder(string str)
{
for (int i = 1; i < str.length(); i++) 
    { 
        if (str.at(i) > str.at(i-1)) 
            return false;        
    } 
  return true ;
}
bool digitsInDescendingOrder(string str)
{
  for (int i = 1; i < str.length(); i++) 
    { 
        if (str.at(i) < str.at(i-1)) 
            return false;        
    } 
  return true ;

}
bool containsOnlyDigit(string str) 
{ 
    int l = str.length(); 
    for (int i = 0; i < l; i++) 
    { 
        if (str.at(i) < '0' || str.at(i) > '9') 
            return false; 
    } 
    //  if we reach here all character are digits 
    return true; 
} 

bool isTimeValid(string &time)
{
    
  if (time.empty()) // check for empty      
     return false ;
   else if (time.find(':') == string::npos) // check for existane of ':'
     return false ;
   else
   {
      int HourMinuteSeperator =  time.find(':') ;
      string hour = time.substr(0,HourMinuteSeperator);
      string minute = time.substr(HourMinuteSeperator+1);
                 
      if (!containsOnlyDigit(hour) 
         || !containsOnlyDigit(minute) 
         || ( atoi(hour.c_str()) < 0 || atoi(hour.c_str()) > 13 ) 
         || ( atoi(minute.c_str()) < 0 || atoi(minute.c_str()) > 59) ) 
      
        { return false ; }
      
   }
   return true;
}

int main()
{
    string time ;
    bool validTime = true ;
     char ch = 'N' ;
    
    do
    {
    do
    {
    cout << "Enter a time (HH:MM): ";
    cin>>time;
    validTime = isTimeValid(time) ;
   
    if (!validTime)
      cout<<"Invalid time format !"<<endl ;
    
    
    }
    while(!validTime) ;
    
    if (time =="12:03" || time == "12:30" || time == "4:04" || time == "4:31")
      cout<<time<<"is a lucky time."<<endl;
    else
    {
      cout<<time<<" is a normal time. ";

      int HourMinuteSeperator =  time.find(':') ;
      string hour = time.substr(0,HourMinuteSeperator);
      string minute = time.substr(HourMinuteSeperator+1);

      if (allDigitsSame(hour+minute))
         cout<<"you might win a lottery."<<endl;
       else if (disgitsInAscendingOrder(hour+minute))
        cout<<"all dreams will come true."<<endl;
      else if (digitsInDescendingOrder(hour+minute))
        cout<<"challenging road is ahead."<<endl;
    }
    cout<<"\nTest the program again (y/n)? : ";
    cin>>ch ;
  } while(ch =='y' || ch == 'Y') ;

    cout<<"Programmer: Nashay Gooding"<<endl;

    return 0 ;
}