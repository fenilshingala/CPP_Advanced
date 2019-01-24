#ifndef ANOTHERINTEGER_H
#define ANOTHERINTEGER_H
#include <fstream> // std::ostream

namespace CS225 {
    class AnotherInteger {
        public:
            static bool noise; // public
            AnotherInteger( int data = 0 );
            AnotherInteger( AnotherInteger const& original);
            AnotherInteger& operator=( AnotherInteger const& rhs);
            operator int() const;
            AnotherInteger const operator-() const;
            friend std::ostream& operator<<( std::ostream &out, AnotherInteger const& obj );
        private:
            int data;
    };
}
#endif
