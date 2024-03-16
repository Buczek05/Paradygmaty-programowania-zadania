#include "triangle.cpp"
#include "node_cord.cpp"

void my_fun(Triangle trr){
    trr.disp();
}

void my_fun(Triangle * trr){
    trr->disp();
}

int main() {
    NODE_COORD A(2, 3);
    NODE_COORD B = A;
    NODE_COORD C;
    NODE_COORD D = C;
    NODE_COORD AA(2, 3), BB(3, 4), CC(0, 0);
    Triangle tr(AA, BB, CC, "triangle 1");
    tr.disp();
    cout << "distance between first and second nodes: " << tr.distance(1, 2) << endl;
    my_fun(tr);
    my_fun(&tr);
    return 0;
}