#include <iostream>
#include <cstdlib>
#include <cstdio> /* sscanf */
#include "functions.h"

using std::cout;
using std::endl;

struct Student {
    char login[9];
    int age;
    int year;
    double GPA;
};

std::ostream& operator<<(std::ostream& os, const Student& s)
{
    os << "(login) " << s.login << ", ";
    os << "(age) " << s.age << ", ";
    os << "(year) " << s.year << ", ";
    os << "(GPA) " << s.GPA << endl;
    return os;
}

bool operator>(const Student& lhs, const Student& rhs) {
    return lhs.GPA > rhs.GPA;
}

bool operator<(const Student& lhs, const Student& rhs) {
    return lhs.GPA < rhs.GPA;
}

void print_students(const Student *s, int size) {
    for (int i = 0; i < size; i++)
        cout << s[i];
}

void test0(void) {
    cout << "***** TestSwap1 *****" << endl;
    int a = 5, b = 8;

    cout << "a = " << a << ", b = " << b << endl;
    CS225::swap(&a, &b);
    cout << "a = " << a << ", b = " << b << endl;
}

void test1(void) {
    cout << "***** TestSwap2 *****" << endl;
    Student s1 = {"jdoe", 20, 3, 3.82};
    Student s2 = {"fbar", 22, 1, 1.28};

    cout << "s1: " << s1;
    cout << "s2: " << s2;
    CS225::swap(&s1, &s2);
    cout << "s1: " << s1;
    cout << "s2: " << s2;
}

void test2(void)
{
    cout << "***** SwapRanges *****" << endl;
    int i1[] = {-1, 2, 6, -1, 9, 5, 7, -1, -1, 8, -1};
    int i2[] = {3, 6, 8, 0, -1, 5, -3, -9, 3, 5, 8};

    int size = sizeof(i1) / sizeof(*i1);

    CS225::display(i1, i1 + size);
    CS225::display(i2, i2 + size);
    CS225::swap_ranges(i1, i1 + size, i2);
    CS225::display(i1, i1 + size);
    CS225::display(i2, i2 + size);
}

void test3(void) {
    cout << "***** Remove1 *****" << endl;
    int i1[] = {5, -7, 4, 10, -21, 15, 9};

    int size = sizeof(i1) / sizeof(*i1);
    CS225::display(i1, i1 + size);
    int item = -1;
    int *newend = CS225::remove(i1, i1 + size,  item);
    cout << "remove " << item << ", new list: ";
    CS225::display(i1, newend);
}

void test4(void) {
    cout << "***** Remove2 *****" << endl;
    int i1[] = {5, -7, 4, 10, -7, 15, 9};

    int size = sizeof(i1) / sizeof(*i1);
    CS225::display(i1, i1 + size);
    int item = -7;
    int *newend = CS225::remove(i1, i1 + size,  item);
    cout << "remove " << item << ", new list: ";
    CS225::display(i1, newend);
}

void test5(void) {
    cout << "***** Remove *****" << endl;
    int i1[] = {-1, -1, -1, -1, -1, -1, -1};

    int size = sizeof(i1) / sizeof(*i1);
    CS225::display(i1, i1 + size);
    int item = -1;
    int *newend = CS225::remove(i1, i1 + size,  item);
    cout << "remove " << item << ", new list: ";
    CS225::display(i1, newend);
}

void test6(void) {
    cout << "***** Count1 *****" << endl;
    int i1[] = {-1, 2, 6, -1, 9, 5, 7, -1, -1, 8, -1};

    int size = sizeof(i1) / sizeof(*i1);
    CS225::display(i1, i1 + size);
    int item = -1;
    int c = CS225::count(i1, i1 + size, item);
    cout << "Count of " << item << " is " << c << endl;
}

void test7(void) {
    cout << "***** Count2 *****" << endl;
    int i1[] = {-1, 2, 6, -1, 9, 5, 7, -1, -1, 8, -1};

    int size = sizeof(i1) / sizeof(*i1);
    CS225::display(i1, i1 + size);
    int item = 50;
    int c = CS225::count(i1, i1 + size, item);
    cout << "Count of " << item << " is " << c << endl;
}

