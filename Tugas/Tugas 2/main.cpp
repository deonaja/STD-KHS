#include<iostream>
#include "sll.h"

using namespace std;

int main() {
    List mAI;
    string nama_barang_mAI;
    int harga_barang_mAI, jml_stok_mAI;
    infotype data_mAI;
    adr p_mAI;

    Create_List(mAI);

    cout << "Masukkan nama barang pertama: ";
    cin >> nama_barang_mAI;
    cout << "Masukkan harga: ";
    cin >> harga_barang_mAI;
    cout << "Masukkan jumlah stok: ";
    cin >> jml_stok_mAI;

    data_mAI.nama = nama_barang_mAI;
    data_mAI.harga = harga_barang_mAI;
    data_mAI.jml_stok = jml_stok_mAI;

    p_mAI = New_Elemen(data_mAI);
    Insert_First(mAI, p_mAI);

    cout << "Masukkan nama barang kedua: ";
    cin >> nama_barang_mAI;
    cout << "Masukkan harga: ";
    cin >> harga_barang_mAI;
    cout << "Masukkan jumlah stok: ";
    cin >> jml_stok_mAI;

    data_mAI.nama = nama_barang_mAI;
    data_mAI.harga = harga_barang_mAI;
    data_mAI.jml_stok = jml_stok_mAI;

    p_mAI = New_Elemen(data_mAI);
    Insert_Last(mAI, p_mAI);

    cout << "Masukkan nama barang ketiga: ";
    cin >> nama_barang_mAI;
    cout << "Masukkan harga: ";
    cin >> harga_barang_mAI;
    cout << "Masukkan jumlah stok: ";
    cin >> jml_stok_mAI;

    data_mAI.nama = nama_barang_mAI;
    data_mAI.harga = harga_barang_mAI;
    data_mAI.jml_stok = jml_stok_mAI;

    p_mAI = New_Elemen(data_mAI);
    Insert_First(mAI, p_mAI);

    cout << "Masukkan nama barang keempat: ";
    cin >> nama_barang_mAI;
    cout << "Masukkan harga: ";
    cin >> harga_barang_mAI;
    cout << "Masukkan jumlah stok: ";
    cin >> jml_stok_mAI;

    data_mAI.nama = nama_barang_mAI;
    data_mAI.harga = harga_barang_mAI;
    data_mAI.jml_stok = jml_stok_mAI;

    p_mAI = New_Elemen(data_mAI);
    Insert_Last(mAI, p_mAI);

    Show(mAI);

    Delete_First(mAI, p_mAI);
    cout << "Setelah menghapus data pertama: " << endl;
    Show(mAI);

    Delete_Last(mAI, p_mAI);
    cout << "Setelah menghapus data terakhir: " << endl;
    Show(mAI);

    return 0;
}
