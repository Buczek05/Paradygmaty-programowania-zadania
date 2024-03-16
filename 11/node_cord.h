#pragma once
#include <iostream>

class NODE_COORD
{
public:
    double *pcoord; //pcoord[0] - x, pcoord[1] - y public:
    NODE_COORD() : pcoord(NULL) {}
    NODE_COORD(double x, double y);
    NODE_COORD(const NODE_COORD &A);
    ~NODE_COORD();
    double distance(const NODE_COORD &A);
    void disp();
private:
    void crash();
};