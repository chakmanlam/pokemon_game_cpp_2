#ifndef TRAINER_H
#define TRAINER_H

#include <string>
#include "pokemon.h"

class Trainer {
private:
    std::string name;
    Pokemon* partner; // Pointer to their Pokémon

public:
    // Constructor
    Trainer(const std::string& trainerName, Pokemon* starter);

    // Getters
    std::string getName() const;
    Pokemon* getPokemon() const;

    // Actions
    void healPokemon();
    void showStatus() const;
};

#endif

