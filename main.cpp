#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Game game;
    game.start();

    return 0;
}


