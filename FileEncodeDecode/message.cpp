#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "message.h"

using namespace std;

Message::Message(int n) {

    numOfMessages = n;
    messageArray = new message[numOfMessages];


}

Message::~Message() {
    // delete messageArray;
}

Message::Message(const Message& rhs) {
    numOfMessages = rhs.numOfMessages;
    messageArray = new message[numOfMessages];
    addMessage(rhs.messageArray->messageNum - 1, rhs.messageArray->codedMessage, rhs.messageArray->decodedMessage);
}

void Message::addMessage(int num, string codedMsg, string decodedMsg) {

    messageArray[num].messageNum = num + 1;
    messageArray[num].codedMessage = codedMsg;
    messageArray[num].decodedMessage = decodedMsg;


}

void Message::printMessagestoFIle(string filename) {

    ofstream ofs;
    ofs.open(filename.c_str(), ofstream::out);



    for (int k = 0; k < numOfMessages; k++) {

        ofs << "Message Num: " << messageArray[k].messageNum << endl;
        ofs << "Coded Message" << endl << messageArray[k].codedMessage << endl;
        ofs << "Decoded Message" << endl << messageArray[k].decodedMessage << endl;
    }

    ofs.close();

}