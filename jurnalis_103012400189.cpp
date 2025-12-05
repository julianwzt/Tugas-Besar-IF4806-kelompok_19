#include <iostream>
#include "Berita.h"
#include "Jurnalis.h"

using namespace std;

void createListParent(ListParent &L) {
    L.first = nullptr;
}

addressP createElementParent(infotypeP X) {
    addressP P = new elmJurnalis;
    P->info = X;
    P->next = nullptr;
    P->child = nullptr;
    return P;
}

void insertFirstParent(ListParent &L, addressP P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertLastParent(ListParent &L, addressP P) {
    if (L.first == nullptr) {
        insertFirstParent(L, P);
    } else {
        addressP Q = L.first;
        while (Q->next != nullptr) Q = Q->next;
        Q->next = P;
    }
}

void deleteFirstParent(ListParent &L, addressP &P) {
    if (L.first != nullptr) {
        P = L.first;
        disconnectAll(P);

        if (L.first->next == nullptr) {
            L.first = nullptr;
        } else {
            L.first = P->next;
            P->next = nullptr;
        }
    }
}

void deleteLastParent(ListParent &L, addressP &P) {
    if (L.first != nullptr) {
        addressP Q = L.first;
        addressP Prec = nullptr;

        while (Q->next != nullptr) {
            Prec = Q;
            Q = Q->next;
        }

        P = Q;
        disconnectAll(P);

        if (Prec == nullptr) {
            L.first = nullptr;
        } else {
            Prec->next = nullptr;
        }
    }
}

void connect(addressP P, adrBerita B) {
    if (P != nullptr && B != nullptr) {
        addressC R = new elmRelasi;
        R->infoBerita = B;
        R->next = P->child;
        P->child = R;
    }
}

void disconnect(addressP P, int idBerita) {
    if (P != nullptr) {
        addressC R = P->child;
        addressC Prec = nullptr;
        while (R != nullptr) {
            if (R->infoBerita->id_berita == idBerita) {
                if (Prec == nullptr) P->child = R->next;
                else Prec->next = R->next;
                delete R;
                return;
            }
            Prec = R;
            R = R->next;
        }
    }
}

void disconnectAll(addressP P) {
    addressC R = P->child;
    while (R != nullptr) {
        addressC temp = R;
        R = R->next;
        delete temp;
    }
    P->child = nullptr;
}
