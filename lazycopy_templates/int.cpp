#include "int.h"
#include <iostream> // std::cout

namespace CS225 {

    bool Integer::noise = true;

    Integer::Integer( int data ) : data( data ) {
        if ( noise ) {
            std::cout << "Integer default ctor (" << data << ")" << std::endl;
        }
    }

    Integer::Integer( Integer const& original) : data( original.data ) {
        if ( noise ) {
            std::cout << "Integer copy ctor (" << data << ")" << std::endl;
        }
    }

    Integer& Integer::operator=( Integer const& rhs ) {
        // no need for self-assignment check
        if ( noise ) {
            std::cout << "Integer assignment (" 
                << data << "<--" << rhs.data << ")" << std::endl;
        }
        data  = rhs.data;
        return *this;
    }

    Integer::operator int() const {
        return data;
    }

    Integer const Integer::operator-() const {
        return Integer( -data );
    }

    std::ostream& operator<<( std::ostream &out, Integer const& obj ) {
        out << obj.data; 
        return out; 
    }

}
