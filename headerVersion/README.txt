Implementation of a simple doubly linked list (DLL) data structure.  

The DLL is consists of a DLList class which holds the a pointer (and double pointer) to the head Node of the list, and the methods that can be performed on it.  Each Node is a simple structure object that stores a value and forward and backwards link pointers.

--Methods--
static Node* buildList(int num): Builds a DLL with num Nodes.  Each node has a value in the range [1, num].  Returns a pointer to the head node.

void printVal(int val): Prints whether or not the value is present in the DLL.

void appendVal(int val): Appends a value to the end of the DLL.

void insertVal(int val, int idx): Inserts val into the DLL at idx.  If val == 0, the head pointer is updated.  If val is greater than the length of the list, val is inserted at the end of the list.

void deleteval(int val): Deletes the first Node with val = val.  Updates head of list if necessary.

void printList(): Prints the values  in the DLL

