/*
 * Character.cpp
 *
 */

#include "GameCharacter.h"

#include <ctime>
#include <iostream>

using namespace std;

GameCharacter::GameCharacter(int hp, int a) {
    // TODO set up the attributes OK
    HP = hp,
    armor = a,
    posX =0,
    posY = 0,
    weapon = nullptr;
    // position and weapon must be set to 0 or null pointer
}



int GameCharacter::getHP() {
    return HP;
}

void GameCharacter::setHP(int hp) {
    this->HP = hp;
}

Weapon* GameCharacter::getWeapon() {
    return weapon;
}

void GameCharacter::setWeapon(Weapon* weapon) {
    this->weapon = weapon;
}

void GameCharacter::move(int x, int y) {
    // TODO implement OK
    this->posX += x;
    this->posY += y;
}

void GameCharacter::move(int distance) {
    // TODO implement OK
    this->posX = this->posX + distance;
    this->posY = this->posY + distance;
}

int GameCharacter::getArmor() {
    return armor;
}

void GameCharacter::setArmor(int defense) {
    this->armor = defense;
}

bool GameCharacter::fight(GameCharacter &enemy) {
    int hit = 1;

    // TODO if a weapon is available use it and store result in hit OK
    if (weapon!=nullptr) {
        hit = getWeapon()->use();
    }

    int damage = 0;
    // TODO if hit > enemy armor value then apply damage using receiveDamage()
    //  and store it in damage variable OK

    if (hit > enemy.getArmor()) {
        damage = enemy.receiveDamage(hit - enemy.getArmor());
    }

    bool success = false;
    if (damage > 0) {
        cout << "You hit the enemy! Enemy hp: " << enemy.getHP() << endl;
        // TODO print "You hit the enemy !" followed by enemy hit points OK
        success = true;
    } else
        cout << "You miss the hit..." << endl;
    return success;
}

int GameCharacter::receiveDamage(int points) {
    // TODO OK
    // if armor > 4 then points are divided by 3
    // if armor > 2 then points are divided by 2
    // if armor >= 1 then points are reduced by 2
    if (getArmor()>4) {
        points = points/3;
    }
    else if (getArmor()>2) {
        points = points/2;
    }
    else if (getArmor()>=1) {
        points = points -2;
    }

    if (points <= 0)
        points = 1;

    HP -= points;
    if (points > 10)
        armor--;

    return points;
}

bool GameCharacter::isLegalFight(GameCharacter &enemy) {
    int maxDistance = 1;
    // FIXME: compute distance and return true if a character is within maxDistance along X or Y OK
    int distanceX = this->getPosX() - enemy.getPosX();
    int distanceY = this->getPosY() - enemy.getPosY();
    if (distanceX <= maxDistance && distanceX>=0 && distanceY>=0 && distanceY <= maxDistance) {
        return true;
    }
    return false;
}