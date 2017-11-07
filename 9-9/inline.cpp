#include<iostream>
using namespace std;

// （1）全局的内联函数要显示的带inline, 一般只适用于小的函数，主要是提高效率，因为编译器会对内联函数加入符号表，对其进行简单的替换，少了汇编的压栈和CALL的开销。
//  (2) 类内部的定义的成员函数都是默认是内联函数，注意一定是定义的，如果只是申明就要带inline关键字，一般内联函数的定义在头文件里。
//  (3) inline关键字是实现型的，就是说只有在定义的时候带上有作用，在申明的时候带不是内联。
#define TRACE(s) cout << #s << endl; s
#define FIELD(a) char* a##_string; int a##_size

class inlineTest {
	int i;
public:
	inlineTest() {}
	inlineTest(int ii): i(ii) { cout << i << endl;}
	int fuct1(int iii) {cout << iii << endl;} // 类内部定义的所以是内联函数

};

int main() {
inlineTest inT(1);
TRACE(inT.fuct1(2));
//TRACE("debug");
}