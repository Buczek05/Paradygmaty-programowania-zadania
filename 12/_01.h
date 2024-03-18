#pragma once
#include <iostream>

using namespace std;

class A {
public:
    A(const char *name);
    A(): name(nullptr) {cout << "Default constructor" << std::endl;}
    A(const A &a);
    ~A() {delete[] name; name = nullptr; cout << "Destructor" << std::endl;}
    void display();
    A& operator=(const A &a);
private:
    char *name;
};


