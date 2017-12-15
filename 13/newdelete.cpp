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
int i = 42;

class Obj {
  int i, j, k; // 3*4个byte
  enum mysize { sz = 100 };// 在类里面不占内存？是全局或者静态的？对sz和mysize取地址都不行
  char buf[sz];//100*1个byte
  int *tmp;//大小为8 bytes，因为地址是64bit
  int size;//大小为4 bytes 对对齐为8 byte

public:
  Obj(int num): tmp(NULL),size(num) { 
    tmp = (int*)malloc(sizeof(int)*size);//malloc的基本单位为byte
    for(int i=0; i < size ;i++)
    {
      *(tmp + i)= i+1;
      cout << "tmp +i add= " << (tmp +i) << " tmp + i = " << *(tmp +i)<< endl;
    }
    cout << "constructor:" << " tmp add= "<< tmp << endl;//" sizeof(tmp) " << sizeof(tmp) << " sizeof(size) " << sizeof(size) << endl;
  }

  void initialize() {
    i = 1;j = 2;k = 3;
    memset(buf, 2, sz);
    buf[99] = 9;
    buf[0] = 1;
    cout << "initializing Obj, buf add = " << &buf << " i add= " << &i << endl;
  }

  void destroy() const {
    cout << "destroying Obj" << endl;
  }

  ~Obj() {
    cout << "destructor" << endl;
    //for(int i=0;i < size;i++) {
     //cout << "tmp + i = " << (tmp + i) << " *(tmp + i) ="  << *(tmp + i) << " i ="  << i << endl;
      if(tmp != NULL){
        free(tmp);//只要释放首地址就可以了，释放tmp+i是不允许的。但是free也仅仅表示tmp开始的后面的malloc的sizeof（int）*size可以被重新malloc了
        tmp = NULL;
      }
    //}
  }
};

class obj1 {
  int* i;
};

int main() {

	Obj O1(2); // (1)
  cout << " O1: "<< &O1 << " sizeof(O1)=" << sizeof(O1) << endl;
	O1.initialize();
  ///delete ((Obj*)&O1); 这个对象应该如何释放?貌似delete 和 free都不行, 因为是在栈上，所以不能释放？退出main函数的时候回自动回收

	Obj* O2 = (Obj*)malloc(sizeof(Obj));//(2)
	cout << "sizeof(Obj)= " << sizeof(Obj) << " O2: "<< O2 <<" sizeof(O2) = " << sizeof(O2) << endl;
	O2->initialize();
	O2->destroy();
  free(O2); // 不能用delete, delete只能用于new出来的对象，这里只是释放了对象的内存，有没有包含里面的数据呢？数据没有
  O2 = NULL;

  Obj* O3 = new Obj(10); //(3) 这三种定义新的对象有什么区别？还是都一样？
                     // 答：第一个是直接申明，编译器会自己申请内存，其大小为128，他是在栈上？第二是C的方法，调用malloc.第三个是通过new来在堆上分配内存和调用构造函数
  cout << "O3 = " << O3 << endl;
  O3->initialize();
  cout << "sizeof(O3) = " << sizeof(O3) << endl;//这里只是指针的大小,所以是8
  delete O3; O3 = NULL;//delete会先调用析构函数然后释放内存，释放内存其实也是调用free。 但是malloc和free并不会调用构造和析构函数

}