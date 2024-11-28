#include "tubes.h"

void menu(listGudang lG, listPenitip lP){
    bool status = false;
    while (!status) {
        char menu;
        mainMenu(menu);
        if (menu == 1) {

        } else if (menu == 2){

        } else if (menu == 3){

        } else if (menu == 4){
            status = true;
        } else {
            cout << "INPUT INVALID" << endl;
        }

    }
}

void mainMenu(char &n) {
    cout << "==========MAIN MENU==========" << endl;
    cout << "1.DATA GUDANG" << endl;
    cout << "2.DATA PENITIP" << endl;
    cout << "3.DATA RELASI" << endl;
    cout << "4.EXIT" << endl;
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
    adrGudang findG = findGudang();
    adrPenitip findP = findPenitip(lG,);
    if (findG != NULL && findP != NULL) {
        adrRelasi R = findG->nextRelasi;
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

void deleteRelasi(listGudang &lG, adrGudang G); // G untuk data parent yang ingin dihapus

adrGudang findGudang();

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

void findRelasi(listGudang &lG, adrPenitip P); //  P untuk mencari relasi dari parent
void showAllGudang();
void showAllPenitip();
void showPenitipDariGudangTertentu();
void showRelasiGudang();
void showRelasiPenitip(listPenitip lP, listGudang lG);
void showGudangPenitip(listGudang lG, adrPenitip P);
void hitungRelasiGudang(listGudang lG);
void hitungRelasiPenitipTertentu();
void hitungPenitipTakBerelasi();
void editSlotGudang(listGudang &lG, adrPenitip P, adrPenitip newP);
