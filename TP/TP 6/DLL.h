#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct  elmtList *address;
typedef struct lagu infotype;

struct lagu {
    string nama;
    string band;
};

struct elmtList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

bool isEmpty_103032300101(List l);
void createList_103032300101(List &l);
address createNewElmnt_103032300101(infotype x);
void insertFirst_103032300101(List &l, address p);
void insertAfter_103032300101(List &l, address &p, address &prec);
void insertLast_103032300101(List &l, address p);
void deleteFirst_103032300101(List &l, address &p);
void deleteAfter_103032300101(List &l, address &p, address &prec);
void deleteLast_103032300101(List &l, address &p);
void concat_103032300101(List l1, List l2, List &l3);
address findLagu_103032300101(string judul, List l);
void removeLagu_103032300101(string judul, List &l);
void show_103032300101(List l);

#endif // DLL_H_INCLUDED
