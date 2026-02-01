#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include "card.h"

class Deck {
    private:
        std::vector<Card> deck;

    public:
        Deck() {
            std::cout << "Default Constructor for DECK";
            for (int i = SPADE; i != DIAMOND + 1; i++) {
                for (int j = 2; j < 15; j++) {
                    Card card(j, (Suit) i);
                    deck.push_back(card);
                }
            }

            std::cout << "deck.size(): " << deck.size();
        }

        void shuffle() {

            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(deck.begin(), deck.end(), g);

        }

        Card draw_and_remove() {
            Card top = deck[0];
            deck.erase(deck.begin(), deck.begin() + 1);
            return top;
        }

        Card draw() {

            return deck[0];

        }

        void display() {
            std::cout << "[";
            for (int i = 0; i < deck.size(); i++) {
                std::cout << deck[i] << ",";
            }

            std::cout << "]";

        }
};