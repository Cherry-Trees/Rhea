#ifndef RANGEFLOAT_HPP
#define RANGEFLOAT_HPP

#include <cstdlib>

namespace Rhea {

    class RangeFloat {

        private:

            double _left, _right;

        public:

            RangeFloat(const double left, const double right);
            RangeFloat(const RangeFloat &other);

            double &left();
            double left() const;

            double &right();
            double right() const;

            double center() const;
            double length() const;
            double min() const;
            double max() const;
            int direction() const;

            
            



    };

}

#endif