#ifndef VECTOR2INT_HPP
#define VECTOR2INT_HPP

#include <stdexcept>

namespace Rhea {

    class Vector2Int {

        private:

            int _x, _y;

        public:

            Vector2Int();
            Vector2Int(const int x, const int y);
            Vector2Int(const Vector2Int &other);

            Vector2Int &operator=(const Vector2Int &other);

            int &x();
            int x() const;

            int &y();
            int y() const;

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

            int &operator[](const int idx);
            int operator[](const int idx) const;

    };

}

#endif