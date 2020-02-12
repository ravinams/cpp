/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stdexcept>
#include<sstream>

#include "INode.h"
#include "DNode.h"
#include "Int341.h"
#include "SqList.h"

using namespace std;

SqList::SqList() {
    m_iList.clear();
}

SqList::~SqList() {

    for (list<INode>::iterator m_list_iter = m_iList.begin(); m_list_iter != m_iList.end(); ++m_list_iter) {

        DNode *temp, *current = m_list_iter->findAt(0);
        while (current != NULL) {
            temp = current->m_next;
            delete current;
            current = temp;
        }

    }
}

SqList::SqList(const SqList & other) {


    m_iList = other.m_iList;
    copy(other.m_iList.begin(), other.m_iList.end(), m_iList.begin());


}

const SqList & SqList::operator=(const SqList & rhs) {

    if (this != &rhs) {
        if (!m_iList.empty()) {
            m_iList.erase(m_iList.begin(), m_iList.end());
        }
        m_iList = rhs.m_iList;
    }
    return *this;

}

void SqList::add(const Int341 & data) {

    // cout << "adding " << data.m_data << " ";

    // Initializing list iterator
    if (m_iList.size() == 0) { // first create INode and insert into list

        INode iNode;
        iNode.add(data);
        m_iList.push_front(iNode);

    } else if (m_iList.size() == 1) { // there is only one INode, then simply add it 

        //   cout << "adding " << data.m_data << " List 0 ";

        m_iList.begin()->add(data);

    }//  else if (m_iList.begin()->findAtPos(0) > data) { // if the new element is less than start element , then insert in first list only
        //
        //         cout<<"adding "<<data.m_data<<" List 0 " ;
        //         
        //        m_iList.begin()->add(data);

        //    }

    else { //expectation is atleast 2 inner lists will available

        //  cout << "adding " << data.m_data << " 1st onwardss ";

        std::list<INode>::iterator it = m_iList.begin();
        std::list<INode>::iterator next_it = ++it;
        int idx = 1;
        while (next_it != m_iList.end()) {

            if (next_it->findAt(0)->m_data >= data) {
                it->add(data);
            }

            it = next_it;

            ++next_it;

            //  cout << "adding " << data.m_data << " List =" + idx++;
        }

        //Last list
        if (next_it->findAt(0)->m_data < data) {
            next_it->add(data);
            //  cout << "adding " << data.m_data << " last list ";
        }
    }

    //            consolidate();
}

Int341 SqList::remove(const Int341 & data) {

    Int341 result;

    if (m_iList.size() == 0) {

        throw overflow_error("SqList.118 - Error : Square list is Empty");

    } else if (m_iList.size() == 1) {

        result = m_iList.begin()->remove(data);

        if (m_iList.begin()->numItems() == 0) {
            m_iList.erase(m_iList.begin());
        }

    } else {

        list<INode>::iterator it = m_iList.begin(), next_it = m_iList.begin();
        std::advance(next_it, 1); // 2nd iNode 

        for (; next_it != m_iList.end(); ++next_it, ++it) {

            if (next_it->findAtPos(0) == data) {

                result = (next_it)->remove(data);

                if (next_it->numItems() == 0) {
                    m_iList.erase(next_it);
                }
                return result ;
            }
            else if (next_it->findAtPos(0) > data)
            {
                
                result = (it)->remove(data);

                if (it->numItems() == 0) {
                    m_iList.erase(it);
                }
                return result ;
            }
            if (next_it == --m_iList.end())
              return next_it->remove(data);
        }

    }

}

Int341 SqList::removeAt(int pos) {


    Int341 result;
    if (pos < 0 || pos >= numItems()) {

        throw out_of_range("SqList:121 - Error : pos is not valid");
    }

    if (numItems() == 0) { // List is empty 

        throw overflow_error("SqList:127 - rror : Square list is Empty");

    } else if (pos < m_iList.begin()->numItems()) { // first iNode

        cout << " first iNode SqList.removeAt = " << pos;


        result = m_iList.begin()->removeAt(pos);

        if (m_iList.begin()->numItems() == 0) {
            m_iList.erase(m_iList.begin());
        }

    } else {

        cout << " second iNode SqList.removeAt = " << pos << endl;

        list<INode>::iterator m_list_iter = ++m_iList.begin(); //second iNode onwards 
        int relativeSize = m_iList.begin()->numItems();
        for (; m_list_iter != m_iList.end(); ++m_list_iter) {

          

            if ( pos < relativeSize ) {
               
                   cout<<"pos = "<< pos <<" previousNodesSize = "<<relativeSize<<" (pos - previousNodesSize) = "<<pos - relativeSize<<endl ;

                result = m_list_iter->removeAt(pos - (relativeSize-1) );

                if (m_list_iter->numItems() == 0) {
                    m_iList.erase(m_list_iter);
                }
                return result;

            } else
                relativeSize = relativeSize + (m_list_iter->numItems());
        }

    }
}

