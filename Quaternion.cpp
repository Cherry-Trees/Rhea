#include "include/Tensors/Quaternion.hpp"

Rhea::Quaternion::Quaternion(): 
    _scalar(0), 
    _vector(0, 0, 0) {}

Rhea::Quaternion::Quaternion(const double scalar, const double x, const double y, const double z):
    _scalar(scalar),
    _vector(x, y, z) {}

Rhea::Quaternion::Quaternion(const double scalar, const Rhea::Vector3 &vector):
    _scalar(scalar),
    _vector(vector) {}

Rhea::Quaternion::Quaternion(const Rhea::Quaternion &other):
    _scalar(other._scalar),
    _vector(other._vector) {}

Rhea::Quaternion &Rhea::Quaternion::operator=(const Rhea::Quaternion &other) {
    _scalar = other._scalar;
    _vector = other._vector;
    return *this;
}

double &Rhea::Quaternion::scalar() {
    return _scalar;
}

double Rhea::Quaternion::scalar() const {
    return _scalar;
}

Rhea::Vector3 &Rhea::Quaternion::vector() {
    return _vector;
}

Rhea::Vector3 Rhea::Quaternion::vector() const {
    return _vector;
}

Rhea::Quaternion Rhea::Quaternion::scalarQuaternion() const {
    return Quaternion(_scalar, 0, 0, 0);
}

Rhea::Quaternion Rhea::Quaternion::vectorQuaternion() const {
    return Quaternion(0, _vector);
}

Rhea::Quaternion Rhea::Quaternion::conjugate() const {
    return Quaternion(_scalar, -_vector);
}

double Rhea::Quaternion::norm() const {
    return std::sqrt(normSquare());
}

double Rhea::Quaternion::normSquare() const {
    return _scalar * _scalar + 
           _vector.x() * _vector.x() + 
           _vector.y() * _vector.y() + 
           _vector.z() * _vector.z();
}

Rhea::Quaternion Rhea::Quaternion::unit() const {
    return *this / norm();
}

Rhea::Quaternion Rhea::Quaternion::unitRotation() const {
    return Quaternion(
        std::cos(_scalar / 2.), 
        std::sin(_scalar / 2.) * _vector.unit()
    );
}

Rhea::Quaternion Rhea::Quaternion::inverse() const {
    return conjugate() / normSquare();
}

Rhea::Quaternion &Rhea::Quaternion::rotate(const Rhea::Quaternion &other) {
    return *this = rotated(other);
}

Rhea::Quaternion &Rhea::Quaternion::rotate(const double radians, const Rhea::Vector3 &axisVector) {
    return *this = rotated(radians, axisVector);
}

Rhea::Quaternion &Rhea::Quaternion::rotate(const double radians, const Axis axis) {
    return *this = rotated(radians, axis);
}

Rhea::Quaternion Rhea::Quaternion::rotated(const Rhea::Quaternion &other) const {
    const Quaternion otherUnitRotation = other.unitRotation();
    return otherUnitRotation * vectorQuaternion() * otherUnitRotation.inverse();
}

Rhea::Quaternion Rhea::Quaternion::rotated(const double radians, const Rhea::Vector3 &axisVector) const {
    return rotated(Quaternion(radians, axisVector));
}

Rhea::Quaternion Rhea::Quaternion::rotated(const double radians, const Axis axis) const {
    Vector3 axisVector = Vector3::zeros();
    switch (axis) {
        case Axis::X:
            axisVector.x() = 1;
            break;
        case Axis::Y:
            axisVector.y() = 1;
            break;
        case Axis::Z:
            axisVector.z() = 1;
            break;
        default:
            throw std::runtime_error("Invalid rotation axis for Quaternion");
    }
    return rotated(radians, axisVector);
}

Rhea::Quaternion &Rhea::Quaternion::scalarize() {
    _vector.fill(0);
    return *this;
}

Rhea::Quaternion &Rhea::Quaternion::vectorize() {
    _scalar = 0;
    return *this;
}

Rhea::Quaternion &Rhea::Quaternion::operator+=(const Rhea::Quaternion &other) {
    _scalar += other._scalar;
    _vector += other._vector;
    return *this;
}

Rhea::Quaternion &Rhea::Quaternion::operator-=(const Rhea::Quaternion &other) {
    _scalar -= other._scalar;
    _vector -= other._vector;
    return *this;
}

Rhea::Quaternion &Rhea::Quaternion::operator*=(const Rhea::Quaternion &other) {
    return *this = *this * other;
}

Rhea::Quaternion &Rhea::Quaternion::operator*=(const double scalar) {
    _scalar *= scalar;
    _vector *= scalar;
    return *this;
}

Rhea::Quaternion &Rhea::Quaternion::operator/=(const double scalar) {
    _scalar /= scalar;
    _vector /= scalar;
    return *this;
}

Rhea::Quaternion Rhea::Quaternion::operator-() const {
    return Quaternion(-_scalar, -_vector);
}

Rhea::Quaternion Rhea::Quaternion::operator*() const {
    return conjugate();
}

Rhea::Quaternion Rhea::Quaternion::operator+(const Rhea::Quaternion &other) const {
    return Quaternion(_scalar + other._scalar, _vector + other._vector);
}

Rhea::Quaternion Rhea::Quaternion::operator-(const Rhea::Quaternion &other) const {
    return Quaternion(_scalar - other._scalar, _vector - other._vector);
}

Rhea::Quaternion Rhea::Quaternion::operator*(const Rhea::Quaternion &other) const {
    return Quaternion(
        _scalar * other._scalar - _vector.dot(other._vector),
        other._vector * _scalar + _vector * other._scalar + _vector.cross(other._vector)
    );
}

Rhea::Quaternion Rhea::Quaternion::operator*(const double scalar) const {
    Quaternion(_scalar * scalar, _vector * scalar);
}

Rhea::Quaternion Rhea::Quaternion::operator/(const double scalar) const {
    Quaternion(_scalar / scalar, _vector / scalar);
}