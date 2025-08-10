#pragma once

namespace BGRCore {
    struct Colour {
        int R;
        int G;
        int B;

        Colour() : R(255), G(255), B(255) {}
        Colour(int r, int g, int b) : R(r), G(g), B(b) {}

        static Colour FromHex(unsigned int hex) {
            return Colour(
                (hex >> 16) & 0xFF,
                (hex >> 8) & 0xFF,
                hex & 0xFF
            );
        }

        static Colour FromFloat(float r, float g, float b) {
            return Colour(
                (int)(r * 255.0f + 0.5f),
                (int)(g * 255.0f + 0.5f),
                (int)(b * 255.0f + 0.5f)
            );
        }

        unsigned int ToHex() const {
            return ((R & 0xFF) << 16) | ((G & 0xFF) << 8) | (B & 0xFF);
        }

        void ToFloat(float& r, float& g, float& b) const {
            r = R / 255.0f;
            g = G / 255.0f;
            b = B / 255.0f;
        }

        void ToFloatArray(float* rgb) const {
            rgb[0] = R / 255.0f;
            rgb[1] = G / 255.0f;
            rgb[2] = B / 255.0f;
        }
    };


    // Primary Colors
    inline static const Colour RED = Colour(220, 38, 38);
    inline static const Colour GREEN = Colour(34, 197, 94);
    inline static const Colour BLUE = Colour(59, 130, 246);

    // Secondary Colors
    inline static const Colour YELLOW = Colour(251, 191, 36);
    inline static const Colour ORANGE = Colour(249, 115, 22);
    inline static const Colour PURPLE = Colour(147, 51, 234);
    inline static const Colour PINK = Colour(236, 72, 153);
    inline static const Colour CYAN = Colour(6, 182, 212);
    inline static const Colour MAGENTA = Colour(217, 70, 239);

    // Neutral Colors
    inline static const Colour WHITE = Colour(255, 255, 255);
    inline static const Colour BLACK = Colour(0, 0, 0);
    inline static const Colour GRAY = Colour(107, 114, 128);
    inline static const Colour LIGHT_GRAY = Colour(209, 213, 219);
    inline static const Colour DARK_GRAY = Colour(55, 65, 81);

    // Earth Tones
    inline static const Colour BROWN = Colour(120, 83, 54);
    inline static const Colour TAN = Colour(184, 158, 130);
    inline static const Colour BEIGE = Colour(240, 228, 207);
    inline static const Colour OLIVE = Colour(132, 132, 43);

    // Pastel Colors
    inline static const Colour LIGHT_PINK = Colour(252, 231, 243);
    inline static const Colour LIGHT_BLUE = Colour(219, 234, 254);
    inline static const Colour LIGHT_GREEN = Colour(220, 252, 231);
    inline static const Colour LIGHT_YELLOW = Colour(254, 249, 195);
    inline static const Colour LIGHT_PURPLE = Colour(237, 233, 254);

    // Vibrant Colors
    inline static const Colour CRIMSON = Colour(185, 28, 28);
    inline static const Colour EMERALD = Colour(16, 185, 129);
    inline static const Colour INDIGO = Colour(79, 70, 229);
    inline static const Colour AMBER = Colour(245, 158, 11);
    inline static const Colour TEAL = Colour(20, 184, 166);
    inline static const Colour VIOLET = Colour(124, 58, 237);

    // Dark Variants
    inline static const Colour DARK_RED = Colour(153, 27, 27);
    inline static const Colour DARK_GREEN = Colour(21, 128, 61);
    inline static const Colour DARK_BLUE = Colour(30, 64, 175);
    inline static const Colour DARK_PURPLE = Colour(88, 28, 135);

    // Nature Colors
    inline static const Colour FOREST_GREEN = Colour(34, 139, 34);
    inline static const Colour SKY_BLUE = Colour(135, 206, 235);
    inline static const Colour SUNSET_ORANGE = Colour(255, 94, 77);
    inline static const Colour OCEAN_BLUE = Colour(0, 119, 190);
    inline static const Colour GRASS_GREEN = Colour(102, 205, 0);
};