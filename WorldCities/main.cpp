#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

#include "city.h"

using namespace std  ;


bool searchCityByCityNumber(const City cities[],int size ,int num,City &ct) ;
bool searchCityByCityName(const City cities[],int size ,string name,City &ct) ;
void printFiveClosestAndFutherstCts(const City cities[], int size , City &ct) ;
bool iequals(const string& a, const string& b) ;
void sort(struct distance* mass, int n) ;
void swap(struct distance* i, struct distance* j) ;

struct distance
    {
        string cityName  ;
        double distance ;
    };
    
int main()
{
    printf("Hello World\n");

    City worldcities[120] ;
    int citiesCount = 0 ;
    
    ifstream inputFile("worldcities.csv") ;
    
    if (!inputFile.is_open())
      {
          cout<<"\nUnable to read worldcities.csv"<<endl;
          return -1 ;
      }
    
    string line ;
    getline(inputFile,line) ; // ignore the header line
    
   
    // read the city data and populate the array 
    while(getline(inputFile,line))
    {
         City cty ;
         
        string city,country;
        string latitude,longitude ;
        
         stringstream ss(line);
         string token ;
         int  tokenCount ;
         
         getline(ss,city, ',');
         getline(ss,country, ',');
         getline(ss,latitude, ',');
         getline(ss,longitude, ',');
         
         
      //  cout << ++citiesCount<<" "<<line <<" -- ";
        
      //  cout <<city<<"--"<< country<<" -- " <<  latitude <<" -- " <<  longitude  <<endl ;
     
        cty.setCity(city) ;
        cty.setCountry( country);
        
       // std::stringstream sslatitude(latitude);
       // std::stringstream sslongitude(longitude);
        
        long double lat , lon ;
        
       // sslatitude >> lat ;
       //  sslongitude >> lon ;
        
        lat = stold(latitude) ;
         lon = stold(longitude) ;
        
        cty.setLatitude(lat) ;
        cty.setLongitude(lon) ;
        
        worldcities[citiesCount++] = cty ;
    }
    
    // temp print 
    /*
    for (int i = 0 ; i < 120 ; i++)
    {
        cout<<worldcities[i].getCity()<<" "<<worldcities[i].getCountry()<<" "<<worldcities[i].getLatitude()<<" "<<worldcities[i].getLongitude() <<endl ; ;
    }
    */
      
       int ch ; int cityIndex = -1 ; string cityName ; int cityNumber  ;  bool found = false ;
      cout<<"Press '1' for search by name or 2 for search by  number or 3 to quit \n" ;
      do
      {
          City cty ; 
          found = false ;
          cout<<"\n Enter your choice (1.Name , 2.Number , 3.Quit) \n" ;
          cin>> ch ;
          if ( ch == 1 || ch ==2 || ch==3 )
          {
              if (ch ==1)
              {
                  cout<<"Enter the name of the city to search for"<<endl ;
                  cin>>cityName ;
                   found = searchCityByCityName(worldcities,120,cityName,cty) ;                                                                                  
              }
              
              else if (ch ==2)
              {
                  cout<<"Enter the city number of the city to search for"<<endl ;
                  cin>>cityNumber ;
                  found = searchCityByCityNumber(worldcities,120,cityNumber,cty) ;                                                                                  
              }
              
              else if (ch == 3)
              {
                  cout<<"Exiting the program" ;
                  break ;
              }
              
              if (found)
              {
                  printFiveClosestAndFutherstCts(worldcities,120,cty) ;
                  break ;   
              }
              else
                  cout<<"Ccanot find any city with given parameter" ;
          }
          else
          {
              cout<<" Invalid choice , renter" <<endl ;
              continue  ;
          }
          
      }
      while(ch == 1 || ch == 2) ;
      
    return 0;
}



bool searchCityByCityNumber(const City cities[],int size ,int num,City &ct) 
{
   if (num < size)
     {
         ct = cities[num-1] ; // -1 since index starts 0
         return true ;
     }
    else
      return false ;
}

bool searchCityByCityName(const City cities[],int size ,string name,City &ct) 
{
    string cityName ;
    for (int i = 0 ; i < size  ; i ++)
    { 
        cityName = cities[i].getCity() ;
        if ( iequals(cityName , name) ) 
          {
             ct = cities[i] ;
             return true ;
          }
    }
    
    return false ;
}

void printFiveClosestAndFutherstCts(const City cities[], int size , City &ct) 
{
       
    cout<<"++++ 5 closest & 5 furtherst distance cities for "<<ct.getCity()<<endl ;
   
    struct distance cityDistance[size] ;
    
    for (int i = 0 ; i < size ; i ++)
    {
        cityDistance[i].cityName = cities[i].getCity() ;
        cityDistance[i].distance = cities[i].distance(ct) ;
    }
    
    /*
    for (int i = 0 ; i < size ; i ++)
    {
        cout<<cityDistance[i].cityName<<" "<<cityDistance[i].distance <<endl;       
    }
    */
    
    // sort
    
    sort(cityDistance,size) ;
    
     
 
    
    // 5 closest  .. 1..5   (0 for self )
    
    cout<<"+++++ Five closest cities ++++"<<endl ;
    for (int i = 1 ; i <= 5 ; i ++)
    {
        cout<<cityDistance[i].cityName<<"    "<<cityDistance[i].distance <<endl;       
    }
    cout<<"+++++ Five Furthest  cities ++++"<<endl ;
    
    for (int j = 115 ; j < 120 ; j ++)
    {
        cout<<cityDistance[j].cityName<<"    "<<cityDistance[j].distance <<endl;       
    }
    // 5 further  115.. 119
    
    
}

void swap(struct distance* i, struct distance* j)
{
    struct distance t;
     t = *i;
    *i = *j;
    *j = t;

}

void sort(struct distance* mass, int n)
{
		int i=0;
		bool swapped=true;
		while(swapped) // loop until no more values were swapped
		{    
                        i++;
			swapped = false;
			for (int j = 0; j < n-i; j++) 
			{
				if(mass[j].distance > mass[j+1].distance)
				{
					swap(&mass[j],&mass[j+1]);
					swapped = true;
				}
				if(mass[j].distance == mass[j+1].distance)
				{
					if(mass[j].cityName > mass[j+1].cityName)
					{
						swap(&mass[j],&mass[j+1]);
						swapped = true;
					}
				}

			}

		}
}

bool iequals(const string& a, const string& b)
{
    unsigned int sz = a.size();
    if (b.size() != sz)
        return false;
    for (unsigned int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}