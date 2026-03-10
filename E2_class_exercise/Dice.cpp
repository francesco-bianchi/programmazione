//
// Created by Marco Bertini on 21/03/18.
//

#include "Dice.h"

#include <ctime> // for time
#include <cstdlib> // for rand and srand


// read: https://stackoverflow.com/questions/7343833/srand-why-call-it-only-once
int Dice::num_rolls=0;

int Dice::roll(int r) {
    int result=0;
    // XXX it goes against the best practice. Set a very high number for max num rolls
    // read: https://stackoverflow.com/questions/1452934/what-is-the-meaning-of-xxx-in-code-comments
    if (num_rolls>=MAX_ROLLS) {
        srand(time(0));
        num_rolls=0;
    }

    for (int i=0; i<r; i++)
        result += rand() % faces;
    num_rolls += r;

    return result;
}