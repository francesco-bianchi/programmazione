/*
 * Character.cpp
 *
 *  Created on: 13/mar/2018
 *  Author: bertini
 */

#include "GameCharacter.h"

#include <ctime>
#include <cmath>
#include <iostream>

#include "Dice.h"

using namespace std;
static const int DEFAULT_HP = 10;
static const int DEFAULT_ARMOR = 10;

GameCharacter::GameCharacter(int hp, int a): HP(hp), armor(a), posX(0), posY(0), weapon(nullptr){
    if (HP <= 0)
        HP =DEFAULT_HP;
    if (a<=0)
        a = DEFAULT_ARMOR;
}

int GameCharacter::getHP() const {
    return HP;
}

void GameCharacter::setHP(int hp) {
    this->HP = hp;
}

Weapon* GameCharacter::getWeapon() const{
    return weapon;
}

void GameCharacter::setWeapon(Weapon* weapon) {
    this->weapon = weapon;
}

void GameCharacter::move(int x, int y) {
    posX += x;
    posY += y;
}

void GameCharacter::move(int distance) {
    posX += distance;
    posY += distance;
}

int GameCharacter::getArmor() const {
    return armor;
}

void GameCharacter::setArmor(int defense) {
    this->armor = defense;
}

bool GameCharacter::fight(GameCharacter &enemy) {
    bool success = false;
    Dice* d = new Dice();
    int resultRoll = d->roll(1); //TODO finire
    int hit = 1;
    if (weapon)
        hit = weapon->use();

    int damage = 0;
    if (hit > enemy.getArmor()) {
        damage = enemy.receiveDamage(hit);
    }

    if (damage) {
        cout << "You hit the enemy ! (HP: " << enemy.getHP() << " punti)" << endl;
        success = true;
    } else
        cout << "You miss the hit..." << endl;
    return success;
}

int GameCharacter::receiveDamage(int points) {
    if (armor > 4)
        points /= 3;
    else if (armor > 2)
        points /= 2;
    else if (armor >= 1)
        points -= 2;

    if (points <= 0)
        points = 1;

    HP -= points;
    if (points > 10)
        armor--;

    return points;
}


bool GameCharacter::isLegalFight(const GameCharacter &enemy) const {
    int maxDistance = 1;
    if ((abs(posX - enemy.posX) > maxDistance) || (abs(posY - enemy.posY) > maxDistance))
        return false;
    return true;
}

static int l1Distance(const GameCharacter &a, const GameCharacter &b) {
    int distanceX = abs(a.getPosX()-b.getPosX());
    int distanceY = abs(a.getPosY()-b.getPosY());
    return distanceX + distanceY;
}