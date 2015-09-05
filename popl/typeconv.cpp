#include<iostream>
using namespace std;

typedef struct t1 {
        int a;
        int b;
} t1;

typedef struct t2{
        int a;
        int b;
} t2;

typedef struct t3{
        int b;
        int a;
} t3;

typedef struct t4 {
        t3 s3;
        t2 s2;
        operator t3() { return s3; };
        operator t2() { return s2; };
    } t4;



int main(int argc, char const *argv[])
{
    std::cout << "Inside type theory\n";

     t1 s1; t2 *ps2; t3 s3; t4 s4;

    t2 s2;

    t3 *ps3;

    s1.a=3; s1.b=5;

    s4.s3.a= 99; s4.s3.b= 55; s4.s2.a= 88; s4.s2.b= 44;

    int i= 65; char ch;

    float f=2.5; double dbl;

    s2= (t2) s1; //This is wrong due to Name equivalence

    s3= s2; // Even this is wrong

    ps2= reinterpret_cast<t2*>(&s1);

    ps3= reinterpret_cast<t3*>(&s1);

    s2= static_cast<t2>(s1); // This is a problem

    ps2= dynamic_cast<t2*>(&s1);

    

    s2= s4; s3= s4;

    s3= static_cast<t3>(s4); // this is the same as previous line

    std::cout << "After casting S2 a: "<< s2.a << " S2 b: " << s2.b << " S3.a="<< s3.a << " S3.b=" << s3.b << std::endl;

    ch = static_cast<char>(i);

    dbl= static_cast<double>(f);

    std::cout << "S2 a: "<< ps2->a << " S2 b: " << ps2->b << std::endl;

    std::cout << "S3 a: "<< ps3->a << " S3 b: " << ps3->b << std::endl;
    /* code */
    return 0;
}
