#include "DLL.h"

void createNewList_103032300101(List &L){
    L.first = NULL;
    L.last  = NULL;
 }
 bool isEmpty_103032300101(List L){
    return L.first == NULL;
 }
address createNewElmt_103032300101(infotype X){
    address p = new elmlist;
    p->info=X;
    p->next = NULL;
    p->prev = NULL;
    return p;
 }
void insertFirst_103032300101(List &L, address P){
    if (isEmpty_103032300101(L)){
        L.first = P;
        L.last = P;
    }else{
        L.first->prev = P;
        P->next = L.first;
        L.first = P;
    }
}
void insertAfter_103032300101(List &L, address &prec, address P){
    P->next = prec->next;
    P->prev = prec;
    prec->next->prev = P;
    prec->next = P;
}
void insertLast_103032300101(List &L, address P){
    if (isEmpty_103032300101(L)){
        L.first = P;
        L.last  = P;
    }else{
        L.last->next = P;
        P->prev = L.last;
        L.last  = P;
    }
}
void deleteFirst_103032300101(List &L, address &P){
    if (L.last==L.first){
        P = L.first;
        L.first = NULL;
        L.last  = NULL;
    }else{
        P = L.first;
        L.first = P->next;
        L.first->prev = NULL;
        P->next = NULL;
    }
}
void deleteAfter_103032300101(List &L, address prec, address &P){
    P = prec->next;
    prec->next = P->next;
    P->next->prev = prec;
    P->next = NULL;
    P->prev = NULL;
}
void deleteLast_103032300101(List &L, address &P){
    if (L.last==L.first){
        P = L.first;
        L.first = NULL;
        L.last  = NULL;
    }else{
        P = L.last;
        L.last = P->prev;
        L.last->next = NULL;
        P->prev = NULL;
    }
}
void concat_103032300101(List L1, List L2, List &L3){
    L3 = L1;
    L3.last->next = L2.first;
    L2.first->prev = L3.last;
    L3.last = L2.last;
}
address findLagu_103032300101(List L, string Judul){
    if (isEmpty_103032300101(L)){
        cout << endl << "Lagu Tidak Ditemukan" << endl;
        return NULL;
    }else{
        address p = L.first;
        while (p!=NULL){
            if (p->info.judul == Judul){
                return p;
            }
            p=p->next;
        }
        cout << endl << "Lagu Tidak Ditemukan" << endl;
        return NULL;
    }
}
void removeLagu_103032300101(List &L, string Judul){
    if (isEmpty_103032300101(L)) {
        cout << "List Kosong" << endl;
    }else{
        address p = findLagu_103032300101(L, Judul);
        if (p != NULL){
            if (p == L.first){
                deleteFirst_103032300101(L,p);
            }else if (p == L.last){
                    deleteLast_103032300101(L,p);
            }else{
                    deleteAfter_103032300101(L, p->prev, p);
            }
            delete p;
        }
    }
}
void show_103032300101(List L){
    address p = L.first;
    while (p!=NULL){
        cout << "Lagu    : " << p->info.judul << endl;
        cout << "Penyanyi: " << p->info.penyanyi << endl << endl;
        p=p->next;
    }
}
