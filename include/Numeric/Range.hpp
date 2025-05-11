#ifndef RANGE_HPP
#define RANGE_HPP

#include <cstdlib>

namespace Rhea {

    class Range {

        private:

            int _start, _stop, _step;

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

            Range(const int left, const int right, const int step = 1);
            Range(const Range &other);

            Range &operator=(const Range &other);

            int &start();
            int start() const;

            int &stop();
            int stop() const;

            int &step();
            int step() const;

            int length() const;
            int direction() const;
            int min() const;
            int max() const;
            Range &swap();
            bool contains(const int value) const;

            Iterator begin() const;
            Iterator end() const;

    }; 
    
}

#endif