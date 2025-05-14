#include "trainer.h"
#include "type_utils.h"
#include "ui_utils.h"
#include <iostream>

Trainer::Trainer(const std::string& trainerName, Pokemon* starter)
    : name(trainerName), partner(starter) {}

std::string Trainer::getName() const {
    return name;
}

Pokemon* Trainer::getPokemon() const {
    return partner;
}

void Trainer::healPokemon() {
    partner->heal();
    std::cout << partner->getName() << " has been healed to full HP!\n";
}

void Trainer::showStatus() const {
    Pokemon* p = partner;

    std::cout << "\n==============================\n";
    std::cout << name << "'s Pokémon:\n";
    std::cout << "Name: " << p->getName() << "\n";
    std::cout << "Type: " << typeToString(p->getType()) << "\n";
    std::cout << "HP:   " << hpBar(p->getCurrentHP(), p->getMaxHP()) << "\n";
    std::cout << "==============================\n";
}

