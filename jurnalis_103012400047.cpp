#include <iostream>
#include "Berita.h"
#include "Jurnalis.h"

using namespace std;

void deleteJurnalisById(ListParent &L, string id){
    addressP P = L.first;
    addressP Prec = nullptr;

    while (P != nullptr && P->info.idJurnalis != id){
        Prec = P;
        P = P->next;
    }
    if(P == nullptr){
        cout << "Jurnalis ID " << id << " tidak ditemukan." << endl;
        return;
    }
    if(Prec == nullptr){
        L.first = P->next;
    }else{
        Prec->next = P->next;
    }
    delete P;
    cout << "Jurnalis " << id << " berhasil dihapus." << endl;
}


addressP findElementParent(ListParent L, string idDicari){
    addressP P = L.first;
    while(P != nullptr){
        if(P->info.idJurnalis == idDicari){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void viewParent(ListParent LJ, ListBerita LB){
    addressP P = LJ.first;
    if(P == nullptr){
        cout << "Data Jurnalis Kosong" << endl;
        return;
    }
    while(P != nullptr){
        cout << "Jurnalis: " << P->info.nama << " (" << P->info.idJurnalis << ")" << endl;

        adrBerita B = LB.first;
        bool adaTulisan = false;
        while(B != nullptr){
            if(B->idPenulis == P->info.idJurnalis){
                cout << "  -> " << B->judul << " (" << B->views << " views)" << endl;
                adaTulisan = true;
            }
            B = B->next;
        }
        if(!adaTulisan) cout << "  -> (Belum ada tulisan)" << endl;
        cout << "-----------------" << endl;
        P = P->next;
    }
}
