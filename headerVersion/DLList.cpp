#include "DLList.h"
#include <iostream>
using namespace std;

DLList::DLList(int num) {
    head = DLList::buildlist(num);
}

DLList::~DLList() {
    deletelist(head);     
}
        
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

void DLList::deletelist(Node *l) {
    Node* prev = NULL;
    while (l != NULL) {
        prev = l;
        l = l->flink;
        delete prev;
    }
}

void DLList::printVal(int val) {
    Node *l = head;
    while (l != NULL) {
        if (l->val == val) {
            cout << l->val << endl;
            return;
        }
        l = l->flink;
    }
    cout << "no " << val << " found" << endl;
}

void DLList::addVal(int val) {
    //Node *c = *pphead;
    Node *c = head;
    while (c->flink != NULL) {
        c = c->flink;
    }
    c->flink = new Node;
    c->flink->val = val;
    c->flink->blink = c;
    c->flink->flink = NULL;
}
         
void DLList::deleteVal(int val) {
    //Node *c = *pphead;
    Node *c = head;
    while (c != NULL && c->val != val) {
        c = c->flink;
    }
    c->flink->blink = c->blink;
    c->blink->flink = c->flink;
    delete c;
}
         
         
void DLList::printlist() {
    Node *cur = head;
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
