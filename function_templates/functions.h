//---------------------------------------------------------------------------
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
//---------------------------------------------------------------------------


// Notes:
// most functions operate with ranges specified by 2 pointers.
// Ranges are half open:
//  value pointed by the first (left)   pointer IS     INCLUDED in the range
//  value pointed by the second (right) pointer IS NOT INCLUDED in the range
// To specify a range with 5 element
// 1 2 3 4 5
// ^         ^
// |         |
// begin     end
// This is often referred to as half-open range (open on the right). 
//
// Whenever a function requires 2 ranges (swap_ranges, copy)
// the first range will be provided as above using 2 pointers, and the second range 
// by only 1 pointer - the beginning of the second range. Functions should assume
// that the second range is long enough to support required operations.

namespace CS225 {

    /////////////////////////////////////////////
    // non const only functions
    // functions are required to modify the range, so
    // functions accept read-write pointers

    // swap 2 locations 
    // implemented 
    template <typename T>
        void swap( T * left, T * right );

    /////////////////////////////////////////////
    // const only functions
    // functions are NOT modifying the range, so
    // functions accept read-only pointers
    // implemented 
    template <typename T>
        void display( T const * begin,  T const * end );

    /////////////////////////////////////////////
    // functions  overloaded by const/non-const
    // depends on the context where the function is used:
    // functions have to be overloaded by const/non-const
    // implemented 

    // pointer to the smallest element.
    // return value is read-write if input array is read-write
    template <typename T>
        T* min_element( T * begin, T * end );
    // return value is read-only  if input array is read-only
    template <typename T>
        T const* min_element( T const * begin, T const * end );
    

   /////////////////////////////////////////////////////////////////// 
   // you implement functions below 
   /////////////////////////////////////////////////////////////////// 
    
    
   /////////////////////////////////////////////////////////////////// 
    // swap 2 ranges
    template <typename T>
        void swap_ranges( T * a_begin, T * a_end, T * b_begin  );
    /////////////////////////////////////////////////////////////////// 
    // remove specified value from the range
    // function should NOT reallocate the array, so all that remove does
    // is move the elements with the specified value into the end of the range
    // return to client a pointer to the first of the "removed" elements:
    // input: 1 6 3 8 2 3 5 - remove 3
    //        1 6 8 2 5 3 3 - resulting range
    //                  ^
    //                  | return value
    template <typename T>
        T * remove( T * begin, T * end, T item );
    /////////////////////////////////////////////////////////////////// 
    // overwrite all elements in the range with a given value
    template <typename T, typename T1>
        void fill(  T * begin, T * end, T1 val );
    /////////////////////////////////////////////////////////////////// 
    // count elements that are equal to a given value 
    template <typename T>
        T count( T * begin, T * end , T item );
    /////////////////////////////////////////////////////////////////// 
    // add all element of the array together
    template <typename T>
        T sum( T * begin, T * end );
    /////////////////////////////////////////////////////////////////// 
    // copy all elements from first range into second
    // if first range is longer then second the function will crash (client's fault)
    // if first range is shorter, then some elements in the second range will remain unchanged.
    // Return the pointer into the second range that points to the first element that was NOT 
    // overwritten (equivalently the next after the last that was overwritten):
    // 1 2 3 4 5      - first range
    // 9 9 9 9 9 9 9  - second range
    // 1 2 3 4 5 9 9  - second range after copy
    //           ^
    //           | return value  
    template <typename T1, typename T2>
        T2 * copy( T1 const * begin, T1 const  * end, T2 * begin_2 );
    /////////////////////////////////////////////////////////////////// 
    // compare 2 ranges, similar to copy you compare each element of the first range to a 
    // corresponding element of the second. 
    // if first range is longer then second the function will crash (client's fault)
    // if first range is shorter, then some elements in the second range will NOT be compared.
    // 1 2 3
    // 1 2    crash
    // ===========
    // 1 2 3
    // 1 5 5 false - not equal
    // ===========
    // 1 2 3
    // 1 2 5 5 false - not equal
    // ===========
    // 1 2 3
    // 1 2 3 5 true - equal
    template <typename T1, typename T2>
        bool equal( T1 * begin, T1 * end, T2 * begin_2 );
    /////////////////////////////////////////////////////////////////// 
    // replace all elements in the range that are equal to old_value with a given value
    template <typename T1, typename T2>
        void replace( T1 * begin, T1 * end, T2 olditem, T2 newitem );
    /////////////////////////////////////////////////////////////////// 
    // pointer to the largest element.
    template <typename T> 
        T const * max_element( T const * begin, T const * end );

    template <typename T> 
        T * max_element( T * begin, T * end );
    /////////////////////////////////////////////////////////////////// 
    // pointer to the *first* element in the range that is equal to a given value
    template <typename T>
        T const * find( T const * begin, T const * end , T const item );

    template <typename T>
        T * find( T * begin, T * end , T const item );

}
#include "functions.cpp"

#endif
//---------------------------------------------------------------------------
