#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int filterCounter = 0;
    string filter = "cout";
    string word;
    
    ifstream in("filterWordCounter.cpp");
    if(!in)
    {
        cout << "File open failed!!!" << endl;
        return 0;
    }
    
    while(!in.eof())
    {
        if(in >> word)
            if(word == filter)
                filterCounter++;
    }
    cout << "Filter word is:\"" << filter << "\", " << "Counter is: " << filterCounter << endl;
}
