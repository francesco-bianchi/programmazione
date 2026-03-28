//
// Created by Marco Bertini on 08/04/18.
//

#ifndef E3_INHERITANCE_EXERCISE_SKELETON_H
#define E3_INHERITANCE_EXERCISE_SKELETON_H
#include "GameCharacter.h"

#include "GameCharacter.h"
class Skeleton : public GameCharacter{
public:
    explicit Skeleton(bool mr)
            : magicRecover(mr) {
        }

    // XXX it's already implemented in .cpp file

    int receiveDamage(int points) override;

    // XXX no need to override other base class methods in this class

    // override base class method
    char getCharacterSymbol() const override {
        return 'S';
    }

private:
    bool magicRecover;
};


#endif //E3_INHERITANCE_EXERCISE_SKELETON_H
