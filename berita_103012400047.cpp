#include <iostream>
#include "Berita.h"
#include "Jurnalis.h"

using namespace std;

void createListBerita(ListBerita &L){
    L.first = nullptr;
    L.last = nullptr;
}

adrBerita createNodeBerita(string id, string judul, string isi, string tanggal, string kategori){
    adrBerita p = new elmBerita;
    p->id_berita = id;
    p->judul = judul;
    p->kategori = kategori;
    p->isi = isi;
    p->tanggal = tanggal;
    p->views = 0;
    p->likes = 0;
    p->next = nullptr;
    p->prev = nullptr;

    return p;
}


void insertFirstBerita(ListBerita &L, adrBerita P){
    if (L.first == nullptr){
        L.first = P;
        L.last = P;
    }else{
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastBerita(ListBerita &L, adrBerita P){
    if (L.first == nullptr){
        L.first = P;
        L.last = P;
    }else{
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void deleteFirstBerita(ListBerita &L){
    adrBerita P;
    if (L.first == nullptr){
        P = nullptr;
        cout << "Berita Kosong" << endl;
    }else if(L.first == L.last){
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    }else{
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
        L.first->prev = nullptr;
    }
}

void deleteLastBerita(ListBerita &L){
    adrBerita P;
    if (L.first == nullptr){
        P = nullptr;
        cout << "Berita Kosong" << endl;
    }else if(L.first == L.last){
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    }else{
        P = L.last;
        L.last = P->prev;
        L.last->next = nullptr;
        P->prev = nullptr;
    }
}

void showAllBerita(ListBerita L){
    adrBerita P;
    P = L.first;
    if (L.first == nullptr){
        cout << "Berita Kosong" << endl;
        return;
    }
    while (P != nullptr){
        cout << "ID: " << P->id_berita << endl;
        cout << "Judul: " << P->judul << endl;
        cout << "Kategori: " << P->kategori << endl;
        cout << "Isi: " << P->isi << endl;
        cout << "Tanggal: " << P->tanggal << endl;
        cout << "Views: " << P->views << ", Likes: " << P->likes << endl;
        cout << "-----------------------------" << endl;
        P = P->next;
    }
}

 int countBerita(ListBerita L){
    int count;
    adrBerita P;

    count = 0;
    P = L.first;
    while (P != nullptr){
        count++;
        P = P->next;
    }
    return count;
 }
