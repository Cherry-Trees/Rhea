#ifndef INTRANGE_HPP
#define INTRANGE_HPP

namespace Rhea {

    class IntRange {
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

            IntRange(const int left, const int right, const int step = 1);
            IntRange(const IntRange &other);

            IntRange &operator=(const IntRange &other);

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
            IntRange &swap();

            bool contains(const int value) const;



            Iterator begin() const;
            Iterator end() const;

    }; 
    
}

#endif