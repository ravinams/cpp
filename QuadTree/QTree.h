/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QTree.h
 * Author: oracle
 *
 * Created on April 3, 2018, 10:17 PM
 */

#ifndef QTREE_H
#define QTREE_H

#include <vector>
#include "Point.h"
#include "BBox.h"
#include "QTNode.h"

class QTree {
public:
    QTree();
    ~QTree();
    bool add(const Point &pt, int data);  // actually, add/replace
    bool remove(const Point &pt);
    bool find(const Point &pt, int &data);
    int findPoints(const BBox &region, std::vector<Point> &found);
    void dump();

    QTNode *m_root;

private:

  

};

#endif /* QTREE_H */

