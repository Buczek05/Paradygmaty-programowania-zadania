//
// Created by Kacper Bukowski on 16/03/2024.
//
#include "Complex_class/Complex_class.cpp"
#ifndef PARADYGMATY_PROGRAMOWANIA_ZADANIA_Z_1_H
#define PARADYGMATY_PROGRAMOWANIA_ZADANIA_Z_1_H


class Triangle {
private:
    MY_POINT pt_1, pt_2, pt_3;
public:
    Triangle() : pt_1(0, 0), pt_2(0, 0), pt_3(0, 0) {}
    Triangle(double x_1, double y_1, double x_2, double y_2, double x_3, double y_3) : pt_1(x_1, y_1), pt_2(x_2, y_2), pt_3(x_3, y_3) {}
    void disp();
    void set_p1(double x, double y) { pt_1.set(x, y); }
    void set_p2(double x, double y) { pt_2.set(x, y); }
    void set_p3(double x, double y) { pt_3.set(x, y); }
    void get_p1() { pt_1.disp(); }
    void get_p2() { pt_2.disp(); }
    void get_p3() { pt_3.disp(); }
    void read_from_console();
};


#endif //PARADYGMATY_PROGRAMOWANIA_ZADANIA_Z_1_H
