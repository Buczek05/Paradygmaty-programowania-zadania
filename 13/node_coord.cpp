#include "node_coord.h"
#include "find_template.cpp"

void NodeCoord::alloc() {
    coor = new double[2];
}

NodeCoord::NodeCoord(double x, double y, const char *str) {
    alloc();
    coor[0] = x;
    coor[1] = y;
    memcpy(name, str, sizeof(char) * NAME_SIZE);
}

NodeCoord::NodeCoord(const NodeCoord &ob) {
    alloc();
    coor[0] = ob.coor[0];
    coor[1] = ob.coor[1];
    memcpy(name, ob.name, sizeof(char) * NAME_SIZE);
}

NodeCoord::~NodeCoord() {
    delete[] coor;
}

NodeCoord &NodeCoord::operator=(const NodeCoord &right) {
    if (this != &right) {
        delete[] coor;
        alloc();
        coor[0] = right.coor[0];
        coor[1] = right.coor[1];
        memcpy(name, right.name, sizeof(char) * NAME_SIZE);
    }
    return *this;
}

int NodeCoord::operator==(const char *str_comp) const {
    return strcmp(name, str_comp) == 0;
}

int NodeCoord::operator==(const double *cr) const {
    return (abs(coor[0] - cr[0]) < EPS && abs(coor[1] - cr[1]) < EPS);
}

void NodeCoord::disp(){
    std::cout << "x = " << coor[0] << " y = " << coor[1] << std::endl;
}


int main() {
    int ndim = 10;
    int it;
    size_t dist;
    double *p_tab;
    double *p_tmp, search_item;

    try {
        p_tab = new double[ndim];
    }
    catch (std::bad_alloc aa) {
        std::cout << "mem_alloc_err\n";
        system("pause");
        exit(1);
    }

    for (it = 0; it < ndim - 1; it++) {
        p_tab[it] = (double) (it + 1);
    }

    search_item = p_tab[ndim - 1] = 3;
    std::cout << "how many " << search_item << " is met in p_tab?\n";
    std::cout << "which elements contain search_item?\n";

    p_tmp = p_tab;
    while (p_tmp) {
        p_tmp = Find(p_tmp, p_tab + ndim, search_item);
        if (p_tmp) {
            dist = p_tmp - p_tab;
            std::cout << "tab [" << dist << "] = " << *p_tmp << std::endl;
            p_tmp++;
        } else {
            std::cout << "End of search\n";
        }
    }

    delete[] p_tab;

    NodeCoord tab_coord[] = {
            NodeCoord(0, -1, "nazwa"),
            NodeCoord(3.000000000000001, 0, "nazwa1"),
            NodeCoord(2, -1, "nazwa2"),
            NodeCoord(0, 5, "nazwa3"),
    };
    double find[2] = {3, 0};
    NodeCoord *tmp = Find(tab_coord, tab_coord + 4, find);
    tmp->disp();
    return 0;
}


