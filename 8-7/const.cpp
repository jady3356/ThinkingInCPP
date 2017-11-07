#include<iostream>
using namespace std;

const int A = 1;
const int B = 2;
const int C = 3;

int Array[A+B+C]; // 在C++中， A,B,C 在编译阶段放入符号表中，如果发现相同的符号就将其值替换；
                 //其是放在符号表中，可能分配存储空间,也可能不分配存储空间 ，使用&符号时候才分配一个临时内存空间,但不会使用其存储空间中的值。

class const1 {
	int i;
public:
	const1(int ii): i(ii) { cout << "initialize: " << i << endl; };
	int func1() const {
	 //i = 100; inlegal: assignment of data-member â€˜const1::iâ€™ in read-only structure
	 cout << "func1" << endl;}; //该函数不会修该类的数据成员，且只能被该类的const对象调用；
	int func2() { i= 10000;cout << "func2" << endl;} //与上面的const函数相反，该函数是要改变成员数据的，而且不能被const的对象调用
};

int main() {
	const const1 c1(1);
	c1.func1();
	//c1.func2();
	const1 c2(2);
	c2.func2();
	c2.func1();
	const int a=3;
	//int* pa=&a;//error: invalid conversion from â€˜const int*â€™ to â€˜int*â€™
	             //原因在于a用const修饰后，已经成为常量了，因此是不允许被修改的，无论是显式的更改a的值或是通过其它方法修改它的值都是不允许的。
	//*pa=4;//
	int *p = NULL;  
    cout<<"a修改前:"<<a<<endl;  
    p = (int *)&a;  // 为什么这样可以？跟29行有什么区别？取地址强转不会编译报错
    *p = 6;  
    cout<<"a修改后:"<<a<<endl;  
    int const*p1;// const 在*左边，常量指针，const修饰的指针指向的值是常量，则表示指针指向的变量的值不可变;
    int* const p2 = NULL; // const 在*右边，指针常量，const 修饰的是指针本身， 则表示指针的值是不可变的； 必须初始化，不然会报错
}