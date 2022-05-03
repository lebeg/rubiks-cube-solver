#include "Cube.h"

namespace {
    Color all_colors[6] = { Color::White, Color::Yellow, Color::Red, Color::Blue, Color::Orange, Color::Green };
    Direction all_directions[6] = { Direction::Front, Direction::Right, Direction::Up, Direction::Bottom, Direction::Left,
                                Direction::Down };
}

Side::Side() {}
Side::Side(const Color &color) {
    centre = color;
    for (auto & cell : cells)
        cell = color;
}

bool Side::is_solved() const {
    for (auto & cell : cells){
        if (cell != centre)
            return false;
    }
    return true;
}

Cube::Cube() {
    auto color = std::begin(all_colors);
// i now represent to you знания о различиях постфиксного и префиксного ++
    _upper = Side(*++color);
    _bottom = Side(*++color);
    _left = Side(*++color);
    _right = Side(*++color);
    _front = Side(*++color);
    _back = Side(*++color);
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

bool Cube::is_solved() const {
    if (!_upper.is_solved())
        return false;
    if (!_bottom.is_solved())
        return false;
    if (!_left.is_solved())
        return false;
    if (!_right.is_solved())
        return false;
    if (!_front.is_solved())
        return false;
    if (!_back.is_solved())
        return false;
    return true;
}

//не уверена что вообще хочу такой оператор, если я конструирую уже нормальный кубик по умолчанию
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

//для него нужна функция getcells
std::istream &operator>>(std::istream &is, Cube &cube) {
    for (auto &color: cube._upper.getcells()) {
        char c;
        is >> c;
        color = static_cast<Color>(c);
    }
    return is;
}