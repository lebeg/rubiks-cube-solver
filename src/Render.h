#pragma once

#include "Cube.h"

class Render {
    const Cube& m_cube;

public:
    Render(const Cube& cube);

    void draw_side(const Side& side);

    void draw();
};