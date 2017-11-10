#include <iostream>
#include "Mirror.h"

using namespace std;

extern Mirror &GetM(); // 据说extern是多余的，试了不加也是可以编译运行。 因为全局的变量和普通函数都有外部链接？
//Mirror M1(&M);
Mirror M1 = GetM();

int main() {
	cout << "M1 : " << &M1 << " " << M1.test() << endl;
	return 0;
}