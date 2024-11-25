#include "DLL.h"
#include <iostream>

using namespace std;

bool isEmpty_103032300101(List l) {
    return (l.first == NULL);
}

void createList_103032300101(List &l) {
    l.first == NULL;
    l.last == NULL;
}

address createNewElmnt_103032300101(infotype x) {
    address p;

    p = new elmtList;
    p->info = x;
    p->next = NULL;
    p->prev = NULL;

    return p;
}

void insertFirst_103032300101(List &l, address p) {
    if (isEmpty_103032300101(l)) {
        l.first = p;
        l.last = p;
    } else {
        p->next = l.first;
        l.first->prev = p;
        l.first = p;
    }
}

void insertAfter_103032300101(List &l, address &p, address &prec) {
    p->next = prec->next;
    p->prev = prec;
    prec->next->prev = p;
    prec->next = p;
}

void insertLast_103032300101(List &l, address p) {
    if (isEmpty_103032300101(l)) {
        l.first = p;
        l.last = p;
    } else {
        p->prev = l.last;
        l.last->next = p;
        l.last = p;
    }
}

void deleteFirst_103032300101(List &l, address &p) {
    if (!isEmpty_103032300101(l)) {
        p = l.first;
        if (l.first == l.last) {
            l.first = NULL;
            l.last = NULL;
        } else {
            l.first = l.first->next;
            l.first->prev = NULL;
            p->next = NULL;
        }
    }
}

void deleteAfter_103032300101(List &l, address &p, address &prec) {
    p = prec->next;
    prec->next = p->next;
    p->next->prev = prec;
    p->next = NULL;
    p->prev = NULL;
}

void deleteLast_103032300101(List &l, address &p) {
    if (!isEmpty_103032300101(l)) {
        p = l.last;
        if (l.first == l.last) {
            l.first = NULL;
            l.last = NULL;
        } else {
            l.last = l.last->prev;
            l.last->next = NULL;
            p->next = NULL;
        }
    }
}

void concat_103032300101(List l1, List l2, List &l3) {
    createList_103032300101(l3);
    address p;
    p = l1.first;
    while (p != NULL) {
        address temp = createNewElmnt_103032300101(p->info);
        insertLast_103032300101(l3, temp);
        p = p->next;
    }
    p = l2.first;
    while (p != NULL) {
        address temp = createNewElmnt_103032300101(p->info);
        insertLast_103032300101(l3, temp);
        p = p->next;
    }
}

address findLagu_103032300101(string judul, List l) {
    if (isEmpty_103032300101(l)) {
        return NULL;
    } else {
        address p = l.first;
        while (p != NULL) {
            if (p->info.nama == judul) {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }
}

void removeLagu_103032300101(string judul, List &l) {
    address lagu = findLagu_103032300101(judul, l);
    address temp;
    if (lagu == l.first) {
        deleteFirst_103032300101(l, temp);
    } else if (lagu == l.last) {
        deleteLast_103032300101(l, temp);
    } else {
        deleteAfter_103032300101(l, temp, lagu->prev);
    }
}

void show_103032300101(List l) {
    address p = l.first;
    if (isEmpty_103032300101(l)) {
        cout << "List Kosong" << endl;
    } else {
        while (p != NULL) {
            cout << p->info.nama << " " << p->info.band << endl;
            p = p->next;
        }
    }
}
