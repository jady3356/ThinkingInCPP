#include "stash.h"
#include "stack.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    Stash intStash;
    intStash.initialize(sizeof(int));
    for(int i = 0; i < 10; i++)
        intStash.add(&i);
    for(int j = 0; j < intStash.count(); j++)
        cout << "intStash.fetch(" << j << ") = "
             << *(int*)intStash.fetch(j)
             << ",Size of intStash = " << (int)(sizeof(intStash.size))
             << endl;
    intStash.cleanup();

    Stash doubleStash;
    doubleStash.initialize(sizeof(double));
    for(int k = 0; k < 10; k++)
        doubleStash.add(&k);
    for(int m = 0; m < doubleStash.count(); m++)
        cout << "doubleStash.fetch(" << m << ") = "
             << *(int*)doubleStash.fetch(m)
             << ",Size of doubleStash = " << (int)(sizeof(doubleStash.storage))
             << endl;
    doubleStash.cleanup();
    
    Stack intStack;
    intStack.initialize();
    
    for(int x = 0; x < 10; x++)
    {
        //int input;
        //new int(input);
        //*input = x;
        intStack.push(&x);
        //delete input;
    }
    for(int y = 0; intStack.peek() != 0; y++)
        cout << "intStack.pop(" << y << ") = "
             << *(int*)intStack.pop()
             << ",Size of intStack = " << (int)(sizeof(intStack))
             << endl;
    intStack.cleanup();
    
}