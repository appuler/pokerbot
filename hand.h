// Hand Class is a set of two cards
// define equality for two hands


// Try to create a set object for that
// Check equality for that set
#include <string>
#include <iostream>
#include <cmath>
#include "card.h"
#include "utils.h"

class Hand {
    private:
        Card card1;
        Card card2;

    public:

        Hand(Card card1, Card card2) {

            if (card1.get_number() > card2.get_number()) {
                this->card1 = card1;
                this->card2 = card2;
            } else {
                this->card2 = card1;
                this->card1 = card2;
            }

        }

        Hand(std::string carda, std::string cardb) {
            
            Card cardc = Card(carda);
            Card cardd = Card(cardb);

            if (cardc.get_number() > cardd.get_number()) {
                this->card1 = cardc;
                this->card2 = cardd;
            } else {
                this->card2 = cardc;
                this->card1 = cardd;
            }
        }


        bool same_suit() {
            return card1.get_suit() == card2.get_suit();
        }

        bool connectors() {
            int a = card1.get_number();
            int b = card2.get_number();

            return (a - b == 1) || (a - b == 12);
        }

        bool pair() {
            return card1.get_number() == card2.get_number();
        }

        int card_distance() {
            // if it's an Ace
            int a = card1.get_number();
            int b = card2.get_number();
            if (card1.get_number()== 14) {
                int upper = a - b;
                int lower = b - 1;

                return min(upper, lower);
            } else {
                return a - b;
            }

            return 0;
        }

        bool suited_connectors() {
            return same_suit() && connectors();
        }

        bool straight_distance(){
            return card_distance() < 5;
        }
};