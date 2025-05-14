#ifndef POKEMON_FACTORY_H
#define POKEMON_FACTORY_H

#include "pokemon.h"
#include "type.h"
#include <vector>
#include <string>
#include "move.h"

Pokemon* createPokemon(const std::string& name) {
    if (name == "Charmander") {
        Pokemon* p = new Pokemon("Charmander", Type::Fire, 20);
        p->addMove(Move("Scratch", Type::Normal, 10));
        p->addMove(Move("Ember", Type::Fire, 12));
        return p;
    }
    if (name == "Bulbasaur") {
        Pokemon* p = new Pokemon("Bulbasaur", Type::Grass, 20);
        p->addMove(Move("Tackle", Type::Normal, 10));
        p->addMove(Move("Vine Whip", Type::Grass, 12));
        return p;
    }
    if (name == "Squirtle") {
        Pokemon* p = new Pokemon("Squirtle", Type::Water, 20);
        p->addMove(Move("Tackle", Type::Normal, 10));
        p->addMove(Move("Water Gun", Type::Water, 12));
        return p;
    }
    if (name == "Pikachu") {
        Pokemon* p = new Pokemon("Pikachu", Type::Electric, 18);
        p->addMove(Move("Quick Attack", Type::Normal, 10));
        p->addMove(Move("Thunder Shock", Type::Electric, 13));
        return p;
    }
    if (name == "Pidgey") {
        Pokemon* p = new Pokemon("Pidgey", Type::Normal, 16);
        p->addMove(Move("Tackle", Type::Normal, 10));
        p->addMove(Move("Gust", Type::Normal, 11));
        return p;
    }
    if (name == "Rattata") {
        Pokemon* p = new Pokemon("Rattata", Type::Normal, 16);
        p->addMove(Move("Tackle", Type::Normal, 10));
        p->addMove(Move("Bite", Type::Normal, 12));
        return p;
    }
    if (name == "Zubat") {
        Pokemon* p = new Pokemon("Zubat", Type::Normal, 17);
        p->addMove(Move("Leech Life", Type::Normal, 10));
        p->addMove(Move("Wing Attack", Type::Normal, 12));
        return p;
    }
    if (name == "Oddish") {
        Pokemon* p = new Pokemon("Oddish", Type::Grass, 18);
        p->addMove(Move("Absorb", Type::Grass, 11));
        p->addMove(Move("Poison Powder", Type::Grass, 0)); // for future status effect
        return p;
    }
    if (name == "Growlithe") {
        Pokemon* p = new Pokemon("Growlithe", Type::Fire, 19);
        p->addMove(Move("Bite", Type::Normal, 10));
        p->addMove(Move("Flame Wheel", Type::Fire, 14));
        return p;
    }
    if (name == "Poliwag") {
        Pokemon* p = new Pokemon("Poliwag", Type::Water, 19);
        p->addMove(Move("Bubble", Type::Water, 11));
        p->addMove(Move("Body Slam", Type::Normal, 13));
        return p;
    }

    Pokemon* fallback = new Pokemon(name, Type::Normal, 20);
    fallback->addMove(Move("Tackle", Type::Normal, 10));
    fallback->addMove(Move("Growl", Type::Normal, 0));
    return fallback;
}

std::vector<std::string> getWildPokemonNames() {
    return {"Pidgey", "Rattata", "Zubat", "Oddish", "Growlithe", "Poliwag"};
}

std::vector<std::string> getStarterOptions() {
    return {"Charmander", "Bulbasaur", "Squirtle"};
}

#endif
