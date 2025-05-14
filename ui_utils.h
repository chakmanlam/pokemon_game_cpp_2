#ifndef UI_UTILS_H
#define UI_UTILS_H

#include <string>

inline std::string hpBar(int current, int max, int width = 20) {
    int filled = (current * width) / max;
    std::string bar = "[";
    for (int i = 0; i < filled; ++i) bar += "█";
    for (int i = filled; i < width; ++i) bar += " ";
    bar += "] " + std::to_string(current) + "/" + std::to_string(max);
    return bar;
}

#endif
