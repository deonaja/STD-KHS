#include "dll.h"

void createNewList_103032300015(List &L){
    L.first = NULL;
    L.last = NULL;
}
bool isEmpty_103032300015(List L){
    return L.first == NULL;
}
address createNewElmt_103032300015(infotype Y){
    address p = new elmlist;
    p-> info=Y;
    p-> next = NULL;
    p-> prev = NULL;
    return p;
}
void insertFirst_103032300015(List &L, address P){
    if (isEmpty_103032300015(L)){
        L.first = P;
        L.last = P;
    }else{
        L.first->prev = P;
        P->next = L.first;
        L.first = P;
    }
}
void insertAfter_103032300015(List &L, address &prec, address P){
    P->next = prec->next;
    P->prev = prec;
    prec->next->prev = P;
    prec->next = P;
}
void insertLast_103032300015(List &L, address P){
    if (isEmpty_103032300015(L)){
        L.first = P;
        L.last = P;
    }else{
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}
void deleteFirst_103032300015(List &L, address &P){
    if (L.last==L.first) {
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    }else{
        P = L.first;
        L.first = P->next;
        L.first->prev = NULL;
        P->next =NULL;
    }
}
void deleteAfter_103032300015(List &L, address Prec, address &P){
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
    P->prev = NULL;
}
void deleteLast_103032300015(List &L, address &P){
    if (L.last==L.first) {
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    }else{
        P = L.last;
        L.last = P->prev;
        L.last->next = NULL;
        P->prev = NULL;
    }
}
void concat_103032300015(List L1, List L2, List &L3){
    L3 = L1;
    L3.last->next = L2.first;
    L2.first->prev = L3.last;
    L3.last = L2.last;
}
address FindLagu_103032300015(List L, string judul){
    if (isEmpty_103032300015(L)) {
        return NULL;
        cout << endl << "Lagu ini tidak tersredia :( " << endl;
    }else{
        address p = L.first;
        while (p!= NULL){
            if(p->info.judul ==judul) {
                return p;
            }
            p=p->next;
        }
    }
    return NULL;
}
void removelagu_103032300015(List &L, string judul1) {
    if(isEmpty_103032300015(L)) {
        cout << "List nya kosong" << endl;
    }else{
        address p = FindLagu_103032300015(L, judul1);
        if (p != NULL) {
            if (p == L.first){
                deleteFirst_103032300015(L,p);
            }else if (p == L.last) {
                deleteLast_103032300015(L,p);
            }else{
                deleteAfter_103032300015(L, p->prev, p);
            }
            delete p;
        }
    }
}
void tampilkan_103032300015(List L){
    address p = L.first;
    while (p!= NULL) {
        cout << "judul lagu : " << p->info.judul << endl;
        cout << "grup band : " << p->info.penyanyi << endl << endl;
        p=p->next;
    }
}
