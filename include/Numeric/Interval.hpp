#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include <cstdlib>

namespace Rhea {

    class Interval {

        private:

            double _left, _right;

        public:

            Interval(const double left, const double right);
            Interval(const Interval &other);

            static Interval empty();
            static Interval universe();

            double &left();
            double left() const;

            double &right();
            double right() const;

            double center() const;
            double length() const;
            double min() const;
            double max() const;
            int direction() const;

            bool contains(const double value) const;
            bool surrounds(const double value) const;

            double clamp(const double value) const;

            
            
            


    };

}

#endif