#include "Cube.h"

namespace {
std::array all_colors { Color::White, Color::Yellow, Color::Red, Color::Blue, Color::Orange, Color::Green };
std::array all_directions { Direction::Front, Direction::Right, Direction::Up, Direction::Bottom, Direction::Left,
    Direction::Back };
std::array all_parts { Side::Part::TopLeft, Side::Part::Top, Side::Part::TopRight,
    Side::Part::Left, Side::Part::Center, Side::Part::Right,
    Side::Part::BottomLeft, Side::Part::Bottom, Side::Part::BottomRight };
}

Cube::Cube()
    : m_colors {}
{
    auto color = std::begin(all_colors);
    auto direction = std::begin(all_directions);
    for (; color != std::end(all_colors); ++color, ++direction) {
        side(*direction).colorize(*color);
    }
}

Side Cube::side(Direction direction)
{
    return { *this, direction };
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
    return std::all_of(std::cbegin(all_directions), std::cend(all_directions),
        [&](auto direction) { return side(direction).solved(); });
}

const Side Cube::side(Direction direction) const
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

unsigned char *at(Part part)
{
    unsigned char a[3];
    if (part.color() == Color::White)
        a = [255, 248, 220];
    if (part.color() == Color::Red)
        a = [240, 128, 128];
    if (part.color() == Color::Green)
        a = [0, 250, 154];
    if (part.color() == Color::Yellow)
        a = [255, 255, 0];
    if (part.color() == Color::Orange)
        a = [255, 140, 0];
    if (part.color() == Color::Blue)
        a = [123, 104, 238];

    return *a;
}

void Side::draw() const
{
    glPushMatrix();
    if (m_direction == Direction::Front)
        glRotated(90, 0,1,0);
    if (m_direction == Direction::Back)
        glRotated(90, 0,-1,0);
    if (m_direction == Direction::Left)
        glRotated(90, 1,0,0);
    if (m_direction == Direction::Right)
        glRotated(90, 0,-1,0);
    if (m_direction == Direction::Bottom)
        glRotated(180, 0,1,0);

    glTranslated(0,0,0.6);

    glBegin(GL_QUADS);

    glColor3ubv(at(Part::TopLeft));
    glNormal3f(0, 0, 1);
    glVertex3f(-0.6, -0.6, 0);
    glVertex3f(-0.6, -0.2, 0);
    glVertex3f(-0.2, -0.2, 0);
    glVertex3f(-0.2, -0.6, 0);

    glColor3ubv(at(Part::Top));
    glNormal3f(0, 0, 1);
    glVertex3f(-0.6, -0.2, 0);
    glVertex3f(-0.6, 0.2, 0);
    glVertex3f(-0.2, 0.2, 0);
    glVertex3f(-0.2, -0.2, 0);

    glColor3ubv(at(Part::TopRight));
    glNormal3f(0, 0, 1);
    glVertex3f(-0.6, 0.2, 0);
    glVertex3f(-0.6, 0.6, 0);
    glVertex3f(-0.2, 0.6, 0);
    glVertex3f(-0.2, -0.2, 0);

    glColor3ubv(at(Part::Center));
    glNormal3f(0, 0, 1);
    glVertex3f(-0.2, -0.2, 0);
    glVertex3f(-0.2, 0.2, 0);
    glVertex3f(0.2, 0.2, 0);
    glVertex3f(0.2, -0.2, 0);

    glColor3ubv(at(Part::Left));
    glNormal3f(0, 0, 1);
    glVertex3f(-0.2, -0.6, 0);
    glVertex3f(-0.2, -0.2, 0);
    glVertex3f(0.2, -0.2, 0);
    glVertex3f(0.2, -0.6, 0);

    glColor3ubv(at(Part::Right));
    glNormal3f(0, 0, 1);
    glVertex3f(-0.2, -0.2, 0);
    glVertex3f(-0.2, 0.2, 0);
    glVertex3f(0.2, 0.2, 0);
    glVertex3f(0.2, -0.2, 0);

    glColor3ubv(at(Part::Bottom));
    glNormal3f(0, 0, 1);
    glVertex3f(0.2, -0.2, 0);
    glVertex3f(0.2, 0.2, 0);
    glVertex3f(0.6, 0.2, 0);
    glVertex3f(0.6, -0.2, 0);

    glColor3ubv(at(Part::BottomLeft));
    glNormal3f(0, 0, 1);
    glVertex3f(0.2, -0.6, 0);
    glVertex3f(0.2, -0.2, 0);
    glVertex3f(0.6, -0.2, 0);
    glVertex3f(0.6, -0.6, 0);

    glColor3ubv(at(Part::BottomRight));
    glNormal3f(0, 0, 1);
    glVertex3f(0.2, 0.2, 0);
    glVertex3f(0.2, 0.6, 0);
    glVertex3f(0.6, 0.6, 0);
    glVertex3f(0.6, 0.2, 0);

    glEnd();
    glPopMatrix();
}

void Cube::draw() const {
    for (int i = 0; i < 6; i++){
        a = Side(*this, all_directions[i]);
        a.draw();
    }
}