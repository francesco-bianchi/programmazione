#include "Sword.h"

Sword::Sword(int s, bool m, bool v) : Weapon(s, m), valirian(v) {
    // there could be some more code here...
    // or just keep it empty, as it makes more sense
}

// Call basicUse() and if valirian double the damage
int Sword::use() {
    int damage = basicUse();
    if (valirian) {
        damage = damage * 2;
    }
    return damage;
}

Sword* Sword::clone() {
    return new Sword(*this);
}