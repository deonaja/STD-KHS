#include "tubes.h"

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

void insertPenitip();
void insertRelation(adrGudang G, adrPenitip P) {
    adrGudang findG = findGudang();
    adrPenitip findP = findPenitip();
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
