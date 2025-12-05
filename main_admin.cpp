#include "Jurnalis.h"
#include "Berita.h"
#include <iostream>

using namespace std;

void hapusBeritaBersih(ListBerita &LB, ListParent &LJ, int id) {
    // untuk memutus relasi di semua Jurnalis
    addressP P = LJ.first;
    while (P != nullptr) {
        disconnect(P, id);
        P = P->next;
    }
    deleteBeritaById(LB, id);
}

void runMenuAdmin(ListParent &LJ, ListBerita &LB) {
    int menu;
    menu = -1;
    while (menu != 0) {
        cout << "\n========= MENU ADMIN =========" << endl;
        cout << "|| 1. Tambah Jurnalis        ||" << endl;
        cout << "|| 2. Tambah Berita          ||" << endl;
        cout << "|| 3. Hubungkan (Connect)    ||" << endl;
        cout << "|| 4. Hapus Jurnalis (by ID) ||" << endl;
        cout << "|| 5. Hapus Berita (by ID)   ||" << endl;
        cout << "|| 6. Lihat Data             ||" << endl;
        cout << "|| 0. Kembali                ||" << endl;
        cout << "|| Pilih:                    ||";
        cin >> menu;
        cout << "==============================="
        if (menu == 1) {
            infotypeP data;
            cout << "ID: "; cin >> data.idJurnalis;
            cout << "Nama: "; cin >> data.nama;
            cout << "Media: "; cin >> data.media;
            insertLastParent(LJ, createElementParent(data));
        }else if (menu == 2){
            int id; string j, k, i, t;
            cout << "ID: "; cin >> id;
            cout << "Judul: "; cin >> j;
            cout << "Kategori: "; cin >> k;
            cout << "Isi: "; cin >> i;
            cout << "Tanggal: "; cin >> t;
            insertLastBerita(LB, createNodeBerita(id, j, i, t, k));
        }else if (menu == 3){
            string idJ; int idB;
            cout << "ID Jurnalis: "; cin >> idJ;
            cout << "ID Berita: "; cin >> idB;
            addressP P = findElementParent(LJ, idJ);
            adrBerita B = findBerita(LB, idB);
            if(P && B) {
                connect(P, B);
                cout << "Berhasil terhubung." << endl;
            } else {
                cout << "Data tidak ditemukan." << endl;
            }
        }else if (menu == 4){
            string idJ;
            cout << "Masukkan ID Jurnalis yg dihapus: "; cin >> idJ;
            deleteJurnalisById(LJ, idJ);
        }else if (menu == 5){
            int idB;
            cout << "Masukkan ID Berita yg dihapus: "; cin >> idB;
            hapusBeritaBersih(LB, LJ, idB);
        }else if (menu == 6){
            viewParent(LJ);
        }
    }
}
