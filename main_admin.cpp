#include "Jurnalis.h"
#include "Berita.h"
#include <iostream>

using namespace std;

void runMenuAdmin(ListParent &LJ, ListBerita &LB){
    int menu;
    menu = -1;
    while(menu != 0){
        cout << "\n========= MENU ADMIN =========" << endl;
        cout << "|| 1. Tambah Jurnalis        ||" << endl;
        cout << "|| 2. Tambah Berita          ||" << endl;
        cout << "|| 3. Hubungkan              ||" << endl;
        cout << "|| 4. Hapus Jurnalis         ||" << endl;
        cout << "|| 5. Hapus Berita           ||" << endl;
        cout << "|| 6. Lihat Data             ||" << endl;
        cout << "|| 0. Kembali                ||" << endl;
        cout << "===============================" <<endl;
        cout << "Pilihan:";
        cin >> menu;
        if(menu == 1){
            infotypeP data;
            cout << "ID: ";
            cin >> data.idJurnalis;
            cout << "Nama: ";
            cin >> data.nama;
            cout << "Media: ";
            cin >> data.media;
            insertFirstParent(LJ, createElementParent(data));
            cout << "Jurnalis Berhasil ditambahkan!" << endl;
        }else if(menu == 2){
            string id, j, k, i, t;
            cout << "ID: ";
            cin >> id;
            cout << "Judul: ";
            cin >> j;
            cout << "Kategori: ";
            cin >> k;
            cout << "Isi: ";
            cin >> i;
            cout << "Tanggal: ";
            cin >> t;
            insertFirstBerita(LB, createNodeBerita(id, j, i, t, k));
            cout << "Berita Berhasil ditambahkan!" << endl;
        }else if (menu == 3){
            string idJ, idB;
            cout << "ID Jurnalis: ";
            cin >> idJ;
            cout << "ID Berita: ";
            cin >> idB;
            addressP P = findElementParent(LJ, idJ);
            adrBerita B = findBerita(LB, idB);
            if(P && B){
                connect(P, B);
                cout << "Jurnalis dan Berita Berhasil terhubung" << endl;
            }else{
                cout << "ID jurnalis/Berita tidak ditemukan" << endl;
            }
        }else if(menu == 4){
            string idJ;
            cout << "Masukkan ID Jurnalis yg ingin dihapus: ";
            cin >> idJ;
            deleteJurnalisById(LJ, idJ);
        }else if(menu == 5){
            string idB;
            cout << "Masukkan ID Berita yg ingin dihapus: ";
            cin >> idB;
            deleteBeritaById(LB, idB);
        }else if(menu == 6){
            viewParent(LJ, LB);
        }
    }
}
