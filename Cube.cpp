#include "Cube.h"

namespace {
    std::array all_colors { Color::White, Color::Yellow, Color::Red, Color::Blue, Color::Orange, Color::Green };
    std::array all_directions { Direction::Front, Direction::Right, Direction::Up, Direction::Bottom, Direction::Left,
                                Direction::Down };
    std::array all_parts { Cube::Side::Part::TopLeft, Cube::Side::Part::Top, Cube::Side::Part::TopRight,
                           Cube::Side::Part::Left, Cube::Side::Part::Center, Cube::Side::Part::Right,
                           Cube::Side::Part::BottomLeft, Cube::Side::Part::Bottom, Cube::Side::Part::BottomRight };
}

Cube::Cube() : m_colors { } {
    auto color = std::begin(all_colors);
    auto direction = std::begin(all_directions);
    for (; color != std::end(all_colors); ++color, ++direction) {
        side(*direction).colorize(*color);
    }
}

Cube::Side Cube::side(Direction direction) {
    return { *this, direction };
}

std::ostream &operator<<(std::ostream &os, const Cube &cube) {
    auto size = cube.m_colors.size();
    auto last = size - 1;
    for (auto i = 0; i < size; ++i) {
        const auto color = cube.m_colors[i];
        os << static_cast<char>(color);
        if (i < last) {
            os << ' ';
        }
    }
    return os;
}

std::istream &operator>>(std::istream &is, Cube &cube) {
    char space;
    for (auto &color: cube.m_colors) {
        char c;
        is >> c;
        color = static_cast<Color>(c);
    }
    return is;
}

void Cube::rotate(Direction direction, int amount) {
    amount = amount % 4;
    if (amount < 0) {
        amount += 4;
    }

    switch (direction) {
        case Direction::Front:
            break;
        case Direction::Right:
            break;
        case Direction::Up:
            break;
        case Direction::Bottom:
            break;
        case Direction::Left:
            break;
        case Direction::Down:
            break;
    }
}

bool Cube::solved() const {
    return std::all_of(std::cbegin(all_directions), std::cend(all_directions),
                       [&](auto direction) { return side(direction).solved(); });
}

const Cube::Side Cube::side(Direction direction) const {
    return { *this, direction };
}

Cube::Side::Side(Cube &cube, Direction direction) : m_cube(cube), m_direction(direction) {

}

Cube::Side::Side(const Cube &cube, Direction direction) : m_cube(const_cast<Cube &>(cube)), m_direction(direction) {

}


Color Cube::Side::color(Cube::Side::Part part) const {
    return m_cube.m_colors[static_cast<int>(m_direction) * Cube::side_size + static_cast<int>(part)];
}

Color &Cube::Side::color(Cube::Side::Part part) {
    return m_cube.m_colors[static_cast<int>(m_direction) * Cube::side_size + static_cast<int>(part)];
}

void Cube::Side::colorize(Color color) {
    for (auto part: all_parts) {
        this->color(part) = color;
    }
}

bool Cube::Side::solved() const {
    auto color = this->color(Cube::Side::Part::TopLeft);
    return std::any_of(std::cbegin(all_parts), std::cend(all_parts),
                       [&](auto part) { return this->color(part) == color; });
}
