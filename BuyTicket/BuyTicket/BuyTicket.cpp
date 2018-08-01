#include <iostream>
#include "BuyTicket.h"

using namespace std;

//void Human::BuyTicket()
//{
//    cout << "人买票." << endl;
//}

void Teacher::BuyTicket()
{
    cout << "老师投币买票." << endl;
}

void Student::BuyTicket()
{
    cout << "学生刷卡买票." << endl;
}
