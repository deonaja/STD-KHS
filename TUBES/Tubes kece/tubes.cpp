#include <tubes.h>

void insertGudang(listGudang &lG, infotypeG x){
    adrGudang G;
    G = new elemenGudang;
    G->info.nomor_gudang = x.nomor_gudang;
    G->info.slot_tersedia_gudang = x.slot_tersedia_gudang;
    G->next = NULL;
    if (lG.first==NULL){
        lG.first = G;
    }else{
        adrParent Q;
        Q = lG.first;
        while (Q->next!=NULL){
        Q = Q->next;
        }
        Q->next = G;
    }
}
