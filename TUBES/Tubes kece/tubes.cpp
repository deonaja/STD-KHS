#include "tubes.h"

void clearScreen() {
    system("cls");
}

void waitForEnter() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore any leftover input
    std::cin.get(); // Wait for Enter
}

void menu(listGudang &lG, listPenitip &lP){
    bool status = false;
    char menu;
    string Back;
    mainMenu(menu);
    while (!status) {
        if (menu == '1') {
            clearScreen();
            menu_1(lG,lP);
        } else if (menu == '2'){
            clearScreen();
            menu_2(lG,lP);
        } else if (menu == '3'){
            clearScreen();
            menu_3(lG,lP);
        } else if (menu == '0'){
            status = true;
        } else {
            cout << "\nINPUT INVALID" << endl;
            waitForEnter();
            clearScreen();
        }
        Back = "";
        if (menu >= '0' && menu <= '3') {
            while (Back != "Y" && Back != "N" && !status) {
                cout << "Kembali ke menu utama? (Y/N) : ";
                cin >> Back;
                if (Back == "Y") {
                    clearScreen();
                    mainMenu(menu);
                } else if (Back == "N") {
                    clearScreen();
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
    cout << "1.Data Gudang" << endl;
    cout << "2.Data Penitip" << endl;
    cout << "3.Data Relasi" << endl;
    cout << "0.Exit" << endl;
    cout << "Pilih : ";
    cin >> n;
}

void menu_1(listGudang &lG, listPenitip &lP) {
    char menu;
    bool status = false;
    string Back;
    menuGudang(menu);
    while (!status) {
        if (menu == '1') {
            clearScreen();
            menu_1_insert(lG);
        } else if (menu == '2') {
            clearScreen();
            menu_1_delete(lG);
        } else if (menu == '3') {
            clearScreen();
            menu_1_find(lG);
        } else if (menu == '4') {
            clearScreen();
            showAllGudang(lG);
            waitForEnter();
            clearScreen();
        } else if (menu == '0') {
            status = true;
        } else {
            cout << "\nINPUT INVALID" << endl;
            waitForEnter();
            clearScreen();
        }
        Back = "";
        if (menu >= '0' && menu <= '3') {
            while (Back != "Y" && Back != "N" && !status) {
                cout << "Kembali ke Menu Gudang? (Y/N) : ";
                cin >> Back;
                if (Back == "Y") {
                    clearScreen();
                    menuGudang(menu);
                } else if (Back == "N") {
                    clearScreen();
                    status = false;
                }
            }
        } else {
            menuGudang(menu);
        }
    }
}

void menu_1_insert(listGudang &lG) {
    gudang G;
    cout << "Masukan Nomor Gudang : ";
    cin >> G.nomor_gudang;
    cout << "Masukan Slot Tersedia Gudang : ";
    cin >> G.slot_tersedia_gudang;
    insertGudang(lG, createNewGudang(G));
    cout << "\nData Berhasil Ditambahkan" << endl;
    waitForEnter();
}

void menu_1_delete(listGudang &lG) {
    gudang G;
    showAllGudang(lG);
    cout << "Masukan Nomor Gudang Yang Ingin Dihapus : ";
    cin >> G.nomor_gudang;
    deleteGudang(lG, findGudang(lG, G.nomor_gudang));
    waitForEnter();
}

void menu_1_find(listGudang &lG) {
    gudang G;
    cout << "Masukan Nomor Gudang Yang Ingin Dicari : ";
    cin >> G.nomor_gudang;
    adrGudang findG = findGudang(lG, G.nomor_gudang);
    if (findG == NULL) {
        cout << "\nGudang dengan nomor " << G.nomor_gudang << " tidak ditemukan" << endl;
    } else {
        cout << "\nGudang dengan nomor " << G.nomor_gudang << " ditemukan" << endl;
        cout << "Data Gudang : " << endl;
        cout << "Nama Gudang            : " << findG->info.nomor_gudang << endl;
        cout << "Slot Tersedia Gudang   : " << findG->info.slot_tersedia_gudang << endl;
        cout << endl;
    }
    waitForEnter();
}

void menuGudang(char &n) {
    cout << "============DATA GUDANG============" << endl;
    cout << "1.Masukan Data Gudang" << endl;
    cout << "2.Delete Data Gudang" << endl;
    cout << "3.Cari Data Gudang" << endl;
    cout << "4.Tampilkan Data Gudang" << endl;
    cout << "1." << endl;
    cout << "0.Back" << endl;
    cout << "Pilih : ";
    cin >> n;
}

void menu_2(listGudang &lG, listPenitip &lP) {
    char menu;
    bool status = false;
    string Back;
    while (!status) {
        menuGudang(menu);
        if (menu == '1') {
            menu_2_insert(lP);
        } else if (menu == '2') {
            menu_2_delete(lP);
        } else if (menu == '3') {

        } else if (menu == '4') {

        } else if (menu == '0') {
            status = true;
        } else {
            cout << "\nINPUT INVALID" << endl;
            waitForEnter();
            clearScreen();
        }
        Back = "";
        if (menu >= '0' && menu <= '3') {
            while (Back != "Y" && Back != "N" && !status) {
                cout << "Kembali ke Menu Penitip? (Y/N) : ";
                cin >> Back;
                if (Back == "Y") {
                    clearScreen();
                    menuPenitip(menu);
                } else if (Back == "N") {
                    clearScreen();
                    status = false;
                }
            }
        } else {
            menuPenitip(menu);
        }
    }
}

void menu_2_insert(listPenitip &lP) {
    penitip P;
    cout << "Masukan Nama Penitip           : ";
    cin >> P.nama_penitip;
    cout << "Masukan Tanggal Masuk Barang   : ";
    cin >> P.tanggal_masuk_barang;
    cout << "Masukan Jumlah Barang          : ";
    cin >> P.jumlah_barang;
    cout << "Masukan Info Barang            : ";
    cin >> P.info_barang;
    insertPenitip(lP, createNewPenitip(P));
    waitForEnter();
}

void menu_2_delete(listPenitip &lP) {
    penitip P;
    showAllPenitip(lP);
    cout << "Masukan Nama Penitip Yang Ingin Dihapus";
    cin >> P.nama_penitip;
    cout << "Masukan Tanggal Masuk Penitip Yang Ingin Dihapus";
    cin >> P.tanggal_masuk_barang;
    deletePenitip(lP, P.nama_penitip, P.tanggal_masuk_barang);
    waitForEnter();
}

void menuPenitip(char &n) {
    cout << "============DATA PENITIP============" << endl;
    cout << "1.Masukan Data Penitip" << endl;
    cout << "2.Delete Data Penitip" << endl;
    cout << "3.Cari Data Penitip" << endl;
    cout << "4.Tampilkan Data Penitip" << endl;
    cout << "1." << endl;
    cout << "0.Back" << endl;
    cout << "Pilih : ";
    cin >> n;
}

void menu_3(listGudang &lG, listPenitip &lP) {
    char menu;
    bool status = false;
    while (!status) {
        menuGudang(menu);
        if (menu == '1') {

        } else if (menu == '2') {

        } else if (menu == '3') {

        } else if (menu == '4') {

        } else if (menu == '0') {
            status = true;
        } else {
            cout << "\nINPUT INVALID" << endl;
            waitForEnter();
            clearScreen();
        }
    }
}

void menuRelasi(char &n) {
    cout << "============DATA RELASI============" << endl;
    cout << "1.Masukan Data Relasi" << endl;
    cout << "2.Delete Data Relasi" << endl;
    cout << "3.Cari Data Relasi" << endl;
    cout << "4.Edit Data Relasi" << endl;
    cout << "1." << endl;
    cout << "0.Back" << endl;
    cout << "Pilih : ";
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
        cout << "\nData Berhasil Ditambahkan" << endl;
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
        cout << "\nData Berhasil Ditambahkan" << endl;
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
        delete Q;
        cout << "\nData Berhasil Dihapus" << endl;
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
                adrRelasi beforeR = R;
                adrRelasi deleteR;
                if (R->nextPenitip == P) {
                    if (G->nextRelasi == R) {
                        deleteR = R;
                        R = R->nextRelasi;
                    } else if (R->nextRelasi == NULL) {

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
            cout<<"Nomor Gudang         : "<<G->info.nomor_gudang<<endl;
            cout<<"Slot Tersedia Gudang : "<<G->info.slot_tersedia_gudang<<endl;
            cout<<endl;
            G = G->next;
        }
    }
}

void showAllPenitip(listPenitip lP) {
    if (lP.first == NULL) {
        cout << "List penitip kosong!" << endl;
    } else {
        adrPenitip P = lP.first;
        while (P != NULL) {
            cout << "Nama Penitip         : " << P->info.nama_penitip << endl;
            cout << "Tanggal Masuk Barang : " << P->info.tanggal_masuk_barang << endl;
            cout << "Jumlah Barang        : " << P->info.jumlah_barang << endl;
            cout << "Info Barang          : " << P->info.info_barang << endl;
            cout << "-----------------------------" << endl;
            P = P->next;
        }
    }
}

void showPenitipDariGudangTertentu();
void showRelasiGudang();
void showRelasiPenitip(listPenitip lP, listGudang lG);
void showGudangPenitip(listGudang lG, adrPenitip P);
void hitungRelasiGudang(listGudang lG);
void hitungRelasiPenitipTertentu();
void hitungPenitipTakBerelasi();
void editSlotGudang(listGudang &lG, adrPenitip P, adrPenitip newP);
