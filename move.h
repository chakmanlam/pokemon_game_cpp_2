#ifndef MOVE_H
#define MOVE_H

#include "type.h"
#include <string>

struct Move {
    std::string name;
    Type type;
    int power; // Base damage for now

    Move(std::string n, Type t, int p)
        : name(n), type(t), power(p) {}
};

#endif