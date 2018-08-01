#include <iostream>
#include "../include/BuyTicket.h"

using namespace std;

int main()
{
    Human *p1 = new Teacher();
    Human *p2 = new Student();

    p1 -> BuyTicket();
    p2 -> BuyTicket();

    delete p1;
    delete p2;

    p1 = p2 = nullptr;

    return 0;
}

