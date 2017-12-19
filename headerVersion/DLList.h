#ifndef __DLLIST_H_DEFINED__
#define __DLLIST_H_DEFINED__

#include "Node.h"

class DLList {

    Node* head;

    public:
        DLList(int num);
        ~DLList();
        static Node* buildlist(int num); 
        static void deletelist(Node *l);
        void printVal(int val); 
        void addVal(int val);
        void deleteVal(int val);
        void printlist();
};

#endif
