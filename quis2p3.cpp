#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

void BUAT_SIMPUL(int X);
void AWAL();
void CETAK();
void INSERTKANAN();
void HAPUS_DEPAN();

struct Node {
    int INFO;       // Nomor Antrian
    struct Node *LINK;
};

typedef struct Node Simpul;
Simpul *P, *FIRST, *LAST, *Q;
int X;

int main() {
    // Data nomor antrian pelanggan yang datang
    int NomorAntrian[5] = {1, 2, 3, 4, 5};
    int I;

    FIRST = NULL; // Inisialisasi Linked List (antrian kosong)

    // Pelanggan pertama datang -> masuk ke AWAL
    I = 0;
    X = NomorAntrian[I];
    BUAT_SIMPUL(X);
    AWAL();

    // Pelanggan berikutnya datang -> selalu masuk ke BELAKANG (INSERTKANAN)
    for(I = 1; I <= 4; I++) {
        X = NomorAntrian[I];
        BUAT_SIMPUL(X);
        INSERTKANAN();
    }

    cout << "=== SISTEM ANTRIAN PELANGGAN DI LOKET PEMBAYARAN ===" << endl;
    cout << endl;
    cout << "Antrian saat ini (Depan -> Belakang) : ";
    CETAK();
    cout << endl << endl;

    // Simulasi: Pelanggan baru datang (Nomor Antrian 6)
    cout << "Pelanggan baru datang dengan Nomor Antrian 6..." << endl;
    X = 6;
    BUAT_SIMPUL(X);
    INSERTKANAN();
    cout << "Antrian setelah pelanggan baru masuk         : ";
    CETAK();
    cout << endl << endl;

    // Simulasi: Pelanggan terdepan selesai dilayani
    cout << "Pelanggan terdepan selesai dilayani, keluar dari antrian..." << endl;
    HAPUS_DEPAN();
    cout << "Antrian setelah pelanggan terdepan keluar    : ";
    CETAK();
    cout << endl << endl;

    // Simulasi: Pelanggan baru lagi (Nomor Antrian 7)
    cout << "Pelanggan baru datang dengan Nomor Antrian 7..." << endl;
    X = 7;
    BUAT_SIMPUL(X);
    INSERTKANAN();
    cout << "Antrian akhir                                : ";
    CETAK();
    cout << endl;

    cin.get();
    return 0;
}
void BUAT_SIMPUL(int X) // Membuat simpul baru
{
    P = (Simpul*) malloc(sizeof(Simpul));
    if(P != NULL) {
        P->INFO = X;
        P->LINK = NULL;
    } else {
        cout << "Pembuatan Simpul Tidak Berhasil" << endl;
        cin.get();
        exit(1);
    }
}

void AWAL() // Pelanggan PERTAMA masuk -> jadi FIRST sekaligus LAST
{
    FIRST = P;
    LAST  = P;
    P->LINK = NULL;
}

void INSERTKANAN() // Pelanggan BARU selalu masuk ke BELAKANG antrian
{
    LAST->LINK = P;
    LAST       = P;
    P->LINK    = NULL;
}
void HAPUS_DEPAN() // Pelanggan terdepan selesai dilayani -> keluar dari antrian
{
    if(FIRST == NULL) {
        cout << "Antrian kosong!" << endl;
        return;
    }
    Simpul *temp = FIRST;
    FIRST = FIRST->LINK;
    if(FIRST == NULL) LAST = NULL; // Jika antrian jadi kosong
    free(temp);
}
void CETAK() // Mencetak seluruh isi antrian dari depan ke belakang
{
    if(FIRST == NULL) {
        cout << "(Antrian Kosong)";
        return;
    }
    Q = FIRST;
    while(Q != NULL) {
        cout << "[" << Q->INFO << "]";
        if(Q->LINK != NULL) cout << " -> ";
        Q = Q->LINK;
    }
}