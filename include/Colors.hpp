#ifndef COLORS_H
#define COLORS_H

#include <stdint.h>

struct Colors {
    uint8_t r, g, b, a;
};

struct ColorsF {
    float r, g, b, a;
};

inline constexpr Colors White = {255, 255, 255, 255};
inline constexpr Colors Black = {0, 0, 0, 0};

inline constexpr Colors Red = {255, 0, 0, 255};
inline constexpr Colors Green = {0, 255, 0, 255};
inline constexpr Colors Blue = {0, 0, 255, 255};

ColorsF ColorIntToFloat(const Colors c) {
    ColorsF f = {c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, c.a / 255.0f};
    return f;
}

#endif