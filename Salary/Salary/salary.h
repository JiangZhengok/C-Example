#ifndef SALARY
#define SALARY

#include <ctime>
#include <string>
#include <fstream>
#include <climits>

using namespace std;
const int MAX = 100000;

enum EmpLevel
{
    enumOfficer = 1,
    enumStaff = 2
};

//员工类
class Employee
{
public:
    Employee(string Name, int Year) : name(Name), year(Year) { }

    string GetName() const;
    int GetYear() const;
    EmpLevel GetLevel() const;

    virtual int GetSalary() = 0;

protected:
    int GetWorkTime() const;

protected:
    string name;
    int year;
    EmpLevel level;
};

//高级员工类
class Officer : public Employee
{
public:
    Officer(string Name, int Year) : Employee(Name, Year)
    {
        level = enumOfficer;
    }

    virtual int GetSalary() override;
};

//普通员工类
class Staff : public Employee
{
public:
    Staff(string Name, int Year) : Employee(Name, Year)
    {
        level = enumStaff;
    }

    virtual int GetSalary() override;
};

class SalarySys
{
private:
    const string FileName;
    Employee *ArraEmp[MAX];
    int CountEmp;

public:
    //构造函数,对属性进行初始化
    SalarySys() : CountEmp(0), FileName("SalaryData.txt")
    {
        for(long i=0; i<MAX; ++i)
            ArraEmp[i] = nullptr;
        Read();
    }
    //析构函数,完成清理工作
    ~SalarySys()
    {
        Write(); //将员工数据写入文件,以备下次读取
        for(long i=0; i<CountEmp; ++i)  //释放数组中已经创建的员工对象
        {
            delete ArraEmp[i];
            ArraEmp[i] = nullptr;
        }
    }

    int Read();     //读取已经输入的文件
    void Write();   //将员工数据写入文件,析构函数调用
    void Input();    //手工输入员工数据
    Employee *GetMaxSalary();  // 获得最高工资的员工对象
    void FindSalary();         // 查询员工工资
    void ListAll();            //列出所有员工的信息
};

#endif // SALARY
























