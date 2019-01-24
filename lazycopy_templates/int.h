#ifndef INTEGER_H
#define INTEGER_H
#include <fstream> // std::ostream

namespace CS225 {
    class Integer {
        public:
            static bool noise; // public
            Integer( int data = 0 );
            Integer( Integer const& original);
            Integer& operator=( Integer const& rhs);
            operator int() const;
            Integer const operator-() const;
            friend std::ostream& operator<<( std::ostream &out, Integer const& obj );
        private:
            int data;
    };
}
#endif
