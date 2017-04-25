#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <conio>
using namespace std;

int main()
{
    vector<string> v;
    string s;
    int index = 0;
    char inputkey;
    
    ifstream in("fillvector.cpp");
    while(getline(in, s))
        v.push_back(s);
    //for(int i = v.size() - 1; i >= 0; i-- )
        //cout << v[i] << endl;
    //cin >> inputkey;
    //cout << inputkey;
    //if(getchar() == '\r')
        //cout << "enter" << endl;
    for(;;)
    {
        //index = v.size();
        cin >> inputkey;
        cout << dec << (int)inputkey << endl;
        
        if((inputkey == 'n') && (index < v.size()))
        {
            cout << v[index++] << endl;
        }
        else
        {
            cout << "End of file." << endl;
            return 0;
        }
        
        //index++;
        //return 0;
    }
}
