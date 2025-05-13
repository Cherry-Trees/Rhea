#include <array>
#include <iostream>
#include "include/Tensors/Matrix4x4.hpp"
#include "include/Numeric/Range.hpp"
#include "include/Tensors/Vector2Int.hpp"
#include "include/Tensors/Quaternion.hpp"

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

    Quaternion q;
    



    return 0;
}