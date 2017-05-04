//: stash.h
// C-like library convert to C++

struct Stash {
    int size;      //Size of each space
    int quantity;  //Number of storage spaces
    int next;
    unsigned char* storage;
    void initialize(int size);
    void cleanup();
    int add(const void* element);
    void* fetch(int index);
    int count();
    void inflate(int increase);
};///:~