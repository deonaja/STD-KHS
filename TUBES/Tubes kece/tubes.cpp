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
    while (!status) {
        mainMenu(menu);
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
    while (!status) {
        menuGudang(menu);
        if (menu == '1') {
            clearScreen();
            menu_1_insert(lG);
            clearScreen();
        } else if (menu == '2') {
            clearScreen();
            menu_1_delete(lG);
            clearScreen();
        } else if (menu == '3') {
            clearScreen();
            menu_1_find(lG);
            clearScreen();
        } else if (menu == '4') {
            clearScreen();
            showAllGudang(lG);
            waitForEnter();
            clearScreen();
        } else if (menu == '0') {
            status = true;
        } else {
            cout << "INPUT INVALID" << endl;
            waitForEnter();
            clearScreen();
        }
    }
}

void menu_1_insert(listGudang &lG) {
    gudang G;
    cout << "Masukan Nomor Gudang : ";
    cin >> G.nomor_gudang;
    cout << "Masukan Slot Tersedia Gudang : ";
    cin >> G.slot_tersedia_gudang;
    while (G.slot_tersedia_gudang <= 0) {
        cout << "Input Harus Lebih Besar Dari 0 !!!" << endl;
        cout << "Masukan Slot Tersedia Gudang : ";
        cin >> G.slot_tersedia_gudang;
    }
    bool unique = true;
    adrGudang tempG = lG.first;
    while (tempG != NULL && unique) {
        if (tempG->info.nomor_gudang == G.nomor_gudang) {
            unique = false;
        }
        tempG = tempG->next;
    }
    if (unique) {
        insertGudang(lG, createNewGudang(G));
        waitForEnter();
    } else {
        cout << "Nomor Gudang /" << G.nomor_gudang << "/ Sudah ada" << endl;
        menu_1_insert(lG);
    }
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
        cout << "Data Gudang :" << endl << endl;
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
            clearScreen();
        } else if (menu == '2') {
            menu_2_delete(lP);
            clearScreen();
        } else if (menu == '3') {
            menu_2_find(lP);
            clearScreen();
        } else if (menu == '4') {

        } else if (menu == '0') {
            status = true;
        } else {
            cout << "INPUT INVALID" << endl;
            waitForEnter();
            clearScreen();
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
    cout << "Masukan Nama Penitip Yang Ingin Dihapus            : ";
    cin >> P.nama_penitip;
    cout << "Masukan Tanggal Masuk Penitip Yang Ingin Dihapus   : ";
    cin >> P.tanggal_masuk_barang;
    deletePenitip(lP, P.nama_penitip, P.tanggal_masuk_barang);
    waitForEnter();
}

void menu_2_find(listPenitip &lP) {
    penitip P;
    cout << "Masukan Nama Penitip Yang Ingin Dicari                 : ";
    cin >> P.nama_penitip;
    cout << "Masukan Tanggal Masuk Barang Penitip Yang Ingin Dicari : ";
    cin >> P.tanggal_masuk_barang;
    adrPenitip findP = findPenitip(lP, P.nama_penitip, P.tanggal_masuk_barang);
    if (findP == NULL) {
        cout << "Data Penitip " << P.nama_penitip << " dan Tanggal " << P.tanggal_masuk_barang << " Tidak Ditemukan" << endl;
    } else {
        cout << "Data Penitip " << P.nama_penitip << " dan Tanggal " << P.tanggal_masuk_barang << " Ditemukan" << endl;
        cout << "Data Penitip" << endl;
        cout << "Nama Penitip                       : " << findP->info.nama_penitip << endl;
        cout << "Tanggal Masuk Barang penitip       : " << findP->info.tanggal_masuk_barang << endl;
        cout << "Jumlah Barang Penitip              : " << findP->info.jumlah_barang << endl;
        cout << "Info Barang Penitip                : " << findP->info.info_barang << endl;
    }
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
            cout << "INPUT INVALID" << endl;
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
    }
    cout << "\nData Berhasil Ditambahkan" << endl;
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
    if (G->info.slot_tersedia_gudang >= 0) {
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
            cout << "\nData Berhasil Ditambahkan" << endl;
        }
    } else {
        cout << "Slot Tersedia Gudang /" << G->info.nomor_gudang << "/ Habis \nSilahkan Input Di Gudang Lainnya" << endl;
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
                adrRelasi beforeR;
                adrRelasi deleteR;
                if (R->nextPenitip == P) {
                    deleteR = R;
                    if (G->nextRelasi == R) {
                        R = R->nextRelasi;
                    } else if (R->nextRelasi == NULL) {
                        beforeR = NULL;
                    } else {
                        beforeR = deleteR->nextRelasi;
                        deleteR->nextRelasi = NULL;
                    }
                }
                delete deleteR;
                beforeR = R;
                R = R->nextRelasi;
            }
            G = G->next;
        }
    }

}

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

