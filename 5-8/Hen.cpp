#include <iostream>
#include <string>
using namespace std;

class Hen
{
    string hen;
    public:
        struct Nest;
        friend class Nest;
        void display();
        
        class Nest
        {
            string nest;
            Hen* h;
            string n;
            public:
                class Egg
                {
                    string egg;
                    public:
                        void display();
                };
                void display(Hen* h);
        };
};

void Hen::display()
{
    hen = "Hen";
    cout << "Hen display: " << hen << endl;
}

void Hen::Nest::display(Hen* rv)
{
    nest = "Nest";
    h = rv;
    n = h->hen;
    //n = "test";
    cout << "Nest display: " << nest << " and " << n << endl;
}

void Hen::Nest::Egg::display()
{
    egg = "Egg";
    cout << "Egg display: " << egg << endl;
}

int main()
{
    Hen testHen;
    Hen::Nest testNest;
    Hen::Nest::Egg testEgg;
    testHen.display();
    testNest.display(&testHen);
    testEgg.display();
}