#include "include/Tensors/Matrix4x4.hpp"

Rhea::Matrix4x4::Matrix4x4(): std::array<std::array<double, 4>, 4>() {}

Rhea::Matrix4x4::Matrix4x4(
    const double i00, const double i01, const double i02, const double i03,
    const double i10, const double i11, const double i12, const double i13,
    const double i20, const double i21, const double i22, const double i23,
    const double i30, const double i31, const double i32, const double i33
) {
    at(0).at(0) = i00;
    at(0).at(1) = i01;
    at(0).at(2) = i02;
    at(0).at(3) = i03;

    at(1).at(0) = i10;
    at(1).at(1) = i11;
    at(1).at(2) = i12;
    at(1).at(3) = i13;

    at(2).at(0) = i20;
    at(2).at(1) = i21;
    at(2).at(2) = i22;
    at(2).at(3) = i23;

    at(3).at(0) = i30;
    at(3).at(1) = i31;
    at(3).at(2) = i32;
    at(3).at(3) = i33;
}

Rhea::Matrix4x4::Matrix4x4(const Rhea::Matrix4x4 &other) {
    *this = other;
}

Rhea::Matrix4x4 Rhea::Matrix4x4::zeros() {
    return Matrix4x4(
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0
    );
}

Rhea::Matrix4x4 Rhea::Matrix4x4::ones() {
    return Matrix4x4(
        1, 1, 1, 1,
        1, 1, 1, 1,
        1, 1, 1, 1,
        1, 1, 1, 1
    );
}

Rhea::Matrix4x4 Rhea::Matrix4x4::identity() {
    return Matrix4x4(
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    );
}


Rhea::Matrix4x4 Rhea::Matrix4x4::translationRow(const double tx, const double ty, const double tz) {
    return Rhea::Matrix4x4(
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        tx, ty, tz, 1
    );
}

Rhea::Matrix4x4 Rhea::Matrix4x4::translationCol(const double tx, const double ty, const double tz) {
    return Rhea::Matrix4x4(
        1, 0, 0, tx,
        0, 1, 0, ty,
        0, 0, 1, tz,
        0, 0, 0, 1
    );
}

Rhea::Matrix4x4 Rhea::Matrix4x4::scaling(const double sx, const double sy, const double sz) {
    return Rhea::Matrix4x4(
        sx, 0, 0, 0,
        0, sy, 0, 0,
        0, 0, sz, 0,
        0, 0, 0, 1  
    );
}

Rhea::Matrix4x4 Rhea::Matrix4x4::rotationZW(const double cos_th, const double sin_th) {
    return Rhea::Matrix4x4(
        cos_th,     -sin_th,    0,          0,
        sin_th,     cos_th,     0,          0,
        0,          0,          1,          0,
        0,          0,          0,          1
    );
}
Rhea::Matrix4x4 Rhea::Matrix4x4::rotationYW(const double cos_th, const double sin_th) {
    return Matrix4x4(
        cos_th,     0,          -sin_th,    0,
        0,          1,          0,          0,
        sin_th,     0,          cos_th,     0,
        0,          0,          0,          1
    );
}

Rhea::Matrix4x4 Rhea::Matrix4x4::rotationYZ(const double cos_th, const double sin_th) {
    return Matrix4x4(
        cos_th,     0,          0,          -sin_th,
        0,          1,          0,          0,
        0,          0,          1,          0,
        sin_th,     0,          0,          cos_th
    );
}

Rhea::Matrix4x4 Rhea::Matrix4x4::rotationXW(const double cos_th, const double sin_th) {
    return Matrix4x4(
        1,          0,          0,          0,
        0,          cos_th,     -sin_th,    0, 
        0,          sin_th,     cos_th,     0,
        0,          0,          0,          1
    );
}

Rhea::Matrix4x4 Rhea::Matrix4x4::rotationXZ(const double cos_th, const double sin_th) {
    return Matrix4x4(
        1,          0,          0,          0,
        0,          cos_th,     0,          -sin_th,
        0,          0,          1,          0,
        0,          sin_th,     0,          cos_th
    );
}

Rhea::Matrix4x4 Rhea::Matrix4x4::rotationXY(const double cos_th, const double sin_th) {
    return Matrix4x4(
        1,          0,          0,          0,
        0,          1,          0,          0,
        0,          0,          cos_th,     -sin_th,
        0,          0,          sin_th,     cos_th
    );
}











Rhea::Matrix4x4 &Rhea::Matrix4x4::operator+=(const Rhea::Matrix4x4 &other) {
    for (unsigned char i = 0; i < 4; ++i)
        for (unsigned char j = 0; j < 4; ++j)
            at(i).at(j) += other.at(i).at(j);

    return *this;
}

Rhea::Matrix4x4 &Rhea::Matrix4x4::operator-=(const Rhea::Matrix4x4 &other) {
    for (unsigned char i = 0; i < 4; ++i)
        for (unsigned char j = 0; j < 4; ++j)
            at(i).at(j) -= other.at(i).at(j);

    return *this;
}

/* Make this better! */
Rhea::Matrix4x4 &Rhea::Matrix4x4::operator*=(const Rhea::Matrix4x4 &other) {
    return *this = *this * other;
}

Rhea::Matrix4x4 &Rhea::Matrix4x4::operator*=(const double scalar) {
    for (unsigned char i = 0; i < 4; ++i)
        for (unsigned char j = 0; j < 4; ++j)
            at(i).at(j) *= scalar;

    return *this;
}

Rhea::Matrix4x4 Rhea::Matrix4x4::operator-() const {
    return Matrix4x4(*this) *= -1;
}

Rhea::Matrix4x4 Rhea::Matrix4x4::operator+(const Rhea::Matrix4x4 &other) const {
    return Matrix4x4(*this) += other;
}

Rhea::Matrix4x4 Rhea::Matrix4x4::operator-(const Rhea::Matrix4x4 &other) const {
    return Matrix4x4(*this) -= other;
}

Rhea::Matrix4x4 Rhea::Matrix4x4::operator*(const Rhea::Matrix4x4 &other) const {
    Matrix4x4 m;
    for (unsigned char i = 0; i < 4; ++i) {
        for (unsigned char j = 0; j < 4; ++j) {
            m[i][j] = 0;
            for (unsigned char k = 0; k < 4; ++k) 
                m[i][j] += at(i).at(k) * other.at(k).at(j);
        }
    }
    return m;
}

Rhea::Matrix4x4 Rhea::Matrix4x4::operator*(const double scalar) const {
    return Matrix4x4(*this) *= scalar;
}

Rhea::Matrix4x4 Rhea::operator*(const double scalar, const Rhea::Matrix4x4 &matrix) {
    return matrix * scalar;
}