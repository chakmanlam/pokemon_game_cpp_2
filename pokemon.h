#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include "type.h"
#include <vector>
#include "move.h"

class Pokemon {
    private:
        std::string name;
        Type type;
        int maxHP;
        int currentHP;
        std::vector<Move> moveset;
    
    public:
        Pokemon(std::string name, Type type, int maxHP);
    
        std::string getName() const;
        Type getType() const;
        int getCurrentHP() const;
        int getMaxHP() const;
    
        void takeDamage(int amount);
        void heal();
        bool isFainted() const;
        int attack() const;

        void addMove(const Move& move);
        const std::vector<Move>& getMoveset() const;
        Move getMove(int index) const;
    
};

#endif
