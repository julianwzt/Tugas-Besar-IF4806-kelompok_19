#include <iostream>
#include "Jurnalis.h"
#include "Berita.h"

using namespace std;

void runMenuAdmin(ListParent &LJ, ListBerita &LB);
void runMenuUser(ListParent &LJ, ListBerita &LB);

int main(){
    ListParent LJ;
    ListBerita LB;

    createListParent(LJ);
    createListBerita(LB);

    int pil = -1;
    while(pil != 0){
        cout << "\n======= MAIN MENU =======" << endl;
        cout << "||1. Admin             ||" << endl;
        cout << "||2. User              ||" << endl;
        cout << "||0. Exit              ||"<< endl;
        cout << "=========================" <<endl;
        cout << "Pilihan: "; cin >> pil;

        if(pil == 1){
            runMenuAdmin(LJ, LB);
        }else if (pil == 2){
            runMenuUser(LJ, LB);
        }
    }
    return 0;
}

