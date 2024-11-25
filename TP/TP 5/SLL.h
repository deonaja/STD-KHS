#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct elm *address;
typedef int infotype;

struct elm {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList_103032300101(List &l);
address newElm_103032300101(infotype x);
void insertLast_103032300101(List &l, address p);
void showAllData_103032300101(List l);
address findMin_103032300101(List l);
void insertMiddle_103032300101(List &l, int value);
void menu_103032300101(int &p);
address searchX(List l, int x);
address deleteBetween(List l, address p, address q);


#endif // SLL_H_INCLUDED
