#include "pokemon.h"
#include <cstdlib>
#include <iostream>

Pokemon::Pokemon(std::string name, Type type, int maxHP)
    : name(name), type(type), maxHP(maxHP), currentHP(maxHP) {}

std::string Pokemon::getName() const {
    return name;
}

Type Pokemon::getType() const {
    return type;
}

int Pokemon::getCurrentHP() const {
    return currentHP;
}

int Pokemon::getMaxHP() const {
    return maxHP;
}

void Pokemon::takeDamage(int amount) {
    currentHP -= amount;
    if (currentHP < 0) currentHP = 0;
}

void Pokemon::heal() {
    currentHP = maxHP;
}

bool Pokemon::isFainted() const {
    return currentHP <= 0;
}

int Pokemon::attack() const {
    return rand() % 10 + 5; // Damage between 5–14
}

void Pokemon::addMove(const Move& move) {
    moveset.push_back(move);
}

const std::vector<Move>& Pokemon::getMoveset() const {
    return moveset;
}

Move Pokemon::getMove(int index) const {
    if (index >= 0 && index < moveset.size()) {
        return moveset[index];
    }
    return Move("Struggle", Type::Normal, 10); // fallback move
}