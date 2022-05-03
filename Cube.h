#pragma once

#include <iostream>
#include <array>
#include <vector>

enum class Direction {
    Front, Right, Up, Bottom, Left, Down
};

enum class Color : char {
    White = 'W', Yellow = 'Y', Red = 'R', Blue = 'B', Orange = 'O', Green = 'G'
};

class Side {
private:
    Color cells[9];
    Color centre; // типа за стороной закреплен центр можно его сюда вынести
public:
    Side();
    Side(const Color &color);

    // Color[] getsells() const; как создать функцию возвращающую массив....
    bool is_solved() const;

    friend class Cube;
};

class Cube {
private:
    Side _upper;
    Side _bottom;
    Side _left;
    Side _right;
    Side _front;
    Side _back;
public:
    Cube();
    //Cube(int rots); будет генерировать случайный кубик путем случайных ротейшн сколько-то раз

    void rotate(Direction direction, int amount); //всегда по часовой стрелке
    //void solve(); видимо решить кубик, попутно выводя ходы

    bool is_solved() const;

    friend std::ostream &operator << (std::ostream &stream, const Cube& cube);
    friend std::istream &operator >> (std::istream &stream, Cube& cube); //реализация в спп

    ~Cube();
};
