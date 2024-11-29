#include "tubes.h"

void menu(listGudang lG, listPenitip lP){
    bool status = false;
    char menu;
    string Back;
    mainMenu(menu);
    while (!status) {
        cout << "a" << endl;
        if (menu == '1') {
            menu_1();
        } else if (menu == '2'){
            //menu_2();
        } else if (menu == '3'){
            //menu_3();
        } else if (menu == '0'){
            status = true;
        } else {
            cout << "INPUT INVALID" << endl;
        }
        Back = "";
        if (menu >= '0' && menu <= '3') {
            while (Back != "Y" && Back != "N" && !status) {
                cout << "Kembali ke menu utama? (Y/N) : ";
                cin >> Back;
                if (Back == "Y") {
                    mainMenu(menu);
                } else if (Back == "N") {
                    status = false;
                }
            }
        } else {
            mainMenu(menu);
        }
    }
}

void mainMenu(char &n) {
    cout << "==========MAIN MENU==========" << endl;
    cout << "1.DATA GUDANG" << endl;
    cout << "2.DATA PENITIP" << endl;
    cout << "3.DATA RELASI" << endl;
    cout << "0.EXIT" << endl;
    cin >> n;
}

void menu_1() {

}

void menu_2() {

}

void menu_3() {

}

void menuGudang(char &n) {
    cout << "============DATA GUDANG============" << endl;
    cout << "1." << endl;
    cout << "1." << endl;
    cout << "1." << endl;
    cout << "1." << endl;
    cout << "1." << endl;
    cout << "1." << endl;
    cin >> n;
}

void menuPenitip(char &n) {
    cout << "============DATA PENITIP============" << endl;
    cout << "1." << endl;
    cout << "1." << endl;
    cout << "1." << endl;
    cout << "1." << endl;
    cout << "1." << endl;
    cout << "1." << endl;
    cin >> n;
}
void menuRelasi(char &n) {
    cout << "============DATA RELASI============" << endl;
    cout << "1." << endl;
    cout << "1." << endl;
    cout << "1." << endl;
    cout << "1." << endl;
    cout << "1." << endl;
    cout << "1." << endl;
    cin >> n;
}

