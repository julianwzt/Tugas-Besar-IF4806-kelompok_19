#ifndef BERITA_H_INCLUDED
#define BERITA_H_INCLUDED

#include <iostream>
#include <string>


using namespace std;

typedef int infotype;
typedef struct elmBerita *adrBerita;

struct elmBerita{
    string id_berita;
    string judul;
    string kategori;
    string isi;
    string tanggal;
    int views;
    int likes;
    adrBerita next;
    adrBerita prev;

};

struct ListBerita{
    adrBerita first;
    adrBerita last;
};

void createListBerita(ListBerita &L);
adrBerita createNodeBerita(string id, string judul, string isi, string tanggal, string kategori);

void insertFirstBerita(ListBerita &L, adrBerita P);
void insertLastBerita(ListBerita &L, adrBerita P);
void insertAfterBerita(ListBerita &L, string idSebelum, adrBerita P);

void deleteFirstBerita(ListBerita &L);
void deleteLastBerita(ListBerita &L);
void deleteAfterBerita(ListBerita &L, string idSebelum);
void deleteBeritaById(ListBerita &L, string id);

void showAllBerita(ListBerita L);
adrBerita findBerita(ListBerita L, string id);

adrBerita getMostViewedBerita(ListBerita L);
adrBerita getMostLikedBerita(ListBerita L);
int countBerita(ListBerita L);


#endif // BERITA_H_INCLUDED
