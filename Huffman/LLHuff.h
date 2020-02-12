/* 
 * File:   LLHuff.h
 * Author: oracle
 *
 * Created on October 22, 2018, 12:53 PM
 */

#ifndef LLHUFF_H
#define LLHUFF_H

#include <iostream>
#include <stdlib.h>
#include "LLNode.h"
#include "LLPQ.h"

using namespace std;

class LLHuff {
	//friend class LLPQnode;
	//friend class LLPQ;
	string file;
	LLNode *root;
	int size;
	
public:
	LLPQ *pq;
	LLPQ *ascii;
	LLHuff(string f);
	~LLHuff();
	void MakeHuff();
	void FindCode(LLNode *root, string path);
	void ReadFile();
	void compressFile();
	void ReadAscii();
};

#endif /* LLHUFF_H */

