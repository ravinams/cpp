#ifndef CITY_H
#define CITY_H

#include <string>
using namespace std  ;
class City
{
    public :
               City() ;
               City(string cty , string ctry , long double lat, long double lon) ;
               long double distance(const City &other) const ;
               string getCity() const ;
               void setCity(string c) ;
               string getCountry() const;
               void   setCountry(string c) ;
               long double getLatitude() const;
               void   setLatitude(long double l) ;
               long double getLongitude() const;
               void   setLongitude(long double l) ;
               const City & operator=(const City & rightHandSide);
              
               
    private : string city ;
              string country ;
              long double latitude ;
              long double longitude ;
      
};

#endif /* CITY_H */

