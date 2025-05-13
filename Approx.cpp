#include "include/Numeric/Approx.hpp"

double Rhea::expApprox(const double value) {
    return 1 +
           value +
           (value * value) / 2. +
           (value * value * value) / 6.;
}

double Rhea::cosApprox(const double value) {
    return 1 -
           (value * value) / 2. +
           (value * value * value * value) / 24.;
}

double Rhea::sinApprox(const double value) {
    return value -
           (value * value * value) / 6. +
           (value * value * value * value * value) / 120.;
}