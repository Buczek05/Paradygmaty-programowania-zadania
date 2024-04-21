#include <fstream>
#include "vector.h"

using namespace std;


void my_vector::alloc() {
    cr = new double[3];
}

my_vector::my_vector(double xx, double yy, double zz) {
    alloc();
    cr[0] = xx;
    cr[1] = yy;
    cr[2] = zz;
}

my_vector::my_vector(const my_vector &ob) {
    if (ob.cr) {
        alloc();
        memcpy(cr, ob.cr, 3 * sizeof(double));
    } else
        cr = NULL;
}

#ifdef OVERLOAD_ASSIGNMENT_OPERATOR

my_vector& my_vector::operator=(const my_vector &pb) {
    if (this != &pb) {
        if (pb.cr) {
            if (!cr) {
                alloc();
            }
            memcpy(cr, pb.cr, 3 * sizeof(double));
        } else {
            if (cr) {
                delete[] cr;
                cr = NULL;
            }
        }
    }
    return *this;
}
#endif

my_vector my_vector::operator+(const my_vector &right) const {
    my_vector result(
            cr[0] + right.cr[0],
            cr[1] + right.cr[1],
            cr[2] + right.cr[2]
    );
    return result;
}

my_vector my_vector::operator*(const my_vector &right) const {
    my_vector result(
            cr[1] * right.cr[2] - cr[2] * right.cr[1],
            cr[2] * right.cr[0] - cr[0] * right.cr[2],
            cr[0] * right.cr[1] - cr[1] * right.cr[0]
    );
    return result;
}

double my_vector::operator*(const my_vector *right) const {
    double result = cr[0] * right->cr[0] + cr[1] * right->cr[1] + cr[2] * right->cr[2];
    return result;
}

void my_vector::disp(const char *str) {
    std::cout << str << ": (" << cr[0] << ", " << cr[1] << ", " << cr[2] << ")" << std::endl;
}

istream& operator>>(istream & strm, my_vector& v) {
    if (v.cr){
        cout << "input vector: x, y, z" << endl;
        strm >> v.cr[0] >> v.cr[1] >> v.cr[2];
    }
    return strm;
}

ostream& operator << (ostream & strm, const my_vector& v){
    if (v.cr){
        strm << ": (" << v.cr[0] << ", " << v.cr[1] << ", " << v.cr[2] << ")" << endl;
    }
    return strm;
}

int main(){
    my_vector v1(1, 2, -1), v2(2, 1, 1), res;
    v1.disp("v1");
    v2.disp("v2");

    res = v1 + v2;
    res.disp("v1 + v2");

    res = v1 * v2;
    res.disp("v1 x v2");

    res = v2 * v1;
    cout << "v1 * v2: " << v2 * v1 << endl;

    cout << "v1 * (&v2): " << v1 * (&v2) << endl;

    my_vector v3(0, 0, 0);
    cin >> v3;
    v3.disp("v3");

    ofstream my_file("output.txt");
    if (my_file.is_open()){
        my_file << "v1 * (&v2): " << v1 * (&v2);
        my_file.close();
    }

    return 0;
}