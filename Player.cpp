#include <cstdlib>
#include "Wheel.h"
#include "Player.h"
#include "Hard.h"

Player::Player() {
    values = 10;
    money = 100.0;
    keepPlaying = true;
}

Player::Player(int Values) {
    values = Values;
    keepPlaying = true;
}

Player::Player(int Values, double Money) {
    values = Values;
    money = Money;
    keepPlaying = true;
}


// set player money
void Player::set_money(double m){
    money = m;
}
// get player money
double Player::get_money(){
    return money;
}


// method to test if game has ended
// (returns true if player runs out of money or choses to end the game)
bool Player::end_game(){
    if ((money > 0) && (keepPlaying == true)){
        return false;
    }
    else{
        return true;
    }   
}