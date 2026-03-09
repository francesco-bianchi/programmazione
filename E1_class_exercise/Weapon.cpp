#include "Weapon.h"

int Weapon::use() {
    if (magic)
        return strength*2;
    return strength;
    // TODO return strenght, but if the weapon is magic return a doubled value of strength OK
}