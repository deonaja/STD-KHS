#include <iostream>
#define max 10

using namespace std;

const int nMax = 51;
struct mahasiswa {
    string NIM, nama;
    int nilai;
};

using arrMhs = mahasiswa[nMax];

int nilaiPertama(arrMhs T , int n, string NIM){
    int idx = -1, i = 0;

    while (idx == -1 && i < n) {
        if (T[i].NIM == NIM) {
            idx = i;
        }
        i++;
    }
    return idx;
}

int main(){
    arrMhs mahasiswa;
    int nData, idx, i;
    string nim, nama;
    cin >> nData;
    if (nData > nMax) {
        nData = nMax;
    }
    for (i = 0; i < nData; i++) {
        cin >> mahasiswa[i].NIM >> mahasiswa[i].nama >> mahasiswa[i].nilai;
    }
    cin >> nim;
    idx = nilaiPertama(mahasiswa, nData, nim);
    if (idx != -1) {
        cout << mahasiswa[idx].nilai;
    } else {
        cout << idx;
    }
    return 0;
}
