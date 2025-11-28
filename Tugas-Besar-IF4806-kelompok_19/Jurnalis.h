#ifndef JURNALIS_H_INCLUDED
#define JURNALIS_H_INCLUDED

#include <iostream>
#include <string>
#include "Berita.h"
using namespace std;

typedef struct elmJurnalis* adrJurnalis;
typedef Jurnalis infotypeJurnalis;

struct elmJurnalis {
    infotypeJurnalis info;
    adrJurnalis next;
    adrBerita child;
};

struct Jurnalis{
    string idJurnalis;
    string nama;
    string media;
};

struct List {
    adrJurnalis first;
    adrJurnalis last;
};

void createList(List &L);
adrJurnalis createElmJurnalis(infotypeJurnalis data);
void insertJurnalis(List &L, adrJurnalis P);
void deleteJurnalis(List &L, string idJurnalis);
adrJurnalis findJurnalis(List L, string idJurnalis);
void showAllJurnalis(List L);


#endif // JURNALIS_H_INCLUDED
