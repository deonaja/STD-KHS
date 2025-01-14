#include "rs.h"

void insertDokter(listDokter &lD, string namaDokter, int idDokter, string spesialisDokter){
    adrDokter newElement = new elemenDokter;
    newElement->info.namaDokter = namaDokter;
    newElement->info.idDokter = idDokter;
    newElement->info.spesialisDokter = spesialisDokter;
    newElement->next = NULL;
    if (lD.first == NULL){
        lD.first = newElement;
    }else{
        adrDokter D = lD.first;
        while (D->next != NULL){
            D = D->next;
        }
        D->next = newElement;
    }

}

void insertPasien(listPasien &lP, int idPasien,string namaPasien, int usia, string Alamat, string namaPenyakit, int biaya, string namaObat){
    adrPasien newElement = new elemenPasien;
    newElement->info.idPasien = idPasien;
    newElement->info.namaPasien = namaPasien;
    newElement->info.usia = usia;
    newElement->info.Alamat = Alamat;
    newElement->info.namaPenyakit = namaPenyakit;
    newElement->info.biaya = biaya;
    newElement->info.namaObat = namaObat;
    newElement->next = NULL;

    if(lP.first == NULL){
        lP.first = newElement;
        lP.last = newElement;
    }else{
        adrPasien P = lP.first;
        adrPasien prev = NULL;

        while(P != NULL){
            prev = P;
            P = P->next;
        }
        prev->next = newElement;
        newElement->prev = prev;
    }

}

void insertRelation(listRelasi &lR, adrDokter D, adrPasien P){
    adrRelasi newElement = new elemenRelasi;
    newElement->nextDokter = D;
    newElement->nextPasien = P;
    newElement->next = NULL;

    if (lR.first == NULL) {
        lR.first = newElement;
    } else {
        adrRelasi R = lR.first;
        while (R->next != NULL) {
            R = R->next;
        }
        R->next = newElement;
    }

}
void deleteDokter(listDokter &lD, int idDokter){
    adrDokter D = lD.first;
    if (D == NULL) {
        cout << "Tidak ada data Dokter" << endl;
    } else {
        adrDokter prev = NULL;
        while (D != NULL && D->info.idDokter != idDokter) {
            prev = D;
            D = D->next;
        }
        if (D == NULL) {
            cout << "Dokter dengan ID " << idDokter << " tidak ditemukan" << endl;
        } else {
            if (D == lD.first) {
                lD.first = D->next;
                delete D;
            } else if (D->next == NULL) {
                prev->next = NULL;
            } else {
                prev->next = D->next;
                delete D;
            }
            cout << "Dokter dengan ID " << idDokter << " telah dihapus" << endl;
        }
    }
}

