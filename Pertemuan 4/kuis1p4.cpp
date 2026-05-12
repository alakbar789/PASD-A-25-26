#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100
#define true 1
#define false 0

struct mahasiswa {
    char nim[15];
    char nama[30];
    int nilai;
};
struct mahasiswa queue[MAX];
int awal, akhir;
void init(void) {
    awal  = -1;
    akhir = -1;
}
int full(void) {
    if (akhir == MAX - 1) return true;
    else return false;
}
int empty(void) {
    if (akhir == -1) return true;
    else return false;
}
void enqueue(struct mahasiswa mhs) {
    if (empty() == true) {
        awal  = 0;
        akhir = 0;
        queue[awal] = mhs;
        cout << "\nData berhasil ditambahkan ke antrian\n";
    } else if (full() != true) {
        akhir++;
        queue[akhir] = mhs;
        cout << "\nData berhasil ditambahkan ke antrian\n";
    } else {
        cout << "\nQueue sudah penuh!\n";
    }
}
struct mahasiswa dequeue(void) {
    struct mahasiswa mhs;
    int i;
    if (empty() != true) {
        mhs = queue[awal];
        for (i = awal; i <= akhir; i++)
            queue[i] = queue[i + 1];
        akhir--;
        if (akhir < 0) {
            awal  = -1;
            akhir = -1;
        }
        return mhs;
    } else {
        cout << "\nQueue kosong! Tidak ada data yang bisa dihapus.\n";
        strcpy(mhs.nim, "");
        strcpy(mhs.nama, "");
        mhs.nilai = 0;
        return mhs;
    }
}
void display(struct mahasiswa mhs) {
    cout << "NIM   : " << mhs.nim   << "\n";
    cout << "Nama  : " << mhs.nama  << "\n";
    cout << "Nilai : " << mhs.nilai << "\n";
    cout << "--------------------------------\n";
}
void tampilkan(void) {
    int i;
    cout << "\n================================\n";
    cout << "       DAFTAR ANTRIAN\n";
    cout << "================================\n";
    if (empty() != true) {
        for (i = awal; i <= akhir; i++) {
            cout << "Data ke-" << (i - awal + 1) << " :\n";
            display(queue[i]);
        }
    } else {
        cout << "Queue kosong. Tidak ada data.\n";
    }
    cout << "\n";
}
struct mahasiswa inputdata(void) {
    struct mahasiswa mhs;
    cout << "\n";
    cout << "Masukkan NIM   : "; cin >> mhs.nim;
    cout << "Masukkan Nama  : "; cin >> mhs.nama;
    cout << "Masukkan Nilai : "; cin >> mhs.nilai;
    return mhs;
}
int main() {
    struct mahasiswa mhs;
    char pilih;
    init();
    cout << "================================\n";
    cout << "    PROGRAM QUEUE MAHASISWA\n";
    cout << "================================\n";
    do {
        cout << "\n1. Enqueue (Tambah Data)\n";
        cout << "2. Dequeue (Hapus Data)\n";
        cout << "3. Tampilkan Data\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu : ";
        cin >> pilih;

        switch (pilih) {
            case '1':
                mhs = inputdata();
                enqueue(mhs);
                break;
            case '2':
                if (empty() != true) {
                    mhs = dequeue();
                    cout << "\nData yang dihapus dari antrian :\n";
                    cout << "--------------------------------\n";
                    display(mhs);
                }
                break;
            case '3':
                tampilkan();
                break;
            case '4':
                cout << "\nProgram selesai. Terima kasih!\n";
                break;
            default:
                cout << "\nPilihan tidak valid! Masukkan 1-4.\n";
                break;
        }
    } while (pilih != '4');
    return 0;
}
