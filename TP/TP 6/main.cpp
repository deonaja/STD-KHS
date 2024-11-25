#include <iostream>
#include "DLL.h"

using namespace std;

int main()
{
    List l;
    infotype x;
    address p, q;
    int i,j;
    createList_103032300101(l);

    for (i = 0; i < 4; i++) {
        cin >> x.nama;
        cin >> x.band;
        p = createNewElmnt_103032300101(x);
        insertLast_103032300101(l, p);
        show_103032300101(l);
    }
    for (i = 0; i < 4; i++) {
        q = l.first;
        for (j = 0; j < 4 - i; i++) {
            q = q->next;
        }
        cout << q->info.nama << endl;
        cout << q->info.band << endl;
    }
}
