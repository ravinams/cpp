/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LLNode.h
 * Author: oracle
 *
 * Created on October 22, 2018, 12:17 PM
 */

#ifndef LLNODE_H
#define LLNODE_H


#include <iostream>
#include <stdlib.h>
using namespace std;

class LLNode {
    //	friend class LLPQ;
    //	friend class LLHuff;
   
     int freq;
      char data;   
      string code;

public:
    
   
   
    
    
    LLNode *next;
    LLNode *prev;
    LLNode *left;
    LLNode *right;
    
    LLNode(char c);
    ~LLNode();
    char getData();
    void setData(char d) ;
    int getFreq();
    void setFreq(int f);
    string getCode();
    void setCode(string c);
};


#endif /* LLNODE_H */

