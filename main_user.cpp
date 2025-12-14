#include "Jurnalis.h"
#include "Berita.h"
#include <iostream>

using namespace std;

void runMenuUser(ListParent &LJ){
    int pil = -1;
    while(pil != 0){
        cout << "\n========== MENU USER ==========" << endl;
        cout << "||1. Cari Berita & Baca      ||" << endl;
        cout << "||2. Tampilkan Semua Berita  ||" << endl;
        cout << "||0. Kembali                 ||" << endl;
        cout << "===============================" <<endl;
        cout << "Pilihan: ";
        cin >> pil;

        if(pil == 1){
            string id;
            cout << "Masukkan ID Berita: ";
            cin >> id;
            adrBerita B = findBeritaGlobal(LJ.first, id);
            if(B != nullptr){
                cout << "\n-------------------------------" << endl;
                cout << "Judul   : " << B->judul << endl;
                cout << "Kategori: " << B->kategori << endl;
                cout << "Isi     : " << B->isi << endl;
                cout << "-------------------------------" << endl;
                B->views++;
                char jawab;
                cout << "Apakah Anda menyukai berita ini? (y/n): ";
                cin >> jawab;
                if(jawab == 'y' || jawab == 'Y'){
                    B->likes++;
                    cout << ">> Anda menyukai berita ini. (Total Likes: " << B->likes << ")" << endl;
                    addressP penulis = findElementParent(LJ, B->idPenulis);
                    if(penulis != nullptr){
                        penulis->info.rating += 2;
                        cout << ">> Rating Jurnalis " << penulis->info.nama
                             << " naik menjadi: " << penulis->info.rating << endl;
                    }
                }else{
                    cout << ">> Terima kasih telah membaca." << endl;
                }

            }else{
                cout << "[!] Berita ID " << id << " tidak ditemukan." << endl;
            }
        }else if(pil == 2){
            showAllBeritaGlobal(LJ.first);
        }
    }
}
