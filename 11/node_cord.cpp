#include "node_cord.h"

using namespace std;

NODE_COORD::NODE_COORD(double x, double y) {
    try {
        pcoord = new double[2];
        pcoord[0] = x;
        pcoord[1] = y;
    }
    catch (bad_alloc) {
        crash();
    }
}

NODE_COORD::NODE_COORD(const NODE_COORD &A) {
    try {
        pcoord = new double[2];
        if (A.pcoord) {
            pcoord[0] = A.pcoord[0];
            pcoord[1] = A.pcoord[1];
        }
    }
    catch (bad_alloc) {
        crash();
    }
}

void NODE_COORD::crash() {
    cout << "memory allocation error\n";
    system("pause");
    exit(1);
}

NODE_COORD::~NODE_COORD() {
    if (pcoord) {
        delete[] pcoord;
        pcoord = NULL;
    }
}

void NODE_COORD::disp() {
    if (pcoord) {
        cout << "x = " << pcoord[0] << " y = " << pcoord[1] << endl;
    }
    else {
        cout << "empty object\n";
    }
}

double NODE_COORD::distance(const NODE_COORD &A) {
    if (pcoord && A.pcoord) {
        return sqrt(pow(pcoord[0] - A.pcoord[0], 2) + pow(pcoord[1] - A.pcoord[1], 2));
    }
    else {
        cout << "empty object\n";
        return 0;
    }
}