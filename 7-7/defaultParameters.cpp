#include <iostream>
using namespace std;

class defaultParameters {
    int local;
public:
    void defaultFun1(int size);
    void defaultFun2(int size, int = 0);
    void defaultFun3(int size, int size2 = 0, int size3 = 0);
    void defaultFun4(int size, int size2 = 0, int size3 = 0, int size4 = 0);
    void print();
};

void defaultParameters::defaultFun1(int size) {
    local = size;
}

void defaultParameters::defaultFun2(int size, int size2) {
    local = size;
}

void defaultParameters::defaultFun3(int size, int size2, int size3) {
    local = size3;
}

void defaultParameters::defaultFun4(int size, int size2, int size3, int size4) {
    local = size4;
}

void defaultParameters::print() {
    cout << local << endl;
}

int main() {
    defaultParameters D;
    D.defaultFun1(1);
    D.print();
    D.defaultFun2(2);
    D.print();
    D.defaultFun3(3);
    D.print();
    D.defaultFun4(4);
    D.print();
}