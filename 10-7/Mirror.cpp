#include <iostream>
#include "Mirror.h"
using namespace std;

Mirror M;
//下面是所谓的消除链接顺序导致的初始化问题的技术2...
Mirror &GetM() {
	static Mirror SM(M);
	cout << "SM : " << &SM << endl;
	return SM;
}
#if 0
Mirror& GetM() {
	static Mirror SM;
	return SM;
}

Mirro M = GetM();

int main() {
	cout << "M : " << M.test() << endl;
	return 0;
}
#endif