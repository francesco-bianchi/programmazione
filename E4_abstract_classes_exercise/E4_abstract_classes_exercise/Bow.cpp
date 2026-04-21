#include "Bow.h"

Bow::Bow(int strength, int ar, bool magic) : Weapon(strength, magic), arrows(ar) {

}

int Bow::use() {
    int damage = 0;
    if (arrows) {
        damage = basicUse();
        arrows--;
    }
    return damage;
}

Bow* Bow::clone() {
    return new Bow(*this);
}
