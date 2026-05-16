#include<iostream>
using namespace std;

class BubbleSort {
public:
    int data[10];
    int n;

    void tukar(int a, int b) {
        int t;
        t = data[b];
        data[b] = data[a];
        data[a] = t;
        cout << "  [Tukar] " << data[b] << " <-> " << data[a] << endl;
    }

    void input() {
        cout << "Masukkan jumlah data = "; cin >> n;
        cout << "----------------------------------------" << endl;
        for(int i = 0; i < n; i++) {
            cout << "Masukkan data ke-" << (i+1) << " = ";
            cin >> data[i];
        }
        cout << endl;
    }

    void tampil() {
        for(int i = 0; i < n; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void sort() {
        for(int i = 1; i < n; i++) {
            cout << "data ke-" << i << " : ";
            for(int j = n-1; j >= i; j--) {
                if(data[j] < data[j-1]) tukar(j, j-1);
            }
            tampil();
        }
        cout << endl;
    }
};

int main() {
    BubbleSort bs;

    cout << "*----------------------------------------*" << endl;
    cout << "*   Selamat datang di aplikasi           *" << endl;
    cout << "*          Bubble Sort                   *" << endl;
    cout << "*----------------------------------------*" << endl;

    bs.input();

    cout << "Data awal: ";
    bs.tampil();

    cout << "\nProses Bubble Sort........." << endl;
    cout << "----------------------------------------" << endl;
    bs.sort();

    cout << "----------------------------------------" << endl;
    cout << "Data setelah diurutkan: ";
    bs.tampil();

    cout << "----------------------------------------" << endl;
    cout << "          TERIMA KASIH                   " << endl;
    cout << "----------------------------------------" << endl;

    return 0;
}