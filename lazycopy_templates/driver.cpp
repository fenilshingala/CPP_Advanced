#include "array.h"
#include "int.h"
#include "int2.h"
#include <iostream>
#include <iomanip>

using CS225::Array;
using CS225::Integer;
using CS225::AnotherInteger;

void test0() {
    //std::cout << "in function " << __FUNCTION__ << ": " << "create empty array" << std::endl;
    std::cout << "create empty array" << std::endl;
    Array<Integer> array;

    std::cout << "create Integer(1)" << std::endl;
    Integer val( 1 );
    std::cout << "insert Integer(1) at 1" << std::endl;
    array.Insert( 1, val );
    std::cout << "array = " << array << std::endl;

    std::cout << "create Integer(2)" << std::endl;
    Integer val2( 2 );
    std::cout << "insert Integer(2) at 5" << std::endl;
    array.Insert( 5, val2 );
    std::cout << "array = " << array << std::endl;
}
void test1() {
    std::cout << "create empty array" << std::endl;
    Array<Integer> array;

    std::cout << "create Integer(1)" << std::endl;
    Integer val( 1 );
    std::cout << "insert Integer(1) at 5" << std::endl;
    array.Insert( 5, val );

    Integer val3( 3 );
    array[3] = val3;
    std::cout << "array = " << array << std::endl;
}
void test2() {
    std::cout << "create empty array" << std::endl;
    Array<Integer> array;

    std::cout << "create Integer(1)" << std::endl;
    Integer val( 1 );
    std::cout << "insert Integer(1) at 5" << std::endl;
    array.Insert( 5, val );

    std::cout << "array[3] = " << array[3] << std::endl;
    std::cout << "array[5] = " << array[5] << std::endl;
}
void test3() {
    std::cout << "create empty array" << std::endl;
    Array<Integer> array;

    std::cout << "create Integer(6)" << std::endl;
    Integer val( 6 );
    std::cout << "insert Integer(6) at 3 and 5" << std::endl;
    array[3] = val;
    array[5] = val;

    for ( int i=0; i<6; ++i ) {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }
}

