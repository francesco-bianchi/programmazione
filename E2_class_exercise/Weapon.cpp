//
// Created on: 13/mar/2018
// Author: bertini
//

#include "Weapon.h"

Weapon::Weapon(int s, bool m) :
    strength(s),
    magic(m) {
        if (strength < 0)
            strength = DEFAULT_STRENGTH;
    }


int Weapon::use() {
    int result = strength;
    if (magic)
        result *= 2;
    return result;
}