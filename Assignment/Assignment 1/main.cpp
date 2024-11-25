#include <iostream>
#include "queue_vaksinasi.h"

using namespace std;

int main()
{
    // Membuat antrean
    Queue Q;
    createQueue_103032300101(Q);
    // Menambahkan beberapa elemen ke dalam queue
    ElemQ* P1 = createElemQueue_103032300101("John Doe", 65, "lansia", 1);
    ElemQ* P2 = createElemQueue_103032300101("Alice", 30, "tenaga kesehatan", 2);
    ElemQ* P3 = createElemQueue_103032300101("Bob", 25, "pekerja", 3);
    ElemQ* P4 = createElemQueue_103032300101("Charlie", 70, "pensiunan", 4);
    ElemQ* P5 = createElemQueue_103032300101("David", 28, "pekerja", 5);
    enqueue_103032300101(Q, P1);
    enqueue_103032300101(Q, P2);
    enqueue_103032300101(Q, P3);
    enqueue_103032300101(Q, P4);
    enqueue_103032300101(Q, P5);
    // Menampilkan isi queue
    cout << "Isi antrean awal:" << endl;
    printInfo_103032300101(Q);
    // Melayani antrean
    cout << "\nMelakukan pelayanan pada antrean:" << endl;
    serveQueue_103032300101(Q);
    // Memeriksa antrean setelah pelayanan
    cout << "\nIsi antrean setelah pelayanan:" << endl;
    printInfo_103032300101(Q);
    // Menambahkan elemen baru untuk simulasi pengaturan ulang prioritas
    ElemQ* P6 = createElemQueue_103032300101("Edward", 22, "pekerja", 6);
    enqueue_103032300101(Q, P1);
    enqueue_103032300101(Q, P2);
    enqueue_103032300101(Q, P3);
    enqueue_103032300101(Q, P4);
    enqueue_103032300101(Q, P5);
    // Simulasi reassignQueue untuk mengatur ulang antrean ke prioritas
    cout << "\nMengatur ulang antrean berdasarkan prioritas:" << endl;
    reassignQueue_103032300101(Q);
    printInfo_103032300101(Q);
    // Simulasi kondisi warga yang menunggu lebih dari 2 jam
    cout << "\nMemeriksa waktu tunggu dan mengubah prioritas jika lebih dari 2 jam:" << endl;
    checkWaitingTime_103032300101(Q, 110); // Asumsikan waktu sekarang 130 menit dari nomor antrean pertama
    printInfo_103032300101(Q);
    // Menangani kondisi darurat untuk seorang warga
    cout << "\nMenangani kondisi darurat untuk warga dengan nomor antrean 5:" << endl;
    emergencyHandle_103032300101(Q, 5);
    printInfo_103032300101(Q);
    // Update prioritas warga setiap jam
    cout << "\nMengupdate prioritas antrean setiap jam:" << endl;
    updatePriority_103032300101(Q);
    printInfo_103032300101(Q);
    // Mencari dan menghapus warga dengan nomor antrean tertentu
    cout << "\nMenghapus warga dengan nomor antrean 3:" << endl;
    ElemQ* removedElem = findAndRemove_103032300101(Q, 3);
    if (removedElem) {
        cout << "Warga yang dihapus: " << removedElem->info.nama << endl;
    }
    printInfo_103032300101(Q);
    // Mengecek ukuran queue
    cout << "\nUkuran antrean saat ini: " << size_103032300101(Q) << endl;
    return 0;
}
