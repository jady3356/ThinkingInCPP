#include<iostream>
using namespace std;
/*
(1)  全局静态对像的构造函数在main()之前调用
(2)  静态数据成员： 所有对象的静态成员共享同一个静态存储区，为这些对象提供了一个通信的方法
(3)  静态成员函数： 只能访问静态数据成员，也只能调用静态成员函数
*/
int a[5] = {1, 2, 3, 4, -1};

int test(int p = 0) {
    static int  *pointer = a;

    if ( (p == 0) && (*pointer != -1)) {
	    pointer++;
    }
    else if(p != 0) {
    	pointer = a;
    }
    cout << pointer << ": "<< *pointer <<endl;
}

int fibonacci(int n, bool f = false){
	if((n == 1) || (n == 2) || (f == true))
		return 1;
	return fibonacci(n-1) + fibonacci(n-2);
}

class monitor {
	int i;
public:
	monitor() { i = 0;}
	void incident() { ++i; cout << i << " incident()" << endl;}
	void decrement() { --i; cout << i << " decrement()" << endl;}
	void print() {
		cout << i <<endl;
	}
};

class monitor2 {
	monitor *p;
public:
	monitor2(monitor *m1p) { p = m1p; p->incident(); p->print();}
	~monitor2() {p->decrement(); p->print();}
};

monitor om1;

monitor2 om2(&om1);

void testM() {
	static monitor2 m2(&om1);
}

int main() {
	test(0);
	test(0);
    test(0);
    test(0);
    test(0);
    test(0);
	test(1);
	test(2);
	test(3);
	test(4);
for(int i = 1; i < 9; i++)
	cout << fibonacci(i) << endl;
	monitor m;
	//monitor::i = 0;
for(int i = 1; i < 9; i++)	
	m.incident();
    m.print();
for(int i = 1; i < 8; i++)
	testM();
}