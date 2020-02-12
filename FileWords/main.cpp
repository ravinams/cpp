/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: oracle
 *
 * Created on February 18, 2018, 7:57 PM
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

void longestMethod(int a, vector<string> vec);

int main(int argc, char** argv) {
    string line;
    vector<string> myWords;
    ifstream myTextFile("myText.txt");
    bool quietMode = false, squishMode = false, censorMode = false, printStatsMode = false, lengthMode = false;

    //stores the lines in file to myWords and pushes it back
    while (getline(myTextFile, line)) {//get each line from the tect file and store each lines in string variable named line
        //cout<<line<<endl;
        myWords.push_back(line);
    }

    longestMethod(myWords.size(), myWords); //declaration of longestMethod passing myWords.vector size to the function and the name of the vector

    //outputs what's inside the vector
    for (int v = 0; v < myWords.size(); v++) //v represents the string's position in the vector. You can specify it, but most just represent it with one character maybe for space wise
    {
        string currentWord = myWords[v]; //the strings inside the array are now represented by the string variable word
        int length = currentWord.length(); //integer length that represents the length of the current string from the myWords vector

        string comment = "", whitespaceComment = "", wordComment = "", goodWordComment = "", realWordComment = "", capWordComment = "", acronymWordComment = ""; //string comments we will be using later
        int wspaceSpaceCounter = 0, wAlphaCounter = 0, wNumCounter = 0, wPunctCounter = 0, gAlnumCounter = 0, rAlphaCounter = 0, aAcronymCounter = 0; //contains all the counters we will be using



        //for whitespace---------------------------------------------------------------------------------------------------------
        for (int charPosition = 0; charPosition < currentWord.length(); charPosition++) //charNumber represents which character number from the string starting from its first letter = 0
        {
            char c = currentWord[charPosition];
            if (isspace(c) == true) {
                wspaceSpaceCounter += 1;
            }//if it has a space, it's not a word
            if (wspaceSpaceCounter > 0) {
                whitespaceComment = " a whitespace";
            }
        }


        //for word---------------------------------------------------------------------------------------------------------------
        for (int i = 0; i < length; i++)//sometimes programmers just use one letter; while i is less than the word's length; increment by 1
        {
            char c = currentWord[i];
            if (isalpha(c) == true) {
                wAlphaCounter += 1;
            }
            else if (ispunct(c) == true) {
                wPunctCounter += 1;
            } else if (isdigit(c) == true) {
                wNumCounter += 1;
            } //if it has punctuation, alphabet, digit then it is a word
            if (wAlphaCounter + wNumCounter + wPunctCounter == length) {
                wordComment = " a word";
            }
        }

        //for goodword-----------------------------------------------------------------------------------------------------------
        for (int i = 0; i < currentWord.length(); i++) //can also be represent with word.length. But I most programmers use length (creating a variable that represents the word's length) instead, for lesser calculations
        {
            char c = currentWord[i];
            if (isalnum(c) == true) {
                gAlnumCounter += 1;
            }
            if (gAlnumCounter == currentWord.length()) {
                goodWordComment = " a goodword";
            }
        }

        //for real word----------------------------------------------------------------------------------------------------------
        for (int i = 0; i < currentWord.length(); i++) {
            char c = currentWord[i];
            if (isalpha(c) == true) {
                rAlphaCounter += 1;
            }
            if (rAlphaCounter == currentWord.length()) {
                realWordComment = " a realword";
            }
        }

        //for capword------------------------------------------------------------------------------------------------------------
        for (int i = 0; i < 1; i++) // 1 < 1 because you only want to scan the first letter which is = to 0
        {
            char c = currentWord[i];
            if (isupper(c) == true) {
                capWordComment = " a capword";
            }
        }
        //for ACRONYMWORDS-------------------------------------------------------------------------------------------------------
        for (int v = 0; v < currentWord.length(); v++) //we are using v here to represent the charNumber, v was already use by this for-loop's parent-loop. This shows feel free to use the same one over and over in loops
        {
            char c = currentWord[v];
            if (isupper(c) == true) {
                aAcronymCounter += 1;
            }
            if (aAcronymCounter == length) {
                acronymWordComment = " an acronym";
            }
        }

        comment = "\tThis is" + wordComment + goodWordComment + realWordComment + capWordComment + acronymWordComment + whitespaceComment + ".";
        cout << "LINE" << v << ":" << currentWord << comment << endl;
        //cout<<"\t\t\twith length of:"<< length << endl;
    }



    return 0;
}




//method that returns the longest line inside a vector

void longestMethod(int a, vector<string> vec) {
    int size = vec.size();

    string longest;
    for (int a = 1; a < size; a++) {
        if (vec[a].size() > vec[a - 1].size()) {
            if (longest.empty()) {
                longest = vec[a];
            } else if (!longest.empty()) {
                if (vec[a].size() > longest.size()) {
                    longest = vec[a];
                } else if (vec[a].size() <= longest.size()) {
                    longest = longest;
                }
            }
        } else if (vec[a - 1].size() >= vec[a].size()) {
            if (longest.empty()) {
                longest = vec[a - 1];
            } else if (!longest.empty()) {
                if (vec[a - 1].size() >= longest.size()) {
                    longest = vec[a - 1];
                } else if (vec[a - 1].size() < longest.size()) {
                    longest = longest;
                }
            }
        }
    }
    cout << "The longest string is " << "\"" << longest << "\"" << "." << endl;
    //getchar();
}