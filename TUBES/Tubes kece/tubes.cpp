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
            cout << "INPUT INVALID" << endl;
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
            menu_1_insert(lG);
            clearScreen();
        } else if (menu == '2') {
            menu_1_delete(lG);
            clearScreen();
        } else if (menu == '3') {
            menu_1_find(lG);
            clearScreen();
        } else if (menu == '4') {
            showAllGudang(lG);
            waitForEnter();
            clearScreen();
        } else if (menu == '0') {
            status = true;
            clearScreen();
        } else {
            cout << "INPUT INVALID" << endl;
            waitForEnter();
            clearScreen();
        }
    }
}

void menu_1_insert(listGudang &lG) {
    gudang G;
    cout << "Masukan Nomor Gudang   : ";
    cin >> G.nomor_gudang;
    cout << "Masukan Slot Gudang    : ";
    cin >> G.slot_tersedia_gudang;
    while (G.slot_tersedia_gudang <= 0) {
        cout << "Input Harus Lebih Besar Dari 0 !!!" << endl;
        cout << "Masukan Slot Tersedia Gudang   : ";
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
        waitForEnter();
        clearScreen();
    }
}

void menu_1_delete(listGudang &lG) {
    gudang G;
    showAllGudang(lG);
    cout << "Masukan Nomor Gudang Yang Ingin Dihapus : ";
    cin >> G.nomor_gudang;
    if (findGudang(lG, G.nomor_gudang) == NULL) {
        cout << "Gudang dengan nomor " << G.nomor_gudang << " tidak ditemukan" << endl;
    } else {
        deleteGudang(lG, findGudang(lG, G.nomor_gudang));
    }
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
    cout << "0.Back" << endl;
    cout << "Pilih : ";
    cin >> n;
}

void menu_2(listGudang &lG, listPenitip &lP) {
    char menu;
    bool status = false;
    string Back;
    while (!status) {
        menuPenitip(menu);
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
            menu_2_show(lP);
            clearScreen();
        } else if (menu == '0') {
            status = true;
            clearScreen();
        } else {
            cout << "INPUT INVALID" << endl;
            waitForEnter();
            clearScreen();
        }
    }
}

void menu_2_insert(listPenitip &lP) {
    penitip P;
    cout << "Masukan Nama Penitip                       : ";
    cin >> P.nama_penitip;
    cout << "Masukan Tanggal Masuk Barang (dd-mm-yyyy)  : ";
    cin >> P.tanggal_masuk_barang;
    cout << "Masukan Jumlah Barang                      : ";
    cin >> P.jumlah_barang;
    if (P.jumlah_barang <= 0 || P.jumlah_barang > 5) {
        cout << "Input Harus Lebih Besar Dari 0 dan Tidak Boleh Lebih Besar Dari 5!!!" << endl;
        waitForEnter();
        clearScreen();
        return;
    }
    for (int i = 0; i < P.jumlah_barang; i++) {
        cout << "Masukan Info Barang Ke-" << i + 1 << " : ";
        cin >> P.info_barang[i];
    }
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
    int i = 0;
    while (findPenitip(lP, P.nama_penitip, P.tanggal_masuk_barang) != NULL) {
        deletePenitip(lP, P.nama_penitip, P.tanggal_masuk_barang);
        i++;
    }
    if (i > 0) {
        cout << "Total Penitip dengan nama " << P.nama_penitip << " dan tanggal " << P.tanggal_masuk_barang << " yang dihapus : " << i << endl;
    }
    waitForEnter();
}

void menu_2_find(listPenitip &lP) {
    penitip P;
    cout << "Masukan Nama Penitip Yang Ingin Dicari            : ";
    cin >> P.nama_penitip;
    cout << "Masukan Tanggal Masuk Penitip Yang Ingin Dicari   : ";
    cin >> P.tanggal_masuk_barang;
    adrPenitip findP = lP.first;
    int i = 0;
    while (findP != NULL) {
        if (findP->info.nama_penitip == P.nama_penitip && findP->info.tanggal_masuk_barang == P.tanggal_masuk_barang) {
            cout << "Penitip dengan nama " << P.nama_penitip << " dan tanggal " << P.tanggal_masuk_barang << " ditemukan" << endl;
            cout << "Data Penitip :" << endl << endl;
            cout << "Nama Penitip         : " << findP->info.nama_penitip << endl;
            cout << "Tanggal Masuk Barang : " << findP->info.tanggal_masuk_barang << endl;
            cout << "Jumlah Barang        : " << findP->info.jumlah_barang << endl;
            for (int i = 0; i < findP->info.jumlah_barang; i++) {
                cout << "Info Barang Ke-" << i + 1 << " : " << findP->info.info_barang[i] << endl;
            }
            cout << endl;
            i++;
        }
        findP = findP->next;
    }
    if (i = 0) {
        cout << "Penitip dengan nama " << P.nama_penitip << " dan tanggal " << P.tanggal_masuk_barang << " tidak ditemukan" << endl;
    } else {
        cout << "Total Penitip dengan nama " << P.nama_penitip << " dan tanggal " << P.tanggal_masuk_barang << " ditemukan : " << i << endl;
    }
    waitForEnter();
}

