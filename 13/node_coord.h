#include <iostream>

#pragma once
#define NAME_SIZE 26
#define EPS 0.000000001

class NodeCoord {
private:
    double *coor;
    char name[NAME_SIZE];
public:
    NodeCoord(double x, double y, const char *str);
    NodeCoord(const NodeCoord &ob);
    ~NodeCoord();
    NodeCoord &operator=(const NodeCoord &right);
    int operator==(const char *str_comp) const;
    int operator==(const double *cr) const;
    void disp();
private:
    void alloc();
};