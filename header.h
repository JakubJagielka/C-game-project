#ifndef HEADER_H
#define HEADER_H

#include <string>

class bohater {
public:
    std::string imie;
    int hp;
    int maxhp;
    int atak;
    int obrona;
    int poziom;
    int doswiadczenie;
    int gold = 0;
    bool pijany = false;
    int szczescie =0;
    class ekwipunek {
        public:
        bool gasnica = false;
        bool kurtka = false;
        int bomba = 0;
        int miksturaleczaca = 0;
    };

    bohater();
    bohater(int wybur, std::string imiem);

    ekwipunek ekwipunek;
};

class Lokalizacje {
public:
    class Zbrojmistrz {
    public:
        void Wizyta(bohater &bohater1);
    };

    class Tawerna {
    public:
        bool wynajetynajemnik = false;
        void Wizyta(bohater &bohater1);
    };

    Zbrojmistrz zbrojmistrz;
    Tawerna tawerna;
};

class oponent {
    public:
    std::string imie;
    int hp;
    int atak;
    int obrona;
    oponent(std::string imie, int hp, int atak, int obrona) : imie(imie), hp(hp), atak(atak), obrona(obrona) {}

    };


class Game {
public:
    bohater bohater1;
    Lokalizacje loc1;
    int poziom = 0;
    bool MamonZostaje = true;

    Game(bohater bohater1, Lokalizacje loc1);
    void Poziom_1();
    void Poziom_2();
    void Poziom_3();

    bool walka(bohater &hero, oponent &opponent, oponent *ally, oponent *opponent2);
    
    };


void attack(bohater &hero, oponent &opponent);
void ability(bohater &hero, oponent &opponent);
void heal(bohater &hero);
void block(bohater &hero);
void opponentMove(bohater &hero, oponent &opponent);

void attack(oponent &ally, oponent &opponent);
void ability(oponent &ally, oponent &opponent);
void heal(oponent &ally);
void block(oponent &ally);
void opponentMove(oponent &ally, oponent &opponent);



#endif // HEADER_H