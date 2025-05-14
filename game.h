#ifndef GAME_H
#define GAME_H

#include <string>
#include "trainer.h"

class Game {
private:
    Trainer* player;
    Trainer* rival;

public:
    Game();
    ~Game();

    void start();
    std::string chooseStarter();

    void exploreWorld();
    bool handleWildBattle();
    void pokemonCenter();
};

#endif
