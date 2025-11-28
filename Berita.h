#ifndef BERITA_H_INCLUDED
#define BERITA_H_INCLUDED
#include <iostream>
#include <string>

typedef int infotype;
typedef struct elmBerita *adrBerita;

struct elmBerita{
    int id_berita;
    string judul;
    string kategori;
    string isi;
    string tanggal;
    int views;
    int likes;

    adrBerita next;
    adrRelasi firstRelasi; //hubungan ke jurnalis
};

struct ListBerita{
    adrBerita first;
};

void createListBerita(adrBerita &first);
adrBerita createNodeBerita(int id, string judul, isi, tanggal, kategori);
void insertFirstBerita(ListBerita &L, adrBerita P);
void insertLastBerita(ListBerita &L, adrBerita P);
void insertAfterBerita(ListBerita &L, int idSebelum, adrBerita P);
void deleteFirstBerita(ListBerita &L);
void deleteLastBerita(ListBerita &L);
void deleteAfterBerita(ListBerita &L, int idSebelum);
void deleteBeritaById(ListBerita &L, int id);
void showAllBerita(ListBerita L);
adrBerita findBerita(ListBerita L, int id);
adrBerita getMostViewedBerita(ListBerita L);
adrBerita getMostLikedBerita(ListBerita L);
int countBerita(ListBerita L);


#endif // BERITA_H_INCLUDED
