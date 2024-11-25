#include <iostream>

using namespace std;

int kendaraan(int kapasitan_kendaraan, int jumlah_penumpang) {
    int jumlah;
    jumlah = jumlah_penumpang / kapasitan_kendaraan;
    if (jumlah_penumpang % kapasitan_kendaraan > 0) {
        jumlah++;
    }
    return jumlah;
}
int main()
{
    int kap_kendaraan, jum_penumpang, banyak_kendaraan;
    cout << "Masukan kapasitas kendaraan ";
    cin >> kap_kendaraan;
    cout << "Masukan jumlah penumpang ";
    cin >> jum_penumpang;
    banyak_kendaraan = kendaraan(kap_kendaraan, jum_penumpang);
    cout << "Banyak kendaraan yang disewa " << banyak_kendaraan << endl;
    return 0;
}