// tests using copy ctor and assignment
void test4() {
    Integer::noise = false;
    std::cout << "create empty array" << std::endl;
    Array<Integer> array;

    for ( int i=0; i<6; ++i ) {
        array[i] = i+2; // use implicit conversion int->Integer
    }

    std::cout << "array = " << array << std::endl;

    Integer::noise = true;
    std::cout << "create shallow copy" << std::endl;
    Array<Integer> array_copy( array ); // shallow copy
    std::cout << "create shallow copy - done, no output expected" << std::endl;
    
        std::cout << "position    array    array_copy" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << "    " <<   i << "          " << array[i] << "          " << array_copy[i] << std::endl;
    }
}
void test5() {
    Integer::noise = false;
    std::cout << "create empty array" << std::endl;
    Array<Integer> array;

    for ( int i=0; i<6; ++i ) {
        array[i] = i+2; // use implicit conversion int->Integer
    }

    std::cout << "array = " << array << std::endl;

    Integer::noise = true;
    std::cout << "create shallow copy" << std::endl;
    Array<Integer> array_copy( array ); // shallow copy
    std::cout << "create shallow copy - done, no output expected" << std::endl;
   
    std::cout << "modify original (should cause deep copy)" << std::endl;
    array[3] = 100;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array_copy" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array_copy[i] << std::endl;
    }
    
    std::cout << "modify original again (NO deep copy this time )" << std::endl;
    array[2] = 100;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array_copy" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array_copy[i] << std::endl;
    }

    std::cout << "modify copy (NO deep copy - original created it's own copy, so array_copy ref counter is 1)" << std::endl;
    array_copy[1] = 100;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array_copy" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array_copy[i] << std::endl;
    }
}
void test6() {
    Integer::noise = false;
    std::cout << "create empty array" << std::endl;
    Array<Integer> array;

    for ( int i=0; i<6; ++i ) {
        array[i] = i+2;
    }
    std::cout << "array = " << array << std::endl;

    std::cout << "create another " << std::endl;
    Array<Integer> array2;
    for ( int i=0; i<6; ++i ) {
        array2[i] = i+20;
    }
    std::cout << "array2 = " << array2 << std::endl;
    std::cout << "-------------------" << std::endl;
    
    
    Integer::noise = true;
    array2 = array; 
    std::cout << "create shallow assign - done, no output expected" << std::endl;
   
    std::cout << "modify original (should cause deep copy)" << std::endl;
    array[3] = -10;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::endl;
    }
    
    std::cout << "modify original again (NO deep copy this time )" << std::endl;
    array[2] = -10;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::endl;
    }

    std::cout << "modify copy (NO deep copy - original created it's own copy, so array2 ref counter is 1)" << std::endl;
    array2[1] = 1000;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::endl;
    }
}
void test7() {
    Integer::noise = false;
    std::cout << "create empty array" << std::endl;
    Array<Integer> array;

    for ( int i=0; i<6; ++i ) {
        array[i] = i+2;
    }
    std::cout << "array = " << array << std::endl;

    std::cout << "create another " << std::endl;
    Array<Integer> array2;
    for ( int i=0; i<6; ++i ) {
        array2[i] = i+20;
    }
    std::cout << "array2 = " << array2 << std::endl;
    
    std::cout << "create yet another " << std::endl;
    Array<Integer> array3;
    for ( int i=0; i<6; ++i ) {
        array3[i] = i+200;
    }
    std::cout << "array3 = " << array3 << std::endl;
    std::cout << "-------------------" << std::endl;
    
    
    Integer::noise = true;
    array2 = array3; 
    array = array2; 
    std::cout << "2 shallow assigns - done, no output expected" << std::endl;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }
    
    std::cout << "modify original (should cause deep copy)" << std::endl;
    array[3] = -10;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }
    
    std::cout << "modify original again (NO deep copy this time )" << std::endl;
    array[2] = -10;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }

    std::cout << "modify copy (should cause deep copy, array2 ref counter is 2 - shared with array3)" << std::endl;
    array2[1] = 1000;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }
}
void test8() {
    Integer::noise = false;
    std::cout << "create empty array" << std::endl;
    Array<Integer> array;

    for ( int i=0; i<6; ++i ) {
        array[i] = i+2;
    }

    Integer::noise = true;
    std::cout << "-------------------" << std::endl;
    std::cout << "create copy " << std::endl;
    Array<Integer> array2( array );
    
    std::cout << "another copy" << std::endl;
    Array<Integer> array3( array );

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }
    std::cout << "-------------------" << std::endl;
    
    std::cout << "modify original (should cause deep copy)" << std::endl;
    array[3] = -10;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }
    
    std::cout << "modify original again (NO deep copy this time )" << std::endl;
    array[2] = -10;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }

    std::cout << "modify copy (should cause deep copy, array2 ref counter is 2 - shared with array3)" << std::endl;
    array2[1] = 1000;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }
}
void test9() {
    Integer::noise = false;
    std::cout << "dynamically allocate empty array and initialize it" << std::endl;
    Array<Integer> * p_array = new Array<Integer>;

    for ( int i=0; i<6; ++i ) {
        (*p_array)[i] = i+2;
    }

    Integer::noise = true;
    std::cout << "-------------------" << std::endl;
    std::cout << "create copy on stack" << std::endl;
    Array<Integer> array2( *p_array );

    std::cout << std::setw(5) << "pos" << std::setw(8) << "p_array" << std::setw(8) << "array2" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << (*p_array)[i] << std::setw(8) << array2[i] << std::endl;
    }

    Integer::noise = true;
    std::cout << "delete dynamically allocated array" << std::endl;
    delete p_array;

    std::cout << "check stack array is good, modify and print" << std::endl;
    std::cout << std::setw(5) << "pos" << std::setw(8) << "array2" << std::endl;
    for ( int i=0; i<6; ++i ) {
        array2[i] = i+100;
        std::cout << std::setw(5) << i << std::setw(8) << array2[i] << std::endl;
    }
}
void test10() {
    // correctness self-assignment test in Array<Integer>
    Integer::noise = false;
    std::cout << "create empty array" << std::endl;
    Array<Integer> array;

    for ( int i=0; i<6; ++i ) {
        array[i] = i+2;
    }

    Integer::noise = true;
    std::cout << "-------------------" << std::endl;
    std::cout << "create copy " << std::endl;
    Array<Integer> array2( array ); 

    Integer::noise = true;
    std::cout << "assign shallow copies" << std::endl;
    array = array2; // aren't they the same ?
}
void test11() {
    Integer::noise = false;
    std::cout << "create empty array" << std::endl;
    Array<Integer> array;

    for ( int i=0; i<6; ++i ) {
        array[i] = i+2;
    }

    Integer::noise = true;
    std::cout << "create const copy array" << std::endl;
    Array<Integer> const array_const( array );

    std::cout << "array_const[3] is " << array_const[3] << std::endl;
    std::cout << "array_const[5] is " << array_const[5] << std::endl;
    //array_const[5] = 6; // should not compile
}
void test12() {
    Integer::noise = false;
    std::cout << "create empty array" << std::endl;
    Array<Integer> array;

    for ( int i=0; i<6; ++i ) {
        array[i] = i+2;
    }

    Integer::noise = true;
    std::cout << "create shallow copy array2" << std::endl;
    Array<Integer> array2( array );
    
    std::cout << "access aroginal (read), no deep copy required" << std::endl;
    std::cout << "array[5] = " << array[5] << std::endl;
    //array_const[5] = 6; // should not compile
}
void test13() { //same as test7 but for different template parameter
    AnotherInteger::noise = false;
    std::cout << "create empty array" << std::endl;
    Array<AnotherInteger> array;

    for ( int i=0; i<6; ++i ) {
        array[i] = i+2;
    }
    std::cout << "array = " << array << std::endl;

    std::cout << "create another " << std::endl;
    Array<AnotherInteger> array2;
    for ( int i=0; i<6; ++i ) {
        array2[i] = i+20;
    }
    std::cout << "array2 = " << array2 << std::endl;
    
    std::cout << "create yet another " << std::endl;
    Array<AnotherInteger> array3;
    for ( int i=0; i<6; ++i ) {
        array3[i] = i+200;
    }
    std::cout << "array3 = " << array3 << std::endl;
    std::cout << "-------------------" << std::endl;
    
    
    AnotherInteger::noise = true;
    array2 = array3; 
    array = array2; 
    std::cout << "2 shallow assigns - done, no output expected" << std::endl;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }
    
    std::cout << "modify original (should cause deep copy)" << std::endl;
    array[3] = -10;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }
    
    std::cout << "modify original again (NO deep copy this time )" << std::endl;
    array[2] = -10;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }

    std::cout << "modify copy (should cause deep copy, array2 ref counter is 2 - shared with array3)" << std::endl;
    array2[1] = 1000;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }
}
void test14() {
    Array<int> a;
    for ( int i=0; i<20; ++i ) {
        a[i] = i+100;
    }
    for ( int i=0; i<20; ++i ) {
        std::cout << a[i] << std::endl;
    }
}
void test15();

void (*pTests[])() = { test0,test1,test2,test3,test4,test5,test6,test7,
	test8,test9,test10,test11,test12,test13,test14,test15
}; 

void test15() {
	for (size_t i = 0; i<sizeof(pTests)/sizeof(pTests[0])-1; ++i) 
		pTests[i]();
}

#include <cstdio> /* sscanf */
int main (int argc, char ** argv) {
    if (argc >1) {
        int test = 0;
        std::sscanf(argv[1],"%i",&test);
        try {
            pTests[test]();
        } catch( const char* msg) {
            std::cerr << msg << std::endl;
        }
    }
    return 0;
}
