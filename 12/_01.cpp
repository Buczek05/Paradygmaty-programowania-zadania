#include "_01.h"
#include <iostream>


A::A(const char *name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    cout << "Parametrized constructor" << std::endl;
}

A::A(const A &a) {
    name = new char[strlen(a.name) + 1];
    strcpy(name, a.name);
    cout << "Copy constructor" << std::endl;
}

void A::display(){
    if (name) {
        cout << name << std::endl;
    }
    else {
        cout << "empty object" << std::endl;
    }
}

A& A::operator=(const A &a) {
    if (this != &a) {
        delete[] name;
        name = new char[strlen(a.name) + 1];
        strcpy(name, a.name);
    }
    return *this;
}

void fun(A a) {
    a.display();
}

void fun(A *a) {
    a->display();
}

A fun(){
    A a("fun");
    return a;
}

void crash() {
    cout << "memory allocation error\n";
    exit(1);
}

int main()
{
    try{
        A a("aaa");
        A b = a;
        A c;
        c = a;
        fun(a);
        fun(&a);
        A d = fun();
    }
    catch (bad_alloc&) {
        crash();
    }
}