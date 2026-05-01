#ifndef UTILITIES_H
#define UTILITIES_H

#include <cstdlib>

template <typename  T, typename U>
int l1Distance(const T& p, const U& q){ //si usa un riferimento per non avere un oggetto di grandi dimensioni e const per la sola lettura(può invocare solo metodi costanti)
    return abs(p.getPosX() - q.getPosX()) + abs(p.getPosY() - q.getPosY());;
}

#endif //UTILITIES_H
