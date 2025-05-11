#include "include/Tensors/Vector2Int.hpp"

Rhea::Vector2Int::Vector2Int(): std::array<int, 2>() {}

Rhea::Vector2Int::Vector2Int(const int x, const int y): std::array<int, 2>{x, y} {}

int &Rhea::Vector2Int::x() {
    return at(0);
}

int Rhea::Vector2Int::x() const {
    return at(0);
}

int &Rhea::Vector2Int::y() {
    return at(1);
}

int Rhea::Vector2Int::y() const {
    return at(1);
}

Rhea::Vector2Int Rhea::Vector2Int::operator-() const {
    return Vector2Int(-x(), -y());
}

Rhea::Vector2Int &Rhea::Vector2Int::operator+=(const Rhea::Vector2Int &other) {
    x() += other.x();
    y() += other.y();
    return *this;
}

Rhea::Vector2Int &Rhea::Vector2Int::operator+=(const int value) {
    x() += value;
    y() += value;
    return *this;
}

Rhea::Vector2Int &Rhea::Vector2Int::operator-=(const Rhea::Vector2Int &other) {
    x() -= other.x();
    y() -= other.y();
    return *this;
}

Rhea::Vector2Int &Rhea::Vector2Int::operator-=(const int value) {
    x() -= value;
    y() -= value;
    return *this;
}

Rhea::Vector2Int &Rhea::Vector2Int::operator*=(const Rhea::Vector2Int &other) {
    x() *= other.x();
    y() *= other.y();
    return *this;
}

Rhea::Vector2Int &Rhea::Vector2Int::operator*=(const int value) {
    x() *= value;
    y() *= value;
    return *this;
}

Rhea::Vector2Int &Rhea::Vector2Int::operator/=(const Rhea::Vector2Int &other) {
    x() /= other.x();
    y() /= other.y();
    return *this;
}

Rhea::Vector2Int &Rhea::Vector2Int::operator/=(const int value) {
    x() /= value;
    y() /= value;
    return *this;
}

Rhea::Vector2Int Rhea::Vector2Int::operator+(const Rhea::Vector2Int &other) const {
    return Vector2Int(x() + other.x(), y() + other.y());
}

Rhea::Vector2Int Rhea::Vector2Int::operator+(const int value) const {
    return Vector2Int(x() + value, y() + value);
}

Rhea::Vector2Int Rhea::Vector2Int::operator-(const Rhea::Vector2Int &other) const {
    return Vector2Int(x() - other.x(), y() - other.y());
}

Rhea::Vector2Int Rhea::Vector2Int::operator-(const int value) const {
    return Vector2Int(x() - value, y() - value);
}

Rhea::Vector2Int Rhea::Vector2Int::operator*(const Rhea::Vector2Int &other) const {
    return Vector2Int(x() * other.x(), y() * other.y());
}

Rhea::Vector2Int Rhea::Vector2Int::operator*(const int value) const {
    return Vector2Int(x() * value, y() * value);
}

Rhea::Vector2Int Rhea::Vector2Int::operator/(const Rhea::Vector2Int &other) const {
    return Vector2Int(x() / other.x(), y() / other.y());
}

Rhea::Vector2Int Rhea::Vector2Int::operator/(const int value) const {
    return Vector2Int(x() / value, y() / value);
}

Rhea::Vector2Int Rhea::operator+(const int value, const Rhea::Vector2Int &vector) {
    return vector + value;
}

Rhea::Vector2Int Rhea::operator-(const int value, const Rhea::Vector2Int &vector) {
    return Vector2Int(value - vector.x(), value - vector.y());
}

Rhea::Vector2Int Rhea::operator*(const int value, const Rhea::Vector2Int &vector) {
    return vector * value;
}

Rhea::Vector2Int Rhea::operator/(const int value, const Rhea::Vector2Int &vector) {
    return Vector2Int(value / vector.x(), value / vector.y());
}