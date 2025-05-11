#include <array>
#include <iostream>
#include "include/Tensors/Matrix4x4.hpp"
#include "include/Numeric/Range.hpp"
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

    Rhea::Vector2Int v(4, -9);

    v = v + 6;
    
    cout << v.x() << ", " << v.y() << endl;

    Range x(0, 10);

    for (int &i: x) {
        i += 2;
        cout << i << endl;
    }

    for (int &i: x) {
        i += 2;
        cout << i << endl;
    }



    return 0;
}