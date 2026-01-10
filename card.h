#include <string>
#include <iostream>
#include <unordered_map>


enum Suit {
    SPADE, 
    HEART, 
    CLUB, 
    DIAMOND
};

std::unordered_map<char, Suit> suites = {
    {'s', SPADE}, 
    {'h', HEART}, 
    {'c', CLUB},
    {'d', DIAMOND}
};

std::unordered_map<Suit, char> reverse_suites = {
    {SPADE, 's'}, 
    {HEART, 'h'}, 
    {CLUB, 'c'},
    {DIAMOND, 'd'}
};

class Card {
    private:
        int number;
        Suit suit;

        bool broadway(char value) {

            char broadway_values[] = {'A', 'K', 'Q', 'J'};

            for (int i = 0; i < 4; i++) {
                if (value == broadway_values[i]) {
                    return true;
                }
            }

            return false;
        }

    public:
        Card(int number, Suit suit) {
            this->number = number;
            this->suit = suit;
        }

        Card(std::string card) {

            std::unordered_map<char, int> values = {
                {'A', 14}, 
                {'K', 13}, 
                {'Q', 12}, 
                {'J', 11}
            };

            std::unordered_map<char, Suit> suites = {
                {'s', SPADE}, 
                {'h', HEART}, 
                {'c', CLUB},
                {'d', DIAMOND}
            };

            bool ten_or_not = card.size() > 2;

            if (!ten_or_not) {
                char value = card.at(0);
                if (broadway(value)) {
                    this->number = values[value];
                } else {
                    this->number = value - '0';
                }
                this->suit = suites[card.at(1)];
            } else {
                this->number = 10;
                this->suit = suites[card.at(2)];
            }           

        }

        int get_number() const {
            return number;
        }

        Suit get_suit() const {
            return suit;
        }

        Card() {
            number = 14;
            suit = SPADE;
        }
};

std::ostream& operator<<(std::ostream& os, const Card& card) {

    os << "Value: " << card.get_number() << "; Suit: " << reverse_suites[card.get_suit()];
    return os;

}