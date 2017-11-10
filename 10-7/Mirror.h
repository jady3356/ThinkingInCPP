#include <iostream>

class Mirror {
public:
	Mirror(): b(true),  Mo(0) { std::cout << "Mirri()" << " " << b << " Mo address: "<< Mo << std::endl; };
	Mirror(Mirror* p): b(false), Mo(p) {std::cout << "Mirri(Mirror* p)"<< " "<< " Mo address: "<< Mo << std::endl;};
	virtual ~Mirror() {};
	bool test() { return Mo == 0 ? b : Mo->test();};
private:
	Mirror* Mo;
	bool b;
};

