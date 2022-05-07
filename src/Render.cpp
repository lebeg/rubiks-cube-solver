#include "Render.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

namespace {
std::uint8_t* convert(Color color)
{
    using uint8_t = std::uint8_t;

    switch (color) {
    case Color::White: {
        static uint8_t color[3] { 255, 248, 220 };
        return color;
    }
    case Color::Red: {
        static uint8_t color[3] { 240, 128, 128 };
        return color;
    }
    case Color::Green: {
        static uint8_t color[3] { 0, 250, 154 };
        return color;
    }
    case Color::Yellow: {
        static uint8_t color[3] { 255, 255, 0 };
        return color;
    }
    case Color::Orange: {
        static uint8_t color[3] { 255, 140, 0 };
        return color;
    }
    case Color::Blue: {
        static uint8_t color[3] { 123, 104, 238 };
        return color;
    }
    }
}
}

Render::Render(const Cube& cube)
    : m_cube(cube)
{
}

void Render::draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (auto direction : directions()) {
        draw_side(m_cube.side(direction));
    }

    glutSwapBuffers();
}

void Render::draw_side(const Side& side)
{
    glPushMatrix();
    auto direction = side.direction();
    switch (direction) {
    case Direction::Front:
        glRotated(90, 0, 1, 0);
        break;
    case Direction::Right:
        glRotated(90, 0, -1, 0);
        break;
    case Direction::Up:
        /* do nothing */
        break;
    case Direction::Bottom:
        glRotated(180, 0, 1, 0);
        break;
    case Direction::Left:
        glRotated(90, 1, 0, 0);
        break;
    case Direction::Back:
        glRotated(90, 0, -1, 0);
        break;
    }

    glTranslated(0, 0, 0.6);

    glBegin(GL_QUADS);

    glColor3ubv(convert(side.color(Side::Part::TopLeft)));
    glNormal3f(0, 0, 1);
    glVertex3f(-0.6, -0.6, 0);
    glVertex3f(-0.6, -0.2, 0);
    glVertex3f(-0.2, -0.2, 0);
    glVertex3f(-0.2, -0.6, 0);

    glColor3ubv(convert(side.color(Side::Part::Top)));
    glNormal3f(0, 0, 1);
    glVertex3f(-0.6, -0.2, 0);
    glVertex3f(-0.6, 0.2, 0);
    glVertex3f(-0.2, 0.2, 0);
    glVertex3f(-0.2, -0.2, 0);

    glColor3ubv(convert(side.color(Side::Part::TopRight)));
    glNormal3f(0, 0, 1);
    glVertex3f(-0.6, 0.2, 0);
    glVertex3f(-0.6, 0.6, 0);
    glVertex3f(-0.2, 0.6, 0);
    glVertex3f(-0.2, -0.2, 0);

    glColor3ubv(convert(side.color(Side::Part::Center)));
    glNormal3f(0, 0, 1);
    glVertex3f(-0.2, -0.2, 0);
    glVertex3f(-0.2, 0.2, 0);
    glVertex3f(0.2, 0.2, 0);
    glVertex3f(0.2, -0.2, 0);

    glColor3ubv(convert(side.color(Side::Part::Left)));
    glNormal3f(0, 0, 1);
    glVertex3f(-0.2, -0.6, 0);
    glVertex3f(-0.2, -0.2, 0);
    glVertex3f(0.2, -0.2, 0);
    glVertex3f(0.2, -0.6, 0);

    glColor3ubv(convert(side.color(Side::Part::Right)));
    glNormal3f(0, 0, 1);
    glVertex3f(-0.2, -0.2, 0);
    glVertex3f(-0.2, 0.2, 0);
    glVertex3f(0.2, 0.2, 0);
    glVertex3f(0.2, -0.2, 0);

    glColor3ubv(convert(side.color(Side::Part::Bottom)));
    glNormal3f(0, 0, 1);
    glVertex3f(0.2, -0.2, 0);
    glVertex3f(0.2, 0.2, 0);
    glVertex3f(0.6, 0.2, 0);
    glVertex3f(0.6, -0.2, 0);

    glColor3ubv(convert(side.color(Side::Part::BottomLeft)));
    glNormal3f(0, 0, 1);
    glVertex3f(0.2, -0.6, 0);
    glVertex3f(0.2, -0.2, 0);
    glVertex3f(0.6, -0.2, 0);
    glVertex3f(0.6, -0.6, 0);

    glColor3ubv(convert(side.color(Side::Part::BottomRight)));
    glNormal3f(0, 0, 1);
    glVertex3f(0.2, 0.2, 0);
    glVertex3f(0.2, 0.6, 0);
    glVertex3f(0.6, 0.6, 0);
    glVertex3f(0.6, 0.2, 0);

    glEnd();
    glPopMatrix();
}
