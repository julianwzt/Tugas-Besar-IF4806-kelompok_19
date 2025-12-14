#include "Berita.h"

adrBerita createNodeBerita(string id, string judul, string isi, string tanggal, string kategori, string idPenulis){
    adrBerita p = new elmBerita;
    p->id_berita = id;
    p->judul = judul;
    p->kategori = kategori;
    p->isi = isi;
    p->tanggal = tanggal;
    p->views = 0;
    p->likes = 0;
    p->idPenulis = idPenulis;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

void insertBeritaToJurnalis(adrBerita &firstBerita, adrBerita P){
    if(firstBerita == nullptr){
        firstBerita = P;
    }else{
        adrBerita Q = firstBerita;
        while(Q->next != nullptr){
            Q = Q->next;
        }
        Q->next = P;
        P->prev = Q;
    }
}

void insertBeritaSortedByViews(adrBerita &firstBerita, adrBerita P){
    if(firstBerita == nullptr || firstBerita->views < P->views){
        P->next = firstBerita;
        if(firstBerita != nullptr) firstBerita->prev = P;
        firstBerita = P;
    }else{
        adrBerita Q = firstBerita;
        while (Q->next != nullptr && Q->next->views >= P->views) {
            Q = Q->next;
        }
        P->next = Q->next;
        if (Q->next != nullptr) Q->next->prev = P;
        Q->next = P;
        P->prev = Q;
    }
}
