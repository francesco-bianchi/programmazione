//
// Created by Marco Bertini on 08/04/18.
//

#ifndef E3_INHERITANCE_EXERCISE_WIZARD_H
#define E3_INHERITANCE_EXERCISE_WIZARD_H

#include <string>
using namespace std;
#include "GameCharacter.h"

class Wizard : public GameCharacter {
    // in this class do not override move()
public:
    // in derived classes we can introduce new behaviours, like this brand new method:
    explicit Wizard(int hp=20, int a=10, int m=10, string n="Wizy") : GameCharacter(hp, a), mana(m), name(n) {};

    explicit Wizard(string n) : GameCharacter(20, 10), mana(10), name(n) {}

    int fight(GameCharacter &enemy) override; //override permette di dire che si sta leggendo nel metodo della classe base e si scrive le cose in più (se non lo trova errore)

    virtual void doMagic(); // it's virtual: we expect to further derive and override its behaviour in derived classes

    // override base class method
    char getCharacterSymbol() const override{
        return 'W';
    }

protected:
    int mana; // spiritual strength
    std::string name;
};


#endif //E3_INHERITANCE_EXERCISE_WIZARD_H
