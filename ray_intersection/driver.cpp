#include "shapes.h" //Shape,Box,Rhombus,BoundingCircle,Ray
#include <iostream>
#include <cstdio>   //sscanf
#include "trace.h"  //global Intersect

////////////////////////////////////////////////////////////////////////////////
void test0() {
    Box box1( 3,2, 2,2 );
    Box box2( 6,0, 2,2 );
    Ray ray( 0,0, 1,0 );

    std::pair<bool, float> res1 = box1.Intersect( ray );
    std::pair<bool, float> res2 = box2.Intersect( ray );

    std::cout << "intersect shape " << box1 << " and ray " << ray << " - ";
    if ( res1.first ) {
        std::cout << "true, t = " << res1.second << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    std::cout << "Intersect shape " << box2 << " and ray " << ray << " - ";
    if ( res2.first ) {
        std::cout << "true, t = " << res2.second << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
}

////////////////////////////////////////////////////////////////////////////////
void test1() {
    Box box1( 3,2, 2,2 );
    Box box2( 6,0, 2,2 );
    Ray ray( 0,0, 1,0 );

    BoundingCircle bc1 = box1.GetBoundingCircle();
    BoundingCircle bc2 = box2.GetBoundingCircle();

    bool bc_int1 = bc1.IntersectTest( ray );
    bool bc_int2 = bc2.IntersectTest( ray );

    std::cout << "Intersect bounding circle " << bc1 << " and ray " << ray;
    std::cout << " - " << std::boolalpha << bc_int1 << std::endl;
    
    std::cout << "Intersect bounding circle " << bc2 << " and ray " << ray;
    std::cout << " - " << std::boolalpha << bc_int2 << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
void test2() {
    Box box1( 4,4, 6,6 );
    Box box2( 10,0, 4,4 );
    Ray ray( 0,0, 1,0 );

    BoundingCircle bc1 = box1.GetBoundingCircle();
    BoundingCircle bc2 = box2.GetBoundingCircle();

    bool bc_int1 = bc1.IntersectTest( ray );
    bool bc_int2 = bc2.IntersectTest( ray );

    std::cout << "Intersect bounding circle " << bc1 << " and ray " << ray;
    std::cout << " - " << std::boolalpha << bc_int1 << std::endl;
    if ( bc_int1 ) { // if intersects circle, perform full intersection test
        std::pair<bool, float> res1 = box1.Intersect( ray );
        std::cout << "intersect shape " << box1 << " and ray " << ray << " - ";
        if ( res1.first ) {
            std::cout << "true, t = " << res1.second << std::endl;
        } else {
            std::cout << "false" << std::endl;
        }
    }
    
    std::cout << "Intersect bounding circle " << bc2 << " and ray " << ray;
    std::cout << " - " << std::boolalpha << bc_int2 << std::endl;
    if ( bc_int2 ) { // if intersects circle, perform full intersection test
        std::pair<bool, float> res2 = box2.Intersect( ray );
        std::cout << "intersect shape " << box2 << " and ray " << ray << " - ";
        if ( res2.first ) {
            std::cout << "true, t = " << res2.second << std::endl;
        } else {
            std::cout << "false" << std::endl;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
void test3() {
    Shape* shapes[] = { new Box( 3,2, 2,2 ), new Box( 6,0, 2,2 ), new Box( 5,5, 2,2 ) };
    Ray ray( 0,0, 1,1 );

    int num_shapes = sizeof(shapes)/sizeof(*shapes);

    std::cout << "Ray " << ray << "\n================\n";
    for ( int i=0; i<num_shapes; ++i) {
        shapes[i]->Print();
        std::cout << ": first check intersection with a bounding circle";
        if ( shapes[i]->GetBoundingCircle().IntersectTest( ray ) ) { //bounding circle test
            std::cout << " - true, make shape-intersection test";
            std::pair<bool, float> res = shapes[i]->Intersect( ray );
            if ( res.first ) {
                std::cout << " - true, t = " << res.second << std::endl;
            } else {
                std::cout << " - false\n";
            }
        } else {
            std::cout << " - false, skip shape-intersection test\n";
        }
    }

    for ( int i=0; i<num_shapes; ++i) {
        delete shapes[i];
    }
}

////////////////////////////////////////////////////////////////////////////////
void test4() {
    Shape* shapes[] = { new Box( 3,2, 2,2 ), new Box( 6,-4, 6,6 ), new Rhombus(12,-2, 4,4), new Box( 10,3, 4,4 ), new Rhombus(20,5, 12,12) };
    // see pic.pdf for above arrangement
    Ray ray( 0,0, 1,0 );

    int num_shapes = sizeof(shapes)/sizeof(*shapes);

//    for ( int i=0; i<num_shapes; ++i) {
//        std::cout << "BoundingCircle " << shapes[i]->GetBoundingCircle() << std::endl;
//    }

    std::cout << "Ray " << ray << "\n================\n";
    for ( int i=0; i<num_shapes; ++i) {
        shapes[i]->Print();
        std::cout << ": first check intersection with a bounding circle";
        if ( shapes[i]->GetBoundingCircle().IntersectTest( ray ) ) { //bounding circle test
            std::cout << " - true, make shape-intersection test";
            std::pair<bool, float> res = shapes[i]->Intersect( ray );
            if ( res.first ) {
                std::cout << " - true, t = " << res.second << std::endl;
            } else {
                std::cout << " - false\n";
            }
        } else {
            std::cout << " - false, skip shape-intersection test\n";
        }
    }

    for ( int i=0; i<num_shapes; ++i) {
        delete shapes[i];
    }
}

////////////////////////////////////////////////////////////////////////////////
void test5() {
    Shape* shapes[] = { new Box( 3,2, 2,2 ), new Box( 6,-4, 6,6 ), new Rhombus(12,-2, 4,4), new Box( 10,3, 4,4 ), new Rhombus(20,5, 12,12) };
    int num_shapes = sizeof(shapes)/sizeof(*shapes);
    
    Ray rays[] = { Ray( 0,0, 1,0 ), Ray( 1,1, 1,0 ), Ray( 8,8, 0,-1 ), Ray( 24,13, -1,-1 ) };
    int num_rays = sizeof(rays)/sizeof(*rays);

    for ( int i=0; i<num_rays; ++i ) {
        std::cout << "Ray " << rays[i] << "  ";
        std::pair<bool,float> res = Intersect( shapes, num_shapes, rays[i] ); // trace.h
        if ( res.first ) { std::cout << "The first intersection is at t = " << res.second << std::endl; } 
        else { std::cout << "There is no intersection\n"; }
    }


    for ( int i=0; i<num_shapes; ++i) { delete shapes[i]; }
}


////////////////////////////////////////////////////////////////////////////////
void test_all();

void (*pTests[])() = { test0,test1,test2,test3,test4,test5,test_all };

void test_all() {
	for (size_t i = 0; i<sizeof(pTests)/sizeof(pTests[0])-1; ++i) 
		pTests[i]();
}

////////////////////////////////////////////////////////////////////////////////
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