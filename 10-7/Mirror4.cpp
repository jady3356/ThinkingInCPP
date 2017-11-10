#include <iostream>
#include "Mirror.h"

using namespace std;

extern Mirror M3;

Mirror &GetM() {
	static Mirror SM(&M3);
	return SM;
}

Mirror M4 = GetM();

int main(){
	cout << "M4 : " << M4.test() << " M3 address:" << &M3 << " M4 address:" << &M4 << endl;
	return 0;
}