#include "Jurnalis.h"

using namespace std;

void deleteJurnalisById(ListParent &L, string id){
    addressP P = L.first;
    addressP Prec = nullptr;
    while (P != nullptr && P->info.idJurnalis != id){
        Prec = P;
        P = P->next;
    }
    if(P == nullptr){
        cout << "Jurnalis tidak ditemukan." << endl;
        return;
    }
    while(P->berita != nullptr){
        string idB = P->berita->id_berita;
        deleteBeritaById(P->berita, idB);
    }
    if(Prec == nullptr){
        L.first = P->next;
    }else{
        Prec->next = P->next;
    }
    delete P;
}

adrBerita findBeritaGlobal(addressP firstJurnalis, string idBerita){
    addressP P = firstJurnalis;
    while(P != nullptr){
        adrBerita B = P->berita;
        while(B != nullptr){
            if(B->id_berita == idBerita) return B;
            B = B->next;
        }
        P = P->next;
    }
    return nullptr;
}
adrBerita getMostViewedGlobal(addressP firstJurnalis){
    addressP P = firstJurnalis;
    adrBerita maxB = nullptr;
    while(P != nullptr){
        if(P->berita != nullptr){
            if(maxB == nullptr || P->berita->views > maxB->views){
                maxB = P->berita;
            }
        }
        P = P->next;
    }
    return maxB;
}

void showAllBeritaGlobal(addressP firstJurnalis){
    addressP P = firstJurnalis;
    bool dataFound = false;

    cout << "\n===================== DATA BERITA ======================" << endl;
    while(P != nullptr){
        adrBerita B = P->berita;
        while(B != nullptr){
            bool sudahMuncul = false;
            addressP cekP = firstJurnalis;
            bool stopLoop = false;
            while(cekP != nullptr && !stopLoop){
                adrBerita cekB = cekP->berita;
                while(cekB != nullptr && !stopLoop){
                    if(cekP == P && cekB == B){
                        stopLoop = true;
                    }
                    else if(cekB->judul == B->judul){
                        sudahMuncul = true;
                        stopLoop = true;
                    }
                    cekB = cekB->next;
                }
                cekP = cekP->next;
            }
            if(!sudahMuncul){
                cout << "JUDUL: " << B->judul << " [" << B->id_berita << "]" << endl;
                cout << "Jumlah views : " << B->views << " | Jumlah like : " << B->likes << endl;
                cout << "---------------------------------------------------------" << endl;
            }
            B = B->next;
        }
        P = P->next;
    }
    if(dataFound) cout << "Belum ada berita sama sekali." << endl;
}

void deleteJurnalisByRatingBelow(ListParent &L, int batasBawah){
    addressP P = L.first;
    addressP Prec = nullptr;
    int countDeleted = 0;
    while(P != nullptr){
        if(P->info.rating < batasBawah){
            addressP toDelete = P;
            while(toDelete->berita != nullptr){
                string idB = toDelete->berita->id_berita;
                deleteBeritaById(toDelete->berita, idB);
            }
            if(Prec == nullptr){
                L.first = P->next;
                P = L.first;
            } else {
                Prec->next = P->next;
                P = P->next;
            }
            cout << "Menghapus Jurnalis: " << toDelete->info.nama << " (Rating: " << toDelete->info.rating << ")" << endl;
            delete toDelete;
            countDeleted++;
        }else{
            Prec = P;
            P = P->next;
        }
    }
    if(countDeleted == 0){
        cout << "Tidak ada jurnalis dengan rating di bawah " << batasBawah << endl;
    } else {
        cout << "Total " << countDeleted << " jurnalis berhasil dihapus." << endl;
    }
}