void test8(void) {
    cout << "***** Find1 *****" << endl;
    const int i1[] = {-1, 2, 6, -1, 9, 5, 7, -1, -1, 8, -1};

    int size = sizeof(i1) / sizeof(*i1);
    const int *end = i1 + size;
    CS225::display(i1, end);
    const int item = 9;
    const int *pos = CS225::find(i1, end, item);
    if (pos != end)
        cout << "Item " << item << " is " << *pos << endl;
    else
        cout << "Item " << item << " was not found" << endl;
}

void test9(void) {
    cout << "***** Find2 *****" << endl;
    int i1[] = {-1, 2, 6, -1, 9, 5, 7, -1, -1, 8, -1};

    int size = sizeof(i1) / sizeof(*i1);
    int *end = i1 + size;
    CS225::display(i1, end);
    const int item = 9;
    int *pos = CS225::find(i1, end, item);

    if (pos != end)
    {
        cout << "Changing " << item << " to 100" << endl;
        *pos = 100;
    }
    else
        cout << "Item " << item << " was not found" << endl;

    CS225::display(i1, end);
}

void test10(void) {
    cout << "***** Find3 *****" << endl;
    const int i1[] = {-1, 2, 6, -1, 9, 5, 7, -1, -1, 8, -1};

    int size = sizeof(i1) / sizeof(*i1);
    const int *end = i1 + size;
    CS225::display(i1, end);
    const int item = 19;
    const int *pos = CS225::find(i1, end, item);
    if (pos != end)
        cout << "Item " << item << " is " << *pos << endl;
    else
        cout << "Item " << item << " was not found" << endl;
}


void test11(void) {
    cout << "***** Copy1 *****" << endl;
    const short i1[] = {-1, 2, 6, -1, 9, 5, 7, -1, -1, 8, -1};
    int size = sizeof(i1) / sizeof(*i1);
    int i2[20] = {0};

    CS225::display(i1, i1 + size);
    int *i2end = CS225::copy(i1, i1 + size, i2);
    CS225::display(i2, i2end);
}

void test12(void) {
    cout << "***** Fill1 *****" << endl;
    int i1[10];
    int size = 10;

    CS225::fill(i1, i1 + size, 12);
    CS225::display(i1, i1 + size);
}

void test13(void) {
    cout << "***** Replace1 *****" << endl;
    int i1[] = {-1, 2, 6, -1, 9, 5, 7, -1, -1, 8, -1};
    int size = sizeof(i1) / sizeof(*i1);

    CS225::display(i1, i1 + size);
    int olditem = -1;
    int newitem = -8;
    cout << "Replacing " << olditem << " with " << newitem << endl;
    CS225::replace(i1, i1 + size, olditem, newitem);
    CS225::display(i1, i1 + size);
}

void test14(void) {
    cout << "***** Min1 *****" << endl;
    const int i1[] = {-1, 2, 6, -31, 9, 5, 7, -21, -1, 8, -10};
    int size = sizeof(i1) / sizeof(*i1);

    CS225::display(i1, i1 + size);
    const int *pos = CS225::min_element(i1, i1 + size);

    cout << "The min element is: " << *pos << endl;
}

void test15(void) {
    cout << "***** Min2 *****" << endl;
    int i1[] = {-1, 2, 6, -31, 9, 5, 7, -21, -1, 8, -10};
    int size = sizeof(i1) / sizeof(*i1);

    CS225::display(i1, i1 + size);
    int *pos = CS225::min_element(i1, i1 + size);

    cout << "The min element is: " << *pos << endl;
    *pos = 0; // set smallest to zero
    CS225::display(i1, i1 + size);
}

void test16(void) {
    cout << "***** Min3 *****" << endl;
    Student s1[] = { {"jdoe", 20, 3, 3.82},
        {"fbar", 22, 1, 1.28},
        {"wxyz", 19, 3, 1.59},
        {"abcd", 20, 1, 1.99},
        {"jbar", 22, 2, 3.38}
    };

    int size = sizeof(s1) / sizeof(*s1);
    Student *end = s1 + size;

    print_students(s1, size);
    Student *pos = CS225::min_element(s1, end);

    cout << "The min element is: " << *pos;
}


