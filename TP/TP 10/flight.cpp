#include "flight.h"

void createListJadwal_103032300101(ListJadwal &L) {
    L.First = NULL;
}

adr_jadwalP createElemenJadwal_103032300101(infotype X) {
    adr_jadwalP p = new elemenJadwal;
    p->info = X;
    p->next = NULL;
    return p;
}

void InsertLastJ_103032300101(ListJadwal &L, adr_jadwalP P) {
    if (L.First == NULL) {
        L.First = P;
    } else {
        adr_jadwalP q = L.First;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = P;
    }
}

void ShowJadwal_103032300101(ListJadwal L) {
    adr_jadwalP P = L.First;
    while (P != NULL) {
        cout << P->info.kode << ", " << P->info.jenis << ", " << P->info.tanggal << ", " << P->info.waktu << ", " << P->info.asal << ", " << P->info.tujuan << ", " << P->info.kapasitas << endl;
        P = P->next;
    }
}

void DeleteFirstJ_103032300101(ListJadwal &L, adr_jadwalP &P) {
    P = L.First;
    if (L.First == NULL) {
        P = NULL;
    } else {
        if (L.First->next == NULL) {
            L.First = NULL;
        } else {
            L.First = L.First->next;
            P = P->next;
        }
    }
}

adr_jadwalP SearchJ_103032300101(ListJadwal L, string dari, string ke, string tanggal) {
    if (L.First == NULL) {
        return NULL;
    } else {
        adr_jadwalP q = L.First;
        while (q != NULL) {
            if (q->info.asal == dari && q->info.tujuan == ke && q->info.tanggal == tanggal) {
                return q;
            }
            q = q->next;
        }
    }
}
