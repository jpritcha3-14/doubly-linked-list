#ifndef __DLLIST_H_DEFINED__
#define __DLLIST_H_DEFINED__

#include "Node.h"

class DLList {

    Node* head;
    Node** pphead;

    public:
        DLList(int num);
        ~DLList();
        static Node* buildlist(int num); 
        static void deletelist(Node *l);
        void printVal(int val); 
        void appendVal(int val);
        void deleteVal(int val);
        void insertVal(int val, int idx);
        void printList();
};

#endif
