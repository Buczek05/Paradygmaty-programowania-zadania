#pragma once
#include "node_cord.h"

using namespace std;

class Triangle {
private:
    NODE_COORD vert_a, vert_b, vert_c;
    char str[128];
    NODE_COORD get_by_index(int index);
public:
    Triangle(NODE_COORD &a, NODE_COORD &b, NODE_COORD &c, const char *name);
    ~Triangle();
    void disp();
    double distance(int first, int second);
};

