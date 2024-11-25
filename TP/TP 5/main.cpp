#include <iostream>
#include "SLL.h"

using namespace std;

int main()
{
    List l;
    infotype x;
    address p;
    createList_103032300101(l);

    string Back;
    bool status;
    int menu, n, i;
    menu_103032300101(menu);
    while (!status) {
        if (menu == 1) {
            cout << "Jumlah data yang akan ditambahkan : ";
            cin >> n;
            while (n > 0) {
                cout << endl << "Masukkan data baru : ";
                cin >> x;
                p = newElm_103032300101(x);
                insertLast_103032300101(l, p);
                n--;
            }
        } else if (menu == 2) {
            showAllData_103032300101(l);
        } else if (menu == 3) {
            cout << "Nilai terkecil data : " << findMin_103032300101(l)->info << endl;
        } else if (menu == 4) {
            cout << "Masukan data baru : ";
            cin >> x;
            insertMiddle_103032300101(l, x);
            cout << "Data berhasil ditambahkan" << endl;
        } else if (menu == 5) {
            deleteBetween(l, searchX(l, 20), searchX(l, 50));
        } else if (menu == 0) {
            status = true;
        }
        Back = "";
        if (menu >= 0 && menu <= 5) {
            while (Back != "Y" && Back != "N" && !status) {
                cout << "Kembali ke menu utama? (Y/N) : ";
                cin >> Back;
                if (Back == "Y") {
                    menu_103032300101(menu);
                } else if (Back == "N") {
                    status = false;
                }
            }
        } else {
            menu_103032300101(menu);
        }
    }
    cout << "BYE BYE" << endl;
    return 0;
}
