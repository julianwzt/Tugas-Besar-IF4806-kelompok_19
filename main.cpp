#include <iostream>
#include "Jurnalis.h"

using namespace std;

void runMenuAdmin(ListParent &LJ);
void runMenuUser(ListParent &LJ);

void loadDummyData(ListParent &LJ){
    infotypeP j1 = {"J01", "Najwa Shihab", "Narasi", 95};
    infotypeP j2 = {"J02", "Karni Ilyas", "TV One", 90};
    infotypeP j3 = {"J03", "Andy F. Noya", "Metro TV", 90};
    infotypeP j4 = {"J04", "Rosianna Silalahi", "Kompas TV", 85};
    infotypeP j5 = {"J05", "Aiman Witjaksono", "iNews", 85};
    infotypeP j6 = {"J06", "Dandhy Laksono", "WatchDoc", 80};

    insertParentSortedByRating(LJ, createElementParent(j1));
    insertParentSortedByRating(LJ, createElementParent(j2));
    insertParentSortedByRating(LJ, createElementParent(j3));
    insertParentSortedByRating(LJ, createElementParent(j4));
    insertParentSortedByRating(LJ, createElementParent(j5));
    insertParentSortedByRating(LJ, createElementParent(j6));

    addressP pNajwa = findElementParent(LJ, "J01");
    addressP pKarni = findElementParent(LJ, "J02");
    addressP pAndy  = findElementParent(LJ, "J03");
    addressP pRosi  = findElementParent(LJ, "J04");
    addressP pAiman = findElementParent(LJ, "J05");
    addressP pDandhy= findElementParent(LJ, "J06");

    int viewT1 = 50000;
    int likeT1 = 5000;

    adrBerita b1 = createNodeBerita("B01", "Debat Panas Pilpres", "Sudut pandang Najwa...", "12-01-2024", "Politik", "J01");
    b1->views = viewT1; b1->likes = likeT1;
    insertBeritaSortedByViews(pNajwa->berita, b1);

    adrBerita b2 = createNodeBerita("B02", "Debat Panas Pilpres", "Diskusi ILC...", "12-01-2024", "Politik", "J02");
    b2->views = viewT1; b2->likes = likeT1;
    insertBeritaSortedByViews(pKarni->berita, b2);

    adrBerita b3 = createNodeBerita("B03", "Debat Panas Pilpres", "Fakta data Aiman...", "12-01-2024", "Politik", "J05");
    b3->views = viewT1; b3->likes = likeT1;
    insertBeritaSortedByViews(pAiman->berita, b3);

    int viewT2 = 25000;
    int likeT2 = 2500;

    adrBerita b4 = createNodeBerita("B04", "Investigasi Tambang Ilegal", "Dokumenter lapangan...", "10-02-2024", "Lingkungan", "J06");
    b4->views = viewT2; b4->likes = likeT2;
    insertBeritaSortedByViews(pDandhy->berita, b4);

    adrBerita b5 = createNodeBerita("B05", "Investigasi Tambang Ilegal", "Wawancara menteri...", "11-02-2024", "Hukum", "J01");
    b5->views = viewT2; b5->likes = likeT2;
    insertBeritaSortedByViews(pNajwa->berita, b5);

    adrBerita b6 = createNodeBerita("B06", "Kisah Difabel Sukses", "Inspiratif...", "05-03-2024", "Sosial", "J03");
    b6->views = 15000; b6->likes = 1800;
    insertBeritaSortedByViews(pAndy->berita, b6);

    adrBerita b8 = createNodeBerita("B08", "Wanita Karir Masa Kini", "Talkshow...", "08-03-2024", "Gaya Hidup", "J04");
    b8->views = 12000; b8->likes = 400;
    insertBeritaSortedByViews(pRosi->berita, b8);

    adrBerita b10 = createNodeBerita("B10", "Misteri Rumah Tua", "Uji nyali...", "20-03-2024", "Horor", "J05");
    b10->views = 40000; b10->likes = 2000;
    insertBeritaSortedByViews(pAiman->berita, b10);

    adrBerita b11 = createNodeBerita("B11", "Korupsi Triliunan", "Tertangkap tangan...", "22-03-2024", "Hukum", "J02");
    b11->views = 35000; b11->likes = 900;
    insertBeritaSortedByViews(pKarni->berita, b11);

    adrBerita b13 = createNodeBerita("B13", "Catatan Najwa: Keadilan", "Narasi penutup...", "30-03-2024", "Opini", "J01");
    b13->views = 60000; b13->likes = 7500;
    insertBeritaSortedByViews(pNajwa->berita, b13);

    adrBerita b7 = createNodeBerita("B07", "Bedah Buku Sejarah", "Review buku...", "01-03-2024", "Pendidikan", "J03");
    b7->views = 5000; b7->likes = 150;
    insertBeritaSortedByViews(pAndy->berita, b7);

    adrBerita b14 = createNodeBerita("B14", "Jejak Kriminal Ibukota", "Liputan malam...", "25-03-2024", "Kriminal", "J05");
    b14->views = 8000; b14->likes = 250;
    insertBeritaSortedByViews(pAiman->berita, b14);
}

int main(){
    ListParent LJ;
    createListParent(LJ);

    loadDummyData(LJ);

    int pil = -1;
    while(pil != 0){
        cout << "\n======= MAIN MENU =======" << endl;
        cout << "||1. Admin             ||" << endl;
        cout << "||2. User              ||" << endl;
        cout << "||0. Exit              ||"<< endl;
        cout << "=========================" <<endl;
        cout << "Pilihan: "; cin >> pil;

        if(pil == 1){
            runMenuAdmin(LJ);
        }else if (pil == 2){
            runMenuUser(LJ);
        }
    }
    return 0;
}
