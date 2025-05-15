#ifndef GAME_H
#define GAME_H

#include <string>
#include "trainer.h"

class Game {
private:
    Trainer* player;
    Trainer* rival;
    Pokemon* rivalPokemon;
    std::string rivalName;
    

public:
    Game();
    ~Game();

    void start();
    std::string chooseStarter();

    void exploreWorld();
    bool handleWildBattle();
    void pokemonCenter();
    void postBattlePrompt();
    bool handleRivalBattle();

};

#endif
