#include <iostream>
#include "Berita.h"

using namespace std;

void deleteBeritaById(ListBerita &L, int id) {
    adrBerita P = findBerita(L, id);

    if (P == nullptr) {
        cout << "Berita ID " << id << " tidak ditemukan." << endl;
        return;
    }

    if (P == L.first) {
        deleteFirstBerita(L, P);
    } else if (P == L.last) {
        deleteLastBerita(L, P);
    } else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
        P->next = nullptr;
        P->prev = nullptr;
    }

    delete P;
    cout << "Berita berhasil dihapus." << endl;
}

adrBerita findBerita(ListBerita L, int id) {
    adrBerita P = L.first;
    while (P != nullptr) {
        if (P->id_berita == id) return P;
        P = P->next;
    }
    return nullptr;
}

adrBerita getMostViewedBerita(ListBerita L) {
    if (L.first == nullptr) return nullptr;
    adrBerita P = L.first, maxP = P;
    while (P != nullptr) {
        if (P->views > maxP->views) maxP = P;
        P = P->next;
    }
    return maxP;
}
