#include "DLList.h"

int main() {
    DLList ll = DLList(4);
    ll.printList(); 
    ll.printVal(4);
    ll.printVal(11);
    ll.appendVal(5);
    ll.deleteVal(2);
    ll.insertVal(42, 0);
    ll.insertVal(69, 3);
    ll.insertVal(100, 100);
    ll.printList();
    ll.deleteVal(42);
    ll.deleteVal(100);
    ll.deleteVal(69);
    ll.printList();
    ll.deleteVal(69);
    
    return 0;
}
