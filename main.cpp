#include <iostream>
#include <string>
#include <vector>
#include "hand.h"



int main() {

    Hand hand = Hand("As", "9d");
    std::cout << hand.card_distance() << " " << hand.straight_distance();

}