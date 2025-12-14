#include "Berita.h"

using namespace std;

void showBeritaByJurnalis(adrBerita firstBerita){
    if(firstBerita == nullptr){
        cout << "   -> (Belum ada berita)" << endl;
    }else{
        adrBerita B = firstBerita;
        while(B != nullptr){
            cout << "   -> [" << B->id_berita << "] " << B->judul
                 << " (" << B->views << " views, " << B->likes << " likes)" << endl;
            B = B->next;
        }
    }
}

void deleteBeritaById(adrBerita &firstBerita, string id){
    if(firstBerita == nullptr){
        return;
    }
    adrBerita P = firstBerita;
    while(P != nullptr && P->id_berita != id){
        P = P->next;
    }
    if(P == nullptr){
        return;
    }
    if(P == firstBerita){
        firstBerita = P->next;
        if(firstBerita != nullptr) firstBerita->prev = nullptr;
    }else{
        P->prev->next = P->next;
        if(P->next != nullptr) P->next->prev = P->prev;
    }
    delete P;
}