void menu_2_show(listPenitip &lP) {
    showAllPenitip(lP);
    waitForEnter();
}

void menuPenitip(char &n) {
    cout << "============DATA PENITIP============" << endl;
    cout << "1.Masukan Data Penitip" << endl;
    cout << "2.Delete Data Penitip" << endl;
    cout << "3.Cari Data Penitip" << endl;
    cout << "4.Tampilkan Data Penitip" << endl;
    cout << "0.Back" << endl;
    cout << "Pilih : ";
    cin >> n;
}

void menu_3(listGudang &lG, listPenitip &lP) {
    char menu;
    bool status = false;
    while (!status) {
        menuRelasi(menu);
        if (menu == '1') {
            menu_3_insert(lG, lP);
            clearScreen();
        } else if (menu == '2') {
            menu_3_delete(lG, lP);
            clearScreen();
        } else if (menu == '3') {
            menu_3_find(lG, lP);
            clearScreen();
        } else if (menu == '4') {
            showRelasiGudang(lG, lP);
            waitForEnter();
            clearScreen();
        } else if (menu == '5') {
            menu_3_showPenitipGudangTertentu(lG, lP);
        } else if (menu == '6') {
            menu_3_relasiPenitip(lG, lP);
        } else if (menu == '0') {
            status = true;
            clearScreen();
        } else {
            cout << "INPUT INVALID" << endl;
            waitForEnter();
            clearScreen();
        }
    }
}

void menu_3_insert(listGudang &lG, listPenitip &lP) {
    int nomor_gudang;
    string nama_penitip, tanggal_masuk_barang;
    if (lG.first == NULL) {
        cout << "Tidak Ada Gudang" << endl;
        waitForEnter();
        clearScreen();
        return;
    }
    showAllGudang(lG);
    cout << "Masukan Nomor Gudang  : ";
    cin >> nomor_gudang;
    adrGudang G = findGudang(lG, nomor_gudang);
    if (G == NULL) {
        cout << "Gudang Tidak Ditemukan" << endl;
        waitForEnter();
        clearScreen();
        return;
    } else if (G->info.slot_tersedia_gudang == 0) {
        cout << "Slot Gudang /" << G->info.nomor_gudang << "/ Sudah Penuh" << endl;
        waitForEnter();
        clearScreen();
        return;
    }
    showAllPenitip(lP);
    cout << "Masukan Nama Penitip           : ";
    cin >> nama_penitip;
    cout << "Masukan Tanggal Masuk Barang   : ";
    cin >> tanggal_masuk_barang;
    adrPenitip P = findPenitip(lP, nama_penitip, tanggal_masuk_barang);
    if (P == NULL) {
        cout << "Penitip Tidak Ditemukan" << endl;
        waitForEnter();
        clearScreen();
        return;
    }
    adrRelasi R = findRelasi(G, P);
    if (R != NULL) {
        cout << "Data Relasi Sudah Ada" << endl;
        waitForEnter();
        clearScreen();
        return;
    }
    insertRelation(lP, lG, G, P);
    waitForEnter();
}

