#include <iostream>
#include "functions.h"

namespace CS225 {
    template <typename T>
    void display( T const *begin, T const *end )
    {
        if( begin != end ) std::cout << *begin++;
        while( begin<end ) {
            std::cout << ", " << *begin;
            ++begin;
        }
        std::cout << std::endl;
    }

    template <typename T>
    void swap( T *left, T *right )
    {
        T temp( *right );
        ( *right ) = ( *left );
        ( *left ) = temp;
    }

    template <typename T>
    T* min_element( T *begin, T *end )
    {
        T* min=begin;
        while( begin!=end ) {
            if( *begin<*min ) min=begin;
            ++begin;
        }
        return min;
    }

    template <typename T>
    T const* min_element( T const *begin, T const *end )
    {
        T const* min=begin;
        while( begin!=end ) {
            if( *begin<*min ) min=begin;
            ++begin;
        }
        return min;
    }

    template <typename T>
    void swap_ranges( T * a_begin, T * a_end, T * b_begin )
    {
        while(a_begin != a_end){
            T temp( *a_begin );
            ( *a_begin ) = ( *b_begin );
            ( *b_begin ) = temp;
            ++a_begin;
            ++b_begin;
        }
    }

    template <typename T>
    T count( T * begin, T * end, T item ){
        int count = 0;
        while(begin != end) {
            if(*begin == item)
                ++count;
            ++begin;
        }
        return count;
    }

    template <typename T>
    T const * find( T const * begin, T const * end , T const item ) {
        while(begin != end){
            if(*begin == item){
                return begin;
            }
            ++begin;
        }
        return begin;
    }

    template <typename T>
    T * find( T * begin, T * end , T const item ) {
        while(begin != end){
            if(*begin == item){
                return begin;
            }
            ++begin;
        }
        return begin;
    }

    template <typename T1, typename T2>
    T2 * copy( T1 const * begin, T1 const * end, T2 * begin_2 ) {
        while(begin != end){
            *begin_2 = static_cast<T2>(*begin);
            ++begin;
            ++begin_2;
        }
        return begin_2;
    }

    template <typename T, typename T1>
    void fill(  T * begin, T * end, T1 val ) {
        while(begin != end){
            *begin = static_cast<T1>(val);
            ++begin;
        }
    }

    template <typename T1, typename T2>
    void replace( T1 * begin, T1 * end, T2 olditem, T2 newitem ){
        while (begin != end){
            if(*begin == olditem){
                *begin = newitem;
            }
            ++begin;
        }
    }

    template <typename T> 
    T const * max_element( T const * begin, T const * end ){
        T const* max=begin;
        while( begin!=end ) {
            if( *begin>*max ) max=begin;
            ++begin;
        }
        return max;
    }

    template <typename T> 
    T * max_element( T * begin, T * end ){
        T * max=begin;
        while( begin!=end ) {
            if( *begin>*max ) max=begin;
            ++begin;
        }
        return max;
    }

    template <typename T1, typename T2>
    bool equal( T1 * begin, T1 * end, T2 * begin_2 ){
        while(begin != end){
            if((*begin) != static_cast<T1>(*begin_2))
                return false;
            ++begin;
            ++begin_2;
        }   
        return true;
    }

    template <typename T>
    T sum( T * begin, T * end ){
        T temp = *begin;
        ++begin;
        while(begin != end){
            temp += *begin;
            ++begin;
        }
        return temp;
    }

    template <typename T>
    T * remove( T * begin, T * end, T item ){
        T * current = begin;
        T * prev = begin;

        while(current != end){
            if(*current == item){
                prev = current;
                T * traceback = current;
                ++current;

                // SWAP
                while(current != end){
                    T temp( *current );
                    ( *current ) = ( *prev );
                    ( *prev ) = temp;
                    ++current;
                    ++prev;
                }
                
                end = prev;
                current = traceback;
            }else{
                ++current;
            }
        }
        return current;
    }
    
}
