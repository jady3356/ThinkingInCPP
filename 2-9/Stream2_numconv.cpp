#include<iostream>
using namespace std;

int main()
{
    float r = 0;
    float s = 0;
    
    cout << "Please input the radius of circle:  ";
    cin >> r;
    if(r > 0)
    {
        cout << "The area of circle is: " 
             << r*r*3.1415926 << endl;
        return 0;
    }
    cout << "Invalid input, r < 0" << endl;
}
