/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <vector>
#include <cstring>
#include "PostFixTokens.h"

using namespace std;

PostFixTokens::PostFixTokens() {

}

PostFixTokens::PostFixTokens(vector<string> inFix) {

    inFixTokens.clear();

    for (int i = 0; i < inFix.size(); i++)
        inFixTokens.push_back(inFix[i]);

    inFixTokens = inFix;
}

PostFixTokens::~PostFixTokens() {
    inFixTokens.clear();
    postFixTokens.clear();
}

vector<string> PostFixTokens::getPostFixTokens() {
    return postFixTokens;
}

vector<string> PostFixTokens::getInFixTokens() {
    return inFixTokens;
}

void PostFixTokens::setInFixTokens(vector<string> inFix) {

    inFixTokens.clear();

    for (int i = 0; i < inFix.size(); i++)
        inFixTokens.push_back(inFix[i]);

}

void PostFixTokens::printPostFix() {

    for (int i = 0; i < inFixTokens.size(); i++)
        cout << inFixTokens[i] << " ";
}

void PostFixTokens::printInFix() {

    for (int i = 0; i < postFixTokens.size(); i++)
        cout << postFixTokens[i] << " ";

}

void PostFixTokens::createPostFix() {
    
    postFixTokens.clear();
    
    std::stack<char> operators; 
    string expression; 
    
    for (int i = 0; i < inFixTokens.size(); i++)
    {
        
    }
    
}

