#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct elemenGudang* adrGudang;
typedef struct elemenPenitip* adrPenitip;
typedef struct elemenRelasi* adrRelasi;

struct gudang {
    int nomor_gudang;
    int slot_tersedia_gudang;
};

struct penitip {
    string nama_penitip;
    string tanggal_masuk_barang;
    int jumlah_barang;
    string info_barang;
};

struct elemenRelasi {
    adrRelasi nextRelasi;
    adrPenitip nextPenitip;
};

struct elemenGudang {
    gudang info;
    adrRelasi nextRelasi;
    adrGudang next;
};

struct elemenPenitip {
    penitip info;
    adrPenitip next;
    adrPenitip prev;
};

struct listPenitip {
    adrPenitip first;
    adrPenitip last;
};

struct listGudang {
    adrGudang first;
};

void menu();
adrGudang createNewGudang(gudang x);
adrPenitip createNewPenitip(penitip x);
adrRelasi createNewRelasi(adrPenitip P);
void insertGudang(listGudang &lG, int nomor_gudang, int slot_tersedia_gudang);
void insertPenitip(listPenitip &lP, adrPenitip P);
void insertRelation(adrGudang G, adrPenitip P); //G untuk data parent yang ingin ditambah relasinya; P untuk child yang akan direlasikan ke parent
void deleteGudang();
void deletePenitip(listPenitip &lP, string nama, string tanggal);
void deleteRelasi(listGudang &lG, adrGudang G); // G untuk data parent yang ingin dihapus
adrGudang findGudang();
adrPenitip findPenitip(listPenitip &lP, string nama, string tanggal);
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


#endif // TUBES_H_INCLUDED
