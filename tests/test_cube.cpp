#include "gtest/gtest.h"

#include "../Cube.h"

TEST(TestCube, TestSerialization) {
    std::string source(
            "W W W W W W W W W Y Y Y Y Y Y Y Y Y R R R R R R R R R B B B B B B B B B O O O O O O O O O G G G G G G G G G");
    std::istringstream is(source);

    Cube cube;
    is >> cube;

    std::ostringstream os;

    os << cube;

    EXPECT_EQ(source, os.str());
}