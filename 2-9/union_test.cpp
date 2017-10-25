#include<iostream>
using namespace std;

union packed {
	char c;
	int i;
	double d;
};

int main() {
	packed P;
	cout << "P address=" << &P << endl;
	P.i = 96;
	cout << "sizeof P="<<sizeof(P) << P.c << endl;
}