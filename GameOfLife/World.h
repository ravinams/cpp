/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   World.h
 * Author: oracle
 *
 * Created on February 22, 2018, 12:42 PM
 */

#ifndef WORLD_H
#define WORLD_H

#include <string>

class World {
   
public  :
     World();
     World(int, int);
       // copy constructor
     World(const World& other) ;
   
    // overloaded assignment operator
   // We can copy into differently-sized square list, as long as it is large
   // enough to hold all of the actual stored data.
    const World& operator=(const World& rhs) ;
    
   
     ~World();
     void randomizeCells(int h , int w , double density );
     void populateFromFile(std::string filename) ;
     void printToConsole() ;
     void printToFile(std::string filename) ;
     void computeNextGeneration(char) ;
     int getAliveNeighborCount(int row , int col , char simulationMode) ;
     
     bool isEmpty() ;
     bool isStabilized() ;
     
private :
    int height , width , generationCount ;
    char ** currentGrid ;
    
    bool stabilizes , empty ;
    
    
};



#endif /* WORLD_H */

