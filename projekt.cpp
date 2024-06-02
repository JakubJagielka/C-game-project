#include <iostream>
#include "header.h"

using namespace std;

bohater::bohater() {}

bohater::bohater(int wybur, string imiem) {
    if (wybur == 1) {
        imie = imiem;
        hp = 200;
        atak = 13;
        obrona = 5;
        poziom = 1;
        doswiadczenie = 0;
    } else if (wybur == 2) {
        hp = 150;
        atak = 20;
        obrona = 3;
        poziom = 1;
        doswiadczenie = 0;
    } else if (wybur == 3) {
        hp = 180;
        atak = 20;
        obrona = 2;
        poziom = 1;
        doswiadczenie = 0;
    }
}

Game::Game(bohater bohater1, Lokalizacje loc1) {
    this->bohater1 = bohater1;
    this->loc1 = loc1;

}

int main() {

    string imiem;
    int wybur;
    cout << "Witaj w grze bohaterze podaj swe imie" << endl;
    cin >> imiem;

    cout << "Witaj " << imiem << "\nWybierz klase: \n1.Mocarz\n2.Jedno szczalowiec\n3.Zlodziej" << endl;
    cin >> wybur;

    bohater bohater1 = bohater(wybur, imiem);
    Lokalizacje loc1;

    Game game(bohater1, loc1);

    game.Poziom_1();
    game.Poziom_2();
    game.Poziom_3();


    return 0;
}