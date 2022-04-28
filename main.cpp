#include <iostream>
#include "Cube.h"

int main() {
    Cube cube;
    std::cout << cube << std::endl;
    std::cout << "Cube is " << (cube.solved() ? "solved" : "unsolved") << std::endl;
    return 0;
}
