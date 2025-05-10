#ifndef MATRIX4x4_HPP
#define MATRIX4x4_HPP

#include <array>

namespace Rhea {

    class Matrix4x4: public std::array<std::array<double, 4>, 4> {
        
        public:
            Matrix4x4();
            Matrix4x4(
                const double i00, const double i01, const double i02, const double i03,
                const double i10, const double i11, const double i12, const double i13,
                const double i20, const double i21, const double i22, const double i23,
                const double i30, const double i31, const double i32, const double i33
            );

            Matrix4x4(const Matrix4x4 &other);

            static Matrix4x4 zeros();
            static Matrix4x4 ones();
            static Matrix4x4 identity();

            static Matrix4x4 translationRow(const double tx, const double ty, const double tz);
            static Matrix4x4 translationCol(const double tx, const double ty, const double tz);
            static Matrix4x4 scaling(const double sx, const double sy, const double sz);
            static Matrix4x4 rotationZW(const double cos_th, const double sin_th);
            static Matrix4x4 rotationYW(const double cos_th, const double sin_th);
            static Matrix4x4 rotationYZ(const double cos_th, const double sin_th);
            static Matrix4x4 rotationXW(const double cos_th, const double sin_th);
            static Matrix4x4 rotationXZ(const double cos_th, const double sin_th);
            static Matrix4x4 rotationXY(const double cos_th, const double sin_th);


            Matrix4x4 &operator+=(const Matrix4x4 &other);
            Matrix4x4 &operator-=(const Matrix4x4 &other);
            Matrix4x4 &operator*=(const Matrix4x4 &other);
            Matrix4x4 &operator*=(const double scalar);
            Matrix4x4 operator-() const;

            Matrix4x4 operator+(const Matrix4x4 &other) const;
            Matrix4x4 operator-(const Matrix4x4 &other) const;
            Matrix4x4 operator*(const Matrix4x4 &other) const;
            Matrix4x4 operator*(const double scalar) const;

        

    };

    Matrix4x4 operator*(const double scalar, const Matrix4x4 &matrix);

    

}

#endif