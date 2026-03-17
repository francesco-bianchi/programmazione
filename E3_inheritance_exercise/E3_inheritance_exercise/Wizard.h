//
// Created by Marco Bertini on 08/04/18.
//

#ifndef E3_INHERITANCE_EXERCISE_WIZARD_H
#define E3_INHERITANCE_EXERCISE_WIZARD_H

#include <string>
using namespace std;
#include "GameCharacter.h"

// TODO extend GameCharacter
class Wizard : public GameCharacter {
    // TODO override fight. Use mana to change behaviour. 
    // XXX it's already implemented in .cpp file

    // in this class do not override move()

    // in derived classes we can introduce new behaviours, like this brand new method:
    Wizard(int hp, int a, int m=10, string n="Wizard") : GameCharacter(hp, a), mana(m), name(n) {};

    int fight(GameCharacter &enemy) override; //override permette di dire che si sta leggendo nel metodo della classe base e si scrive le cose in più (se non lo trova errore)

    virtual void doMagic(); // it's virtual: we expect to further derive and override its behaviour in derived classes

    // override base class method
    char getCharacterSymbol() const {
        return 'W';
    }

protected:
    int mana; // spiritual strength
    std::string name;
};


#endif //E3_INHERITANCE_EXERCISE_WIZARD_H
