#include "tubes.h"

adrGudang createNewGudang(gudang x) {
    adrGudang G = new elemenGudang;
    G->info.nomor_gudang = x.nomor_gudang;
    G->info.slot_tersedia_gudang = x.slot_tersedia_gudang;
    G->next = NULL;
    G->nextRelasi = NULL;
    return G;
}
adrPenitip createNewPenitip(penitip x);

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

void insertPenitip();
void insertRelation(listGudang &lG, adrGudang G, adrPenitip P) {

} //G untuk data parent yang ingin ditambah relasinya; P untuk child yang akan direlasikan ke parent
void deleteGudang();
void deletePenitip();
void deleteRelasi(listGudang &lG, adrGudang G); // G untuk data parent yang ingin dihapus
void findGudang();
void findPenitip();
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
void editSlotGudang(listGudang &lG, adrPenitip P, adrPenitip newP); // P untuk relasi child yang ingin diganti; newP untuk tujuan baru relasi yang diganti
