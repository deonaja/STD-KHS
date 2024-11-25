#include <iostream>
#include "SLL.h"

using namespace std;

// Procedure createList
void createList_103032300101(List &l) {
    l.first = nullptr;
}

// Function newElm
address newElm_103032300101(infotype x){
    address p;

    p = new elm;
    p->info = x;
    p->next = nullptr;

    return p;
}

void insertLast_103032300101(List &l, address p) {
    address q = l.first;
    if (l.first == nullptr) {
        l.first = p;
    } else {
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = p;
    }
}

void showAllData_103032300101(List l) {
    address q = l.first;
    while (q != nullptr) {
        if (q->next != nullptr) {
            printf("%d, ", q->info);
        } else {
            printf("%d ", q->info);
        }
        q = q->next;
    }
    cout << endl;
}

address findMin_103032300101(List l) {
    address q = l.first;
    address r = l.first;
    while (q != nullptr) {
        if (q->info < r->info) {
            r = q;
        }
        q = q->next;
    }
    return r;
}


void insertMiddle_103032300101(List &l, int value) {
    address p = l.first;
    address q = l.first;
    q = newElm_103032300101(value);
    int i, n;
    n = 0;
    while (p != nullptr) {
        n++;
        p = p->next;
    }
    p = l.first;
    for (i = 1; i <= n / 2; i++){
        p = p->next;
    }
    q->next = p->next;
    p->next = q;
}

void menu_103032300101(int &p) {
    cout << "======MENU=======" << endl;
    cout << "1. Menambah N data baru" << endl;
    cout << "2. Menampilkan semua data" << endl;
    cout << "3. Mencari nilai terkecil data" << endl;
    cout << "4. Masukan nilai ke tengah data" << endl;
    cout << "5. Delete Between" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukan menu : ";
    cin >> p;
}

address searchX(List l, int x){
    address q = l.first;
    while (q->next != nullptr && q->info != x) {
        q = q->next;
    }
    if (q->info == x) {
        return q;
    } else {
        return nullptr;
    }
}

address deleteBetween(List l, address p, address q) {
    address r;
    r = p->next;
    while (r->next != q) {
        r = r->next;
    }
    r->next = nullptr;
    r = p->next;
    p->next = q;
    p = nullptr;
    q = nullptr;
    return r;
}

void cetakElem(List l1,List l2) {
    address p, q;
    int i, n;
    p = l2.first;
    while (p != nullptr) {
        n = p->info;
        q = l1.first;
        i = 1;
        while (i < n) {
            q = q->next;
            i++;
        }
        if (q != nullptr) {
            cout << q->info << endl;
        }
        p = p->next;
    }
}

/*float consonantPersentage_103032300101(List l) {
    address q = l.first;
    float persen, kon, vok;
    if q != nullptr {
        if (q->info == 'a' || q->info == 'A' || q->info == 'i' || q->info == 'I' || q->info == 'u' || q->info == 'U' || q->info == 'e' || q->info == 'E' || q->info == 'o' || q->info == 'O' ) {
            vok++;
        } else {
            kon++;
        }
        q = q->next;
    }
    persen = (kon / (kon + vok))
    return persen*100
}

void showFirstK_103032300101(List l, int k) {
    address p = l.first;
    while k > 0 {
        p = p->next;
        k--
    }
    cout << p->info << endl;
}*/