void deletePasien(listPasien &lP, int idPasien){
    adrPasien P = lP.first;
    adrPasien prev = NULL;

    while (P != NULL && P->info.idPasien != idPasien) {
        prev = P;
        P = P->next;
    }

    if (P != NULL) {
        if (prev == NULL) {
            lP.first = P->next;
        } else if (P->next == NULL) {
            lP.last = prev;
            prev->next = NULL;
            P->prev = NULL;
        } else {
            prev->next = P->next;
            P->next->prev = prev;
        }
        delete P;
        cout << "Pasien dengan ID " << idPasien << " telah dihapus" << endl;
    } else {
        cout << "Pasien dengan ID " << idPasien << " tidak ditemukan" << endl;
    }

}
void deleteRelation(listRelasi &lR, adrDokter D, adrPasien P){
    adrRelasi R = lR.first;
    adrRelasi prev = NULL;

    while (R != NULL && (R->nextDokter != D || R->nextPasien != P)) {
        prev = R;
        R = R->next;
    }

    if (R != NULL) {
        if (prev == NULL) {
            lR.first = R->next;
        } else {
            prev->next = R->next;
        }
        delete R;
        cout << "Relasi berhasil dihapus." << endl;
    } else {
        cout << "Relasi tidak ditemukan." << endl;
    }

}
void findDokter(const listDokter &lD, int idDokter) {
    adrDokter D = lD.first;
    while (D != NULL && D->info.idDokter != idDokter) {
        D = D->next;
    }
    if (D != NULL) {
        cout << "Dokter ditemukan: Nama = "<< D->info.namaDokter << endl;
    } else {
        cout << "Dokter tidak ditemukan." << endl;
    }
    cout << "---------------------------" << endl;
}
void findPasien(const listPasien &lP, int idPasien) {
    adrPasien P = lP.first;
    while (P != NULL && P->info.idPasien != idPasien) {
        P = P->next;
    }
    if (P != NULL) {
        cout << "Pasien ditemukan: Nama = " << P->info.namaPasien << endl;
    } else {
        cout << "Pasien tidak ditemukan." << endl;
    }
    cout << "---------------------------" << endl;

}
void findRelation(const listRelasi &lR, adrDokter D, adrPasien P) {
    adrRelasi R = lR.first;
    while (R != NULL) {
        if (R->nextDokter == D && R->nextPasien == P) {
            cout << "Relasi ditemukan antara dokter dan pasien." << endl;
            cout << "---------------------------" << endl;
            return;
        }
        R = R->next;
    }
    cout << "Relasi tidak ditemukan." << endl;
    cout << "---------------------------" << endl;

}
void showAllDataDokter(listDokter &lD){
    if (lD.first == NULL){
        cout << "Tidak ada data Dokter." << endl;
        return;
    }

    adrDokter current = lD.first;
    while (current != NULL){
        cout << "ID Dokter: " << current ->info.idDokter << endl;
        cout << "Nama Dokter: " << current->info.namaDokter << endl;
        cout << "spesialis: " << current->info.spesialisDokter << endl;
        cout << "-------------------" << endl;
        current = current->next;
    }

}
void showAllDataPasien(listPasien &lP){
    adrPasien p = lP.first;
    if (p == NULL) {
        cout << "Tidak ada data Pasien" << endl;
        return;
    }
    while (p != NULL) {
        cout << "Nama Pasien            : " << p->info.namaPasien << endl;
        cout << "ID Pasien              : " << p->info.idPasien << endl;
        cout << "Usia Pasien            : " << p->info.usia << endl;
        cout << "Alamat Pasien          : " << p->info.Alamat << endl;
        cout << "Penyakit Pasien        : " << p->info.namaPenyakit << endl;
        cout << "Nama Obat Pasien       : " << p->info.namaObat << endl;
        cout << "Biaya Pasien           : " << p->info.biaya << endl;
        cout << "------------------------------------------------" << endl;
        p = p->next;
    }
}
void showAllRelation(listRelasi &lR) {
    adrRelasi R = lR.first;
    if (R == NULL) {
        cout << "Tidak ada Relasi" << endl;
        return;
    }
    cout << "---------HALO INI DAFTAR RS HARI INI---------" << endl;
    while (R != NULL) {
        cout << "Dokter: " << R->nextDokter->info.namaDokter << " merawat Pasien: " << R->nextPasien->info.namaPasien << endl;
        R = R->next;
    }
    cout << "------------------------------------------------" << endl;

}
void showDataDokter(listRelasi lR, int idPasien){
    adrRelasi R = lR.first;
    while (R != NULL) {
        if (R->nextPasien->info.idPasien == idPasien) {
            cout << "Dokter: " << R->nextDokter->info.namaDokter << " (ID: " << R->nextDokter->info.idDokter << ")\n";
        }
        R = R->next;
    }
    cout << "---------------------------" << endl;
}
void showDataPasien(listRelasi lR, int idDokter){
    adrRelasi R = lR.first;
    while (R != NULL) {
        if (R->nextDokter->info.idDokter == idDokter) {
            cout << "Pasien: " << R->nextPasien->info.namaPasien << " (ID: " << R->nextPasien->info.idPasien << ")\n";
        }
        R = R->next;
    }
    cout << "---------------------------" << endl;
}
void showDataRelation(listRelasi lR){
    int idDokter, idPasien;
    cout << "Masukkan ID Dokter: ";
    cin >> idDokter;
    cout << "Masukkan ID Pasien: ";
    cin >> idPasien;

    adrRelasi R = lR.first;
    while (R != NULL) {
        if (R->nextDokter->info.idDokter == idDokter && R->nextPasien->info.idPasien == idPasien) {
            cout << "Relasi ditemukan:\n";
            cout << "Dokter: " << R->nextDokter->info.namaDokter << " (ID: " << R->nextDokter->info.idDokter << ")\n";
            cout << "Pasien: " << R->nextPasien->info.namaPasien << " (ID: " << R->nextPasien->info.idPasien << ")\n";
            cout << "---------------------------" << endl;
            return;
        }
        R = R->next;
    }
    cout << "Relasi antara Dokter dengan ID " << idDokter << " dan Pasien dengan ID " << idPasien << " tidak ditemukan." << endl;
    cout << "---------------------------" << endl;

}
void countPasien(listRelasi lR, int idPasien){
    int count = 0;
    adrRelasi R = lR.first;
    while (R != NULL) {
        if (R->nextPasien->info.idPasien == idPasien) {
            count++;
        }
        R = R->next;
    }
    cout << "Jumlah Dokter Pada ID Pasien <" << idPasien << "> : " << count << endl;
    cout << "---------------------------" << endl;
}

