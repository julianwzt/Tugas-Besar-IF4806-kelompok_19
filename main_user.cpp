#include "Jurnalis.h"
#include "Berita.h"
#include <iostream>

using namespace std;

void runMenuUser(ListParent &LJ, ListBerita &LB) {
    int pil = -1;
    while (pil != 0) {
        cout << "\n========== MENU USER ==========" << endl;
        cout << "||1. Cari Berita             ||" << endl;
        cout << "||2. Lihat Berita Terpopuler ||" << endl;
        cout << "||3. Tampilkan Semua Berita  ||" << endl;
        cout << "||0. Kembali                 ||" << endl;
        cout << "===============================" <<endl;
        cout << "Pilihan: ";
        cin >> pil;

        if (pil == 1) {
            string id;
            cout << "ID Berita: ";
            cin >> id;
            adrBerita B = findBerita(LB, id);
            if (B) {
                cout << "Ditemukan: " << B->judul << endl;
                B->views++;
                cout << "Views bertambah jadi: " << B->views << endl;
            }else{
                cout << "Berita ID " << id << " tidak ditemukan." << endl;
            }
        }
        else if (pil == 2) {
            adrBerita B = getMostViewedBerita(LB);
            if(B) cout << "Top: " << B->judul << " (" << B->views << " views)" << endl;
        }
        else if (pil == 3) {
            showAllBerita(LB);
        }
    }
}
