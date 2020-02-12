/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: oracle
 *
 * Created on March 6, 2018, 12:25 PM
 */


#include "SyntaxChecker.h" 
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    if (argc < 2) {
        printf("Please supply the file name as argument \n");
        exit(0);
    } else if (argc > 2) {
        printf("Too many arguments , only one argument is required  \n");
        exit(0);
    }
    
    string file = argv[1] , error;
    bool status  ;
//    cout<<"Enter the file name:" ;
//    cin>>file ;
    
    ifstream ifs;
    ifs.open(file.c_str(), ios_base::in);
    if (ifs.is_open())
    {
    
     SyntaxChecker sc ;
    status = sc.areParanthesesBalanced(file ,error) ;
     if (status)
           cout<<"The delimiter syntax is correct."<<endl ;
     else
         cout<<error<<endl ;
    }
    else
    {
        cout<<"Unable to open the file to read"<<endl ; 
    }
           
    return 0;
}

