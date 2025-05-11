#ifndef VECTOR2INT_HPP
#define VECTOR2INT_HPP

#include <array>

namespace Rhea {

    class Vector2Int: public std::array<int, 2> {

        public:

            Vector2Int();
            Vector2Int(const int x, const int y);

            int &x();
            int x() const;

            int &y();
            int y() const;

            Vector2Int operator-() const;

            Vector2Int &operator+=(const Vector2Int &other);
            Vector2Int &operator+=(const int value);

            Vector2Int &operator-=(const Vector2Int &other);
            Vector2Int &operator-=(const int value);

            Vector2Int &operator*=(const Vector2Int &other);
            Vector2Int &operator*=(const int value);

            Vector2Int &operator/=(const Vector2Int &other);
            Vector2Int &operator/=(const int value);

            Vector2Int operator+(const Vector2Int &other) const;
            Vector2Int operator+(const int value) const;

            Vector2Int operator-(const Vector2Int &other) const;
            Vector2Int operator-(const int value) const;

            Vector2Int operator*(const Vector2Int &other) const;
            Vector2Int operator*(const int value) const;

            Vector2Int operator/(const Vector2Int &other) const;
            Vector2Int operator/(const int value) const;
    };


    Vector2Int operator+(const int value, const Vector2Int &vector);
    Vector2Int operator-(const int value, const Vector2Int &vector);
    Vector2Int operator*(const int value, const Vector2Int &vector);
    Vector2Int operator/(const int value, const Vector2Int &vector);

}

#endif