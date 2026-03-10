#ifndef E2_CLASS_EXERCISE_DICE_H
#define E2_CLASS_EXERCISE_DICE_H
#include <cstdlib>
#include <ctime>


class Dice {
public:
    explicit Dice(int faces=6): faces(faces){
        if (faces <= 1)
            faces = 6;
        srand(time(0) );
    }

    int roll(int r);

private:
    int faces;
    static int num_rolls;
    const int MAX_ROLLS = 1000;
};


#endif //E2_CLASS_EXERCISE_DICE_H
