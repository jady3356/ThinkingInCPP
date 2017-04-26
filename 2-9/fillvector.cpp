#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ncurses.h>
using namespace std;

int main()
{
    vector<string> v;
    string s,l;
    int index = 0;
    char inputkey;
    
    ifstream in("fillvector.cpp");
    while(getline(in, s))
    {
        v.push_back(s);
        cout << s;
        while(getchar() != '\n')
        {;}
    }
    //cout << l << endl;
    //cout << v[index++] << endl;
    //for(;;)
    //{
        //if((getchar() == '\n') && (index < v.size()))
        //{
        //   cout << v[index++];
        //}
    //}
        
    //for(int i = v.size() - 1; i >= 0; i-- )
        //cout << v[i] << endl;
    //cin >> inputkey;
    //cout << inputkey;
    //if(getchar() == '\r')
        //cout << "enter" << endl;
    
    
    #if 0
    for(;;)
    {
        //index = v.size();
        //cin >> inputkey;
        inputkey = getch();
        cout << dec << (int)inputkey << endl;
        
        
        if((inputkey == -1) && (index < v.size()))
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
     #endif
}
