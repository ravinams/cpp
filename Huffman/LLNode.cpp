#include "LLNode.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

LLNode::LLNode(char c) {
    data = c;
    next = NULL;
    prev = NULL;
    right = NULL;
    left = NULL;
    freq = 1;
}

LLNode::~LLNode() {

}

char LLNode::getData() {
    return data;
}

  void LLNode::setData(char d) 
  {
      data = d ;
  }

int LLNode::getFreq() {
    return freq;
}

void LLNode::setFreq(int f) {
    freq = f;
}

string LLNode::getCode() {
    return code;
}

void LLNode::setCode(string c)
{
    code = c ;
}