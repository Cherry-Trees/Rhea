#include <array>
#include <iostream>
#include "include/Tensors/Matrix4x4.hpp"
#include "include/Numeric/RangeInt.hpp"
#include "include/Tensors/Vector2Int.hpp"

using namespace Rhea;
using namespace std;

std::ostream &operator<<(std::ostream &os, const Matrix4x4 &matrix) {
    os << '[';
    for (int i = 0; i < 4; ++i) {
        if (i != 0)
            os << ' ';
        os << "[ ";
        for (int j = 0; j < 4; ++j)
            os << matrix[i][j] << ' ';
        
            os << ']';
        if (i != 3)
            os << std::endl;

    }
    os << ']';
    return os;
}

int main() {

    Matrix4x4 a(
        1, 2, 7, 9,
        0, 5, -22, 1,
        9, 0, 0, 0,
        0, -1, 2, 10
    );

    Matrix4x4 b(
        1,2,3,4,
        5,6,7,8,
        9,10,11,12,
        13,14,15,16
    );

    Vector2Int v(4, -9);

    v += 99;
    
    cout << v.x() << ", " << v.y() << endl;



    return 0;
}