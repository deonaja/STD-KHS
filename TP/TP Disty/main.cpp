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
   createNewList_103032300015(L1);
   createNewList_103032300015(L2);
   createNewList_103032300015(L3);
   cout <<"============== Lagu Pertama ==============";
   for (i=0;i<3;i++){
        cout << endl << "Penyanyi Ke-" << i+1 << ": ";
        cin >> data.penyanyi;
        cout << endl << "Judul Ke-" << i+1 << ": ";
        cin >> data.judul;
        p = createNewElmt_103032300015(data);
        insertLast_103032300015(L1,p);
    }
    cout <<"============== Lagu Kedua ==============";
    for (j=0;j<3;j++){
        cout << endl << "Penyanyi Ke-" << j+1 << ": ";
        cin >> data.penyanyi;
        cout << endl << "Judul Ke-" << j+1 << ": ";
        cin >> data.judul;
        p = createNewElmt_103032300015(data);
        insertLast_103032300015(L2,p);
    }
    cout << "============== Lagu Pertama ==============" << endl;
    tampilkan_103032300015(L1);
    cout << "============== Lagu Kedua ==============" << endl;
    tampilkan_103032300015(L2);
    cout << "============== Lagu Ketiga ==============" << endl;
    concat_103032300015(L1, L2, L3);
    tampilkan_103032300015(L3);
    cout << "============== Lagu setelah delete First ==============" << endl;
    deleteFirst_103032300015(L3,p);
    tampilkan_103032300015(L3);
    cout << "============== Lagu setelah delete Last ==============" << endl;
    deleteLast_103032300015(L3,p);
    tampilkan_103032300015(L3);
    cout << "============== Lagu setelah delete After ==============";
    cout << endl << "Judul Lagu yang setelahnya akan dihapus: ";
    cin >> judul;
    q = FindLagu_103032300015(L3,judul);
    if (q != NULL){
        deleteAfter_103032300015(L3,q,p);
        tampilkan_103032300015(L3);
    }
    cout << endl << "Masukkan judul lagu yang akan dihapus: ";
    cin >> judul;
    removelagu_103032300015(L3, judul);
    tampilkan_103032300015(L3);
    cout << "============== Lagu Insert After ==============";
    cout << endl << "Judul Lagu yang setelahnya akan ditambah: ";
    cin >> judul;
    q = FindLagu_103032300015(L3, judul);
    if (q!=NULL) {
        cout << endl << "Judul lagu yang akan ditambahkan: ";
        cin >> data.judul;
        cout << endl << "Nama penyanyi yang akan ditambahkan: ";
        cin >> data.penyanyi;
        p = createNewElmt_103032300015(data);
        insertAfter_103032300015(L3, q, p);
        tampilkan_103032300015(L3);
    }
    return 0;
}