void countDokter(listRelasi lR, int idDokter){
    int count = 0;
    adrRelasi R = lR.first;
    while (R !=NULL) {
        if (R->nextDokter->info.idDokter == idDokter) {
            count++;
        }
        R = R->next;
    }
    cout << "Jumlah Pasien Pada ID Dokter <" << idDokter << "> : " << count << endl;

}
void countPasienTanpaDokter(listPasien &lP, listRelasi &lR){
    int count = 0;
    adrPasien P = lP.first;
    while (P != NULL) {
        adrRelasi R = lR.first;
        bool found = false;
        while (R != NULL) {
            if (R->nextPasien == P) {
                found = true;
            }
            R = R->next;
        }
        if (!found) {
            count++;
        }
        P = P->next;
    }
    cout << "Jumlah Pasien tanpa Dokter: " << count << endl;
    cout << "---------------------------" << endl;
}
void countDokterTanpaPasien(listDokter &lD, listRelasi &lR){
    int count = 0;
    adrDokter currentDokter = lD.first;
    while (currentDokter != NULL) {
        bool hasPasien = false;
        adrRelasi currentRelasi = lR.first;
        while (currentRelasi != NULL){
            if (currentRelasi->nextDokter == currentDokter){
                hasPasien = true;
                break;
            }
            currentRelasi = currentRelasi->next;
        }
        if (!hasPasien){
            count++;
        }
        currentDokter = currentDokter->next;
    }
    cout << "jumlah dokter tanpa pasien: " << count << endl;


}
void editRelationParentChild(listRelasi &lR, adrDokter D, adrPasien P, adrDokter newDokter, adrPasien newPasien){
   adrRelasi R = lR.first;

    while (R != NULL) {
        if (R->nextDokter == D && R->nextPasien == P) {
            R->nextDokter = newDokter;
            R->nextPasien = newPasien;
            cout << "Relasi berhasil diperbarui." << endl;
            return;
        }
        R = R->next;
    }
    cout << "Relasi tidak ditemukan." << endl;
}
void deleteFirstDokter(listDokter &LD){
    if (LD.first == NULL){
        cout << "list dokter kosong, tidak ada yang bisa dihapus" << endl;
        return;
    }
    adrDokter temp = LD.first;
    LD.first = LD.first->next;
    delete temp;
    cout << "Dokter Pertama telah dihapus." << endl;


}
void deleteAfterDokter(listDokter &LD, int idDokter){
    if (LD.first = NULL) {
        cout << "List dokter kosong, tidak ada yang dihapus" << endl;
        return;
    }
    adrDokter current = LD.first;
    while (current != NULL && current-> info.idDokter != idDokter){
        current = current -> next;
    }
    if (current == NULL || current->next == NULL){
        cout << "Dokter dengan ID " << idDokter << "tidak ditemukan" << endl;
        return;
    }
    adrDokter temp = current->next;
    current->next = current->next->next;
    delete temp;

}
