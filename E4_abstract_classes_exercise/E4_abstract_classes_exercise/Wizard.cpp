#include "Wizard.h"

#include <iostream>


void Wizard::doMagic() {
    if (mana > 1) {
        std::cout << "Do magic trick !" << std::endl;
        setArmor(armor+(mana)/2);
    }
}

int Wizard::fight(GameCharacter &enemy) {
    int damage = 0;
    damage = basicFight(enemy);
    if (mana > 20) {
        damage *= 1.2;
        mana--;
    } else if (mana > 10)
        damage += 2;
    return damage;
}
