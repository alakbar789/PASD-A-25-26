#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// =============================================
// STRUKTUR DATA
// =============================================

struct DataKaryawan {
    string nip;
    string nama_karyawan;
    double gaji;
};

struct elemen {
    DataKaryawan data;  // Kontainer
    elemen* next;       // Pointer next
};

struct queue {
    elemen* first;  // Pointer first
    elemen* last;   // Pointer last
};

// =============================================
// FUNGSI / PROSEDUR
// =============================================

// Inisialisasi queue kosong
void buatQKosong(queue &q) {
    q.first = NULL;
    q.last  = NULL;
}

// Cek apakah queue kosong
bool isKosong(queue q) {
    return q.first == NULL;
}

// Hitung jumlah elemen dalam queue
int jmlElemen(queue q) {
    int count = 0;
    elemen* temp = q.first;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Tambah data karyawan ke belakang queue (enqueue)
void add(queue &q, DataKaryawan dk) {
    elemen* baru = new elemen;
    baru->data = dk;
    baru->next = NULL;

    if (isKosong(q)) {
        q.first = baru;
        q.last  = baru;
    } else {
        q.last->next = baru;
        q.last = baru;
    }
}

// Hapus data karyawan dari depan queue (dequeue)
void del(queue &q) {
    if (isKosong(q)) {
        cout << "Queue kosong! Tidak ada data yang dihapus." << endl;
        return;
    }
    elemen* hapus = q.first;
    cout << "Data dihapus: [" << hapus->data.nip << "] "
         << hapus->data.nama_karyawan << endl;
    q.first = q.first->next;
    if (q.first == NULL) {
        q.last = NULL;
    }
    delete hapus;
}

// Tampilkan seluruh isi queue
void CetakQueue(queue q) {
    if (isKosong(q)) {
        cout << "  Queue kosong." << endl;
        return;
    }
    cout << left
         << setw(12) << "NIP"
         << setw(25) << "Nama Karyawan"
         << setw(15) << "Gaji" << endl;
    cout << string(52, '-') << endl;

    elemen* temp = q.first;
    int no = 1;
    while (temp != NULL) {
        cout << setw(12) << temp->data.nip
             << setw(25) << temp->data.nama_karyawan
             << "Rp " << fixed << setprecision(0)
             << temp->data.gaji << endl;
        temp = temp->next;
        no++;
    }
    cout << string(52, '-') << endl;
    cout << "Jumlah elemen: " << jmlElemen(q) << endl;
}

// =============================================
// MAIN PROGRAM
// =============================================

int main() {
    queue antrian;

    // 1. Inisialisasi antrian
    buatQKosong(antrian);

    // 2. Cetak kondisi awal (kosong)
    cout << "=====================================" << endl;
    cout << "       QUEUE LINKED LIST             " << endl;
    cout << "       DATA KARYAWAN                 " << endl;
    cout << "=====================================" << endl;
    cout << "\n[1] Kondisi awal antrian:" << endl;
    if (isKosong(antrian))
        cout << "  Antrian kosong." << endl;

    // 3. Tambahkan 7 data karyawan secara langsung (hardcoded)
    DataKaryawan karyawan[7] = {
        {"K001", "maou emperor",      5500000},
        {"K002", "Siti Rahayu",       6200000},
        {"K003", "Ahmad Fauzi",       4800000},
        {"K004", "Dewi Lestari",      7100000},
        {"K005", "Rudi Hartono",      5300000},
        {"K006", "Nina Permata",      6800000},
        {"K007", "Hendra Wijaya",     5900000}
    };

    for (int i = 0; i < 7; i++) {
        add(antrian, karyawan[i]);
    }

    // 4. Tampilkan seluruh isi antrian
    cout << "\n[2] Seluruh isi antrian (7 karyawan):" << endl;
    CetakQueue(antrian);

    // 5. Lakukan 2 kali penghapusan (del) dan tampilkan sisa antrian
    cout << "\n[3] Melakukan 2 kali penghapusan (dari depan):" << endl;
    del(antrian);
    del(antrian);

    cout << "\n[4] Sisa antrian setelah 2 penghapusan:" << endl;
    CetakQueue(antrian);

    return 0;
}
