//
// Created by Marco Bertini on 08/04/18.
//

#ifndef E3_INHERITANCE_EXERCISE_ORC_H
#define E3_INHERITANCE_EXERCISE_ORC_H
#include "GameCharacter.h"

class Orc : public GameCharacter{
public:
    explicit Orc(int s, int hp=20) {
        strength = s;
    };
    int fight(GameCharacter &enemy) override;

    void move(int x, int y) override;

    // override base class method
    char getCharacterSymbol() {
        return 'O';
    }

protected:
    int strength;
};


#endif //E3_INHERITANCE_EXERCISE_ORC_H
