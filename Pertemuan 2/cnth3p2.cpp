#include <iostream>
using namespace std;

// pendeklarasian tipe data baru struct mahasiswa
class mahasiswa{
public:
char npm[9];
char nama[30];
float ipk;
};
int main() {
// buat variabel mhs bertipe data mahasiswa
mahasiswa mhs;
cout <<" nomor pokok mahasiswa = "; cin >> mhs.npm;
cout <<" nama mahasiswa = "; cin >> mhs.nama;
cout <<" index prestasi komulatif  = "; cin >> mhs.ipk;
cout<<endl;
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
cout <<"				data anda" <<endl;
cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
cout <<" nomor pokok mahasiswa 		= " << mhs.npm <<endl;
cout <<" nama mahasiswa				= " << mhs.nama <<endl;
cout <<" index prestasi komulatif  	= " << mhs.ipk <<endl;
cin.get();
}