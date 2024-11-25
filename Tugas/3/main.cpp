#include <iostream>

using namespace std;
// deklarasi List
typedef struct elm *address;
typedef float infotype;

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
        printf("%.1f, ", q->info);
        q = q->next;
    }
    cout << endl;
}

int main()
{
    List l;
    infotype a,b,c,d,e;
    address a1,b1,c1,d1,e1;
    createList(l);

    a = 10.5;
    a1 = newElm(a);
    insertFirst(l, a1);

    b = 12.0;
    b1 = newElm(b);
    insertLast(l, b1);

    c = 20.9;
    c1 = newElm(c);
    insertLast(l, c1);

    d = 25.1;
    d1 = newElm(d);
    insertLast(l, d1);

    cout << "Before inputAscending :" << endl;
    show(l);

    e = 20.0;
    e1 = newElm(e);
    insertAscending(l, e1);

    cout << "After inputAscending :" << endl;
    show(l);

    return 0;
}
