/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   message.h
 * Author: oracle
 *
 * Created on March 17, 2018, 10:45 AM
 */

#ifndef MESSAGE_H
#define MESSAGE_H

#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

struct message {
    int messageNum;
    string codedMessage;
    string decodedMessage;
};

class Message {
private:
    int numOfMessages;
    message *messageArray;

public:
    Message(int n);
    ~Message();
    Message(const Message& rhs);
    void addMessage(int num, string codedMsg, string decodedMsg);
    void printMessagestoFIle(string filename);

};


#endif /* MESSAGE_H */

