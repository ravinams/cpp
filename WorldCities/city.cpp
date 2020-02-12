#include "city.h"
#include <cmath>

#ifndef M_PI
#define M_PI    3.1415926535897932384626433832795
#endif

City::City ()
{

}

City::City (string cty, string ctry, long double lat, long double lon)
{
  city = cty;
  country = ctry;
  latitude = lat;
  longitude = lon;
}

const City & City::operator=(const City & rightHandSide)
{
	if ( this != &rightHandSide) 
	  {
	     city =   rightHandSide.getCity() ; 
              country =   rightHandSide.getCountry() ; 
               latitude =   rightHandSide.getLatitude() ; 
                longitude =   rightHandSide.getLongitude() ; 
           }
	      
	  
	return *this;
}

string
City::getCity () const
{
  return city;
}

void
City::setCity (string c)
{
  city = c;
}

string
City::getCountry () const
{
  return country;
}

void
City::setCountry (string c)
{
  country = c;
}

long double
City::getLatitude () const
{
  return latitude;
}

void
City::setLatitude (long double l)
{
  latitude = l;
}

long double
City::getLongitude () const
{
  return longitude;
}

void
City::setLongitude (long double l)
{
  longitude = l;
}

long double
toRadians (const long double degree)
{
  long double one_deg = (M_PI) / 180;
  return (one_deg * degree);
}

long double
City::distance (const City & other) const
{
  // Convert the latitudes  
  // and longitudes 
  // from degree to radians. 
  long double lat1 = toRadians (latitude);
  long double long1 = toRadians (longitude);
  long double lat2 = toRadians (other.latitude);
  long double long2 = toRadians (other.longitude);

  // Haversine Formula 
  long double dlong = long2 - long1;
  long double dlat = lat2 - lat1;

  long double ans = pow (sin (dlat / 2), 2) +
    cos (lat1) * cos (lat2) * pow (sin (dlong / 2), 2);

  ans = 2 * asin (sqrt (ans));

  // Radius of Earth in  
  // Kilometers, R = 6371 
  // Use R = 3956 for miles 
  long double R = 6371;

  // Calculate the result 
  ans = ans * R;

  return ans;

}
