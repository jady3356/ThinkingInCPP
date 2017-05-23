#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class text {
string str;
vector<string> v;
public:
    void read();
    void read(char* filename);
    string contents(int index);

};

void text::read(char* filename) {
    ifstream in(filename);
    while(getline(in, str)) 
        v.push_back(str);
    //cout << v.size();
    //return v.size();
}

string text::contents(int index) {
    if(index < v.size())
       return v[index];
    return "EOD";
}

int main()
{
    char* filename = "text.cpp";
    text txt;
    txt.read(filename);
    int i = 0;
    while(txt.contents(i) != "EOD")
        cout << txt.contents(i++) << endl;
}