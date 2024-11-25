#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List L;
    infotype x;
    address p;
    createList(L);

    cout << "Angka pertama ";
    cin >> x;
    p = allocate(x);
    insertFirst(L, p);
    printInfo(L);

    cout << "Angka kedua ";
    cin >> x;
    p = allocate(x);
    insertFirst(L, p);
    printInfo(L);

    cout << "Angka ketiga ";
    cin >> x;
    p = allocate(x);
    insertFirst(L, p);
    printInfo(L);
    return 0;
}
