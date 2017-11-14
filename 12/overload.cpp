#include <iostream>
using namespace std;

/*
运算符重载的使用场景：　由于一般数据类型间的运算符没有重载的必要，所以运算符重载主要是面向对象之间的。通过重载可以把功能相似的几个函数合为一个，使得程序更加简洁、高效。
自己的理解： 就是为方便快捷的操作类对象而生，对于一般的对象不需要。它只是另一种形式的函数而已

*/

class Integer {
  int i;
public:
  Integer(int ii) : i(ii) {}
  const Integer
  operator+(const Integer& rv) const {
    cout << "operator+: i = " << i << " rv.i=" << rv.i << endl;
    return Integer(i + rv.i);
  }
  Integer&
  operator+=(const Integer& rv) {
    cout << "operator+=: i = " << i << " rv.i=" << rv.i << endl;;
    i += rv.i;
    //cout << "operator+=: i = " << i << " rv.i=" << rv.i << endl;;
    return *this;
  }
  void print() {cout << i << endl;}
};

int main() {
  cout << "built-in types:" << endl;
  int i = 1, j = 2, k = 3;
  k += i + j;
  cout << "user-defined types:" << endl;
  Integer ii(2), jj(4), kk(3);
  kk += ii + jj; //ii.operator+(Integer jj)---成员函数，ii被当做第一个参数，所以i用的是ii的初值
  kk.print();
} ///:~