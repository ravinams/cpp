/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DNode.h
 * Author: oracle
 *
 * Created on March 7, 2018, 10:08 PM
 */

#ifndef DNODE_H
#define DNODE_H

#include "Int341.h"

class DNode {
private:

public:

    Int341 m_data;
    DNode *m_next;

    DNode(Int341 data);
    ~DNode();

};

#endif /* DNODE_H */

