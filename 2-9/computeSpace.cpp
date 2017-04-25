#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int space = 0;
    char c;
    
    ifstream in("computeSpace.cpp");
    if(!in)
    {
        cout << "File open failed!!!" << endl;
        return 0;
    }
    while(in)
    {
        in.get(c);
        if(c == ' ')
        {
            space++;
            cout << "*";
        }
        else 
        {
            cout << " ";
        }
    }
    cout << "Number of space in this file is: "<< space << endl;
}
