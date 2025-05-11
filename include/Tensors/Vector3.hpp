#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <array>

namespace Rhea {

    class Vector3: public std::array<double, 3> {

        public:

            Vector3();
            Vector3(const double x, const double y, const double z);

            double &x();
            double x() const;

            double &y();
            double y() const;

            double &z();
            double z() const;

            
            
    };

}

#endif