#include "_02.h"

NODE_COORD::NODE_COORD(double x, double y) {
    alloc();
    pcoord[0] = x;
    pcoord[1] = y;
}

NODE_COORD::~NODE_COORD() {
    if (pcoord != NULL) {
        delete[] pcoord;
    }
    cout << "destructor: NODE_COORD\n";
}

void NODE_COORD::set(double x, double y) {
    if (pcoord == NULL) {
        alloc();
    }
    pcoord[0] = x;
    pcoord[1] = y;
}

void NODE_COORD::alloc(){
    try {
        pcoord = new double[2];
    }
    catch (bad_alloc) {
        crash();
    }
}

void NODE_COORD::disp() {
    if (pcoord == NULL) {
        cout << "Error: memory not allocated\n";
        return;
    }
    cout << "x: " << pcoord[0] << " y: " << pcoord[1] << endl;
}

void NODE_COORD::crash() {
    cout << "Memory allocation error\n";
    exit(1);
}

void fun(NODE_COORD *ptr) {
    for (size_t i = 0; i < 10; ++i) {
        ptr[i].disp();
    }
}

int main ()
{
    const double math_pi = 3.141592;
    NODE_COORD tb[3] = { NODE_COORD(0, 0), NODE_COORD(1, 0), NODE_COORD(0, 1) };
    for(size_t i=0; i<3; ++i)
    {
        tb[i].disp();
    }
    NODE_COORD * ptr = NULL;
    ptr = new NODE_COORD[10];
    for(size_t i=0; i<10; ++i)
        ptr[i].set(10 * cos(2 * math_pi * i / 10), 10 * sin(2 * math_pi * i / 10));
    {
    }
    fun(ptr);
    delete[] ptr;
    return 0;
}