#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <limits>

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
    adrGudang nextGudang;
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

struct listRelasi{
    adrRelasi first;
};

void clearScreen();
void waitForEnter();
void menu(listGudang &lG, listPenitip &lP);
void mainMenu(char &n);
void menu_1(listGudang &lG, listPenitip &lP);
void menu_1_insert(listGudang &lG);
void menu_1_delete(listGudang &lG);
void menu_1_find(listGudang &lG);
void menu_2(listGudang &lG, listPenitip &lP);
void menu_2_insert(listPenitip &lP);
void menu_2_delete(listPenitip &lP);
void menu_3(listGudang &lG, listPenitip &lP);
void menuGudang(char &n);
void menuPenitip(char &n);
void menuRelasi(char &n);
adrGudang createNewGudang(gudang x);
adrPenitip createNewPenitip(penitip x);
adrRelasi createNewRelasi(adrPenitip P);
void insertGudang(listGudang &lG, adrGudang G);
void insertPenitip(listPenitip &lP, adrPenitip P);
void insertRelation(listPenitip lP, listGudang lG, adrGudang G, adrPenitip P); //G untuk data parent yang ingin ditambah relasinya; P untuk child yang akan direlasikan ke parent
void deleteGudang(listGudang &lG, adrGudang G);
void deletePenitip(listPenitip &lP, string nama, string tanggal);
void deleteRelasi(listGudang &lG, adrPenitip P);
adrGudang findGudang(listGudang &lG, int nomor_gudang);
adrPenitip findPenitip(listPenitip &lP, string nama, string tanggal);
void findRelasi(listGudang &lG, adrPenitip P); //  P untuk mencari relasi dari parent
void showAllGudang(listGudang lG);
void showAllPenitip(listPenitip lP);
void showPenitipDariGudangTertentu();
void showRelasiGudang();
void showRelasiPenitip(listPenitip lP, listGudang lG);
void showGudangPenitip(listGudang lG, adrPenitip P);
void hitungRelasiGudang(listGudang lG);
void hitungRelasiPenitipTertentu();
void hitungPenitipTakBerelasi();
void editSlotGudang(listGudang &lG, adrPenitip P, adrPenitip newP); // P untuk relasi child yang ingin diganti; newP untuk tujuan baru relasi yang diganti


#endif // TUBES_H_INCLUDED
