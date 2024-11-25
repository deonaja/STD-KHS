#include <iostream>
#include "flight.h"

using namespace std;

int main()
{
    ListJadwal l;
    int n, i;
    string jad;
    adr_jadwalP p;
    infotype x;
    createListJadwal_103032300101(l);
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> x.asal;
        cin >> x.jenis;
        cin >> x.kapasitas;
        cin >> x.kode;
        cin >> x.tanggal;
        cin >> x.tujuan;
        cin >> x.waktu;
        p = createElemenJadwal_103032300101(x);
        InsertLastJ_103032300101(l, p);
    }

    cout << "\nData Sebelum Delete Jadwal Penerbangan Terbaru" << endl;
    ShowJadwal_103032300101(l);
    DeleteFirstJ_103032300101(l,p);
    cout << "\nData Setelah Delete Jadwal Penerbangan Terbaru" << endl;
    ShowJadwal_103032300101(l);

    p = SearchJ_103032300101(l, "surabaya", "malang", "9_Desember_2022");
    if (p == NULL) {
        cout << "\nJadwal Penerbangan Tidak Ditemukan" << endl;
    } else {
        cout << "\nJadwal Penerbangan Ditemukan Dengan Spesifik Sebagai Berikut : " << endl;
        cout << p->info.kode << ", " << p->info.jenis << ", " << p->info.tanggal << ", " << p->info.waktu << ", " << p->info.asal << ", " << p->info.tujuan << ", " << p->info.kapasitas << endl;
    }

    return 0;
}
