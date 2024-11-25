#include <iostream>

using namespace std;
// deklarasi List
typedef struct elm *address;
typedef int infotype;

struct elm {
    infotype info;
    address next;
};

struct List {
    address first;
};

// Procedure createList
void createList(List &l) {
    l.first = nullptr;
}

// Function newElm
address newElm(infotype x){
    address p;

    p = new elm;
    p->info = x;
    p->next = nullptr;

    return p;
}

//Procedure insertAscending
void insertAscending(List &l, address p){
    address q = l.first;
    while(q->next != nullptr && q->next->info < p->info) {
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
}

void insertFirst(List &l, address p) {
    if (l.first == nullptr) {
        l.first = p;
    } else {
        p->next = l.first;
        l.first = p;
    }
}

void insertLast(List &l, address p) {
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

void show(List l) {
    address q = l.first;
    while (q != nullptr) {
        printf("%d, ", q->info);
        q = q->next;
    }
    cout << endl;
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

void deleteSpecial(List &l, address &p, int x) {
    address q = l.first;
    address r;
    address keep = searchX(l, x);
    if (keep == nullptr){
        cout << "Tidak ada Elemen Bernilai X dalam list" << endl;
    } else {
        if (keep->next == nullptr) {
            while (q->next != nullptr){
                r = q;
                q = q->next;
            }
            p = r->next;
            r->next = nullptr;
        } else if (keep == l.first) {
            p = l.first;
            l.first = l.first->next;
            p->next = nullptr;
        } else {
            p = keep->next;
            keep->next = p->next;
            p->next = nullptr;
        }
    }
}

int main()
{
    List l;
    address p;
    infotype a, b, c, d;
    address a1, b1, c1, d1;
    createList(l);

    a = 15;
    a1 = newElm(a);
    insertFirst(l, a1);

    b = 30;
    b1 = newElm(b);
    insertLast(l, b1);

    c = 40;
    c1 = newElm(c);
    insertLast(l, c1);

    d = 50;
    d1 = newElm(d);
    insertLast(l, d1);
    show(l);

    deleteSpecial(l, p, 30);
    show(l);

    return 0;
}
