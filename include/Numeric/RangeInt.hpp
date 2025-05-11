#ifndef RANGEINT_HPP
#define RANGEINT_HPP

#include <cstdlib>

namespace Rhea {

    class RangeInt {

        private:

            int _left, _right, _step;

        public:

            class Iterator {
                private:
                    int _at, _step;

                public:
                    Iterator(const int at, const int step);
                    Iterator(const Iterator &other);

                    Iterator &operator=(const Iterator &other);
                    Iterator &operator++();

                    int &operator*();
                    int operator*() const;

                    bool operator==(const Iterator &other) const;
                    bool operator!=(const Iterator &other) const;
            };

            RangeInt(const int left, const int right, const int step = 1);
            RangeInt(const RangeInt &other);

            RangeInt &operator=(const RangeInt &other);

            int &left();
            int left() const;

            int &right();
            int right() const;

            int &step();
            int step() const;

            int length() const;
            int direction() const;
            int min() const;
            int max() const;
            RangeInt &swap();
            bool contains(const int value) const;

            Iterator begin() const;
            Iterator end() const;

    }; 
    
}

#endif