Int341 & SqList::operator[](int pos) {

    if (pos < 0 || pos >= numItems()) {
        throw out_of_range("SqList.184 - Error : pos is not valid");
    }

    if (numItems() == 0) { // List is empty 

        throw overflow_error("Error : Square list is Empty");

    } else if (pos == 0) { // first position

        return m_iList.begin()->findAtPos(0);

    } else {

        list<INode>::iterator m_list_iter = m_iList.begin();
        int allNodeSize = 0;
        int currentNodeSize = 0;
        for (; m_list_iter != m_iList.end(); ++m_list_iter) {
            currentNodeSize = m_list_iter->numItems() - 1;
            if (pos <= allNodeSize + currentNodeSize) {
                return m_list_iter->findAtPos(pos - allNodeSize);
            } else {
                allNodeSize = allNodeSize + currentNodeSize;
            }
        }

        return m_iList.end()->findAtPos(pos - allNodeSize);

    }

}

int SqList::indexOf(const Int341 & data) {

    if (numItems() == 0) {

        throw overflow_error("Error : Square list is Empty");

    } else if (m_iList.size() == 1) {

        return m_iList.begin()->indexOf(data);

    } else {
        list<INode>::iterator m_list_iter = m_iList.begin();
        int allNodeSize = m_list_iter->numItems() - 1;
        int relIdex = -1;
        advance(m_list_iter, 1); //start from second iterator

        for (; m_list_iter != m_iList.end(); ++m_list_iter) {
            if (m_list_iter->findAtPos(0) <= data) {
                relIdex = (--m_list_iter)->indexOf(data);

            }
            allNodeSize = allNodeSize + m_list_iter->numItems() - 1;
        }

        return allNodeSize + relIdex;
    }

}

int SqList::numItems() {
    int tot = 0;
    for (list<INode>::iterator m_list_iter = m_iList.begin(); m_list_iter != m_iList.end(); ++m_list_iter) {
        tot = tot + m_list_iter->numItems();
    }
    return tot;
}

void SqList::dump() {
    cout << "----- SqList dump() -----" << endl;
    cout << "number of items = " << numItems() << endl;
    cout << "-------------------------" << endl;


    list<INode>::iterator m_list_iter = m_iList.begin();
    int i = 0;
    for (; m_list_iter != m_iList.end(); ++m_list_iter) {
        cout << i++ << " ";
        m_list_iter->dump();
        cout << endl;
    }
}

void SqList::consolidate() {
    /*
     * 
     * 1). too short ..4*(currSize+1)*(currSize+1) <= n 
     * 2). too long  .. (currSize-1)*(currSize-1) > 4*n  
     * 
     */

    DNode *dp, *end_dp;

    int prevSize, currSize, newSize;
    bool prevIsShort = false;
    bool currIsShort;
    int prevVal;

    int index = 0;

    int n = numItems();

    list<INode>::iterator it, next_it;
    for (it = m_iList.begin(); it != m_iList.end(); it++, index++) {


        currSize = it->numItems();
        next_it = it;


        if (currSize == 0) //remove the empty list 
        {
            m_iList.erase(it);
        } else if ((currSize - 1)*(currSize - 1) > 4 * n) // too long
        {
            //            cout<<" BEFORE  "<<endl ;  
            //            it->dump() ;

            newSize = currSize / 2;

            dp = it->findAt(newSize);
            it->setSize(newSize);

            //  cout << "SPLIT, currSize , newSize " << index << " ," << currSize << "," << newSize << " , " << dp->m_data.m_data << endl;

            INode newINode;
            newINode.m_dNode = dp;
            newINode.setSize(newSize);

            //            cout<<" AFTER  "<<endl ;  
            //            it->dump() ;
            //            newINode.dump() ;

            //          //  cout << " setting new size  ";

            //          //  cout << " inserting ";

            if (m_iList.size() == 1)
                m_iList.push_back(newINode);
            else
                m_iList.insert(++next_it, newINode);
            //          



            advance(it, -1); //ignore next list since it is NEWLY created .

        } else if (4 * (currSize + 1)*(currSize + 1) <= n) // too short 
        {

        }

    }

}