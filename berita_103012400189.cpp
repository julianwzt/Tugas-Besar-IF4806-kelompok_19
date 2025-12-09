#include <iostream>
#include "Berita.h"

using namespace std;

void deleteBeritaById(ListBerita &L, string id){
    adrBerita P = findBerita(L, id);
    if(P == nullptr){
        cout << "Berita ID " << id << " tidak ditemukan." << endl;
        return;
    }

    if(P == L.first){
        deleteFirstBerita(L);
    }else if (P == L.last){
        deleteLastBerita(L);
    }else{
        P->prev->next = P->next;
        P->next->prev = P->prev;
        P->next = nullptr;
        P->prev = nullptr;
    }

    delete P;
    cout << "Berita berhasil dihapus." << endl;
}

adrBerita findBerita(ListBerita L, string id){
    adrBerita P = L.first;
    if(L.first == nullptr){
        return nullptr;
    }
    while(P != nullptr){
        if(P->id_berita == id){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

adrBerita getMostViewedBerita(ListBerita L){
    adrBerita P = L.first;
    adrBerita maxP = P;
    if(L.first == nullptr){
        cout << "Data Berita Kosong" << endl;
        return nullptr;
    }
    while(P != nullptr){
        if (P->views > maxP->views) maxP = P;
        P = P->next;
    }
    return maxP;
}
