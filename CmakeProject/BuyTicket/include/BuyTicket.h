#ifndef BUYTICKET
#define BUYTICKET

#include <iostream>
using namespace std;

//定义human类
class Human
{
public:
    void BuyTicket();
};

//派生类,表示老师和学生
class Teacher : public Human
{
public:
    void BuyTicket(); //重新定义基类接口函数
};

class Student : public Human
{
public:
    void BuyTicket();
};

#endif // BUYTICKET

