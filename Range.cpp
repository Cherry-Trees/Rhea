#include "include/Numeric/Range.hpp"

Rhea::Range::Range(const int left, const int right, const int step): 
    _start(left), 
    _stop(right), 
    _step(left < right? 1: -1) {}

Rhea::Range::Range(const Rhea::Range &other):
    _start(other._start), 
    _stop(other._stop), 
    _step(other._step) {}

Rhea::Range &Rhea::Range::operator=(const Range &other) {
    _start = other._start;
    _stop = other._stop;
    _step = other._step;
    return *this;
}

Rhea::Range::Iterator::Iterator(const int at, const int step): 
    _at(at), 
    _step(step) {}

Rhea::Range::Iterator::Iterator(const Rhea::Range::Iterator &other): 
    _at(other._at), 
    _step(other._step) {}

Rhea::Range::Iterator &Rhea::Range::Iterator::operator=(const Rhea::Range::Iterator &other) {
    _at = other._at;
    _step = other._step;
    return *this;
}

Rhea::Range::Iterator &Rhea::Range::Iterator::operator++() {
    _at += _step;
    return *this;
}

int &Rhea::Range::Iterator::operator*() {
    return _at;
}

int Rhea::Range::Iterator::operator*() const {
    return _at;
}

bool Rhea::Range::Iterator::operator==(const Rhea::Range::Iterator &other) const {
    return _at == other._at;
}
bool Rhea::Range::Iterator::operator!=(const Rhea::Range::Iterator &other) const {
    return _at < other._at;
}

int &Rhea::Range::start() {
    return _start;
}

int Rhea::Range::start() const {
    return _start;
}

int &Rhea::Range::stop() {
    return _stop;
}

int Rhea::Range::stop() const {
    return _stop;
}

int &Rhea::Range::step() {
    return _step;
}

int Rhea::Range::step() const {
    return _step;
}

int Rhea::Range::length() const {
    return std::abs(_stop - _start);
}

int Rhea::Range::direction() const {
    return _step < 0? -1: 1;
}

int Rhea::Range::min() const {
    return _start < _stop? _start: _stop;
}

int Rhea::Range::max() const {
    return _start > _stop? _start: _stop;
}

Rhea::Range &Rhea::Range::swap() {
    const int temp = _start;
    _start = _stop;
    _stop = temp;
    _step *= -1;
    return *this;
}

bool Rhea::Range::contains(const int value) const {
    return _start <= value && value <= _stop;
}

Rhea::Range::Iterator Rhea::Range::begin() const {
    return Iterator(_start, _step);
}

Rhea::Range::Iterator Rhea::Range::end() const {
    return Iterator(_stop, _step);
}