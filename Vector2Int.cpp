#include "include/Tensors/Vector2Int.hpp"

Rhea::Vector2Int::Vector2Int(): 
    _x(0), 
    _y(0) {}

Rhea::Vector2Int::Vector2Int(const int x, const int y):
    _x(x),
    _y(y) {}

Rhea::Vector2Int::Vector2Int(const Rhea::Vector2Int &other):
    _x(other._x),
    _y(other._y) {}

Rhea::Vector2Int &Rhea::Vector2Int::operator=(const Rhea::Vector2Int &other) {
    _x = other._x;
    _y = other._y;
    return *this;
}

int &Rhea::Vector2Int::x() {
    return _x;
}

int Rhea::Vector2Int::x() const {
    return _x;
}

int &Rhea::Vector2Int::y() {
    return _y;
}

int Rhea::Vector2Int::y() const {
    return _y;
}

Rhea::Vector2Int &Rhea::Vector2Int::operator+=(const Rhea::Vector2Int &other) {
    _x += other._x;
    _y += other._y;
    return *this;
}

Rhea::Vector2Int &Rhea::Vector2Int::operator+=(const int value) {
    _x += value;
    _y += value;
    return *this;
}

Rhea::Vector2Int &Rhea::Vector2Int::operator-=(const Rhea::Vector2Int &other) {
    _x -= other._x;
    _y -= other._y;
    return *this;
}

Rhea::Vector2Int &Rhea::Vector2Int::operator-=(const int value) {
    _x -= value;
    _y -= value;
    return *this;
}

Rhea::Vector2Int &Rhea::Vector2Int::operator*=(const Rhea::Vector2Int &other) {
    _x *= other._x;
    _y *= other._y;
    return *this;
}

Rhea::Vector2Int &Rhea::Vector2Int::operator*=(const int value) {
    _x *= value;
    _y *= value;
    return *this;
}

Rhea::Vector2Int &Rhea::Vector2Int::operator/=(const Rhea::Vector2Int &other) {
    _x /= other._x;
    _y /= other._y;
    return *this;
}

Rhea::Vector2Int &Rhea::Vector2Int::operator/=(const int value) {
    _x /= value;
    _y /= value;
    return *this;
}

Rhea::Vector2Int Rhea::Vector2Int::operator+(const Rhea::Vector2Int &other) const {
    return Vector2Int(_x + other._x, _y + other._y);
}

Rhea::Vector2Int Rhea::Vector2Int::operator+(const int value) const {
    return Vector2Int(_x + value, _y + value);
}

Rhea::Vector2Int Rhea::Vector2Int::operator-(const Rhea::Vector2Int &other) const {
    return Vector2Int(_x - other._x, _y - other._y);
}

Rhea::Vector2Int Rhea::Vector2Int::operator-(const int value) const {
    return Vector2Int(_x - value, _y - value);
}

Rhea::Vector2Int Rhea::Vector2Int::operator*(const Rhea::Vector2Int &other) const {
    return Vector2Int(_x * other._x, _y * other._y);
}

Rhea::Vector2Int Rhea::Vector2Int::operator*(const int value) const {
    return Vector2Int(_x * value, _y * value);
}

Rhea::Vector2Int Rhea::Vector2Int::operator/(const Rhea::Vector2Int &other) const {
    return Vector2Int(_x / other._x, _y / other._y);
}

Rhea::Vector2Int Rhea::Vector2Int::operator/(const int value) const {
    return Vector2Int(_x / value, _y / value);
}

int &Rhea::Vector2Int::operator[](const int idx) {
    switch (idx) {
        case 0: return _x;
        case 1: return _y;
        default:
            throw std::out_of_range("Max index for Vector2Int is 1");
    }
}

int Rhea::Vector2Int::operator[](const int idx) const {
    switch (idx) {
        case 0: return _x;
        case 1: return _y;
        default:
            throw std::out_of_range("Max index for Vector2Int is 1");
    }
}