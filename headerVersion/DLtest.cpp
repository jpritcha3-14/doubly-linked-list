#include "DLList.h"

int main() {
    DLList ll = DLList(4);
    ll.printVal(3);
    ll.addVal(5);
    ll.deleteVal(2);
    ll.printlist();
    return 0;
}
