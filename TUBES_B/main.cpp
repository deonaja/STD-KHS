#include "rs.h"
#include <iostream>
using namespace std;

int main() {
    listDokter lD;
    listPasien lP;
    listRelasi lR;
    lD.first = NULL;
    lP.first = NULL;
    lP.last = NULL;
    lR.first = NULL;

    int choice;
    do {
        cout << "---------------------------------------|\n";
        cout << "     SELAMAT DATANG DI RS MOFU         |\n";
        cout << "---------------------------------------|\n";
        cout << "Menu:                                  |\n";
        cout << "1. Tambah Dokter                       |\n";
        cout << "2. Tambah Pasien                       |\n";
        cout << "3. Tambah Relasi                       |\n";
        cout << "4. Hapus Dokter                        |\n";
        cout << "5. Hapus Pasien                        |\n";
        cout << "6. Hapus Relasi                        |\n";
        cout << "7. Tampilkan Semua Dokter              |\n";
        cout << "8. Tampilkan Semua Pasien              |\n";
        cout << "9. Tampilkan Semua Relasi              |\n";
        cout << "10. Cari Dokter                        |\n";
        cout << "11. Cari Pasien                        |\n";
        cout << "12. Cari Relasi                        |\n";
        cout << "13. Hitung Relasi Dokter               |\n";
        cout << "14. Hitung Relasi Pasien               |\n";
        cout << "15. Hitung Pasien Tak Berelasi         |\n";
        cout << "16. Hitung Dokter Tak Berelasi         |\n";
        cout << "17. Show Pasien Dari Dokter tertentu   |\n";
        cout << "18. Show Dokter Dari Pasien tertentu   |\n";
        cout << "19. Edit Relasi                        |\n";
        cout << "0. Keluar                              |\n";
        cout << "<-------------------------------------->\n";
        cout << "Pilihan Anda:";
        cin >> choice;

        if (choice == 1) {
            string nama, spesialis;
            int id;
            cout << "Masukkan Nama Dokter: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan ID Dokter: ";
            cin >> id;
            cout << "Masukkan Spesialis Dokter: ";
            cin.ignore();
            getline(cin, spesialis);
            insertDokter(lD, nama, id, spesialis);
        } else if (choice == 2) {
            string nama, alamat, penyakit, obat;
            int id, usia, biaya;
            cout << "Masukkan Nama Pasien: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan ID Pasien: ";
            cin >> id;
            cout << "Masukkan Usia Pasien: ";
            cin >> usia;
            cout << "Masukkan Alamat Pasien: ";
            cin.ignore();
            getline(cin, alamat);
            cout << "Masukkan Nama Penyakit: ";
            getline(cin, penyakit);
            cout << "Masukkan Biaya: ";
            cin >> biaya;
            cout << "Masukkan Nama Obat: ";
            cin.ignore();
            getline(cin, obat);
            insertPasien(lP, id, nama, usia, alamat, penyakit, biaya, obat);
        } else if (choice == 3) {
            int idDokter, idPasien;
            cout << "Masukkan ID Dokter: ";
            cin >> idDokter;
            cout << "Masukkan ID Pasien: ";
            cin >> idPasien;
            adrDokter D = lD.first;
            while (D != NULL && D->info.idDokter != idDokter) {
                D = D->next;
            }
            adrPasien P = lP.first;
            while (P != NULL && P->info.idPasien != idPasien) {
                P = P->next;
            }
            if (D != NULL && P != NULL) {
                insertRelation(lR, D, P);
            } else {
                cout << "Dokter atau Pasien tidak ditemukan!" << endl;
            }
        } else if (choice == 4) {
            int id;
            cout << "Masukkan ID Dokter yang ingin dihapus: ";
            cin >> id;
            deleteDokter(lD, id);
        } else if (choice == 5) {
            int id;
            cout << "Masukkan ID Pasien yang ingin dihapus: ";
            cin >> id;
            deletePasien(lP, id);
        } else if (choice == 6) {
            int idDokter, idPasien;
            cout << "Masukkan ID Dokter: ";
            cin >> idDokter;
            cout << "Masukkan ID Pasien: ";
            cin >> idPasien;
            adrDokter D = lD.first;
            while (D != NULL && D->info.idDokter != idDokter) {
                D = D->next;
            }
            adrPasien P = lP.first;
            while (P != NULL && P->info.idPasien != idPasien) {
                P = P->next;
            }
            if (D != NULL && P != NULL) {
                deleteRelation(lR, D, P);
            } else {
                cout << "Dokter atau Pasien tidak ditemukan!" << endl;
            }
        } else if (choice == 7) {
            showAllDataDokter(lD);
        } else if (choice == 8) {
            showAllDataPasien(lP);
        } else if (choice == 9) {
            showAllRelation(lR);
        } else if (choice == 10) {
            int id;
            cout << "Masukkan ID Pasien: ";
            cin >> id;
            findPasien(lP, id);
        } else if (choice == 11) {
            int id;
            cout << "Masukkan ID Dokter: ";
            cin >> id;
            findDokter(lD, id);
        } else if (choice == 12) {
            int idDokter, idPasien;
            cout << "Masukkan ID Dokter: ";
            cin >> idDokter;
            cout << "Masukkan ID Pasien: ";
            cin >> idPasien;
            adrDokter D = lD.first;
            while (D != NULL && D->info.idDokter != idDokter) {
                D = D->next;
            }
            adrPasien P = lP.first;
            while (P != NULL && P->info.idPasien != idPasien) {
                P = P->next;
            }
            if (D != NULL && P != NULL) {
                findRelation(lR, D, P);
            } else {
                cout << "Dokter atau Pasien tidak ditemukan!" << endl;
            }
        } else if (choice == 13) {
            int id;
            cout << "Masukkan ID Dokter: ";
            cin >> id;
            adrDokter D = lD.first;
            while (D != NULL && D->info.idDokter != id) {
                D = D->next;
            }
            if (D == NULL) {
                cout << "ID Dokter Tidak Ditemukan" << endl;
            } else {
                countDokter(lR, id);
            }
        } else if (choice == 14) {
            int id;
            cout << "Masukkan ID Pasien: ";
            cin >> id;
            adrPasien P = lP.first;
            while (P != NULL && P->info.idPasien != id) {
                P = P->next;
            }
            if (P == NULL) {
                cout << "ID Pasien Tidak Ditemukan" << endl;
            } else {
                countPasien(lR, id);
            }
        } else if (choice == 15) {
            countPasienTanpaDokter(lP,lR);
        } else if (choice == 16) {
            countDokterTanpaPasien(lD,lR);
        } else if (choice == 17) {
            int idDokter;
            cout << "Masukkan ID Dokter: ";
            cin >> idDokter;
            adrDokter D = lD.first;
            while (D != NULL && D->info.idDokter != idDokter) {
                D = D->next;
            }
            if (D != NULL) {
                showDataPasien(lR, idDokter);
            } else {
                cout << "Dokter tidak ditemukan!" << endl;
            }
        } else if (choice == 18) {
            int idPasien;
            cout << "Masukkan ID Pasien: ";
            cin >> idPasien;
            adrPasien P = lP.first;
            while (P != NULL && P->info.idPasien != idPasien) {
                P = P->next;
            }
            if (P != NULL) {
                showDataDokter(lR, idPasien);
            } else {
                cout << "Pasien tidak ditemukan!" << endl;
            }
        } else if (choice == 19) {
            int idDokter, idPasien, newIdDokter, newIdPasien;
            cout << "Masukkan ID Dokter: ";
            cin >> idDokter;
            cout << "Masukkan ID Pasien: ";
            cin >> idPasien;
            cout << "Masukkan ID Dokter Baru: ";
            cin >> newIdDokter;
            cout << "Masukkan ID Pasien Baru: ";
            cin >> newIdPasien;
            adrDokter D = lD.first;
            while (D != NULL && D->info.idDokter != idDokter) {
                D = D->next;
            }
            adrPasien P = lP.first;
            while (P != NULL && P->info.idPasien != idPasien) {
                P = P->next;
            }
            adrDokter newD = lD.first;
            while (newD != NULL && newD->info.idDokter != newIdDokter) {
                newD = newD->next;
            }
            adrPasien newP = lP.first;
            while (newP != NULL && newP->info.idPasien != newIdPasien) {
                newP = newP->next;
            }
            if (D != NULL && P != NULL && newD != NULL && newP != NULL) {
                editRelationParentChild(lR, D, P, newD, newP);
            } else {
                cout << "Dokter atau Pasien tidak ditemukan!" << endl;
            }
        } else if (choice == 0) {
            cout << "Keluar dari program." << endl;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 0);

    return 0;
}
