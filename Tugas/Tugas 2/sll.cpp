#include <iostream>
#include "sll.h"
using namespace std;

void Create_List(List &L) {
    L.first = nullptr;
}

adr New_Elemen(infotype data) {
    adr p = new elmList;
    p->info = data;
    p->next = nullptr;
    return p;
}

void Insert_First(List &L, adr p) {
    if (L.first == nullptr) {
        L.first = p;
    } else {
        p->next = L.first;
        L.first = p;
    }
}

void Insert_Last(List &L, adr p) {
    if (L.first == nullptr) {
        L.first = p;
    } else {
        adr q = L.first;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = p;
    }
}

void Insert_After(List &L, adr prec, adr p) {
    if (prec != nullptr) {
        p->next = prec->next;
        prec->next = p;
    }
}

void Delete_First(List &L, adr &p) {
    if (L.first == nullptr) {
        p = nullptr;
    } else if (L.first->next == nullptr) {
        p = L.first;
        L.first = nullptr;
    } else {
        p = L.first;
        L.first = p->next;
        p->next = nullptr;
    }
}

void Delete_Last(List &L, adr &p) {
    if (L.first == nullptr) {
        p = nullptr;
    } else if (L.first->next == nullptr) {
        p = L.first;
        L.first = nullptr;
    } else {
        adr q = L.first;
        adr r = nullptr;
        while (q->next != nullptr) {
            r = q;
            q = q->next;
        }
        p = q;
        r->next = nullptr;
    }
}

void Delete_After(List &L, adr prec, adr &p) {
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}

void Show(const List &L) {
    if (L.first == nullptr) {
        cout << "List kosong" << endl;
    } else {
        adr p = L.first;
        while (p != nullptr) {
            cout << "Nama barang: " << p->info.nama << endl;
            cout << "Harga barang: " << p->info.harga << endl;
            cout << "Jumlah stok barang: " << p->info.jml_stok << endl;
            p = p->next;
        }
    }
}