void menu_3_delete(listGudang &lG, listPenitip &lP) {
    int nomor_gudang;
    string nama_penitip, tanggal_masuk_barang;

    showRelasiGudang(lG, lP);
    cout << "Masukan Nomor Gudang  : ";
    cin >> nomor_gudang;
    adrGudang G = findGudang(lG, nomor_gudang);
    if (G == NULL) {
        cout << "Gudang Tidak Ditemukan" << endl;
        waitForEnter();
        clearScreen();
        return;
    } else if (G->nextRelasi == NULL) {
        cout << "Slot Gudang /" << G->info.nomor_gudang << "/ Tidak Memiliki Relasi" << endl;
        waitForEnter();
        clearScreen();
        return;
    }
    cout << "Masukan Nama Penitip           : ";
    cin >> nama_penitip;
    cout << "Masukan Tanggal Masuk Barang   : ";
    cin >> tanggal_masuk_barang;
    adrPenitip P = findPenitip(lP, nama_penitip, tanggal_masuk_barang);
    if (P == NULL) {
        cout << "Penitip Tidak Ditemukan" << endl;
        waitForEnter();
        clearScreen();
        return;
    }
    deleteRelasi(lG, G, P);
    waitForEnter();
}

void menu_3_find(listGudang &lG, listPenitip &lP) {
    int nomor_gudang;
    string nama_penitip, tanggal_masuk_barang;
    if (lG.first == NULL) {
        cout << "Tidak Ada Gudang" << endl;
        waitForEnter();
        clearScreen();
        return;
    }
    showAllGudang(lG);
    cout << "Masukan Nomor Gudang   : ";
    cin >> nomor_gudang;
    adrGudang G = findGudang(lG, nomor_gudang);
    if (G == NULL) {
        cout << "Gudang Tidak Ditemukan" << endl;
        waitForEnter();
        clearScreen();
        return;
    }
    showAllPenitip(lP);
    cout << "Masukan Nama Penitip           : ";
    cin >> nama_penitip;
    cout << "Masukan Tanggal Masuk Barang   : ";
    cin >> tanggal_masuk_barang;
    adrPenitip P = findPenitip(lP, nama_penitip, tanggal_masuk_barang);
    if (P == NULL) {
        cout << "Penitip Tidak Ditemukan" << endl;
        waitForEnter();
        clearScreen();
        return;
    }
    adrRelasi R = findRelasi(G, P);
    if (R == NULL) {
        cout << "Data Tidak Ditemukan" << endl;
    } else {
        cout << "Data Ditemukan" << endl;
        cout << "Data Gudang          :" << endl;
        cout << "Nomor Gudang         : " << G->info.nomor_gudang << endl;
        cout << "Slot Tersedia Gudang : " << G->info.slot_tersedia_gudang << endl;
        cout << "Nama Penitip           : " << P->info.nama_penitip << endl;
        cout << "Tanggal Masuk Barang   : " << P->info.tanggal_masuk_barang << endl;
        cout << "Jumlah Barang          : " << P->info.jumlah_barang << endl;
        for (int i = 0; i < P->info.jumlah_barang; i++) {
            cout << "Info Barang Ke-" << i + 1 << " : " << P->info.info_barang[i] << endl;
        }
    }
    waitForEnter();
}

void menu_3_showPenitipGudangTertentu(listGudang &lG, listPenitip &lP) {
    int nomor_gudang;
    cout << "Masukan Nomor Gudang   : ";
    cin >> nomor_gudang;
    adrGudang G = findGudang(lG, nomor_gudang);
    if (G == NULL) {
        cout << "Gudang Tidak Ditemukan" << endl;
        waitForEnter();
        clearScreen();
        return;
    }
    showPenitipDariGudangTertentu(lP, lG, G);
    waitForEnter();
}

void menu_3_relasiPenitip(listGudang &lG, listPenitip &lP) {
    string nama_penitip, tanggal_masuk_barang;
    cout << "Masukan Nama Penitip           : ";
    cin >> nama_penitip;
    cout << "Masukan Tanggal Masuk Barang   : ";
    cin >> tanggal_masuk_barang;
    adrPenitip P = findPenitip(lP, nama_penitip, tanggal_masuk_barang);
    if (P == NULL) {
        cout << "Penitip Tidak Ditemukan" << endl;
        waitForEnter();
        clearScreen();
        return;
    }
    showRelasiPenitip(lP, lG, P);
    waitForEnter();
}

