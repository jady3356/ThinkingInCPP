#include <iostream>
using namespace std;

struct Test {
    int var1;
    int func1(Test* input1, int input2)
    {
        cout << "Test::func1, input2=" << input2 << "Test.var1 = " << input1->var1 << endl;
    }

    int func2(Test* input1)
    {
        cout << "Test::func2, input.var1=" << input1->var1 <<endl;
    }
};

int globalFucn1(Test* input1, int input2)
{
    cout << "globalFucn1,input1.var1=" << input1-> var1 << endl;
}

int globalFucn2(Test* input1)
{
    cout << "globalFucn2, input.var1=" << input1->var1 <<endl;
}

int main()
{
    Test A;
    A.var1 = 1;
    A.func1(&A, 3);
    A.func2(&A);
    Test B;
    B.var1 = 2;
    globalFucn1(&B, B.var1);
    globalFucn2(&B);
    globalFucn1(&A, A.var1);
    globalFucn2(&A);
}