#include <iostream>
#include <cstdlib> 
#include <cstring>
/*
首先，平时所声明的类只是一种类型定义，它本身是没有大小可言的。 因此，如果用sizeof运算符对一个类型名操作，那得到的是具有该类型实体的大小。
（一）类内部的成员变量：
普通的变量：是要占用内存的，但是要注意内存对齐（这点和struct类型很相似）。
static修饰的静态变量：不占用内存，原因是编译器将其放在全局变量区。
从父类继承的变量：计算进子类中
（二）类内部的成员函数：
非虚函数(构造函数、静态函数、成员函数等)：不占用内存。
虚函数：要占用4个字节(32位的操作系统)，用来指定虚拟函数表的入口地址。跟虚函数的个数没有关系。父类子类共享一个虚函数指针
*/
using namespace std;

class Obj {
  int i, j, k; // 3*4个byte
  enum { sz = 100 };
  char buf[sz];//100*1个byte
public:
  void initialize() { // Can't use constructor
    i = j = k = 0;
    memset(buf, 0, sz);
    cout << "initializing Obj, buf add = " << &buf << endl;
  }
  void destroy() const { // Can't use destructor
    cout << "destroying Obj" << endl;
  }
};

class obj1 {
  int* i;
};

int main() {
  //cout << "sizeof(obj1)" << sizeof(obj1) << endl;
	Obj O1; // (1)
	O1.initialize();
	cout << " O1: "<< &O1 << " sizeof(O1)" << sizeof(O1) << endl;
  ///delete ((Obj*)&O1); 这个对象应该如何释放?貌似delete 和 free都不行
	Obj* O2 = (Obj*)malloc(sizeof(Obj));//(2)
	cout << "sizeof(Obj)= " << sizeof(Obj) << " O2: "<< O2 <<" sizeof(O2) = " << sizeof(O2) << endl;
	O2->initialize();
	O2->destroy();
  free(O2); // 不能用delete, delete只能用于new出来的对象，这里只是释放了对象的内存，有没有包含里面的数据呢？
  Obj* O3 = new Obj; //(3) 这三种定义新的对象有什么区别？还是都一样？
                     // 答：第一个是直接申明，编译器会自己申请内存，其大小为112，他是在栈上？第二是C的方法，调用malloc.第三个是通过new来在堆上分配内存和调用构造函数
  O3->initialize();
  cout << "O3 = " << O3 << endl;
  cout << "sizeof(O3) = " << sizeof(O3) << endl;//这里只是指针的大小,所以是8
  delete O3; O3 = NULL;//delete会先调用析构函数然后释放内存，释放内存其实也是调用free
}