#include "Codeword.h"
#include <ctype.h>


template <typename  T>
Codeword<T>::Codeword()
{  
    numOfSymbols = 0 ;
    cnt = 0 ;
    symbols = nullptr ;
    
}

template <typename  T>
Codeword<T>::Codeword(int l ) 
{
    numOfSymbols =  l;
    cnt = 0 ;
    symbols = new T[numOfSymbols] ;
}

template <typename  T>
int Codeword<T>::addSymbol(T value)
 {
    if (cnt < numOfSymbols)
    {
        symbols[cnt++] = value ;
        return 1 ;
    }
    
    return 0 ;
 }

template <typename  T>
Codeword<T>::~Codeword() {
    
//    if (symbols != nullptr)
//         delete[] symbols ;
         
           numOfSymbols = 0 ;
    cnt = 0 ;
    symbols = nullptr ;
}
template <typename  T>
int Codeword<T>::Weight() const {
    
    int w = 0; 
    for (int i=0 ; i < numOfSymbols ; i++)
    {         
     if ( (  isalpha(symbols[i].getValue()) &&  symbols[i].getValue() != 'a' )  || ( !isalpha(symbols[i].getValue()) && symbols[i].getValue() != 0 ) )   
           w++ ;       
    }
    return w;
}
template <typename  T>
int Codeword<T>::Distance(const Codeword &cw) {
    int d = 0 , diff =0  ;
    for (int i=0 ; i < numOfSymbols ; i++)
    {
        diff = 0 ;
        diff =  symbols[i]-cw.symbols[i] ;
        // cout<<diff<<" " ;
        d = d + diff ;        
    }
    return d  ;    
}

template <typename  T>
void Codeword<T>::Display() {   
    for (int i=0 ; i < numOfSymbols ; i++)
       cout<<symbols[i]<<" " ;      
   cout<<"  Weight : "<<Weight()<< endl ;
}