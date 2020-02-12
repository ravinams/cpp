/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Driver.cpp
 * Author: oracle
 *
 * Created on October 27, 2018, 4:12 AM
 */

#include <iostream>
#include <string>
#include <vector> 
#include "LinkedSortedList.h" // ADT list operations

using namespace std;

/*
 * 
 */

void displayList(LinkedSortedList<int>& sortedList)
{
    int listSize = 0 ;
    cout<<"\nDisplaying List in FORWARD ( START --> END )direction"<<endl ;        
    listSize = sortedList.getLength() ;    
    for (int j= 1 ; j <= listSize ; j++)
    {
        cout<<sortedList.getEntry(j) <<" --> " ;
    }
    cout<<endl ;
    
    cout<<"\nDisplaying List in BACKWARD ( START --> END ) direction"<<endl ;        
    /*
       Since the List is sorted in ASCENDEING order , printing the list from END position will fulfill the requirement.
     */
    listSize = sortedList.getLength() ;    
    for (int k= listSize ; k >=1  ; k--)
    {
        cout<<sortedList.getEntry(k) <<"  <-- " ;
    }
    cout<<endl ;
}
int main(int argc, char** argv) {

    LinkedSortedList<int> lst ;
    int listSize = 0 ;
    
    // add 50 random 
    int randNumber = 0 ;
      cout<<"\nRandom numbers "<<endl ;
    for (int i = 0; i < 10; i++) {
               
        randNumber = rand() ;
         cout << randNumber <<endl ;
        lst.insertSorted(randNumber) ;
        
    }
     
    cout<<"\nDeleting list after INSERTING random values "<<endl ; 
    displayList(lst) ;
   
    
    cout<<"\nDeleting the ODD values from the list "<<endl ; 
    
    listSize = lst.getLength() ; 
    vector<int> oddNumList ; // to store the odd values 
    int lstValue ;
    // Loop to capture the ODD values 
    for (int j= 1 ; j <= listSize ; j++)
    {
        lstValue = lst.getEntry(j) ;
        
        if ( lstValue %2 != 0 ) // ODD NUMBER 
        {          
            oddNumList.push_back(lstValue) ;          
        }
                
    }
    // Loop to delete the ODD values from SortedList
    
    for (auto it = oddNumList.begin(); it != oddNumList.end(); it++) 
      lst.removeSorted(*it);
    
    
    cout<<"\nDeleting list after DELETING odd values "<<endl ; 
    displayList(lst) ;
    
}

