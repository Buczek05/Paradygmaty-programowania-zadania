//
// Created by Kacper Bukowski on 16/03/2024.
//

#include "z_1.h"

void Triangle::disp() {
    cout << "P1: ";
    pt_1.disp();
    cout << "P2: ";
    pt_2.disp();
    cout << "P3: ";
    pt_3.disp();
}

void Triangle::read_from_console() {
    double x, y;
    cout << "Podaj x i y dla punktu 1: ";
    cin >> x >> y;
    set_p1(x, y);
    cout << "Podaj x i y dla punktu 2: ";
    cin >> x >> y;
    set_p2(x, y);
    cout << "Podaj x i y dla punktu 3: ";
    cin >> x >> y;
    set_p3(x, y);
}

int main(){
    Triangle a;
    a.read_from_console();
    a.disp();
}