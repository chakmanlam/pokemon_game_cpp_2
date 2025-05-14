#ifndef TYPE_UTILS_H
#define TYPE_UTILS_H

#include "type.h"
#include <string>

inline std::string typeToString(Type type) {
    switch (type) {
        case Type::Fire: return "Fire";
        case Type::Water: return "Water";
        case Type::Grass: return "Grass";
        case Type::Electric: return "Electric";
        case Type::Normal: return "Normal";
        default: return "Unknown";
    }
}

#endif
