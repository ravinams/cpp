/*
        (name header)
 */

#include "BST.h"


// Definition function insert (non-recursive) 

void BST::insert(int insertItem) {

    Node *newNode = new Node;
    newNode->data = insertItem;
    newNode->llink = newNode->rlink = NULL;

    if (root == NULL) {
        root = newNode;
    } else {
        Node **current = &root;
        while (*current) {

            if (newNode->data == (*current)->data) {
                cout << "The item to insert is already in the list – duplicates are not allowed.";
                return;
            } else if (newNode->data < (*current)->data) {
                current = &(*current)->llink;
            } else {
                current = &(*current)->rlink;
            }
        }
        *current = newNode;
        newNode->llink = newNode->rlink = NULL;

    }




}

// Definition function totalNodes

int BST::totalNodes() {
    return totalNodes(root);
}

// Definition function totalNodes (recursive)

int BST::totalNodes(Node* &p) {
    if (p == nullptr)
        return 0;
    else if (p->llink != nullptr)
        return 1 + totalNodes(p->llink);
    else if (p->rlink != nullptr)
        return 1 + totalNodes(p->rlink);
}

// Definition overloaded function preorderTraversal

void BST::preorderTraversal() const {
    if (root == nullptr)
        cerr << "There is no tree.";
    else {
        inorderTraversal(root);
    }
}


// Definition overloaded function preorderTraversal (recursive)

void BST::preorderTraversal(const Node *p) const {
    if (p != nullptr) {
        /* first print data of node */
        cout << p->data << " ";

        /* then recur on left sutree */
        preorderTraversal(p->llink);

        /* now recur on right subtree */
        preorderTraversal(p->rlink);
    }
}

// Definition overloaded function postorderTraversal

void BST::postorderTraversal() const {
    if (root == nullptr)
        cerr << "There is no tree.";
    else {
        inorderTraversal(root);
    }
}
// Definition overloaded function postorderTraversal (recursive)

void BST::postorderTraversal(const Node *p) const {
    if (p != nullptr) {
        // first recur on left subtree 
        postorderTraversal(p->llink);

        // then recur on right subtree 
        postorderTraversal(p->rlink);

        // now deal with the node 
        cout << p->data << " ";
    }
}
