#include "Cube.h"

namespace {

std::array all_parts { Side::Part::TopLeft, Side::Part::Top, Side::Part::TopRight,
    Side::Part::Left, Side::Part::Center, Side::Part::Right,
    Side::Part::BottomLeft, Side::Part::Bottom, Side::Part::BottomRight };
}

Cube::Cube()
    : m_colors {}
{
    auto color = std::cbegin(::colors());
    auto direction = std::cbegin(directions());
    for (; color != std::cend(::colors()); ++color, ++direction) {
        side(*direction).colorize(*color);
    }
}

std::ostream& operator<<(std::ostream& os, const Cube& cube)
{
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

std::istream& operator>>(std::istream& is, Cube& cube)
{
    char space;
    for (auto& color : cube.m_colors) {
        char c;
        is >> c;
        color = static_cast<Color>(c);
    }
    return is;
}

const std::array<Direction, Cube::sides>& directions()
{
    static std::array all {
        Direction::Front,
        Direction::Right,
        Direction::Up,
        Direction::Bottom,
        Direction::Left,
        Direction::Back
    };
    return all;
}

const std::array<Color, Cube::sides>& colors()
{
    static std::array all {
        Color::White,
        Color::Yellow,
        Color::Red,
        Color::Blue,
        Color::Orange,
        Color::Green
    };
    return all;
}

void Cube::rotate(Direction direction, int amount)
{
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
    case Direction::Back:
        break;
    }
}

bool Cube::solved() const
{
    return !std::any_of(std::cbegin(directions()), std::cend(directions()),
        [&](auto direction) { return !side(direction).solved(); });
}

Side Cube::side(Direction direction) const
{
    return { *this, direction };
}

Side::Side(Cube& cube, Direction direction)
    : m_cube(cube)
    , m_direction(direction)
{
}

Side::Side(const Cube& cube, Direction direction)
    : m_cube(const_cast<Cube&>(cube))
    , m_direction(direction)
{
}

Color Side::color(Side::Part part) const
{
    return m_cube.m_colors[static_cast<int>(m_direction) * Cube::side_size + static_cast<int>(part)];
}

Color& Side::color(Side::Part part)
{
    return m_cube.m_colors[static_cast<int>(m_direction) * Cube::side_size + static_cast<int>(part)];
}

void Side::colorize(Color color)
{
    for (auto part : all_parts) {
        this->color(part) = color;
    }
}

bool Side::solved() const
{
    auto color = this->color(Side::Part::TopLeft);
    return std::any_of(std::cbegin(all_parts), std::cend(all_parts),
        [&](auto part) { return this->color(part) == color; });
}

Direction Side::direction() const
{
    return m_direction;
}
