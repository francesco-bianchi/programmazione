#ifndef WEAPON_H
#define WEAPON_H


class Weapon {
public:
    // TODO implement constructor with two arguments: strength and magic, with a default value of false OK
    Weapon(int strength, bool magic=false)
            : strength(strength),
              magic(magic) {
        }

    int use(); // FIXME

    int getStrength() const {
        return strength;
    }

    bool getMagic() const {
        return magic;
    }

    // TODO implement getter/setter for attributes OK

protected:
    int strength;
    bool magic;
};

#endif //WEAPON_H
