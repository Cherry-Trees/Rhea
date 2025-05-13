#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include <cmath>
#include <stdexcept>
#include "Vector3.hpp"
#include "../Enums/Axis.hpp"

namespace Rhea {

    class Quaternion {

        private:

            double _scalar;
            Vector3 _vector;

        public:

            Quaternion();
            Quaternion(const double scalar, const double x, const double y, const double z);
            Quaternion(const double scalar, const Vector3 &vector);
            Quaternion(const Quaternion &other);

            Quaternion &operator=(const Quaternion &other);

            double &scalar();
            double scalar() const;

            Vector3 &vector();
            Vector3 vector() const;

            Quaternion scalarQuaternion() const;
            Quaternion vectorQuaternion() const;

            Quaternion conjugate() const;
            double norm() const;
            double normSquare() const;
            Quaternion unit() const;
            Quaternion unitRotation() const;
            Quaternion inverse() const;

            Quaternion &rotate(const Quaternion &other);
            Quaternion &rotate(const double radians, const Vector3 &axis);
            Quaternion &rotate(const double radians, const Axis axis);

            Quaternion rotated(const Quaternion &other) const;
            Quaternion rotated(const double radians, const Vector3 &axis) const;
            Quaternion rotated(const double radians, const Axis axis) const;

            Quaternion &scalarize();
            Quaternion &vectorize();

            Quaternion &operator+=(const Quaternion &other);
            Quaternion &operator-=(const Quaternion &other);
            Quaternion &operator*=(const Quaternion &other);

            Quaternion &operator*=(const double scalar);
            Quaternion &operator/=(const double scalar);

            Quaternion operator-() const;
            Quaternion operator*() const;
            Quaternion operator+(const Quaternion &other) const;
            Quaternion operator-(const Quaternion &other) const;
            Quaternion operator*(const Quaternion &other) const;

            Quaternion operator*(const double scalar) const;
            Quaternion operator/(const double scalar) const;
            
    };

}

#endif