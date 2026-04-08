#include <iostream>
using namespace std;

// pendeklarasian tipe data baru struct mahasiswa
class mahasiswa{
public:
char kodebarang[9];
char namabarang[30];
int harga;
};
int main() {
// buat variabel mhs bertipe data mahasiswa
mahasiswa mhs;
cout <<" nama barang = "; cin >> mhs.namabarang;
cout <<" kode barang = "; cin >> mhs.kodebarang;
cout <<" harga barang  = "; cin >> mhs.harga;
cout<<endl;
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
cout <<"				data anda" <<endl;
cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
cout <<" nama barang 				= " << mhs.namabarang <<endl;
cout <<" kode barang				= " << mhs.kodebarang <<endl;
cout <<" harga barang			  	= " << mhs.harga <<endl;
cin.get();
}