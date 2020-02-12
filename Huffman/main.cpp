#include <stdio.h>
#include <iostream>
#include "LLNode.h"
#include "LLHuff.h"
using namespace std;
int main() {
cout << "reading file" << endl;
LLHuff code("tests.txt");
code.ReadFile();
code.pq->printLLPQ();
code.pq->sortLL();
code.pq->printLLPQ();
code.MakeHuff();
code.compressFile();
code.ReadAscii();
return 0;
}