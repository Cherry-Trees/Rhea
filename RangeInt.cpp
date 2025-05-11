#include "include/Numeric/RangeInt.hpp"

Rhea::RangeInt::RangeInt(const int left, const int right, const int step): 
    _left(left), 
    _right(right), 
    _step(step) {}

Rhea::RangeInt::RangeInt(const Rhea::RangeInt &other):
    _left(other._left), 
    _right(other._right), 
    _step(other._step) {}

Rhea::RangeInt &Rhea::RangeInt::operator=(const RangeInt &other) {
    _left = other._left;
    _right = other._right;
    _step = other._step;
    return *this;
}

Rhea::RangeInt::Iterator::Iterator(const int at, const int step): 
    _at(at), 
    _step(step) {}

Rhea::RangeInt::Iterator::Iterator(const Rhea::RangeInt::Iterator &other): 
    _at(other._at), 
    _step(other._step) {}

Rhea::RangeInt::Iterator &Rhea::RangeInt::Iterator::operator=(const Rhea::RangeInt::Iterator &other) {
    _at = other._at;
    _step = other._step;
    return *this;
}

Rhea::RangeInt::Iterator &Rhea::RangeInt::Iterator::operator++() {
    _at += _step;
    return *this;
}

int &Rhea::RangeInt::Iterator::operator*() {
    return _at;
}

int Rhea::RangeInt::Iterator::operator*() const {
    return _at;
}

bool Rhea::RangeInt::Iterator::operator==(const Rhea::RangeInt::Iterator &other) const {
    return _at == other._at;
}
bool Rhea::RangeInt::Iterator::operator!=(const Rhea::RangeInt::Iterator &other) const {
    return _at < other._at;
}

int &Rhea::RangeInt::left() {
    return _left;
}

int Rhea::RangeInt::left() const {
    return _left;
}

int &Rhea::RangeInt::right() {
    return _right;
}

int Rhea::RangeInt::right() const {
    return _right;
}

int &Rhea::RangeInt::step() {
    return _step;
}

int Rhea::RangeInt::step() const {
    return _step;
}

int Rhea::RangeInt::length() const {
    return std::abs(_right - _left);
}

int Rhea::RangeInt::direction() const {
    return _left <= _right? 1: -1;
}

int Rhea::RangeInt::min() const {
    return _left < _right? _left: _right;
}

int Rhea::RangeInt::max() const {
    return _left > _right? _left: _right;
}

Rhea::RangeInt &Rhea::RangeInt::swap() {
    const int temp = _left;
    _left = _right;
    _right = temp;
    _step *= -1;
    return *this;
}

bool Rhea::RangeInt::contains(const int value) const {
    return _left <= value && value <= _right;
}

Rhea::RangeInt::Iterator Rhea::RangeInt::begin() const {
    return Iterator(_left, _step);
}

Rhea::RangeInt::Iterator Rhea::RangeInt::end() const {
    return Iterator(_right, _step);
}