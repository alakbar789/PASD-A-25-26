//Sequence Search menggunakan fungsi
#include<iostream>
using namespace std;
int Search01(int A[], int, int);
int main()
{
    int JmlElemenArray;
    cout << "****************************************" <<endl;
    cout << "** S E Q U E N T I A L    S E A R C H **" <<endl;
    cout << "****************************************" <<endl;
    cout << "Masukkan jumlah elemen array: "; cin >> JmlElemenArray;
    int tika[JmlElemenArray];
    cout << endl;
    cout << "Masukkan isi data:" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
    for(int count=0; count<JmlElemenArray; count++)
    {
        cout << "Data [" << count << "] --> "; cin >> tika[count];
    }

    int pilihan;
    do {
        cout << endl;
        cout << "****************************************" <<endl;
        cout << "**            M E N U                **" <<endl;
        cout << "****************************************" <<endl;
        cout << "  1. Tampilkan Data" << endl;
        cout << "  2. Cari Data" << endl;
        cout << "  3. Keluar" << endl;
        cout << "****************************************" <<endl;
        cout << "Pilihan: "; cin >> pilihan;
        cout << endl;

        switch(pilihan)
        {
            case 1:
                cout << "****************************************" <<endl;
                cout << "Isi data nya adalah" << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << endl;
                for(int count=0; count<JmlElemenArray; count++)
                {
                    cout << "\t"<< "Data [" << count << "]" << "--> " << tika[count]<<endl;
                }
                break;

            case 2:
                int SearchElemen, flaq;
                cout << "Masukkan data yang akan Anda cari ?   "; cin >> SearchElemen;
                flaq = Search01(tika, JmlElemenArray, SearchElemen);
                if(flaq != -1)
                    cout << "Data yang dicari ditemukan pada posisi : Data["<< flaq <<"]"<<endl;
                else
                    cout << "Data yang Anda cari tidak ditemukan" << endl;
                break;

            case 3:
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while(pilihan != 3);

    cin.get();
    return 0;
}
int Search01(int tika[], int JmlElemenArray, int Elemen)
{
    int flaq = -1;
    for(int count=0; count<JmlElemenArray; count++)
    {
        if(Elemen==tika[count])
        {
            flaq=count;
            break;
        }
    }
    return flaq;
}
