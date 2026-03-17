/*
 * Character.h
 *
 *  Created on: 13/mar/2018
 *  Author: bertini
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "Weapon.h"

class GameCharacter {
public:
    GameCharacter();
    explicit GameCharacter(int hp, int a = 10);

    ~GameCharacter();

    GameCharacter(const GameCharacter &original);
    GameCharacter &operator=(const GameCharacter &right);

    virtual void move(int x, int y);

    virtual char getCharacterSymbol() const {
        return 'C';
    }

    virtual int fight(GameCharacter &enemy); // virtual cambia il comportamento del compilatore: genererà codice che permette di capire a quale metodo fra le classi derivate
    //si deve fare -> se ho puntatore.fight() il puntatore potrebbe essere Wizard o Knight e non si può fare il cast perché cambia ad ogni run(quindi va a vedere a cosa
    //sta puntando e chiama il metodo di quella classe derivata e non il metodo della classe base come fa senza virtual -> si usa con il POLIMORFISMO

    bool isLegalFight(const GameCharacter &enemy) const;

    virtual int receiveDamage(int points);

    static int l1Distance(const GameCharacter& p, const GameCharacter& q);

    int getPosX() const {
        return posX;
    }
    void setPosX(int posX) {
        GameCharacter::posX = posX;
    }

    int getPosY() const {
        return posY;
    }
    void setPosY(int posY) {
        GameCharacter::posY = posY;
    }

    int getHP() const;
    void setHP(int hp);

    Weapon* getWeapon();
    void setWeapon(Weapon* weapon);

    int getArmor() const;
    void setArmor(int defense);

    int getMovements() const;
    void setMovements(int movements);

protected:
    int HP;
    int armor;
    int movements;
    int posX;
    int posY;
    Weapon* weapon;
};

#endif // CHARACTER_H_
