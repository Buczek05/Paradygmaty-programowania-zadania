#include <iostream>

#pragma once
#define OVERLOAD_ASSIGNMENT_OPERATOR

using namespace std;

class my_vector
{
private:
    double* cr; //cr[0] - x; cr[1] - y; cr[2] - z
public:
    my_vector() : cr(NULL) {}
    my_vector(double xx, double yy, double zz);
    my_vector(const my_vector& ob);
    ~my_vector() {
        if (cr)
            delete[] cr;
        cr = NULL;
    }
    my_vector& operator = (const my_vector & pb);
    my_vector operator + (const my_vector& right) const;
    my_vector operator * (const my_vector& right) const; //vector product: res = v1 x v2
    double operator * (const my_vector* right) const; //dot product: dot = v1 * v2
    friend istream& operator >> (istream& strm, my_vector& v);
    friend ostream& operator << (ostream& strm, const my_vector& v);
    void disp(const char* str);
private:
    void alloc(); //allocation of memory
};