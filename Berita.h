#ifndef BERITA_H_INCLUDED
#define BERITA_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

typedef struct elmBerita *adrBerita;

struct elmBerita{
    string id_berita;
    string judul;
    string kategori;
    string isi;
    string tanggal;
    int views;
    int likes;
    string idPenulis;
    adrBerita next;
    adrBerita prev;
};

adrBerita createNodeBerita(string id, string judul, string isi, string tanggal, string kategori, string idPenulis);
void insertBeritaSortedByViews(adrBerita &firstBerita, adrBerita P);
void insertBeritaToJurnalis(adrBerita &firstBerita, adrBerita P);
void deleteBeritaById(adrBerita &firstBerita, string id);
void showBeritaByJurnalis(adrBerita firstBerita);

#endif // BERITA_H_INCLUDED
