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
            cout << "ID: "; cin >> data.idJurnalis;
            cout << "Nama: "; cin >> data.nama;
            cout << "Media: "; cin >> data.media;
            cout << "Rating (1-100): "; cin >> data.rating;
            insertParentSortedByRating(LJ, createElementParent(data));
            cout << "Jurnalis berhasil ditambahkan." << endl;

        }else if(menu == 2){
            int nPenulis;
            cout << "Berita ini ditulis oleh berapa jurnalis? : ";
            cin >> nPenulis;

            if(nPenulis > 0){
                string idB, judul, kat, isi, tgl;
                cout << "\n>> Masukkan Data Berita <<" << endl;
                cout << "ID Berita : "; cin >> idB;
                cout << "Judul     : "; cin >> judul;
                cout << "Kategori  : "; cin >> kat;
                cout << "Isi       : "; cin >> isi;
                cout << "Tanggal   : "; cin >> tgl;
                for(int i = 1; i <= nPenulis; i++){
                    string idJ;
                    cout << "\nMasukkan ID Jurnalis ke-" << i << ": ";
                    cin >> idJ;
                    addressP P = findElementParent(LJ, idJ);
                    if(P != nullptr){
                        adrBerita B = createNodeBerita(idB, judul, isi, tgl, kat, idJ);
                        insertBeritaSortedByViews(P->berita, B);
                        cout << "-> [Sukses] Berita ditambahkan ke Jurnalis " << P->info.nama << endl;
                    }else{
                        cout << "-> [Gagal] Jurnalis ID " << idJ << " tidak ditemukan!" << endl;
                    }
                }
            }else{
                cout << "Jumlah penulis tidak valid." << endl;
            }

        }else if(menu == 3){
            int subMenu;
            cout << "\n============== Hapus Jurnalis =============="<<endl;
            cout << "1. Hapus berdasarkan ID Spesifik          ||" << endl;
            cout << "2. Bersihkan Jurnalis dengan rating rendah||" << endl;
            cout << "============================================" <<endl;
            cout << "Pilihan: ";
            cin >> subMenu;
            if(subMenu == 1){
                string idJ;
                cout << "Masukkan ID Jurnalis yg ingin dihapus: "; cin >> idJ;
                deleteJurnalisById(LJ, idJ);
            }else if(subMenu == 2){
                int batas;
                cout << "Hapus jurnalis rating di bawah: "; cin >> batas;
                deleteJurnalisByRatingBelow(LJ, batas);
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
