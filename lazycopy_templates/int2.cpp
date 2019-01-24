#include "int2.h"
#include <iostream> // std::cout

namespace CS225 {

    bool AnotherInteger::noise = true;

    AnotherInteger::AnotherInteger( int data ) : data( data ) {
        if ( noise ) {
            std::cout << "AnotherInteger default ctor (" << data << ")" << std::endl;
        }
    }

    AnotherInteger::AnotherInteger( AnotherInteger const& original) : data( original.data ) {
        if ( noise ) {
            std::cout << "AnotherInteger copy ctor (" << data << ")" << std::endl;
        }
    }

    AnotherInteger& AnotherInteger::operator=( AnotherInteger const& rhs ) {
        // no need for self-assignment check
        if ( noise ) {
            std::cout << "AnotherInteger assignment (" 
                << data << "<--" << rhs.data << ")" << std::endl;
        }
        data  = rhs.data;
        return *this;
    }

    AnotherInteger::operator int() const {
        return data;
    }

    AnotherInteger const AnotherInteger::operator-() const {
        return AnotherInteger( -data );
    }

    std::ostream& operator<<( std::ostream &out, AnotherInteger const& obj ) {
        out << obj.data; 
        return out; 
    }

}
