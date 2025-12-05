#include <iostream>
#include "Berita.h"
#include "Jurnalis.h"

using namespace std;

void deleteJurnalisById(ListParent &L, string id){
    addressP P = L.first;
    addressP Prec = nullptr;

    while (P != nullptr && P->info.idJurnalis != id) {
        Prec = P;
        P = P->next;
    }

    if (P == nullptr) {
        cout << "Jurnalis tidak ditemukan." << endl;
        return;
    }
    disconnectAll(P);

    if (Prec == nullptr) {
        L.first = P->next;
    } else {
        Prec->next = P->next;
    }

    delete P;
    cout << "Jurnalis " << id << " berhasil dihapus." << endl;
}


addressP findElementParent(ListParent L, string idDicari){
    addressP P = L.first;
    while (P != nullptr) {
        if (P->info.idJurnalis == idDicari) return P;
        P = P->next;
    }
    return nullptr;
}

void viewParent(ListParent L){
    addressP P = L.first;
    while (P != nullptr) {
        cout << "Jurnalis: " << P->info.nama << " (" << P->info.idJurnalis << ")" << endl;
        addressC R = P->child;
        while (R != nullptr) {
            cout << "  -> " << R->infoBerita->judul << endl;
            R = R->next;
        }
        cout << "-----------------" << endl;
        P = P->next;
    }
}
