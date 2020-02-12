#include<cstring>
#include<fstream>
#include<iostream>
#include<string>

#include"DynamicArray.h"
#include"StaticArray.h"
using namespace std;

//Structs
struct SectionsForTerm
{
  string term;
  int numberOfSectionsSeen;
  DynamicArray<string> seenSectionNumber;
};

struct subject
{
  string subjectCode;
  int count;
};

int check_term_duplication(const string, const StaticArray<SectionsForTerm,200>&, int);

bool check_section_duplication(const string, const SectionsForTerm&);

int main()
{
  StaticArray<SectionsForTerm,200> alreadySeen;
  DynamicArray<subject> subjectCount(100);
  int count = 0;
  int duplicates = 0;
  int numberOfTermSeen = 0;
  int subjectIndex = 0;
  int loading = 0;

  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";

  // open the input file
  ifstream fin;
  fin.open("schedule.txt");
  if (!fin.good()) throw "I/O error";

  // read the input file
  while (fin.good())
  {
    // read the line
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());

    if (buf[0] == 0) continue; // skip blank lines

    //parse the line
    const string term(token = strtok(buf, tab));
    const string section((token = strtok(0, tab)) ? token : "");
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line: no dash in course name
    const string subjectCode(course.begin(), course.begin() + course.find('-'));
    loading++;

    if(loading%1000 == 0)
    {
      cout <<'.';
      cout.flush();
    }

    bool found = false;
    int term_index = check_term_duplication(term, alreadySeen, numberOfTermSeen);
    if(term_index != -1)
    {
      found = check_section_duplication(section,alreadySeen[term_index]);

      if(!found)
      {
        alreadySeen[term_index].seenSectionNumber[alreadySeen[term_index].numberOfSectionsSeen++] = section;
      }
    }
    else
    {
      alreadySeen[numberOfTermSeen].term = term;
      alreadySeen[numberOfTermSeen].numberOfSectionsSeen = 1;
      alreadySeen[numberOfTermSeen].seenSectionNumber[0] = section;
      numberOfTermSeen++;
    }

    if(!found)
    for(int i = 0; i < subjectIndex; i++)
    {
      if(subjectCount[i].subjectCode.compare(subjectCode) == 0)
      {
        found = true;
        subjectCount[i].count++;
        break;
      }
    }
    else
      duplicates++;
    if(!found)
    {
      subjectCount[subjectIndex].subjectCode = subjectCode;
      subjectCount[subjectIndex].count = 1;
      subjectIndex++;
    }
    count++;
  }
  for(int i =0; i < subjectIndex;i++)
	{
	  for(int j = 0; j< subjectIndex;j++)
	  {
	    if(subjectCount[i].subjectCode < subjectCount[j].subjectCode)
		    swap(subjectCount[i], subjectCount[j]);
	  }
  }
  for(int i = 0; i <subjectIndex;i++)
  {
    cout << endl;
    cout << subjectCount[i].subjectCode << ", ";
    cout << subjectCount[i].count << " sections\n";
  }
  cout << duplicates;
  fin.close();
}

int check_term_duplication(const string term,const StaticArray<SectionsForTerm,200>& classArray, int size)
{
  int term_index = -1;
  for(int i = 0;i< size;i++)
  {
    if(classArray[i].term == term)
    {
      term_index = i;
      break;
    }
  }
  return term_index;
}

bool check_section_duplication(const string section, const SectionsForTerm& termArray)
{
  bool found = false;
  for(int i = 0; i < termArray.numberOfSectionsSeen; i++)
  {
    if(termArray.seenSectionNumber[i] == section)
    {
      found = true;
      break;
    }
  }
  return found;
}