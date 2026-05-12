#include <iostream>
#include <string>
using namespace std;

typedef int angka;
typedef float pecahan;
typedef char huruf[30];
int main() {

angka umur;
pecahan pecah;
huruf nama;
huruf karakter;
cout <<" masukkan umur anda : ";cin>>umur;
cout <<" umur anda adalah "<<umur<<endl;
cout<<endl;
cout <<" masukkan bilangan pecahan : ";cin>>pecah;
cout <<" bilangan pecahan "<<pecah<<endl;
cout<<endl;
cout <<" masukkan nama : ";cin>>nama;
cout <<" nama anda "<<nama<<endl;
cout<<endl;
cout <<" masukkan satu huruf : ";cin>>karakter;
cout <<" huruf anda "<< karakter<<endl;
cin.get();
}