void menuRelasi(char &n) {
    cout << "============DATA RELASI============" << endl;
    cout << "1.Masukan Data Relasi" << endl;
    cout << "2.Delete Data Relasi" << endl;
    cout << "3.Cari Data Relasi" << endl;
    cout << "4.Show Data Relasi" << endl;
    cout << "5.Show Data Penitip Dari Gudang Tertentu" << endl;
    cout << "6.Show Data Penitip Beserta Data Gudang Yang Masing Masing Penitip Tempati" << endl;
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

void insertRelation(listPenitip lP, listGudang &lG, adrGudang G, adrPenitip P) {
    if (G->info.slot_tersedia_gudang > 0) {
        adrGudang tempG = lG.first;
        while (tempG != NULL) {
            if (tempG->info.nomor_gudang == G->info.nomor_gudang) {
                adrPenitip tempP = findPenitip(lP, P->info.nama_penitip, P->info.tanggal_masuk_barang);
                if (tempP != NULL) {
                    adrRelasi R = createNewRelasi(tempP);
                    if (tempG->nextRelasi == NULL) {
                        tempG->nextRelasi = R;
                    } else {
                        adrRelasi Q = tempG->nextRelasi;
                        while (Q->nextRelasi != NULL) {
                            Q = Q->nextRelasi;
                        }
                        Q->nextRelasi = R;
                    }
                    tempG->info.slot_tersedia_gudang--;
                    cout << "Data Berhasil Ditambahkan" << endl;
                }
            }
            tempG = tempG->next;
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
        cout << "\nData Berhasil Dihapus" << endl;
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

void deleteRelasi(listGudang &lG, adrGudang G, adrPenitip P) {
    if (lG.first == NULL) {
        cout << "Tidak Ada Gudang" << endl;
    } else {
        adrGudang tempG = findGudang(lG, G->info.nomor_gudang);
        if (tempG == NULL) {
            cout << "Gudang Tidak Ditemukan" << endl;
        } else {
            adrRelasi R = findRelasi(tempG, P);
            if (R == NULL) {
                cout << "Data Tidak Ditemukan" << endl;
            } else {
                if (tempG->nextRelasi == R) {
                    tempG->nextRelasi = R->nextRelasi;
                    R->nextRelasi = NULL;
                } else {
                    adrRelasi Q = tempG->nextRelasi;
                    while (Q->nextRelasi != R) {
                        Q = Q->nextRelasi;
                    }
                    Q->nextRelasi = R->nextRelasi;
                    R->nextRelasi = NULL;
                }
                tempG->info.slot_tersedia_gudang++;
                cout << "Data Berhasil Dihapus" << endl;
            }
        }
//        adrGudang G = lG.first;
//        while (G != NULL) {
//            adrRelasi R = G->nextRelasi;
//            while (R != NULL) {
//                if (R->nextPenitip == P) {
//                    if (R == G->nextRelasi) {
//                        G->nextRelasi = R->nextRelasi;
//                        R->nextRelasi = NULL;
//                    } else {
//                        adrRelasi Q = G->nextRelasi;
//                        while (Q->nextRelasi != R) {
//                            Q = Q->nextRelasi;
//                        }
//                        Q->nextRelasi = R->nextRelasi;
//                        R->nextRelasi = NULL;
//                    }
//                    G->info.slot_tersedia_gudang++;
//                    cout << "Data Berhasil Dihapus" << endl;
//                }
//                R = R->nextRelasi;
//
////                adrRelasi beforeR;
////                adrRelasi deleteR;
////                if (R->nextPenitip == P) {
////                    deleteR = R;
////                    if (G->nextRelasi == R) {
////                        R = R->nextRelasi;
////                    } else if (R->nextRelasi == NULL) {
////                        beforeR = NULL;
////                    } else {
////                        beforeR = deleteR->nextRelasi;
////                        deleteR->nextRelasi = NULL;
////                    }
////                    G->info.slot_tersedia_gudang++;
////                }
////                delete deleteR;
////                beforeR = R;
////                R = R->nextRelasi;
//            }
//            G = G->next;
//        }
    }

}

adrGudang findGudang(listGudang &lG, int nomor_gudang){
    if(lG.first == NULL){
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

adrRelasi findRelasi(adrGudang G, adrPenitip P) {
    adrRelasi R = G->nextRelasi;
    while (R != NULL) {
        if (R->nextPenitip == P) {
            return R;
        }
        R = R->nextRelasi;
    }
    return NULL;
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
            for (int i = 0; i < P->info.jumlah_barang; i++) {
                cout << "Info Barang Ke-" << i + 1 << " : " << P->info.info_barang[i] << endl;
            }
            cout << "-----------------------------" << endl;
            P = P->next;
        }
    }
}

void showPenitipDariGudangTertentu(listPenitip lP, listGudang lG, adrGudang G) {
    if (G == NULL) {
        cout << "Gudang tidak ditemukan!" << endl;
        return;
    }
    adrPenitip P = lP.first;
    bool ketemu = false;
    while (P != NULL) {
        adrRelasi R = P->nextRelasi;
        while (R != NULL) {
            if (R->nextGudang == G) {
                cout << "Nama Penitip         : " << P->info.nama_penitip << endl;
                cout << "Tanggal Masuk Barang : " << P->info.tanggal_masuk_barang << endl;
                cout << "Jumlah Barang        : " << P->info.jumlah_barang << endl;
                for (int i = 0; i < P->info.jumlah_barang && i < 5; i++) {
                    cout << "Info Barang Ke-" << i + 1 << " : " << P->info.info_barang[i] << endl;
                }
                cout << "-----------------------------" << endl;
                ketemu = true;
            }
            R = R->nextRelasi;
        }
        P = P->next;
    }

    if (!ketemu) {
        cout << "Tidak ada penitip di gudang dengan nomor: " << G->info.nomor_gudang << endl;
    }
}

void showRelasiGudang(listGudang lG, listPenitip lP) {
    if (lG.first == NULL) {
        cout << "List gudang kosong!" << endl;
        return;
    }
    adrGudang G = lG.first;
    while (G != NULL) {
        cout << "==============================" << endl;
        cout << "Nomor Gudang         : " << G->info.nomor_gudang << endl;
        cout << "Slot Tersedia Gudang : " << G->info.slot_tersedia_gudang << endl;

        adrRelasi R = G->nextRelasi;
        if (R == NULL) {
            cout << "Tidak ada slot gudang yang terpakai." << endl;
        } else {
            cout << "Slot Terpakai Oleh Data Berikut:" << endl;
            while (R != NULL) {
                cout << "------------------------------" << endl;
                cout << "Nama Penitip         : " << R->nextPenitip->info.nama_penitip << endl;
                cout << "Tanggal Masuk Barang : " << R->nextPenitip->info.tanggal_masuk_barang << endl;
                cout << "Jumlah Barang        : " << R->nextPenitip->info.jumlah_barang << endl;
                for (int i = 0; i < R->nextPenitip->info.jumlah_barang; i++) {
                    cout << "Info Barang Ke-" << i + 1 << " : " << R->nextPenitip->info.info_barang[i] << endl;
                }
                cout << "------------------------------" << endl;
                R = R->nextRelasi;
            }
        }
        G = G->next;
    }
    cout << "==============================" << endl;
}

void showRelasiPenitip(listPenitip lP, listGudang lG, adrPenitip P) {
    adrPenitip tempP = lP.first;
    bool find;
    while (tempP != NULL) {
        cout << "------------------------------" << endl;
        cout << "Nama Penitip         : " << P->info.nama_penitip << endl;
        cout << "Tanggal Masuk Barang : " << P->info.tanggal_masuk_barang << endl;
        cout << "Jumlah Barang        : " << P->info.jumlah_barang << endl;
        for (int i = 0; i < P->info.jumlah_barang; i++) {
            cout << "Info Barang Ke-" << i + 1 << " : " << P->info.info_barang[i] << endl;
        }
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

void hitungRelasiPenitipTertentu(listGudang lG, string nama_penitip) {
    adrGudang G = lG.first;
    int jumlahRelasi = 0;
    while (G != NULL) {
        adrRelasi R = G->nextRelasi;
        while (R != NULL) {
            if (R->nextPenitip->info.nama_penitip == nama_penitip) {
                jumlahRelasi++;
            }
            R = R->nextRelasi;
        }

        G = G->next;
    }
    if (jumlahRelasi > 0) {
        cout << "Penitip \"" << nama_penitip << "\" memiliki " << jumlahRelasi << " relasi dengan gudang." << endl;
    } else {
        cout << "Penitip dengan nama \"" << nama_penitip << "\" tidak memiliki relasi dengan gudang." << endl;
    }
}

void hitungPenitipTakBerelasi(listPenitip lP, listGudang lG){
    int count = 0;
    adrPenitip P = lP.first;
    while (P != NULL) {
        bool hasRelation = false;
        adrGudang G = lG.first;
        while (G != NULL && !hasRelation) {
            adrRelasi R = G->nextRelasi;
            while (R != NULL) {
                if (R->nextPenitip == P) {
                    hasRelation = true;
                    break;
                }
                R = R->nextRelasi;
            }
            G = G->next;
        }
        if (!hasRelation) {
            count++;
        }
        P = P->next;
    }
    cout << "Jumlah penitip tanpa relasi: " << count << endl;
}

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
