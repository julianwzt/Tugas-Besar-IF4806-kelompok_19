#ifndef JURNALIS_H_INCLUDED
#define JURNALIS_H_INCLUDED

#include <iostream>
#include <string>
#include "Berita.h"

using namespace std;

typedef struct elmRelasi *addressC;
struct elmRelasi {
    addressC next;
    adrBerita infoBerita;
};

typedef struct Jurnalis infotypeP;
typedef struct elmJurnalis *addressP;

struct Jurnalis {
    string idJurnalis;
    string nama;
    string media;
};

struct elmJurnalis {
    infotypeP info;
    addressP next;
    addressC child;
};

struct ListParent {
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
void viewParent(ListParent L);
void connect(addressP P, adrBerita B);//
void disconnect(addressP P, int idBerita);//
void disconnectAll(addressP P);//

#endif // JURNALIS_H_INCLUDED
