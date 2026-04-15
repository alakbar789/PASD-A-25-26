#include <iostream>
#include <string>
using namespace std;

// Deklarasi struktur data buku
typedef struct {
    string kode_buku;
    string judul_buku;
    string pengarang;
} DataBuku;

// Deklarasi struktur elemen
typedef struct elm *alamatelm;
typedef struct elm {
    DataBuku Kontainer;
    alamatelm next;
} elemen;

// Deklarasi struktur stack
typedef struct {
    elemen* top;
} Stack;

void buatSTkosong(Stack *S) {
    (*S).top = NULL;
}

int isKosong(Stack S) {
    bool hasil = false;
    if(S.top == NULL) {
        hasil = true;
    }
    return hasil;
}

int jmlElemen(Stack S) {
    int hasil = 0;
    if(S.top != NULL) {
        elemen *bantu;
        bantu = S.top;
        while(bantu != NULL) {
            hasil = hasil + 1;
            bantu = bantu -> next;
        }
    }
    return hasil;
}

void push(string kode_buku, string judul_buku, string pengarang, Stack *S) {
    elemen *info;
    info = new elemen;
    info -> Kontainer.kode_buku = kode_buku;
    info -> Kontainer.judul_buku = judul_buku;
    info -> Kontainer.pengarang = pengarang;

    if((*S).top == NULL) {
        info -> next = NULL;
    }
    else {
        info -> next = (*S).top;
    }
    (*S).top = info;
    info = NULL;
}

void Pop(Stack *S) {
    if((*S).top != NULL) {
        elemen *hapus = (*S).top;
        if(jmlElemen(*S) == 1) {
            (*S).top = NULL;
        }
        else {
            (*S).top = (*S).top -> next;
        }
        hapus -> next = NULL;
        delete hapus;
    }
    else {
        cout << "Stack Kosong" << endl;
    }
}

void CetakStack(Stack S) {
    if(S.top != NULL) {
        cout << " MENAMPILKAN STACK BUKU " << endl;
        elemen *bantu = S.top;
        int i = 1;
        while(bantu != NULL) {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Elemen ke    : " << i << endl;
            cout << "Kode Buku    : " << bantu -> Kontainer.kode_buku << endl;
            cout << "Judul Buku   : " << bantu -> Kontainer.judul_buku << endl;
            cout << "Pengarang    : " << bantu -> Kontainer.pengarang << endl;
            bantu = bantu -> next;
            i = i + 1;
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
    else {
        cout << "Stack Kosong " << endl;
    }
}

int main() {
    Stack S;

    buatSTkosong(&S);
    CetakStack(S);
    cout << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;

    push("BK001", "Pemrograman C++", "Bjarne Stroustrup", &S);
    push("BK002", "Struktur Data", "Rinaldi Munir", &S);
    push("BK003", "Algoritma", "Thomas Cormen", &S);
    push("BK004", "Basis Data", "Ramez Elmasri", &S);
    push("BK005", "Jaringan Komputer", "Andrew Tanenbaum", &S);

    CetakStack(S);
    cout << "=====================" << endl;
    cout << endl;
    cout << endl;

    Pop(&S);
    CetakStack(S);
    cout << endl;
    cout << endl;

    Pop(&S);
    CetakStack(S);
    cout << "=====================" << endl;

    return 0;
}