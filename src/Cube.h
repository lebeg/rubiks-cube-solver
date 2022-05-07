#pragma once

#include <array>
#include <iostream>

enum class Direction {
    Front,
    Right,
    Up,
    Bottom,
    Left,
    Back
};

enum class Color : char {
    White = 'W',
    Yellow = 'Y',
    Red = 'R',
    Blue = 'B',
    Orange = 'O',
    Green = 'G'
};

class Cube;

class Side {
    Side(Cube& cube, Direction direction);

    Side(const Cube& cube, Direction direction);

    Cube& m_cube;
    Direction m_direction;

    friend class Cube;

public:
    enum class Part {
        TopLeft,
        Top,
        TopRight,
        Left,
        Center,
        Right,
        BottomLeft,
        Bottom,
        BottomRight
    };

    Color color(Part part) const;

    Color& color(Part part);

    void colorize(Color color);

    bool solved() const;
    Direction direction() const;
};

class Cube {
    friend std::ostream& operator<<(std::ostream&, const Cube& cube);
    friend std::istream& operator>>(std::istream&, Cube& cube);
    friend class Side;

public:
    static constexpr std::size_t edge_size = 3;
    static constexpr std::size_t sides = 6;
    static constexpr std::size_t side_size = edge_size * edge_size;

private:
    std::array<Color, side_size * sides> m_colors {};

public:
    Cube();

    const Color* colors() const
    {
        return m_colors.data();
    }
    
    Side side(Direction direction) const;

    void rotate(Direction direction, int amount);

    bool solved() const;
};

std::ostream& operator<<(std::ostream& os, const Cube& cube);

std::istream& operator>>(std::istream& is, Cube& cube);

const std::array<Direction, Cube::sides>& directions();
const std::array<Color, Cube::sides>& colors();
