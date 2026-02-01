#include <vector>
#include <iostream>
#include "card.h"

enum board_state {
    PREFLOP,
    FLOP,
    TURN,
    RIVER
};

class Board {

    private:
        board_state state;
        std::vector<Card> board;

    public:
        

    
};