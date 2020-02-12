#include <cstdlib>
#include <fstream>
#include <cstring>
#include <iostream>
#include <sstream>
#include "message.h"

using namespace std;


char cArray[26];

string decode(string encodedMsg) {

    string decodedMsg;

    for (int i = 0; i < encodedMsg.length(); i++) {

        decodedMsg = decodedMsg + ((encodedMsg[i] < 65 || encodedMsg[i] > 90) ? encodedMsg[i] : cArray[encodedMsg[i] - 65]);
    }

    return decodedMsg;
}
/**
int main(int argc, char** argv) {

    string inputFile;
    ifstream ifs;

    cout << "\nPlease enter the input file name with its extension : ";
    cin>>inputFile;


    ifs.open(inputFile.c_str(), ios_base::in);
    if (ifs.fail()) {
        cout << "Input File unable to open.";
        exit(1);
    }

    string line = "";
    int lineIndex = 0, numOfMessages;
    char source, target, dummy;
    stringstream ss;

    while (getline(ifs, line)) {
        ++lineIndex;

        ss.str(line);

        if (lineIndex <= 26) {

            ss >> source >> dummy>>target;
            // cout << source - 65 << source << dummy << target << endl;
            cArray[source - 65] = target;
        }
        if (lineIndex == 27) {
            ss >> numOfMessages;
            //   cout << numOfMessages << endl;
            break; // stop reading the file  
        }
    }


    Message msgs(numOfMessages);

    //continue reading messages ;
    int msgIndx = 0;
    while (getline(ifs, line)) {

        msgs.addMessage(msgIndx, line, decode(line));
        msgIndx++;
    }

    //print messages 
    msgs.printMessagestoFIle("out.txt");

    ifs.close();

    return 0;
}

*/

