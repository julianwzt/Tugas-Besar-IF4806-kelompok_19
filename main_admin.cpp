#include "Jurnalis.h"
#include "Berita.h"
#include <iostream>

using namespace std;

void runMenuAdmin(ListParent &LJ){
    int menu = -1;
    while(menu != 0){
        cout << "\n========= MENU ADMIN ==========" << endl;
        cout << "|| 1. Tambah Jurnalis        || " << endl;
        cout << "|| 2. Tambah Berita          ||" << endl;
        cout << "|| 3. Hapus Jurnalis         ||" << endl;
        cout << "|| 4. Hapus Berita           ||" << endl;
        cout << "|| 5. Lihat Data             ||" << endl;
        cout << "|| 0. Kembali                ||" << endl;
        cout << "===============================" <<endl;
        cout << "Pilihan: ";
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
            int subMenu;
            cout << "\n=============== Hapus Berita =============" << endl;
            cout << "||1. Hapus berdasarkan ID Spesifik      ||"<< endl;
            cout << "||2. Bersihkan Berita dengan like rendah||" << endl;
            cout << "==========================================" <<endl;
            cout << "Pilihan: ";
            cin >> subMenu;
            if(subMenu == 1){
                string idJ, idB;
                cout << "Masukkan ID Jurnalis pemilik berita: ";
                cin >> idJ;
                addressP P = findElementParent(LJ, idJ);
                if(P != nullptr){
                    cout << "Masukkan ID Berita yg ingin dihapus: ";
                    cin >> idB;
                    deleteBeritaById(P->berita, idB);
                }else{
                    cout << "Jurnalis tidak ditemukan." << endl;
                }
            }else if(subMenu == 2){
                int batas;
                cout << "Hapus semua berita yang LIKES-nya di bawah angka: ";
                cin >> batas;
                cout << "\n>> Memulai pembersihan berita dengan likes rendah..." << endl;
                deleteBeritaGlobalByLikesBelow(LJ, batas);
                cout << ">> Proses selesai." << endl;
            }else{
                cout << "Pilihan tidak valid." << endl;
            }
        }else if(menu == 5){
            int subMenu;
            cout << "\n======  LIHAT DATA =======" << endl;
            cout << "||1. Lihat Data Jurnalis||" << endl;
            cout << "||2. Lihat Data Berita  ||" << endl;
            cout << "||3. Lihat Data Lengkap ||" << endl;
            cout << "==========================" <<endl;
            cout << "Pilihan: ";
            cin >> subMenu;

            cout << endl;
            if(subMenu == 1){
                viewJurnalisOnly(LJ);
            }else if(subMenu == 2){
                showAllBeritaGlobal(LJ.first);
            }else if(subMenu == 3){
                viewParent(LJ);
            }else{
                cout << "Pilihan tidak valid." << endl;
            }
        }
    }
}
