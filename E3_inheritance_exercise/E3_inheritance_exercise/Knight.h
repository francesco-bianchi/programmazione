//
// Created by Marco Bertini on 08/04/18.
//

#ifndef E3_INHERITANCE_EXERCISE_KNIGHT_H
#define E3_INHERITANCE_EXERCISE_KNIGHT_H

#include <string>
#include <utility>
using namespace std;
#include "GameCharacter.h"

// extend GameCharacter
class Knight : public GameCharacter {
public:
    explicit Knight(int hp=20, int a=10, int d=5, bool p=false, string n="Knight") : GameCharacter(hp, a), dexterity(d), paladin(p), name(n) {};

    explicit Knight(string n) : GameCharacter(20, 10), dexterity(5), paladin(false), name(n) {};
    int fight(GameCharacter &enemy) override; //override permette di dire che si sta leggendo nel metodo della classe base e si scrive le cose in più (se non lo trova errore)

    void move(int x, int y) override;

    char getCharacterSymbol() const override{
        return 'K';
    }

private:
    int dexterity;
    bool paladin;
    std::string name;
};


#endif //E3_INHERITANCE_EXERCISE_KNIGHT_H
