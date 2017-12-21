#include "DLList.h"
#include <iostream>
using namespace std;

// Constructor
DLList::DLList(int num) {
    head = DLList::buildlist(num);
    pphead = &head;
}

// Destructor
DLList::~DLList() {
    deletelist(*pphead);     
}

// Bilds a DLL with num elements with vals = [1,num]        
Node* DLList::buildlist(int num) {
    Node *headptr = new Node;
    Node *curptr = headptr;
    Node *prevptr = NULL;
         
    for (int i = 1; i <= num; i++){
        //cout << i << endl;
        Node* nextptr = new Node;
        curptr->val = i;
        curptr->flink = nextptr;
        curptr->blink = prevptr;
        if (i==num) {
            curptr->flink = NULL;
            delete nextptr;
        } else {
            prevptr = curptr;
            curptr = nextptr;
        }
    }
    return headptr;
}

// Deletes Nodes starting with l from from heap memory
void DLList::deletelist(Node *l) {
    Node* prev = NULL;
    while (l != NULL) {
        prev = l;
        l = l->flink;
        delete prev;
    }
}

// Prints a val if a node with that val is present in the DLL
void DLList::printVal(int val) {
    Node *l = *pphead;
    int idx = 0;
    while (l != NULL) {
        if (l->val == val) {
            cout << "Found " << l->val << " at index " << idx << endl;
            return;
        }
        idx++;
        l = l->flink;
    }
    cout << "No " << val << " found in DLL" << endl;
}

// Appends a node with val == val to the end of the DLL 
void DLList::appendVal(int val) {
    Node *c = *pphead;
    //Node *c = head;
    while (c->flink != NULL) {
        c = c->flink;
    }
    c->flink = new Node;
    c->flink->val = val;
    c->flink->blink = c;
    c->flink->flink = NULL;
}
         

// Deletes a node with val == val if it is present in the DLL
void DLList::deleteVal(int val) {
    Node *c = *pphead;
    //Node *c = head;
    while (c->val != val) {
        c = c->flink;
        if (c == NULL) {
            cout << val << " is not in DLL!" << endl;
            return; 
        }
    }
    if (c->flink != NULL) {
        c->flink->blink = c->blink;
    }
    if (c->blink != NULL) {
        c->blink->flink = c->flink;
    } else {
        *pphead = c->flink; //Update head if first node deleted
    }
    delete c;
}

// Inserts val at idx, if idx > length of DLL, appends val to end of DLL
void DLList::insertVal(int val, int idx) {
    Node* newNode = new Node;
    newNode->val = val;

    if (idx == 0) {
        newNode->flink = *pphead;
        newNode->blink = NULL;
        (*pphead)->blink = newNode;
        *pphead = newNode; // Update head pointer
    } else {
        int loc = 1;
        Node* cur = *pphead;
        while (loc < idx) {
            if (cur->flink == NULL) {
                break;
            }
            cur = cur->flink; 
            ++loc;
        }
        newNode->blink = cur;
        newNode->flink = cur->flink;
        cur->flink = newNode;
    }
}
         
         
// Prints all values in DLL
void DLList::printList() {
    //Node* cur = head;
    Node* cur = *pphead;
    cout << "NULL <- ";
    while (cur != NULL) {
        if (cur->flink == NULL) {
            cout << "{" << cur->val << "} -> NULL\n";
            cur = cur->flink;
        } else {
            cout << "{" << cur->val << "} <-> ";
            cur = cur->flink;
        }
    }
}
