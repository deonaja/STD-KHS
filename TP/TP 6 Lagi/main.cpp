#include <iostream>
#include "DLL.h"
using namespace std;

int main()
{
   List L1,L2,L3;
   address p,q;
   infotype data;
   int i,j;
   string judul;
   createNewList_103032300101(L1);
   createNewList_103032300101(L2);
   createNewList_103032300101(L3);
   cout << "List ke-1" << endl;
   for (i=0;i<3;i++){
        cout << endl << "Penyanyi Ke-" << i+1 << ": ";
        cin >> data.penyanyi;
        cout << endl << "Judul Ke-" << i+1 << ": ";
        cin >> data.judul;
        p = createNewElmt_103032300101(data);
        insertLast_103032300101(L1,p);
    }
    cout << "List ke-2" << endl;
    for (j=0;j<3;j++){
        cout << endl << "Penyanyi Ke-" << j+1 << ": ";
        cin >> data.penyanyi;
        cout << endl << "Judul Ke-" << j+1 << ": ";
        cin >> data.judul;
        p = createNewElmt_103032300101(data);
        insertLast_103032300101(L2,p);
    }
    cout << "List ke-1" << endl;
    show_103032300101(L1);
    cout << "List ke-2" << endl;
    show_103032300101(L2);
    cout << "List ke-3 (Gabungan List 1 dan List 2)" << endl;
    concat_103032300101(L1, L2, L3);
    show_103032300101(L3);
    cout << "List 3 setelah delete first" << endl;
    deleteFirst_103032300101(L3,p);
    show_103032300101(L3);
    cout << "List 3 setelah delete last" << endl;
    deleteLast_103032300101(L3,p);
    show_103032300101(L3);
    cout << "Delete After";
    cout << endl << "Judul Lagu yang setelahnya akan dihapus: ";
    cin >> judul;
    q = findLagu_103032300101(L3,judul);
    if (q != NULL){
        deleteAfter_103032300101(L3,q,p);
        show_103032300101(L3);
    }
    cout << endl << "Masukkan judul lagu yang akan dihapus: ";
    cin >> judul;
    removeLagu_103032300101(L3, judul);
    show_103032300101(L3);
    cout << "Insert After";
    cout << endl << "Judul Lagu yang setelahnya akan ditambah: ";
    cin >> judul;
    q = findLagu_103032300101(L3, judul);
    if (q!=NULL) {
        cout << endl << "Judul lagu yang akan ditambahkan: ";
        cin >> data.judul;
        cout << endl << "Nama penyanyi yang akan ditambahkan: ";
        cin >> data.penyanyi;
        p = createNewElmt_103032300101(data);
        insertAfter_103032300101(L3, q, p);
        show_103032300101(L3);
    }
    return 0;
}
