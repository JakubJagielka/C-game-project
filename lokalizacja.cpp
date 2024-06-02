#include <iostream>
#include "header.h"

using namespace std;

void Lokalizacje::Zbrojmistrz::Wizyta(bohater &bohater1) {
    cout << "Witaj w sklepie zbrojmistrza, masz " << bohater1.gold << " Zlota, co chcesz kupic?\n1. Ulepsz gasnica (10 zlota)\n2. Ulepsz Kurtke przeciw-pozarowa (10 zlota)\n3. Bomba wodna (5 zlota)\n4. Wyjdz" << endl;
    int wybor3;
    cin >> wybor3;
    switch (wybor3) {
        case 1:
            if (bohater1.gold >= 10) {
                cout << "Ulepszyles Gasnice" << endl;
                bohater1.atak += 5;
                bohater1.ekwipunek.gasnica = true;
                bohater1.gold -= 10;
            } else {
                cout << "Nie masz wystarczajaco zlota" << endl;
            }
            Wizyta(bohater1);
            break;
        case 2:
            if (bohater1.gold >= 10) {
                cout << "Ulepszyles Kurtka przeciw-pozarowa" << endl;
                bohater1.obrona += 3;
                bohater1.ekwipunek.kurtka = true;
                bohater1.gold -= 10;
            } else {
                cout << "Nie masz wystarczajaco zlota" << endl;
            }
            Wizyta(bohater1);
            break;
        case 3:
            if (bohater1.gold >= 5) {
                cout << "Kupiles Bomba wodna" << endl;
                bohater1.ekwipunek.bomba += 1;
                bohater1.gold -= 5;
            } else {
                cout << "Nie masz wystarczajaco zlota" << endl;
            }
            Wizyta(bohater1);
            break;
        case 4:
            break;
        default:
            cout << "Nieprawidlowy wybor" << endl;
            Wizyta(bohater1);
            break;
    }
}

void Lokalizacje::Tawerna::Wizyta(bohater &bohater1) {
    cout << "Witaj w tawernie, co chcesz zrobic?\n1. Kup piwo (5 zlota)\n2. Zatrudnij najemnika (10 zlota)\n3. Zapytaj o plotki\n4. Wyjdz" << endl;
    int wybor4;
    cin >> wybor4;
    switch (wybor4) {
        case 1:
            if (bohater1.gold >= 5) {
                cout << "Odrazu czujesz sie lepiej, czujesz sie bardziej pewny siebie, czujesz ze muglbys pokonac te smoki sam." << endl;
                bohater1.pijany = true;
                bohater1.gold -= 5;
                cout << "|Bohater jest teraz pijany|" << endl;
                cout << "Niestety inni zbyt bardzo zazdroszcza ci sil(tak ci sie przynajmniej wydaje) i zostales wyrzucony z tawerny" << endl;
            } else {
                cout << "Nie masz wystarczajaco zlota" << endl;
            }
            Wizyta(bohater1);
            break;
        case 2:
            if (bohater1.gold >= 10) {
                bohater1.gold -= 10;
                cout << "Najemnik zgodzil sie wziol zloto i powiedzial ze wyruszy jak tylko wyjdziesz z miasta. Czy cie oklamal? Mozliwe" << endl;
                this->wynajetynajemnik = true;
            } else {
                cout << "Nie masz wystarczajaco zlota" << endl;
            }
            Wizyta(bohater1);
            break;
        case 3:
            cout << "Chodza plotki ze czarnym smoka czesto brakuje powietrza, bomby dymne sa na nie bardzo efektywne" << endl;
            cout << "Uslyszales rowniez ze smoki sa podburzane przez tajemnicza sile znana tylko jako 'Wladca Zaru'," << endl;
            Wizyta(bohater1);
            break;
        case 4:
            break;
        default:
            cout << "Nieprawidlowy wybor" << endl;
            Wizyta(bohater1);
            break;
    }
}