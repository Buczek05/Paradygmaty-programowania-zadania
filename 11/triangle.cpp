//
// Created by Kacper Bukowski on 16/03/2024.
//

#include "triangle.h"
#include "string.h"

Triangle::Triangle(NODE_COORD &a, NODE_COORD &b, NODE_COORD &c, const char *name) : vert_a(a), vert_b(b), vert_c(c){
    strcpy(str, name);
    str[127] = '\0';
}

Triangle::~Triangle() {
}

void Triangle::disp() {
    cout << "Triangle " << str << " vertices: " << endl;
    vert_a.disp();
    vert_b.disp();
    vert_c.disp();
}

NODE_COORD Triangle::get_by_index(int index) {
    if (index == 1) {
        return vert_a;
    } else if (index == 2) {
        return vert_b;
    } else if (index == 3) {
        return vert_c;
    } else {
        return NODE_COORD();
    }
}

double Triangle::distance(int first, int second) {
    return get_by_index(first).distance(get_by_index(second));
}