#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;


struct Toko {
    string nama;
    int harga;
    int jml_stok;
};


typedef Toko infotype;


typedef struct elmList *adr;


struct elmList {
    infotype info;
    adr next;
};


struct List {
    adr first;
};


void Create_List(List &L);
adr New_Elemen(infotype data);
void Insert_First(List &L, adr p);
void Insert_Last(List &L, adr p);
void Insert_After(List &L, adr prec, adr p);
void Delete_First(List &L, adr &p);
void Delete_Last(List &L, adr &p);
void Delete_After(List &L, adr prec, adr &p);
void Show(const List &L);


#endif // SLL_H_INCLUDED
