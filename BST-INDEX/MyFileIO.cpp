#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include "MyFileIO.h"

bool fileExists(std::string st)
{
	bool result;
	std::ifstream infile(st.c_str());
	result = infile.good();
	if (infile.is_open() == true)
	{
		infile.close();
	}
	return (result);
}

bool writefile(std::string filename, char *ptr, int length)
{
	bool result = false;
	std::ofstream outfile(filename.c_str(), std::ios::out | std::ios::binary);
	if (outfile.is_open() == true)
	{
		outfile.write(ptr, length);
		outfile.close();
		result = true;
	}
	return(result);
}
std::string nowtoString()
{
	time_t now = time(0);
	tm  tstruct;
	char buf[80];
//	localtime_s(&tstruct, &now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	std::string st(buf);
	return st;
}
int build_file_array(std::string st, int ptr, char data[])
{
	getChars(0, st.length(), data, ptr, st);
	return (ptr + st.length());
}
void getChars(int beginst, int endst, char data[], int ptr, std::string st)
{
	int i;
	for (i = 0; i < (endst - beginst); i++)
	{
		data[i + ptr] = st[beginst + i];
	}
}
std::string valueOf(int num)
{
	std::stringstream ss;
	ss << num;
	return(ss.str());
}
std::string getCRLF()
{
	std::string CRLF = "\x0D\x0A";
	return CRLF;
}
std::string getCode(int ptr, char data[])
{
	int code = 0;
	for (int i = 0; i < ptr; i++)
	{
		code = code + (int)data[i];
	}
	return (valueOf(code) + getCRLF());
}