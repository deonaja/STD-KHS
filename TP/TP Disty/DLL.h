#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED
#include <iostream>
using namespace std;
struct infotype{
    string judul;
    string penyanyi;
};
typedef struct elmlist *address;
struct elmlist{
    infotype info;
    address prev;
    address next;
};
struct List{
    address first;
    address last;
};
void createNewList_103032300015(List &L);
bool isEmpty_103032300015(List L);
address createNewElmt_103032300015(infotype Y);
void insertFirst_103032300015(List &L, address P);
void insertAfter_103032300015(List &L, address &prec, address P);
void insertLast_103032300015(List &L, address P);
void deleteFirst_103032300015(List &L, address &P);
void deleteAfter_103032300015(List &L, address Prec, address &P);
void deleteLast_103032300015(List &L, address &P);
void concat_103032300015(List L1, List L2, List &L3);
address FindLagu_103032300015(List L, string judul);
void removelagu_103032300015(List &L, string judul);
void tampilkan_103032300015(List L);

#endif // DLL_H_INCLUDED
