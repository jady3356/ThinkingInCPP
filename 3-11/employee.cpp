#include "employee.h"
employee::employee(string s, int n)
{
    name = s;
    num = n;
}
int employee::getnum()
{
    return num + 1;
}
