//
// Created by Marco Bertini on 08/04/18.
//

#include "Knight.h"

#include "Dice.h"

int Knight::fight(GameCharacter &enemy) {
    int damage = GameCharacter::fight(enemy);
    if (dexterity > 10)
        damage += GameCharacter::fight(enemy);
    if (paladin)
        damage +=10;
    return damage;
}

void Knight::move(int x, int y) {
    GameCharacter::move(x, y);
    if (dexterity > 10)
        GameCharacter::move(x, y);
}
