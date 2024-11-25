#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED
#include <iostream>

using namespace std;

struct jadwalPenerbangan {
    string kode;
    string jenis;
    string tanggal;
    string waktu;
    string asal;
    string tujuan;
    int kapasitas;
};

typedef struct jadwalPenerbangan infotype;
typedef struct elemenJadwal *adr_jadwalP;
struct elemenJadwal{
    infotype info;
    adr_jadwalP next;
};
struct ListJadwal{
    adr_jadwalP First;
};

void createListJadwal_103032300101(ListJadwal &L);
adr_jadwalP createElemenJadwal_103032300101(infotype X);
void InsertLastJ_103032300101(ListJadwal &L, adr_jadwalP P);
void ShowJadwal_103032300101(ListJadwal L);
void DeleteFirstJ_103032300101(ListJadwal &L, adr_jadwalP &P);
adr_jadwalP SearchJ_103032300101(ListJadwal L, string dari, string ke, string tanggal);

#endif // FLIGHT_H_INCLUDED
