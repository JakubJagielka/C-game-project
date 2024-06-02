#include <iostream>
#include <string>
#include <cstdlib>  // for std::rand()
#include <ctime>    // for std::time()
#include "header.h"

// Function prototypes for two opponents/allies
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

void attack(bohater &hero, oponent &opponent) {
    int damage = hero.atak - opponent.obrona;
    if (damage < 0) damage = 0;
    opponent.hp -= damage;
    std::cout << hero.imie << " attacks for " << damage << " damage!" << std::endl;
}

void ability(bohater &hero, oponent &opponent) {
    int damage = (hero.atak * 2) - opponent.obrona;
    if (damage < 0) damage = 0;
    opponent.hp -= damage;
    std::cout << hero.imie << " uses an ability and attacks for " << damage << " damage!" << std::endl;
}

void heal(bohater &hero) {
    if (hero.ekwipunek.miksturaleczaca > 0) {
        hero.hp += 20;
        hero.ekwipunek.miksturaleczaca--;
        std::cout << hero.imie << " uses a healing potion and recovers 20 HP!" << std::endl;
    } else {
        std::cout << "No healing potions left!" << std::endl;
    }
}

void block(bohater &hero) {
    std::cout << hero.imie << " prepares to block the next attack!" << std::endl;
    hero.obrona += 10;
}

void attack(oponent &ally, oponent &opponent) {
    int damage = ally.atak - opponent.obrona;
    if (damage < 0) damage = 0;
    opponent.hp -= damage;
    std::cout << ally.imie << " attacks for " << damage << " damage!" << std::endl;
}

void ability(oponent &ally, oponent &opponent) {
    int damage = (ally.atak * 2) - opponent.obrona;
    if (damage < 0) damage = 0;
    opponent.hp -= damage;
    std::cout << ally.imie << " uses an ability and attacks for " << damage << " damage!" << std::endl;
}

void heal(oponent &ally) {
    std::cout << ally.imie << " can't heal!" << std::endl;
}

void block(oponent &ally) {
    std::cout << ally.imie << " prepares to block the next attack!" << std::endl;
    ally.obrona += 10;
}

void opponentMove(bohater &hero, oponent &opponent) {
    int move = std::rand() % 3;
    int damage;
    switch (move) {
        case 0:
            std::cout << "Opponent attacks!" << std::endl;
            damage = opponent.atak - hero.obrona;
            if (damage < 0) damage = 0;
            hero.hp -= damage;
            std::cout << hero.imie << " takes " << damage << " damage!" << std::endl;
            break;
        case 1:
            std::cout << "Opponent uses an ability!" << std::endl;
            damage = (opponent.atak * 2) - hero.obrona;
            if (damage < 0) damage = 0;
            hero.hp -= damage;
            std::cout << hero.imie << " takes " << damage << " damage!" << std::endl;
            break;
        case 2:
            std::cout << "Opponent heals!" << std::endl;
            opponent.hp += 20;
            std::cout << "Opponent heals 20 HP!" << std::endl;
            break;
    }
}

void opponentMove(oponent &ally, oponent &opponent) {
    int move = std::rand() % 3;
    int damage;
    switch (move) {
        case 0:
            std::cout << "Opponent attacks!" << std::endl;
            damage = opponent.atak - ally.obrona;
            if (damage < 0) damage = 0;
            ally.hp -= damage;
            std::cout << ally.imie << " takes " << damage << " damage!" << std::endl;
            break;
        case 1:
            std::cout << "Opponent uses an ability!" << std::endl;
            damage = (opponent.atak * 2) - ally.obrona;
            if (damage < 0) damage = 0;
            ally.hp -= damage;
            std::cout << ally.imie << " takes " << damage << " damage!" << std::endl;
            break;
        case 2:
            std::cout << "Opponent heals!" << std::endl;
            opponent.hp += 20;
            std::cout << "Opponent heals 20 HP!" << std::endl;
            break;
    }
}

bool Game::walka(bohater &hero, oponent &opponent, oponent *ally = nullptr, oponent *opponent2 = nullptr) {
    std::srand(std::time(0));

    while (hero.hp > 0 && opponent.hp > 0 && (!opponent2 || opponent2->hp > 0)) {
        std::cout << "Hero HP: " << hero.hp << ", Opponent HP: " << opponent.hp;
        if (opponent2) std::cout << ", Opponent2 HP: " << opponent2->hp;
        if (ally) std::cout << ", Ally HP: " << ally->hp;
        std::cout << std::endl;

        std::cout << "Choose your action: (1) Attack (2) Ability (3) Heal (4) Block" << std::endl;
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                attack(hero, opponent);
                if (opponent2 && opponent.hp <= 0) attack(hero, *opponent2);
                break;
            case 2:
                ability(hero, opponent);
                if (opponent2 && opponent.hp <= 0) ability(hero, *opponent2);
                break;
            case 3:
                heal(hero);
                break;
            case 4:
                block(hero);
                break;
            default:
                std::cout << "Invalid choice! Try again." << std::endl;
                continue;
        }

        if (opponent.hp > 0) {
            opponentMove(hero, opponent);
        } else if (opponent2 && opponent2->hp > 0) {
            opponentMove(hero, *opponent2);
        }

        if (ally && ally->hp > 0) {
            int allyChoice = std::rand() % 4;
            switch (allyChoice) {
                case 0:
                    attack(*ally, opponent);
                    if (opponent2 && opponent.hp <= 0) attack(*ally, *opponent2);
                    break;
                case 1:
                    ability(*ally, opponent);
                    if (opponent2 && opponent.hp <= 0) ability(*ally, *opponent2);
                    break;
                case 2:
                    heal(*ally);
                    break;
                case 3:
                    block(*ally);
                    break;
            }
        }
    }

    if (hero.hp <= 0) {
        std::cout << "You have been defeated!" << std::endl;
        std::cout << "Thre story ends here, you are a dead man." << std::endl;
        std::cin.ignore();
        std::cin.ignore();
        std::cout<<"You better hope there is afterlife"<<std::endl;
        exit(0);
        return false;
    } else {
        std::cout << "You defeated the " << opponent.imie << std::endl;

        return true;
    }
}