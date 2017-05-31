#include <iostream>
#include <string>

using namespace std;

class message {
    string priStr;
    public:
        message(string input);
        void print();
        void print(string str);
}; 

message::message(string input) {
    priStr = input;
}

void message::print() {
    cout << priStr << endl;
}

void message::print(string str) {
    cout << str << " + " << priStr << endl;
}

int main() {
    message msg("test");
    //msg.message("test"); will report compile error!!!
    msg.print();
    msg.print("aaa");
}