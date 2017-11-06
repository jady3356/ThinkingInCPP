//: TestMem.cpp
#include"Mem.h"
#include<cstring>
#include<iostream>

using namespace std;
enum class ENUMTEST: short {ONE, TWO};

class MyString {
	Mem* buf;
	char* intialList;
public:
	MyString();
	MyString(char* str);
	~MyString();
	void concat(char* str);
	void print(ostream& os);
};

MyString::MyString() { buf = 0; cout << "MyString::MyString()" << endl;}

MyString::MyString(char* str):  intialList(str){ // 内部类型也可以看成一个构造函数: intialList()
	buf = new Mem(strlen(str) + 1);
	//cout << "MyString::MyString(char* str), " << "buf address:" << dec << buf << " intialList= " << intialList << endl;
	//printf(" buf %p ", buf);
	strcpy((char*)buf->pointer(), str);
}

void MyString::concat(char* str) {
	if(!buf) buf = new Mem;
	cout << "MyString::concat(char* str), " << "buf address: " << hex << buf << endl;
	strcat((char*)buf->pointer(buf->msize() + strlen(str) + 1), str);
}

void MyString::print(ostream& os) {
	if(!buf) return;
	os << " buf address: " << hex << buf << " " << buf->pointer() << endl;
}

MyString::~MyString() { delete buf; }
 
int main() {
	MyString s = "My test string";// 构造函数&重载：带入参的初始化，调用MyString(char* str), 
								  // s = "My test string" == s("My test string"), = 表示初始化，等同于调用带参数的初始化构造函数
	cout << "s size: " << sizeof(s) << ", s address: " << hex << &s << endl; 
	//printf(" s %p", s);
	s.print(cout);
	s.concat(", some addition staff");
	s.print(cout);
	MyString s2;// 构造函数&重载：不带入参的初始化，调用MyString()
	cout << "s2 size: " << sizeof(s2) << ", s2 address: " << hex << &s2 << endl; 
	s2.concat("Using default constructor");
	s2.print(cout);
} ///:~