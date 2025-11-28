#ifndef JURNALIS_H_INCLUDED
#define JURNALIS_H_INCLUDED

#include <iostream>
#include <string>
#include "Berita.h"

typedef Jurnalis infotypeP;
typedef struct elmJurnalis* addressP;

struct elmJurnalis {
    infotypeP info;
    addressP next;
    addressC child;
}

struct Jurnalis{
    string idJurnalis;
    string nama;
    string media;
};

struct ListParent {
    addressP first;
};

void createListParent(ListParent &L);
addressP createElementParent(infotypeP X);
void insertFirstParent(ListParent &L, addressP P);
void insertLastParent(ListParent &L, addressP P);
void insertAfterParent(ListParent &L, addressP prec, addressP P);
void deleteFirstParent(ListParent &L, addressP &P);
void deleteLastParent(ListParent &L, addressP &P);
void deleteAfterParent(ListParent &L, addressP prec, addressP &P);
addressP findElementParent(ListParent L, string idDicari);
void viewParent(ListParent L);


#endif // JURNALIS_H_INCLUDED
