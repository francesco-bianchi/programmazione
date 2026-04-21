#ifndef E3_INHERITANCE_EXERCISE_KNIGHT_H
#define E3_INHERITANCE_EXERCISE_KNIGHT_H

#include <string>
#include "GameCharacter.h"

// extend GameCharacter
class Knight : public virtual GameCharacter { //l'ereditarietà diventa virtuale per evitare il diamond problem (uguale per wizard)
public:
    Knight(std::string n, int d, int hp = 20, int armor = 12, bool p = false);

    // override basicFight: dexterity > 10 perform second attack
    // if paladin then +10 damage
    int fight(GameCharacter &enemy) override;

    // override move: if dexterity > 10 allow +1 movement
    virtual void move(int x, int y) override;

    // override base class method
    virtual char getCharacterSymbol() const override {
        return 'K';
    }

private:
    int dexterity;
    bool paladin;
    std::string name;
};


#endif //E3_INHERITANCE_EXERCISE_KNIGHT_H
