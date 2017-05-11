#include <iostream>
#include <string>
using namespace std;

class Hen
{
    //void display();
    string name;
    public:
        void display();
        class Nest
        {
            //void display();
            string egg;
            public:
                void display();
        };
};

void Hen::display()
{
    name = "Hen";
    cout << "Hen display: " << name << endl;
}

void Hen::Nest::display()
{
    egg = "Egg";
    cout << "Nest display: " << egg << endl;
}

int main()
{
    Hen testHen;
    Hen::Nest testNest;
    testHen.display();
    testNest.display();
}