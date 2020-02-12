/* 
 * File:   LLPQ.h
 * Author: oracle
 *
 * Created on October 22, 2018, 12:19 PM
 */

#ifndef LLPQ_H
#define LLPQ_H

#include <string>
#include "LLNode.h"

class LLPQ{
	// friend class LLHuff;
	
	int size;

  LLNode *first;
	 LLNode *last;
        
public:
    
  
        
        
	LLPQ();
	~LLPQ();
	void printLLPQ();
	void addFirst(char c, string code);
	void addAtFirst(char c, string code);
	LLNode *remFirst();
	string findCode(char c);
	void sortLL();
	void insertUnique(char c);
	void insertInOrder(LLNode *n);
	void push(LLNode* n);
        void setSize(int s) ;
        int getSize() ;
        LLNode * getFirst()
        {
            return first ;
        }
};

#endif /* LLPQ_H */

