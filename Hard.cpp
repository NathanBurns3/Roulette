#include <cstdlib>
#include "Wheel.h"
#include "Player.h"
#include "Hard.h"

Hard::Hard(int playerVal) {
    values = playerVal;
    playerValue = playerVal;
    winLoss = 0;
}

// if house wins
void Hard::win() {
    if (winLoss <= 0){      // won round once
        winLoss = 1;
    }
    else if (winLoss == 1 && values-incr >= playerValue){   // won twice: decrease values
        values -= incr;
        winLoss = 0;
    }
}
// if house loses
void Hard::loss() {
    winLoss = 0;
    if (values+incr <= 20){      // lost: increase values
        values += incr;
    }
}


// spin method overload
int Hard::spin(int playerResult){
    return rand() % values + 1;
}