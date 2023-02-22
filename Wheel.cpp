#include <cstdlib>
#include "Wheel.h"
#include "Player.h"
#include "Hard.h"

int Wheel::spin() {
    return rand() % values + 1;
}