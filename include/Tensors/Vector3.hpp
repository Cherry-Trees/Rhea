#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <array>

namespace Rhea {

    class Vector3: public std::array<double, 3> {

        public:

            Vector3();
            Vector3(const double x, const double y, const double z);

            static Vector3 zeros();
            static Vector3 ones();

            double &x();
            double x() const;

            double &y();
            double y() const;

            double &z();
            double z() const;

            double dot(const Vector3 &other) const;
            Vector3 cross(const Vector3 &other) const;
            double norm() const;
            double normSquare() const;
            Vector3 &normalize();
            Vector3 unit() const;

            Vector3 &operator+=(const Vector3 &other);
            Vector3 &operator-=(const Vector3 &other);
            Vector3 &operator*=(const double scalar);
            Vector3 &operator/=(const double scalar);

            Vector3 operator+(const Vector3 &other) const;
            Vector3 operator-() const;
            Vector3 operator-(const Vector3 &other) const;
            Vector3 operator*(const double scalar) const;
            Vector3 operator/(const double scalar) const;
    };

    Vector3 operator*(const double scalar, const Vector3 &other);

}

#endif