void test17(void) {
    cout << "***** Max1 *****" << endl;
    const int i1[] = {-1, 2, 6, -31, 9, 5, 7, -21, -1, 8, -10};
    int size = sizeof(i1) / sizeof(*i1);

    CS225::display(i1, i1 + size);
    const int *pos = CS225::max_element(i1, i1 + size);

    cout << "The max element is: " << *pos << endl;
}

void test18(void) {
    cout << "***** Max2 *****" << endl;
    int i1[] = {-1, 2, 6, -31, 9, 5, 7, -21, -1, 8, -10};
    int size = sizeof(i1) / sizeof(*i1);

    CS225::display(i1, i1 + size);
    int *pos = CS225::max_element(i1, i1 + size);

    cout << "The max element is: " << *pos << endl;
}

void test19(void) {
    cout << "***** Max3 *****" << endl;
    Student s1[] = { {"jdoe", 20, 3, 3.82},
        {"fbar", 22, 1, 1.28},
        {"wxyz", 19, 3, 1.59},
        {"abcd", 20, 1, 1.99},
        {"jbar", 22, 2, 3.38}
    };

    int size = sizeof(s1) / sizeof(*s1);
    Student *end = s1 + size;

    print_students(s1, size);
    Student *pos = CS225::max_element(s1, end);

    cout << "The max element is: " << *pos;
}

void test20(void) {
    cout << "***** Equal1 *****" << endl;
    int i1[] = {-1, 2, 6, -1, 9, 5, 7, -1, -1, 8, -1};
    short i2[] = {-1, 2, 6, -1, 9, 5, 7, -1, -1, 8, -1};

    int size = sizeof(i1) / sizeof(*i1);

    CS225::display(i1, i1 + size);
    CS225::display(i2, i2 + size);
    bool same = CS225::equal(i1, i1 + size, i2);
    if (same)
        std::cout << "Arrays are equal\n";
    else
        std::cout << "Arrays are not equal\n";
}

void test21(void) {
    cout << "***** Equal2 *****" << endl;
    int i1[] = {-1, 2, 6, -1, 9, 5, 7};
    short i2[] = {-1, 2, 6, -1, 9, 5, 7, -1, -1, 8, -1};

    int size1 = sizeof(i1) / sizeof(*i1);
    int size2 = sizeof(i2) / sizeof(*i2);

    CS225::display(i1, i1 + size1);
    CS225::display(i2, i2 + size2);
    bool same = CS225::equal(i1, i1 + size1, i2);
    if (same)
        std::cout << "Arrays are equal\n";
    else
        std::cout << "Arrays are not equal\n";
}

void test22(void) {
    cout << "***** Equal3 *****" << endl;
    int i1[] = {-1, 2, 6, -1, 9, 5, 7};
    short i2[] = {-1, 2, 6, -1, 9, 6, 7};

    int size1 = sizeof(i1) / sizeof(i1);
    int size2 = sizeof(i2) / sizeof(i2);

    CS225::display(i1, i1 + size1);
    CS225::display(i2, i2 + size2);
    bool same = CS225::equal(i1, i1 + size1, i2);
    if (same)
        std::cout << "Arrays are equal\n";
    else
        std::cout << "Arrays are not equal\n";
}

void test23(void) {
    cout << "***** Sum1 *****" << endl;
    int i1[] = {3, 6, 8, 0, -1, 5, -3, -9, 3, 5, 8, -20, -5};

    int size = sizeof(i1) / sizeof(*i1);

    CS225::display(i1, i1 + size);
    int total = CS225::sum(i1, i1 + size);
    std::cout << "Sum is " << total << std::endl;
}

void test24(void);

void (*pTests[])() = {
    test0, test1, test2, test3, test4, test5, test6, test7, test8, test9, test10, test11,
    test12, test13, test14, test15, test16, test17, test18, test19,
    test20, test21, test22, test23
};

void test24(void) {
	for ( unsigned i = 0; i<sizeof(pTests)/sizeof(pTests[0])-1; ++i) 
		pTests[i]();
}

int main(int argc, char *argv[] ) {
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
