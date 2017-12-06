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
} B, B2; //定义了名字为Big的结构，同时申明了2个数据对象，B2和B

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
  /*    引用
    (1) 定义：为一个变量（目标）设置别名，对引用的操作与对变量的操作一样;申明时必须同时初始化
    (2) 适用场景：1.作为函数的入参或返回值，会提高效率，因为直接对实参操作，不需要拷贝行参为其分配内存副本，有点类似指针，但是指针也是形参，需要拷贝副本；
                 2.常（const）引用，函数入参是引用时尽量使用const；
                 3.引用作为函数返回值，好处是内存中不会产生返回值的副本。注意：不能返回局部变量的引用；不能返回new出来的mem的引用。
  */
  int x = 1;
	int& a = x;// a是x的引用，引用就是a和x的绑定，a是x的别名
	a++;
	cout << "x address= " << &x << endl;
	cout << "a = "<< a << " x = " << x << endl; 

	int* i = &a;//指针引用,用p对引用a取地址
  cout << "i = " << i << endl;//a是x的引用，所以他们的地址一样
  increment(i);
  cout << "i = " << i << endl;

	B2 = bigfun(B);//B是一个Big的数据类型
	cout << "B2.i= " << B2.i << " B.i= " << B.i << endl; //这里的入参B.i不会被改写？

	Data d, *dp = &d;
  int Data::*pmInt = &Data::a;//定义整型的成员指针pm，并让其指向类成员a的地址
  dp->*pmInt = 47; 
  pmInt = &Data::b;//pm重新指向b成员
  d.*pmInt = 48;
  pmInt = &Data::c;//pm重新指向c成员
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