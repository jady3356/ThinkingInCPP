//: Mem.cpp
#include"Mem.h"
#include<cstring>
#include<iostream>
using namespace std;

Mem::Mem() { mem = 0; size = 0; cout << "Mem::Mem(), Constructor Mem()" << endl;}

Mem::Mem(int sz) {
	mem = 0;
	size = 0;
	ensureMinsize(sz);
	cout << "Mem::Mem(int sz), Constructor Mem(int sz)" << endl;
}

Mem::~Mem() { delete []mem; }

int Mem::msize() { return size; }

void Mem::ensureMinsize(int minSize) {
	if(size < minSize){
		byte* newmem = new byte[minSize];
		cout << "Mem::ensureMinsize(int minSize), newmem address: " << newmem
		<< " minSize = "<< minSize 
		<< " Size=" << size << endl;
		memset(newmem + size, 0, minSize - size);
		memcpy(newmem, mem, size);
		delete []mem;
		mem = newmem;
		size = minSize;
	}
}

byte* Mem::pointer() { //cout << "Mem::pointer(), mem address: " << dec << mem << endl;
    return mem; 
}
byte* Mem::pointer(int minSize) {
	ensureMinsize(minSize);
	//cout << "Mem::pointer(int minSize), mem address: " << hex << &mem << endl;
	return mem;
}///:~