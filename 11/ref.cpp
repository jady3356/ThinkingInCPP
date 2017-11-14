#include <iostream>
#include <fstream>
using namespace std;

ofstream out("HowMany.out");
/*
1. 拷贝构造函数使用场景：1）对象以值传递的方式作为函数入参；2）对象以值传递的方式从函数返回；3）对象需要通过另外一个对象进行初始化
2. 拷贝构造函数的作用： ①对于凡是包含动态分配成员或包含指针成员的类都应该提供拷贝构造函数；②在提供拷贝构造函数的同时，还应该考虑重载"="赋值操作符号。
3. 对拷贝构造函数自己的理解：如果不定义的话就是浅拷贝，只会对数据成员简单的赋值，这样对于有指针设计内存的成员的拷贝就会有问题，就需要用到拷贝构造函数来深拷贝
*/

void increment(int*& i) { i++; } // 引用：指针++，指向下一个地址

struct Big {
  char buf[100];
  int i;
  long d;
} B, B2; //定义了1个数据对象，B2？

Big bigfun(Big b) {
  b.i = 100; // Do something to the argument
  return b;
}

class Data {
public:  
  int a, b, c; 
  void print() const {
    cout << "a = " << a << ", b = " << b
         << ", c = " << c << endl;
  }
};

class A {
  static int i;
public:
  void print() { cout << i << endl;}//...
  void add() {i++;}
};

int A::i = 1;

class HowMany {
  static int objectCount;
public:
  HowMany() { objectCount++; }
  static void print(const string& msg = "") {
    if(msg.size() != 0) out << msg << ": ";
    out << "objectCount = "
         << objectCount << endl;
  }
  HowMany(const HowMany& h) { objectCount++;     
  	out << "copy constructor: objectCount = "
         << objectCount << endl;}  //拷贝构造函数说明时候被调用呢？？？编译器怎么知道，是按值传递或者有对象的拷贝的时候？
         						//

  ~HowMany() {
    objectCount--;
    print("~HowMany()");
  }
};

int HowMany::objectCount = 0;

// Pass and return BY VALUE:
HowMany f(HowMany x) {
  x.print("x argument inside f()");
  return x;
}



int main() {
	int x = 1;
	int& a = x;
	a++;
	//cout <<　"a address = " << &a <<　endl;
	cout << "x address= " << &x << endl;
	cout << "a = "<< a << " x = " << x << endl; 

	int* i = &a;//指针引用
	
    cout << "i = " << i << endl;
    increment(i);
    cout << "i = " << i << endl;

	B2 = bigfun(B);//B代表一种数据类型
	cout << "B2.i= " << B2.i << " B.i= " << B.i << endl; 

	Data d, *dp = &d;
    int Data::*pmInt = &Data::a;
    dp->*pmInt = 47;
    pmInt = &Data::b;
    d.*pmInt = 48;
    pmInt = &Data::c;
    dp->*pmInt = 49;
    dp->print();

    A aa;
    aa.print();
    aa.add();
    aa.print();
    A bb;//静态成员所有对象共有
    bb.print();

    HowMany h;
    HowMany::print("after construction of h");
    HowMany h2 = f(h); //就类对象而言，相同类型的类对象是通过拷贝构造函数来完成整个复制过程的
    HowMany::print("after call to f()");
}