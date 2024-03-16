#include <iostream>
#include "01.h"

using namespace std;

double::MyVolume::calculate(){
    V = a * b * c;
    return V;
}

void::MyVolume::display(){
    cout << "V = " << V << endl;
}

void::MyVolume::read_from_console(){
    cout << "Podaj a: ";
    cin >> a;
    cout << "Podaj b: ";
    cin >> b;
    cout << "Podaj c: ";
    cin >> c;
}

int main(){
    MyVolume obj;
    obj.read_from_console();
    obj.calculate();
    obj.display();

    return 0;
}