void showPenitipDariGudangTertentu(listRelasi lR, adrGudang G){
    if(lR.first == NULL){
        cout<<"list relasi kosong!"<<endl;
    }else{
        adrRelasi R;
        R = lR.first;
        while(R!=NULL){
            if(R->nextGudang == G){
                cout<<"Nama Penitip         : "<<R->nextPenitip->info.nama_penitip<<endl;
                cout<<"Tanggal Masuk Barang : "<<R->nextPenitip->info.tanggal_masuk_barang<<endl;
                cout<<"Jumlah Barang        : "<<R->nextPenitip->info.jumlah_barang<<endl;
                cout<<"Info Barang          : "<<R->nextPenitip->info.info_barang<<endl;
            }
            R = R->nextRelasi;
        }
    }
}
void showRelasiGudang();
void showRelasiPenitip(listPenitip lP, listGudang lG, adrPenitip P) {
    adrPenitip tempP = lP.first;
    bool find;
    while (tempP != NULL) {
        cout << "------------------------------" << endl;
        cout << "Nama Penitip         : " << P->info.nama_penitip << endl;
        cout << "Tanggal Masuk Barang : " << P->info.tanggal_masuk_barang << endl;
        cout << "Jumlah Barang        : " << P->info.jumlah_barang << endl;
        cout << "Info Barang          : " << P->info.info_barang << endl;
        cout << "------------------------------" << endl;
        adrGudang G = lG.first;
        while (G != NULL) {
            find = false;
            adrRelasi R = G->nextRelasi;
            while (R != NULL && !find) {
                if (R->nextPenitip == P) {
                    cout << "Data Gudang Yang Berelasi Dengan " << P->info.nama_penitip << " :" << endl;
                    cout << "Nomor Gudang           : " << G->info.nomor_gudang;
                    cout << "Slot Tersedia Gudang   : " << G->info.slot_tersedia_gudang;
                    cout << "==============================" << endl;
                    find = true;
                }
                R = R->nextRelasi;
            }
        }
        if (!find) {
            cout << "Data Penitip /" << P->info.nama_penitip << "/ Belum Berelasi Dengan Gudang Manapun" << endl;
        }
        P = P->next;
    }
}

void showGudangPenitip(listGudang lG, adrPenitip P) {
    adrGudang G = lG.first;
    bool done = false;
    if (P == NULL) {
        cout << "Data Penitip /" << P->info.nama_penitip << "/ Tidak Ditemukan" << endl;
    } else {
        while (G != NULL) {
            adrRelasi R = G->nextRelasi;
            while (R != NULL) {
                if (R->nextPenitip == P) {
                    if (!done) {
                        cout << "Gudang yang Berelasi Dengan /" << P->info.nama_penitip << "/ Ditemukan" << endl;
                        done = true;
                    }
                    cout << endl;
                    cout << "------------------------------" << endl;
                    cout << "Nomor Gudang           : " << G->info.nomor_gudang;
                    cout << "Slot Tersedia Gudang   : " << G->info.slot_tersedia_gudang;
                    cout << "------------------------------" << endl;
                }
                R = R->nextRelasi;
            }
            G = G->next;
        }
    }
}
void hitungRelasiGudang(listGudang lG) {
    adrGudang G = lG.first;
    int i= 0;
    while (G != NULL) {
        adrRelasi R = G->nextRelasi;
        while (R != NULL) {
            i++;
            R = R->nextRelasi;
        }
        cout << "Relasi Nomor Gudang /" << G->info.nomor_gudang << "/ adalah " << i << endl;
        G = G->next;
    }
}

void hitungRelasiPenitipTertentu();
void hitungPenitipTakBerelasi();
void editSlotGudang(listGudang &lG, adrPenitip P, adrPenitip newP) {
    int i = 0;
    if (P == NULL) {
        cout << "Data Penitip Tidak Ditemukan" << endl;
    } else {
        adrGudang G = lG.first;
        while (G != NULL) {
            adrRelasi R = G->nextRelasi;
            while (R != NULL) {
                if (R->nextPenitip == P) {
                    R->nextPenitip = newP;
                    i++;
                }
                R = R->nextRelasi;
            }
            G = G->next;
        }
    }
    if (i == 0) {
        cout << "Tidak Ada Data Yang Dapat Diganti" << endl;
    } else {
        cout << "Data Berhasil Diganti" << endl;
        cout << "Sebanyak /" << i << "/ Data Diganti" << endl;
    }
}
