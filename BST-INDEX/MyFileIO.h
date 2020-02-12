
#ifndef MYFILEIO_H
#define MYFILEIO_H

#include <string>

bool fileExists(std::string st);
bool writefile(std::string filename, char *ptr, int length);
std::string nowtoString();
void getChars(int beginst, int endst, char data[], int ptr, std::string st);
int build_file_array(std::string st, int ptr, char data[]);
std::string valueOf(int num);
std::string getCRLF();
std::string getCode(int ptr, char data[]);

#endif