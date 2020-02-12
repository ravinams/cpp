#include <iostream>
using namespace std;

class Node {
public:
    int m_data;
    Node *m_next;
};

Node *createNode(int val) {
    
    Node *newNode = new Node;
    newNode->m_data = val;
    newNode->m_next = NULL;
    
    return newNode;
}

Node *getListFromUser() {
    
    Node * head = NULL, *previous, *nxt;
    int cnt = -1;
    int val = 0;
    int myNums[1000];

    cout << "Enter numbers , 0 to stop\n";
    cin>>val;

    while (val != 0) {
        myNums[++cnt] = val;
        cin>>val;
    }

    if (cnt >= 0) {
        // create head node ;
        head = createNode(myNums[0]);
        
        // create other nodes if elements exists 
        previous = head;
        for (int i = 1; i <= cnt; i++) {
            nxt = createNode(myNums[i]);

            previous->m_next = nxt;

            previous = nxt;

        }
    }

    return head;
}

int main() {

    Node *head = NULL, *curr, *next;
    
    head = getListFromUser();
    
    next = head;

    while (next != NULL) {
        curr = next;
        cout << "Next #: " << curr->m_data << endl;
        next = curr->m_next;
        delete curr;

    }
    return 0;
}