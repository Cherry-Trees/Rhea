#include "include/Numeric/IntRange.hpp"

Rhea::IntRange::IntRange(const int left, const int right, const int step): _left(left), _right(right), _step(step) {}

Rhea::IntRange::Iterator::Iterator(const int at, const int step): _at(at), _step(step) {}
Rhea::IntRange::Iterator::Iterator(const Rhea::IntRange::Iterator &other): _at(other._at), _step(other._step) {}

Rhea::IntRange::Iterator &Rhea::IntRange::Iterator::operator=(const Rhea::IntRange::Iterator &other) {
    _at = other._at;
    _step = other._step;
    return *this;
}

Rhea::IntRange::Iterator &Rhea::IntRange::Iterator::operator++() {
    _at += _step;
    return *this;
}

int &Rhea::IntRange::Iterator::operator*() {
    return _at;
}

int Rhea::IntRange::Iterator::operator*() const {
    return _at;
}

bool Rhea::IntRange::Iterator::operator==(const Rhea::IntRange::Iterator &other) const {
    return _at == other._at;
}
bool Rhea::IntRange::Iterator::operator!=(const Rhea::IntRange::Iterator &other) const {
    return _at < other._at;
}

Rhea::IntRange::Iterator Rhea::IntRange::begin() const {
    return Iterator(_left, _step);
}

Rhea::IntRange::Iterator Rhea::IntRange::end() const {
    return Iterator(_right, _step);
}

int Rhea::IntRange::left() const {
    return _left;
}