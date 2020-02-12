#include <iostream>
#include <string>
using namespace std;

int* array = NULL;

int arraySize = 2;
int arrayElmentsCount = 0;

void addElement(int element) {
    /*
      Before adding check if sufficient space available
     if yes , then simply add the element to the array
     if no , then double the array size and add element 
    
     */

    if ( arraySize <= arrayElmentsCount )
    {
       arraySize = arraySize * 2;
               
       cout << " Since array is already full , increasing it's size to : "<<arraySize<< endl;
         
       int *tmp = new int[arraySize];         
       for (int i = 0; i < arrayElmentsCount; i++) {
            tmp[i] = array[i]; // copy values to new array.
        }
        delete [] array;
        array = tmp;  
    }
    
    // find the appropriate position
    int pos = 0  ;
    for(int j=0;j<arrayElmentsCount;++j)
        if( array[j]<=element && element<array[j+1] )
        {
            pos=j+1;
            break;
        }
      
    // shift the elements right to make space 
    for(int k=arrayElmentsCount+1;k>pos;--k)
        array[k]=array[k-1];
    
    array[pos]=element;
    
    arrayElmentsCount++ ;            
}

void deleteElement(int element) {
    
    int indx = -1 ;
    
    // first find whether element exists or not 
    
    for (int i = 0; i < arrayElmentsCount; i++) {
        if (element == array[i])
        {
            indx =  i;
            break ;
        }
    }
    
    
    // if element exists , then delete it by replacing next element with current element till end of array
    if (indx > -1)
    {
        for (int i = indx ; i < arrayElmentsCount-1 ; i++)
            array[i] = array[i+1] ;
        
        arrayElmentsCount-- ;
        
        if (arrayElmentsCount <= arraySize/2)
        {
             arraySize = arraySize / 2;
             int *tmp = new int[arraySize];
             for (int i = 0; i < arrayElmentsCount; i++) {
              tmp[i] = array[i]; // copy values to new array.
        }
        delete [] array;
        array = tmp;
        cout << endl << " Array size shrunk to "<<arraySize<< endl;
             
        }
        
    }
     // if element does not exists , then print necessary message .
    else
    {
       cout << endl <<"Error  " << element<<" not inside the array" << endl;  
    }
        
}


int main() {


    int element;
    int userChoice = 5;
    array = new int[arraySize];

    do {

        cout << endl << "----------------------" << endl;
        cout << "1). Print Elements " << endl;
        cout << "2). Add Element " << endl;
        cout << "3). Delete Element  " << endl;
        cout << "4). Return size " << endl;
        cout << "5). Exit " << endl;
        cout << "----------------------" << endl;
        cout << "Your Selection : ";
        cin >> userChoice;


        switch (userChoice) {
                case 1:
                cout << "\n Elements : ";
                for (int i = 0; i < arrayElmentsCount; i++) {
                    cout << array[i] << " ";
                }
                cout << endl;
                break;
            case 2:
                cout << "\n  Element to add : ";
                cin >> element;
                addElement(element) ;
                cout << endl;
                break;
            case 3:
                cout << "\n Element to delete : ";
                cin >> element;
                deleteElement(element) ;
                cout << endl;
                break;
            case 4:
                cout << "\n Size of the Array is " << arraySize << " there are " << arrayElmentsCount << " Element(s) inside";
                cout << endl;
                break;
            case 5:
                cout << "\n Exiting .... ";
                cout << endl;
                break;
        }


    } while (userChoice < 5);

    delete [] array;
    array = NULL;
}
