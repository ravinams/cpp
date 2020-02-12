#define _CRT_SECURE_NO_WARNINGS

#include<cstring>
#include<fstream>
#include<iostream>
#include<string>
#include<queue>
using namespace std;

#include"DynamicArray.h"
#include"StaticArray.h"
#include"AssociativeArray.h"


string check_term_duplication(const string, const AssociativeArray<string, bool> &, int);
bool check_section_duplication(const string, const AssociativeArray<string, bool> &);
DynamicArray<string> outputSortedArray(DynamicArray<string>, queue <string>);


int main()
{
	AssociativeArray <string, int> sectionCount;
	AssociativeArray <string, int> subjectCount;
	AssociativeArray <string, AssociativeArray<string, int> > count;
	AssociativeArray <string, AssociativeArray<string, bool> > alreadySeen;
	AssociativeArray <string, int> alreadySeenCourses;
	AssociativeArray <string, bool> alreadySeenSubject;
	AssociativeArray <string, bool> alreadySeenCourse;


	int i = 0;
	int duplicates = 0;
	int numberOfTermSeen = 0;
	int subjectIndex = 0;
	int loading = 0;
	int numberOfSections = 0;

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

		if (loading % 1000 == 0)
		{
			cout << '.';
			cout.flush();
		}


		/*bool found = false;
		string term_index = check_term_duplication(term, alreadySeen[term]); // check if term is already in alreadyseen array
		if (term_index != "null")  // if term was not in alreadyseen array
		{
			found = check_section_duplication(section, alreadySeen[term_index]);  // found equals the result of check_section_dupliation array

			if (!found)  // if section was not in already seen array
			{
				//alreadySeen[term_index][section] = section; // if 
			}
		}*/
		/*else
		{
			alreadySeen[alreadySeen[term].size()] = term;  // assign alreadyseen term to term
			alreadySeen[alreadySeen[term].size()].numberOfSectionsSeen = 1;  //
			alreadySeen[alreadySeen[term].size()].seenSectionNumber[0] = section;  // first section number of alreadyseen array assigned to section
			numberOfTermSeen++;
		}*/



		//===========================================
		//Count Subject
		//===========================================
		if (alreadySeenSubject[subjectCode] == true)
		{
			if (alreadySeenCourse[course] != true)
			{
				sectionCount[course]++;
				alreadySeenCourse[course] = true;
				subjectCount[subjectCode]++;
			}
		}
		else
		{
			alreadySeenSubject[subjectCode] = true;
		}


		//===================================
		//Duplication check
		//===================================
		if (alreadySeen[term][section])
			duplicates++;
		else
		{
			alreadySeen[term][section] = true;
			count[subjectCode][course]++;
		}

	}

	//=============================================================================================
	//sort the output
	//=============================================================================================
	queue<string> subKeys = count.keys(); //use this queue to sort the subjectCode

	DynamicArray<string> subjectArray;
	DynamicArray<string> sortedArray;

	//Nested for loop sort
	/*for (int i = 0; i < subKeys.size(); i++)
	{
		cout << subjectArray[i] << ", " << count[subjectArray[i]].size() << " courses"; //number of courses

		queue<string> courseKeys = count[subjectArray[i]].keys;

		DynamicArray<string> courseArray = outputSortedArray(courseKeys);

		for (int j = 0; j < count[subjectArray[i]].size(); j++)
		{
			cout << courseArray[j] << ", " << count[subjectArray[i]][courseArray[j]];
		}
	}*/
	//=================================================================
	//output
	//=================================================================
	cout << "\nDuplication: " << duplicates << endl;
	cout << sectionCount["COMSC-090"] << endl;
	cout << "COMSC, " << subjectCount["COMSC"] << " course(s)" << endl;
}

string check_term_duplication(const string term, const AssociativeArray<string, bool>& classArray)
{
	string term_index = "null";  //default 
	if(classArray.containsKey(term) == true)  //if alreadyseen array contains term 
	{
		term_index = term;                    //set term_index = term
	}
	return term_index;
}


bool check_section_duplication(const string section, const AssociativeArray<string, bool>& termArray)
{
  bool found = false;
  if(termArray.containsKey(section) == true)
  {
	  found = true;
  }
  return found;
}

/*DynamicArray<string> outputSortedArray(DynamicArray<string> sortedArray, queue <string> keys)  //pass subKeys into keys
{
	//Convert queue into array
	for (int i = 0; i < subKeys.size(); i++)
	{
		subjectArray[i] = subKeys.front();
		subKeys.pop();
	}

	// sort array


}*/