#include <iostream>
#include "Wheel.h"
#include "Player.h"
#include "Hard.h"


int main() {
    int val;
    double mon;
    char hard;

    bool hardMode;

    //prompt for values on the board
    std::cout << "How many values are on the board? (minimum 6, maximum 20): ";
    std::cin >> val;
    //if they enter an invalid range, prompt again
    while (val < 6 || val > 20) {
        std::cout << "\nInvalid range of values. Enter a new number (minimum 6, maximum 20): ";
        std::cin >> val;
    }

    //prompt for the starting money amount
    std::cout << "\nHow much money do you have?: ";
    std::cin >> mon;

    
    Player p1 = Player(val, mon);   //create a player instance for the user
    Player House = Player(val);     //create a player instance for the house


    //ask if player would like to play in hard mode
    std::cout << "\nWould you like to play in hard mode? (Y/N): ";
    std::cin >> hard;
    Hard house(val);
    //if the user doesn't enter a valid choice, prompt again
    while (!(hard == 'Y' || hard == 'y' || hard == 'N' || hard == 'n')) {
        std::cout << "\nInvalid choice. Enter a new choice (Y/N): ";
        std::cin >> hard;
    }
    if (hard == 'Y' || hard == 'y') {       // set to hard mode if yes
        hardMode = true;
    }
    else { hardMode = false; }


    //if the player wants to keep playing and they still have money left, keep playing
    while (!p1.end_game()) {
        int bet;
        int playerResult;
        int wagerChoice;
        char continueChoice;
        int houseResult1, houseResult2;
        
        //prompt the user for their bet
        std::cout << "\nWhat is your minimum bet?: ";
        std::cin >> bet;
        //if they bet if over their amount of money or under the minimum, prompt again
        while (bet > p1.get_money()) {
            std::cout << "\nInvalid bet. Enter a new bet: ";
            std::cin >> bet;
        }

        //spin the wheel
        playerResult = p1.spin();
        //output the players result
        std::cout << "\nYour spin result is " << playerResult;

        //prompt the user to make a choice on their wager
        std::cout << "\nPress 1 to double your wager.\nPress 2 to halve your wager.\nPress 3 to keep your wager.\n";
        std::cin >> wagerChoice;
        //if they enter an invalid choice, prompt again
        while (wagerChoice < 1 || wagerChoice > 3) {
            std::cout << "\nInvalid choice. Enter a new choice (1-3): ";
            std::cin >> wagerChoice;
        }

        //run through the different choices
        //double
        if (wagerChoice == 1) {
            //double the bet
            bet = bet * 2;
            //if the bet is more than half of the player's total money,
            //change the bet to the value of the player's money
            if (bet > p1.get_money()) {
                bet = p1.get_money();
            }
            
            //get the house's results
            if (hardMode == false) {
                houseResult1 = House.spin();                // if not hard mode
                houseResult2 = House.spin();
            }
            else {
                houseResult1 = house.spin(playerResult);    // if hard mode
                houseResult2 = house.spin(playerResult);
            }

            //check the houses results to the players results
            if (houseResult1 >= playerResult || houseResult2 >= playerResult) {
                //player lost
                std::cout << "\nYou lost (-$" << bet << "). House Result: " << houseResult1 << " and " << houseResult2;
                p1.set_money(p1.get_money() - bet);
                house.win();
            }
            else {
                //player won
                std::cout << "\nYou won (+$" << bet << "). House Results: " << houseResult1 << " and " << houseResult2;
                p1.set_money(p1.get_money() + bet);
                house.loss();
            }
        }
        //halve
        else if (wagerChoice == 2) {
            //get the house's results
            if (hardMode == false) {
                houseResult1 = House.spin();                // if not hard mode
                houseResult2 = House.spin();
            }
            else {
                houseResult1 = house.spin(playerResult);    // if hard mode
                houseResult2 = house.spin(playerResult);
            }

            //check the houses results to the players results
            if (houseResult1 >= playerResult && houseResult2 >= playerResult) {
                //player lost
                std::cout << "\nYou lost (-$" << bet << "). House Result: " << houseResult1 << " and " << houseResult2;
                p1.set_money(p1.get_money() - bet);
                house.win();
            }
            else {
                //player won
                std::cout << "\nYou won (no change). House Results: " << houseResult1 << " and " << houseResult2;
                house.loss();
            }
        }
        //keep
        else {
            //get the house's result
            if (hardMode == false) { houseResult1 = House.spin(); }      // if not hard mode
            else { houseResult1 = house.spin(playerResult); }            // if hard mode

            //check the houses result to the players result
            if (houseResult1 >= playerResult) {
                //player lost
                std::cout << "\nYou lost (-$" << bet << "). House Result: " << houseResult1;
                p1.set_money(p1.get_money() - bet);
                house.win();
            }
            else {
                //player won
                std::cout << "\nYou won (+$" << bet << "). House Result: " << houseResult1;
                p1.set_money(p1.get_money() + bet);
                house.loss();
            }
        }

        //print out the players money total
        std::cout << "\nYour money total is: " << p1.get_money();

        //ask if they want to keep playing
        std::cout << "\nDo you want to keep playing? (Y/N): ";
        std::cin >> continueChoice;
        //if the user doesn't enter a valid choice, prompt again
        while (!(continueChoice == 'Y' || continueChoice == 'y' || continueChoice == 'N' || continueChoice == 'n')) {
            std::cout << "\nInvalid choice. Enter a new choice (Y/N): ";
            std::cin >> continueChoice;
        }
        //change the keepPlaying variable based off of the users choice
        if (continueChoice == 'N' || continueChoice == 'n') {
            p1.keepPlaying = false;
        }
    };
}