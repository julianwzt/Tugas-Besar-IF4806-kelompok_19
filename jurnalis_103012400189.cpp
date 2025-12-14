#include "Jurnalis.h"

void createListParent(ListParent &L){
    L.first = nullptr;
}

addressP createElementParent(infotypeP X){
    addressP P = new elmJurnalis;
    P->info = X;
    P->next = nullptr;
    P->berita = nullptr;
    return P;
}

void insertFirstParent(ListParent &L, addressP P){
    if(L.first == nullptr){
        L.first = P;
    }else{
        P->next = L.first;
        L.first = P;
    }
}

void insertParentSortedByRating(ListParent &L, addressP P){
    if (L.first == nullptr ||
        P->info.rating > L.first->info.rating ||
        (P->info.rating == L.first->info.rating && P->info.nama < L.first->info.nama)) {
        insertFirstParent(L, P);
    }
    else {
        addressP Q = L.first;
        while (Q->next != nullptr && (Q->next->info.rating > P->info.rating ||(Q->next->info.rating == P->info.rating && Q->next->info.nama < P->info.nama))) {
               Q = Q->next;
        }
        P->next = Q->next;
        Q->next = P;
    }
}

addressP findElementParent(ListParent L, string idDicari){
    addressP P = L.first;
    while(P != nullptr){
        if(P->info.idJurnalis == idDicari) return P;
        P = P->next;
    }
    return nullptr;
}

void viewParent(ListParent LJ){
    addressP P = LJ.first;
    if(P == nullptr){
        cout << "Data Jurnalis Kosong" << endl;
        return;
    }
    while(P != nullptr){
        cout << "Jurnalis: " << P->info.nama << " (" << P->info.idJurnalis << ")" << endl;
        showBeritaByJurnalis(P->berita);
        cout << "-----------------" << endl;
        P = P->next;
    }
}

void viewJurnalisOnly(ListParent LJ){
    addressP P = LJ.first;
    if(P == nullptr){
        cout << "Data Jurnalis Kosong" << endl;
        return;
    }
    cout << "\n========================= DAFTAR JURNALIS =============================" << endl;
    while(P != nullptr){
        cout << "ID: " << P->info.idJurnalis
             << " | Nama: " << P->info.nama
             << " | Media: " << P->info.media
             << " | Rating: " << P->info.rating << endl;
        P = P->next;
    }
    cout << "=======================================================================" << endl;
}

void deleteBeritaGlobalByLikesBelow(ListParent &L, int batasBawah){
    addressP P = L.first;
    int totalDeleted = 0;
    while(P != nullptr){
        adrBerita B = P->berita;
        while(B != nullptr){
            adrBerita nextB = B->next;
            if(B->likes < batasBawah){
                string judulB = B->judul;
                deleteBeritaById(P->berita, B->id_berita);
                cout << "-> Menghapus: " << judulB << " (Likes: " << B->likes << ") dari " << P->info.nama << endl;
                totalDeleted++;
            }
            B = nextB;
        }
        P = P->next;
    }
    if(totalDeleted == 0){
        cout << "Tidak ada berita dengan Likes di bawah " << batasBawah << endl;
    }else{
        cout << "Total " << totalDeleted << " berita kurang populer (Low Likes) berhasil dihapus." << endl;
    }
}
