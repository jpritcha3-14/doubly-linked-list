#include <stdio.h>
#include <iostream>
using namespace std;
 
struct list {
  int val;
  struct list *flink;
  struct list *blink;
};
 
struct list *buildlist(int num);
void printVal(list*, int);
void printlist(list*);
void deleteVal(list**, int);
void addVal(list**, int);
void deletelist(list*);
 
int main() {
 
  list *ll = buildlist(4);
  printVal(ll, 3);
  addVal(&ll, 5);
  deleteVal(&ll, 2);
  printlist(ll);
  deletelist(ll);
  return 0;
 
}
 
list* buildlist(int num) {
  list *headptr = new list;
  list *curptr = headptr;
  list *prevptr = NULL;
 
 
  for (int i = 1; i <= num; i++){
    //cout << i << endl;
    list* nextptr = new list;
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
 
void printVal(list *l, int val) {
  while (l != NULL) {
    if (l->val == val) {
      cout << l->val << endl;
      return;
    }
    l = l->flink;
  }
  cout << "no " << val << " found" << endl;
}
 
void addVal(struct list **l, int val) {
  list *c = *l;
  while (c->flink != NULL) {
    c = c->flink;
  }
    c->flink = new list;
    c->flink->val = val;
    c->flink->blink = c;
    c->flink->flink = NULL;
}
 
void deleteVal(struct list **l, int val) {
  list *c = *l;
  while (c != NULL && c->val != val) {
    c = c->flink;
  }
  c->flink->blink = c->blink;
  c->blink->flink = c->flink;
  delete c;
}
 
 
void printlist(list *l) {
  list *cur = l;
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
 
void deletelist(list *l) {
  list* prev = NULL;
  while (l != NULL) {
    prev = l;
    l = l->flink;
    delete prev;
  }
}
