#include <iostream>
#include <string>

using namespace std;

class constructor {
    int i;
public:
    constructor(int ii);
    ~constructor();
    void print();
};

constructor::constructor(int ii) {
    i = ii;
    cout << "constructor" << endl;
}

constructor::~constructor() {
    cout << "~constructor" << endl;
}

void constructor::print() {
    cout << "i = " << i << endl;
}

int main() {
    constructor c(0);
    constructor cc[] = {constructor(1), constructor(2),constructor(3),constructor(4)};
    for(int i = 0;i < sizeof(cc)/sizeof(*cc);i++)
        cc[i].print();
}