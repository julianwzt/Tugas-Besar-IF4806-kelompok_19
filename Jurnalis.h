#ifndef JURNALIS_H_INCLUDED
#define JURNALIS_H_INCLUDED

#include "Berita.h"
#include <iostream>
#include <string>

using namespace std;

typedef struct Jurnalis infotypeP;
typedef struct elmJurnalis *addressP;

struct Jurnalis{
    string idJurnalis;
    string nama;
    string media;
    int rating;
};

struct elmJurnalis{
    infotypeP info;
    addressP next;
    adrBerita berita;
};

struct ListParent{
    addressP first;
};

void createListParent(ListParent &L);
addressP createElementParent(infotypeP X);
void insertFirstParent(ListParent &L, addressP P);
void insertParentSortedByRating(ListParent &L, addressP P);
void deleteJurnalisById(ListParent &L, string id);
addressP findElementParent(ListParent L, string idDicari);
void viewParent(ListParent LJ);
void viewJurnalisOnly(ListParent LJ);
void showAllBeritaGlobal(addressP firstJurnalis);
adrBerita findBeritaGlobal(addressP firstJurnalis, string idBerita);
adrBerita getMostViewedGlobal(addressP firstJurnalis);
void deleteJurnalisByRatingBelow(ListParent &L, int batasBawah);
void deleteBeritaGlobalByLikesBelow(ListParent &L, int batasBawah);

#endif // JURNALIS_H_INCLUDED
