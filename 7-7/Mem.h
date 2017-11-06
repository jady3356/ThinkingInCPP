//: Mem.h
#ifndef MEM_H
#define MEM_H
typedef unsigned char byte;

class Mem {
	byte* mem;
	int size;
	void ensureMinsize(int minSize);
public:
	Mem();
	Mem(int sz);
	~Mem();
	int msize();
	byte* pointer();
	byte* pointer(int minSize);
};
#endif //MEM_H //:~