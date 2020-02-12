/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<cstdlib>
#include "Int341.h"
#include "DNode.h"
using namespace std;

DNode::DNode(Int341 data) {
    m_data = data;
    m_next = NULL ;
}

DNode::~DNode() {

}

