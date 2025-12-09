#include <iostream>
#include "Berita.h"
#include "Jurnalis.h"

using namespace std;

void createListParent(ListParent &L){
    L.first = nullptr;
}

addressP createElementParent(infotypeP X){
    addressP P = new elmJurnalis;
    P->info = X;
    P->next = nullptr;
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

void insertLastParent(ListParent &L, addressP P){
    if(L.first == nullptr){
        L.first = P;
    }else{
        addressP Q = L.first;
        while (Q->next != nullptr) Q = Q->next;
        Q->next = P;
    }
}

void deleteFirstParent(ListParent &L, addressP &P){
    if(L.first != nullptr){
        P = L.first;
        if(L.first->next == nullptr){
            L.first = nullptr;
        }else{
            L.first = P->next;
            P->next = nullptr;
        }
    }
}

void deleteLastParent(ListParent &L, addressP &P){
    if(L.first != nullptr){
        addressP Q = L.first;
        addressP Prec = nullptr;
        while(Q->next != nullptr){
            Prec = Q;
            Q = Q->next;
        }
        P = Q;
        if(Prec == nullptr){
            L.first = nullptr;
        }else{
            Prec->next = nullptr;
        }
    }
}

void connect(addressP P, adrBerita B){
    if(P != nullptr && B != nullptr){
        B->idPenulis = P->info.idJurnalis;
    }
}

void disconnect(adrBerita B){
    if(B != nullptr){
        B->idPenulis = "";
    }
}
