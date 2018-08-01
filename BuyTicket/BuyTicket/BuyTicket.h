#ifndef _BUYTICKET_H_
#define _BUYTICKET_H_

#include <iostream>
using namespace std;

//定义human类
class Human
{
public:
    virtual void BuyTicket() = 0;

};

//派生类,表示老师和学生
class Teacher : public Human
{
public:
    virtual void BuyTicket() override; //重新定义基类接口函数
};

class Student : public Human
{
public:
    virtual void BuyTicket() override;
};

#endif // BUYTICKET

