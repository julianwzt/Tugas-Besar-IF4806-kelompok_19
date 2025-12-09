#ifndef JURNALIS_H_INCLUDED
#define JURNALIS_H_INCLUDED

#include <iostream>
#include <string>
#include "Berita.h"

using namespace std;

typedef struct Jurnalis infotypeP;
typedef struct elmJurnalis *addressP;

struct Jurnalis{
    string idJurnalis;
    string nama;
    string media;
};

struct elmJurnalis{
    infotypeP info;
    addressP next;
};

struct ListParent{
    addressP first;
};

void createListParent(ListParent &L);
addressP createElementParent(infotypeP X);

void insertFirstParent(ListParent &L, addressP P);
void insertLastParent(ListParent &L, addressP P);

void deleteFirstParent(ListParent &L, addressP &P);
void deleteLastParent(ListParent &L, addressP &P);
void deleteJurnalisById(ListParent &L, string id);

addressP findElementParent(ListParent L, string idDicari);
void viewParent(ListParent LJ, ListBerita LB);
void connect(addressP P, adrBerita B);
void disconnect(adrBerita B);

#endif // JURNALIS_H_INCLUDED
