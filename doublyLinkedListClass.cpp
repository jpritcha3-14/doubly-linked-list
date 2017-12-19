#include <stdio.h>
#include <iostream>
using namespace std;

struct Node {
    int val;
    struct Node *flink;
    struct Node *blink;
};

class DLList {
    struct Node *head;

    public:
        DLList(int num) {
            head = buildlist(num);
        }

        ~DLList() {
            deletelist(head);     
        }
        
        static Node* buildlist(int num) {
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

        static void deletelist(Node *l) {
            Node* prev = NULL;
            while (l != NULL) {
                prev = l;
                l = l->flink;
                delete prev;
            }
        }

        void printVal(int val) {
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

        void addVal(int val) {
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
         
        void deleteVal(int val) {
            //Node *c = *pphead;
            Node *c = head;
            while (c != NULL && c->val != val) {
                c = c->flink;
            }
            c->flink->blink = c->blink;
            c->blink->flink = c->flink;
            delete c;
        }
         
         
        void printlist() {
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
         

};
 
int main() {
    DLList ll = DLList(4);
    ll.printVal(3);
    ll.addVal(5);
    ll.deleteVal(2);
    ll.printlist();
    return 0;
}
 