adrGudang createNewGudang(gudang x) {
    adrGudang G = new elemenGudang;
    G->info = x;
    G->next = NULL;
    G->nextRelasi = NULL;
    return G;
}
adrPenitip createNewPenitip(penitip x) {
    adrPenitip P = new elemenPenitip;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

adrRelasi createNewRelasi(adrPenitip P){
    adrRelasi R = new elemenRelasi;
    R->nextPenitip = P;
    R->nextRelasi = NULL;
    return R;
}

void insertGudang(listGudang &lG, adrGudang G){
    if (lG.first==NULL){
        lG.first = G;
    } else {
        adrGudang Q;
        Q = lG.first;
        while (Q->next!=NULL){
            Q = Q->next;
        }
        Q->next = G;
    }
}

void insertPenitip(listPenitip &lP, adrPenitip P){
     if (P != NULL) {
        if (lP.first == NULL) {
            lP.first = P;
            lP.last = P;
        } else {
            lP.last->next = P;
            P->prev = lP.last;
            lP.last = P;
        }
    }
}

void insertRelation(listPenitip lP, listGudang lG, adrGudang G, adrPenitip P) {
    if (G != NULL && P != NULL) {
        adrRelasi R = G->nextRelasi;
        if (R == NULL) {
            R->nextPenitip = P;
        } else {
            adrRelasi Q = R, S = createNewRelasi(P);
            while (Q->nextRelasi != NULL) {
                Q = Q->nextRelasi;
            }
            Q->nextRelasi = S;
        }
    }
} //G untuk data parent yang ingin ditambah relasinya; P untuk child yang akan direlasikan ke parent

void deleteGudang(listGudang &lG, adrGudang G){
    if(lG.first == NULL){
        cout<<"list gudang kosong"<<endl;
    }else if(G == lG.first){
        lG.first = G->next;
        G->next = NULL;
    }else{
        adrGudang Q;
        adrGudang P;
        P = NULL;
        Q = lG.first;
        while(Q!=NULL && Q!=G){
            P = Q;
            Q = Q->next;
        }
        if (Q == NULL){
            cout<<"gudang tidak ditemukan dalam list"<<endl;
        } else if (Q->next == NULL){
            P->next = NULL;
        }else{
            P->next = Q->next;
            Q->next = NULL;
        }
    }
}

void deletePenitip(listPenitip &lP, string nama, string tanggal){
    adrPenitip p = findPenitip(lP, nama, tanggal);
    // Jika elemen tidak ditemukan
    if (p == NULL) {
        cout << "Data dengan nama \"" << nama << "\" dan tanggal \"" << tanggal << "\" tidak ditemukan." << endl;
        return;
    }
    // Jika elemen ditemukan di awal
    if (p == lP.first) {
        if (lP.first == lP.last) {
            // Hanya ada satu elemen
            lP.first = NULL;
            lP.last = NULL;
        } else {
            // Lebih dari satu elemen
            lP.first = p->next;
            lP.first->prev = NULL;
        }
    }
    // Jika elemen ditemukan di akhir
    else if (p == lP.last) {
        lP.last = p->prev;
        lP.last->next = NULL;
    }
    // Jika elemen ditemukan di tengah
    else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
    // Dealokasi memori elemen yang dihapus
    delete p;
    cout << "Data dengan nama \"" << nama << "\" dan tanggal \"" << tanggal << "\" berhasil dihapus." << endl;
}

void deleteRelasi(listGudang &lG, adrPenitip P) {
    if (lG.first == NULL) {
        cout << "Tidak Ada Gudang" << endl;
    } else {
        adrGudang G = lG.first;
        while (G != NULL) {
            adrRelasi R = G->nextRelasi;
            while (R != NULL) {
                adrRelasi tempR;
                if (R->nextPenitip == P) {
                    if (G->nextRelasi == R) {
                        tempR = R;
                        R = R->nextRelasi;
                    } else if (R->nextRelasi = NULL) {

                    } else {

                    }
                }
                R = R->nextRelasi;
            }
            G = G->next;
        }
    }
} // Belum Selesai.

adrGudang findGudang(listGudang &lG, int nomor_gudang){
    if(lG.first == NULL){
        cout<<"list gudang kosong, gudang tidak ditemukan"<<endl;
        return NULL;
    }else{
        adrGudang G;
        G = lG.first;
        while (G != NULL){
            if(G->info.nomor_gudang == nomor_gudang){
                return G;
            }
            G = G->next;
        }
        cout<<"gudang dengan nomor "<<nomor_gudang<<" tidak ditemukan!"<<endl;
        return NULL;
    }
}
adrPenitip findPenitip(listPenitip &lP, string nama, string tanggal){
    adrPenitip p = lP.first;

    // Mencari elemen berdasarkan nama dan tanggal
    while (p != NULL) {
        if (p->info.nama_penitip == nama && p->info.tanggal_masuk_barang == tanggal) {
            return p; // Elemen ditemukan
        }
        p = p->next;
    }

    return NULL; // Elemen tidak ditemukan
}

void findRelasi(listGudang &lG, adrPenitip P) {
    adrGudang G = lG.first;
    while (G != NULL) {
        adrRelasi R = G->nextRelasi;
        while (R != NULL) {
            if (R->nextPenitip == P) {
                cout << "================" << endl;
            }
            R = R->nextRelasi;
        }
        G = G->next;
    }
} //  P untuk mencari relasi dari parent
void showAllGudang(listGudang lG){
    if(lG.first == NULL){
        cout<<"list gudang kosong! "<<endl;
    }else{
        adrGudang G;
        G = lG.first;
        while(G!=NULL){
            cout<<"nomor gudang: "<<G->info.nomor_gudang<<endl;
            cout<<"slot tersedia gudang: "<<G->info.slot_tersedia_gudang<<endl;
            G = G->next;
        }
    }
}
void showAllPenitip();
void showPenitipDariGudangTertentu();
void showRelasiGudang();
void showRelasiPenitip(listPenitip lP, listGudang lG);
void showGudangPenitip(listGudang lG, adrPenitip P);
void hitungRelasiGudang(listGudang lG);
void hitungRelasiPenitipTertentu();
void hitungPenitipTakBerelasi();
void editSlotGudang(listGudang &lG, adrPenitip P, adrPenitip newP);
