#ifndef VAULT_H
#define VAULT_H

#include <iostream>
#include "Inventory.h"

// it represents a container of objects of the same type with a maximum number of stored objects
// defined at compile time (use a non-type template argument) or creation time (constructor parameter)
// default number of stored objects is 10
// it has a (x,y) position and a closed bool attribute with an open() method that sets it to false (set to true in constrctor).
// Overriden printContent method can print content only if closed == false
template <typename T, int N=10>
class Vault : public Inventory<T, N> {
public:
    Vault(int posX, int posY): posX(posX), posY(posY), closed(false) {}

    virtual ~Vault() {}

    virtual void printContent() const override;

    void open() {
        closed = false;
    }

    int getPosX() const {
        return posX;
    }

    int getPosY() const {
        return posY;
    }

protected:
    bool closed;
    int posX;
    int posY;
};

template <typename T, int N>
void Vault<T,N>::printContent() const {
    if (!closed) {
        std::cout << "The vault contains:" << std::endl;
        Inventory<T,N>::printContent();
    }
}

#endif //VAULT_H
