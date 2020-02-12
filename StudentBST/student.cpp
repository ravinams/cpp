#include <iostream>

#include "student.h"

using namespace std;

//Constructor for the student class
student::student()
{
	uniqueID = 0;
	GPA = 0;
}

student::student(string name, int uniqueID, float GPA)
{
    this->name = name;
    this->uniqueID = uniqueID;
    this->GPA = GPA;
}
student::~student()
{

}

void student::printStudent()
{
    cout << "Name : "<< name << endl;
	cout << "Unique ID : " << uniqueID << endl;
    cout << "GPA : " << GPA << endl;
}

string student::getName()
{
    return name;
}

float student::getGPA()
{
    return GPA;
}

bool student::operator<(student rhs)
{
    if (uniqueID < (rhs.uniqueID))
        return true;

    return false;
}

bool student::operator>(student rhs)
{
    if (uniqueID > (rhs.uniqueID))
        return true;

    return false;
}

bool student::operator==(student rhs)
{
    if (uniqueID == (rhs.uniqueID))
        return true;

    return false;
}  