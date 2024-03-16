#pragma once

class MyVolume{
private:
    double a, b, c, V;
public:
    MyVolume() : a(0), b(0), c(0), V(0) {}
    MyVolume(double aa, double bb, double cc) : a(aa), b(bb), c(cc), V(0) {}
    double calculate();
    void display();
    void read_from_console();
};
