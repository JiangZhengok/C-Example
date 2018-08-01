#include <iostream>
#include "../include/BuyTicket.h"

using namespace std;

void Human::BuyTicket()
{
    cout << "人买票." << endl;
}

void Teacher::BuyTicket()
{
    cout << "老师买票." << endl;
}

void Student::BuyTicket()
{
    cout << "学生买票." << endl;
}
