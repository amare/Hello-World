//
// @file:           test_union.cc
// @author:         cuckoo
// @date:           2016/12/30 10:29:04
// @description:    to be Byte Aligned in union or struct
// @note            http://blog.jobbole.com/109429/
//

#include <iostream>
using std::cout;
using std::endl;

union Data0
{
    int a;
    int b;
};

union Data1
{
    int a;
    double b;
};

union Data2
{
    char a[9];
    double b;
};

struct Data3
{
    int a;
    int c;
    double b;
};

struct S1
{
    char c;
    int i;
};
struct S2
{
    int i;
    char c;
};
struct S3
{
    char c1;
    S1 s;
    char c2;
};
struct S1_2
{
    char c;
    short s;
};
struct S4
{
    char c;
    S1_2 s;
    int i;
};
struct S5
{
    char c1;
    S1_2 s;
    char c2;
};
struct S6
{
    char c1;
    char c2;
    S1_2 s;
};
struct S7
{
    char c;
    int i;
    S1_2 s;
};

int main()
{
    cout << "sizeof union Data0: " << sizeof(Data0) << endl;
    cout << "sizeof union Data1: " << sizeof(Data1) << endl;
    cout << "sizeof union Data2: " << sizeof(Data2) << endl;

    Data3 d3 = {0, 0, 0.0};
    cout << "address of d3: " << &d3 << endl;
    cout << "address of d3.a: " << &(d3.a) << endl;
    cout << "address of d3.b: " << &(d3.b) << endl;
    cout << "address of d3.c: " << &(d3.c) << endl;

    cout << "sizeof struct S1: " << sizeof(S1) << endl;
    cout << "sizeof struct S2: " << sizeof(S2) << endl;
    cout << "sizeof struct S3: " << sizeof(S3) << endl;
    cout << "offset of c1 in S3: " << offsetof(S3, c1) << endl;
    cout << "offset of s in S3: " << offsetof(S3, s) << endl;
    cout << "offset of c2 in S3: " << offsetof(S3, c2) << endl;

    cout << "sizeof struct S1_2: " << sizeof(S1_2) << endl;
    cout << "sizeof struct S4: " << sizeof(S4) << endl;
    cout << "offset of c in S4: " << offsetof(S4, c) << endl;
    cout << "offset of s in S4: " << offsetof(S4, s) << endl;
    cout << "offset of i in S4: " << offsetof(S4, i) << endl;

    cout << "sizeof struct S5: " << sizeof(S5) << endl;
    cout << "offset of c1 in S5: " << offsetof(S5, c1) << endl;
    cout << "offset of s in S5: " << offsetof(S5, s) << endl;
    cout << "offset of c2 in S5: " << offsetof(S5, c2) << endl;

    cout << "sizeof struct S6: " << sizeof(S6) << endl;
    cout << "offset of c1 in S6: " << offsetof(S6, c1) << endl;
    cout << "offset of c2 in S6: " << offsetof(S6, c2) << endl;
    cout << "offset of s in S6: " << offsetof(S6, s) << endl;

    cout << "sizeof struct S7: " << sizeof(S7) << endl;
    cout << "offset of c in S7: " << offsetof(S7, c) << endl;
    cout << "offset of i in S7: " << offsetof(S7, i) << endl;
    cout << "offset of s in S7: " << offsetof(S7, s) << endl;
    return 0;
}
