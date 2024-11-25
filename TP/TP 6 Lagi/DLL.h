#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED
#include <iostream>
using namespace std;
typedef struct elmlist *address;
struct infotype {
    string judul;
    string penyanyi;
};
struct elmlist{
    infotype info;
    address prev;
    address next;
};
struct List{
    address first;
    address last;
};
void createNewList_103032300101(List&L);
bool isEmpty_103032300101(List L);
address createNewElmt_103032300101(infotype X);
void insertFirst_103032300101(List &L, address P);
void insertAfter_103032300101(List &L, address &prec, address P);
void insertLast_103032300101(List &L, address p);
void deleteFirst_103032300101(List &L, address &P);
void deleteAfter_103032300101(List &L, address prec, address &P);
void deleteLast_103032300101(List &L, address &P);
void concat_103032300101(List L1, List L2, List &L3);
address findLagu_103032300101(List L, string Judul);
void removeLagu_103032300101(List &L, string Judul);
void show_103032300101(List L);
#endif // DLL_H_INCLUDED
