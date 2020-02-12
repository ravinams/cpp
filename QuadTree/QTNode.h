#ifndef QTNODE_H
#define QTNODE_H

#include <vector>
#include "Point.h"
#include "BBox.h"

#define QT_NUM_KIDS 4


class QTNode {
public:
    class iterator {
    public:
	iterator();
	bool operator==(const QTNode::iterator &other);
	bool operator!=(const QTNode::iterator &other);
	iterator &operator++();          // Prefix: e.g. "++it"
	iterator operator++(int dummy);  // Postfix: "it++"
	QTNode *&operator*();

    private:
	const QTNode* m_pCurrentNode;

    };

    QTNode();
    QTNode(BBox &region) ;
    ~QTNode();
    bool add(const Point &pt, int data);  // actually, add/replace
    bool remove(const Point &pt, bool &empty);
    bool find(const Point &pt, int &data);
    int findPoints(const BBox &region, std::vector<Point> &found);
    void dump();

    iterator begin();
    iterator end();

    BBox m_bounds;  // The bounding box for this node
    Point m_point;  // If leaf node (i.e., no kids), m_point, m_data hold the
    int m_data;     // actual point and data value the user inserted.
    // YOu must add data member(s) to store pointers to child QTNode's

    // Children of this tree
    
    QTNode *botLeft = NULL;
    QTNode *botRight = NULL;
    QTNode *topLeft = NULL;
    QTNode *topRight = NULL;
    
private : 
    
   
    
    bool isLeaf() ;
    void subdivide() ; // this will divide the current leaf node into INTERNAL node and add 4 child nodes
    void merge() ; // if the current node has only one LEAF node , then it will delete that LEAF node and convert current into LEAF node .
    int childrenCount() ;
   
    
    //
    // YOU CAN ADD ANY OTHER CONSTRUCTORS, MEMBER FUNCTIONS, MEMBER DATA, ETC.
    // AS NEEDED.
    //

};
#endif /* QTNODE_H */

