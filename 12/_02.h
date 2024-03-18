#pragma once
#include <iostream>

using namespace std;

class NODE_COORD
{
    double *pcoord; //pcoord[0] - x, pcoord[1] - y
public:
    NODE_COORD() : pcoord(NULL) {cout << "default constructor: NODE_COORD\n";}
    NODE_COORD(double x, double y); //parameterized constructor
    ~NODE_COORD(); //destructor
    void set(double x, double y); //set x, y coordinates
    void disp(); //display x, y coordinates on screen
private:
    void alloc();
    void crash(); //memory allocation error handler – call
//this function if a memory allocation fails
};