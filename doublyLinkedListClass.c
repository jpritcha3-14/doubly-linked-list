#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int val;
    struct Node *flink;
    struct Node *blink;
} Node;

// Class definition
typedef struct DLList {
    struct Node *head;
    struct Node **pphead;
    void (**vtable)(struct Node **node, int val);
} DLList;

// Method Declariations
void print_Val(struct Node **pphead, int val) {
    struct Node *l = *pphead;
    //struct Node *l = head;
    while (l != NULL) {
        if (l->val == val) {
            printf("%d\n", l->val); 
            return;
        }
        l = l->flink;
    }
    printf("No %d Found\n", val);
}

void add_Val(struct Node **pphead, int val) {
    struct Node *c = *pphead;
    //struct Node *c = head;
    while (c->flink != NULL) {
        c = c->flink;
    }
    c->flink = (struct Node*)malloc(sizeof(Node));
    c->flink->val = val;
    c->flink->blink = c;
    c->flink->flink = NULL;
}

void delete_Val(struct Node **pphead, int val) {
    struct Node *c = *pphead;
    //Node *c = head;
    while (c->val != val) {
        c = c->flink;
        if (c == NULL) {
            printf("%d is not in DLL!\n", c->val); 
            return;
        }
    }
    if (c->flink != NULL) {
        c->flink->blink = c->blink; 
    }
    if (c->blink != NULL) {
        c->blink->flink = c->flink; 
    } else {
        *pphead = c->flink;
    }
    free(c);
}

void print_List(struct Node **pphead) {
    Node *cur = *pphead;
    //Node *cur = head;
    printf("NULL <- ");
    while (cur != NULL) {
        if (cur->flink == NULL) {
            printf("{%d} -> NULL\n", cur->val);
            cur = cur->flink;
        } else {
            printf("{%d} <-> ", cur->val);
            cur = cur->flink;
        }
    }
}

void delete_List(struct Node **pphead) {
    Node* prev = NULL;
    Node* cur = *pphead;
    while (cur != NULL) {
        prev = cur;
        cur = cur->flink;
        free(prev);
    }
}

// Declare the vtable as an array of pointers to functions that return void* pointers
void (*DLLVTable[])() = {&print_Val, &add_Val, &delete_Val, &print_List, &delete_List};

// Wrapper functions for calling object methods from their vtable
enum {call_print, call_add, call_delete, call_printList, call_deleteList};
void printVal(DLList* obj, int val) {
    obj->vtable[call_print](obj->pphead, val);
}
void addVal(DLList* obj, int val) {
    obj->vtable[call_add](obj->pphead, val);
}
void deleteVal(DLList* obj, int val) {
    obj->vtable[call_delete](obj->pphead, val);
}
void printList(DLList* obj, int val) {
    obj->vtable[call_printList](obj->pphead, val);
}
void deleteList(DLList* obj, int val) {
    obj->vtable[call_deleteList](obj->pphead, val);
}

Node* buildList(int num) {
    Node *headptr = (Node*)malloc(sizeof(Node));
    Node *curptr = headptr;
    Node *prevptr = NULL;
     
    for (int i = 1; i <= num; i++) {
         Node* nextptr = (Node*)malloc(sizeof(Node));
         curptr->val = i;
         curptr->flink = nextptr;
         curptr->blink = prevptr;
         if (i==num) {
             curptr->flink = NULL;
             free(nextptr);
        } else {
             prevptr = curptr;
             curptr = nextptr;
        }
    }
    return headptr;
}

// DLL constructor
DLList* newDLL(int num) {
    DLList* obj = (DLList*)malloc(sizeof(DLList));
    obj->vtable = DLLVTable;
    obj->head = buildList(num); 
    obj->pphead = &(obj->head);
    return obj;
}

int main() {
    DLList* ll = newDLL(4);
    printList(ll, 0); //1
    printVal(ll, 3);
    addVal(ll, 5);
    printList(ll, 0); //2
    deleteVal(ll, 2);
    printList(ll, 0); //3
    deleteVal(ll, 1);
    printList(ll, 0); //4
    deleteList(ll, 0);
    free(ll);
    return 0;
}
