#include "queue_vaksinasi.h"

void createQueue_103032300101(Queue &Q) {
    Q.head = NULL;
    Q.tail = NULL;
}

bool isEmpty_103032300101(Queue Q) {
    return Q.head == NULL;
}

ElemQ* createElemQueue_103032300101(string nama, int usia, string pekerjaan, int nomor_antrean) {
    ElemQ* p = new ElemQ;
    p->info.nama = nama;
    p->info.usia = usia;
    p->info.pekerjaan = pekerjaan;
    p->info.prioritas = usia >= 60 || pekerjaan == "tenaga kesehatan";
    p->info.nomor_antrean = nomor_antrean;
    p->info.kondisi_darurat = false;
    p->next = NULL;
    return p;
}

void enqueue_103032300101(Queue &Q, ElemQ *P) {
    if (isEmpty_103032300101(Q)) {
        Q.head = P;
        Q.tail = P;
    } else if (P->info.prioritas) {
        if (!Q.head->info.prioritas || P->info.kondisi_darurat) {
            P->next = Q.head;
            Q.head = P;
        } else {
            ElemQ *temp = Q.head;
            while (temp->next != NULL && temp->next->info.prioritas) {
                temp = temp->next;
            }
            P->next = temp->next;
            temp->next = P;
            if (P->next == NULL) {
                Q.tail = P;
            }
        }
    } else {
        Q.tail->next = P;
        Q.tail = P;
    }
}

void dequeue_103032300101(Queue &Q, ElemQ *&P) {
    if (isEmpty_103032300101(Q)) {
        P = NULL;
        cout << " Semua warga telah terlayani" << endl;
    } else {
        P = Q.head;
        Q.head = Q.head->next;
        if (Q.head == NULL) {
            Q.tail = NULL;
        }
        P->next = NULL;
    }
}

ElemQ* front_103032300101(Queue Q) {
    return Q.head;
}

ElemQ* back_103032300101(Queue Q) {
    return Q.tail;
}

int size_103032300101(Queue Q) {
    int count = 0;
    ElemQ* temp = Q.head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void printInfo_103032300101(Queue Q) {
    ElemQ* p = Q.head;
    if (Q.head == NULL) {
        cout << "Antrean Kosong" << endl;
    } else {
        while (p != NULL) {
            cout << "Nama: " << p->info.nama << endl;
            cout << "Usia: " << p->info.usia << endl;
            cout << "Pekerjaan: " << p->info.pekerjaan << endl;
            if (p->info.prioritas) {
                cout << "Prioritas: Ya" << endl;
            } else {
                cout << "Prioritas: Tidak" << endl;
            };
            cout << "Nomor Antrian: " << p->info.nomor_antrean << endl;
            cout << "-------------------------------------" << endl;
            p = p->next;
        }
    }
}

void serveQueue_103032300101(Queue &Q) {
    if (!isEmpty_103032300101(Q)) {
        int kouta = 100;
        ElemQ *P;
        while (!isEmpty_103032300101(Q) && kouta != 0){
            dequeue_103032300101(Q,P);
            cout << "Melayanin warga:" << endl;
            cout << "------------------------------" << endl;
            cout << "Nama: " << P->info.nama << endl;
            cout << "Usia: " << P->info.usia << endl;
            cout << "Pekerjaan: " << P->info.pekerjaan << endl;
            if (P->info.prioritas){
                cout << "Prioritas: Ya" << endl;
            }else{
                cout << "Prioritas: Tidak" << endl;
            }
            cout << "Vaksinasi berhasil." << endl;
            cout << "------------------------------" << endl;
            kouta--;
        }
        if (kouta == 0){
            cout << endl << "---------------KAPASITAS TELAH PENUH---------------" << endl;
        }
        if (!isEmpty_103032300101(Q)){
            cout << endl << "---------------SILAKAN DATANG KEMBALI BESOK---------------" << endl;
        }
    }
}

void reassignQueue_103032300101(Queue &Q) {
    Queue S;
    createQueue_103032300101(S);
    int P = size_103032300101(Q);
    ElemQ *R;
    while (P != 0 || !isEmpty_103032300101(Q)){
        dequeue_103032300101(Q,R);
        enqueue_103032300101(S,R);
        P--;
    }
    Q = S;
}

void checkWaitingTime_103032300101(Queue &Q, int waktu_sekarang) {
    ElemQ *P = Q.head;
    if (waktu_sekarang > 120){
        P = Q.head;
        while (P!=NULL){
            P->info.prioritas = true;
            P=P->next;
        }
    }
    reassignQueue_103032300101(Q);
}

void emergencyHandle_103032300101(Queue &Q, int nomor_antrean) {
    ElemQ *P = Q.head;

    while (P != NULL && P->info.nomor_antrean != nomor_antrean){
        P=P->next;
    };

    if (P == NULL){
        printf("Nomor Antrean %d tidak ditemukan \n", nomor_antrean);
    } else {
        P->info.kondisi_darurat = true;
        P->info.prioritas = true;
        reassignQueue_103032300101(Q);
    }
}

void updatePriority_103032300101(Queue &Q) {
    ElemQ *P = Q.head;
    ElemQ *R;
    checkWaitingTime_103032300101(Q, 130);
    while (P != NULL){
        if (P->info.kondisi_darurat){
            reassignQueue_103032300101(Q);
        }
        P = P->next;
    }
}
ElemQ* findAndRemove_103032300101(Queue &Q, int nomor_antrean) {
    ElemQ *P, *S, *R;
    P = Q.head;
    S = Q.head;
    while (P->next != NULL){
        if (nomor_antrean == P->info.nomor_antrean){
            if (P == Q.head){
                dequeue_103032300101(Q,R);
                return R;
            }else if (P == Q.tail){
                Q.tail = S;
                Q.tail->next = NULL;
                return P;
            }else{
                S->next = P->next;
                P->next = NULL;
                return P;
            }
        }
        S = P;
        P = P->next;
    }
    return NULL;
}
