#include <iostream>
#include "salary.h"

//基类员工类方法
string Employee::GetName() const
{
    return name;
}

EmpLevel Employee::GetLevel() const
{
    return level;
}

int Employee::GetYear() const
{
    return year;
}

int Employee::GetWorkTime() const
{
    time_t t = time(0);
    struct tm* now = localtime(&t);

    return now -> tm_year + 1900 - year +1;
}

//高级员工类方法
int Officer::GetSalary()
{
    return GetWorkTime() * 5000;
}
//普通员工类方法
int Staff::GetSalary()
{
    return GetWorkTime() * 1000;
}

//工资管理类方法
int SalarySys::Read() //读文件
{
    string strName = "";
    int Level = 0, Year = 0;
    int i = 0; //读取数据的个数
    ifstream fin(FileName);
    if(fin.is_open())
    {
        while(1)
        {
            fin >> strName >> Level >> Year;
            if(!fin)  break;
            //根据读取的员工级别分别创建不同的员工对象,并保存到ArraEmp数组进行管理.
            if(Level == enumOfficer)
            {
                ArraEmp[i] = new Officer(strName, Year);
                i++;
            }
            if(Level == enumStaff)
            {
                ArraEmp[i] = new Staff(strName, Year);
                i++;
            }
            if(i>=MAX)  break;
        }
        fin.close();
    }
    else
        cout << "读取时打开文件失败!" << endl;
    cout << "已读取 " << i << " 个员工数据." << endl;
    CountEmp = i;
    return CountEmp;
}

void SalarySys::Write() //写文件
{
    ofstream fout(FileName);
    if(fout.is_open())
    {
        for(int i=0; i<CountEmp; i++)
        {
            Employee *p = ArraEmp[i];
            fout << p -> GetName() << "\t" << p -> GetLevel() << "\t" << p -> GetYear() << endl;
        }
        fout.close();
    }
    else
        cout << "写入时打开文件失败." << endl;
}

void SalarySys::Input()
{
    string strName = "";
    int Level = 0, Year = 0;
    cout << "请输入员工信息(名字 级别(1-高级员工, 2-一般员工) 入职年份),如:Jiangzheng 2 1995" << endl;
    cout << "-1表示输入结束." << endl;
    int i = CountEmp;
    for(; i<MAX; i++)
    {
        cout << "请输入 " << i << " 号员工信息:" << endl;
        if(cin >> strName >> Level >> Year)  //输入正确
        {
            if(strName == "-1") //检查是否输入结束
                break;          //结束输入循环
            if(Level == enumOfficer)
                ArraEmp[i] = new Officer(strName, Year);
            else if(Level == enumStaff)
                ArraEmp[i] = new Staff(strName, Year);
            else
            {
                cout << "员工级别输入错误,请重新输入." << endl;
                cin.clear();  //清理输入标志位
                cin.sync();   //清空键盘缓冲区
                i--;          //本次输入作废,不计算在内
                continue;     //直接开始下一次输入循环
            }
        }
        else                                //输入错误
        {
            cout << "输入有误,请重新输入." << endl;
            cin.clear();  //清理输入标志位
            cin.sync();   //清空键盘缓冲区
            i--;          //本次输入作废,不计算在内
            continue;     //直接开始下一次输入循环
        }

    }
    //输入完毕,调整当前数组中的数据量
    CountEmp = i;
    //SalarySys::Write();
    //return CountEmp;
}

Employee* SalarySys::GetMaxSalary() //获得最高工资的员工对象
{
    Employee *pmax = nullptr;
    int max = INT_MIN;
    for(int i=0; i<CountEmp; i++)
    {
        if(ArraEmp[i] -> GetSalary() > max)
        {
            max = ArraEmp[i] -> GetSalary();
            pmax = ArraEmp[i];
        }
    }

    return pmax;
}

void SalarySys::FindSalary()   //查询员工工资
{
    while(1)
    {
        string strName = "";
        cout << "\n请输入要查询员工的姓名(-1表示结束查询):" << endl;
        if(cin >> strName) //输入正确
        {
            if(strName == "-1")
            {
                cout << "查询完毕,感谢使用." << endl;
                break;
            }
            bool find = false;
            for(int i=0; i<CountEmp; i++)
            {
                if(strName == ArraEmp[i] -> GetName())
                {
                    cout << "员工姓名:" << ArraEmp[i] -> GetName() << endl;
                    cout << "员工工资:" << ArraEmp[i] -> GetSalary() << endl;
                    find = true;
                    break;
                }
            }
            if(!find)
                cout << "无法找到名字为" << strName << "的员工." << endl
                     << "请核对姓名,重新输入." << endl;

        }
        else              //输入错误
        {
            cout << "输入有误,请重新输入." << endl;
            cin.clear();
            cin.sync();
            continue;
        }

    }
}

void SalarySys::ListAll()
{
    cout << "所有员工的信息如下:" << endl;
    Employee *pAll = nullptr;
    for(int i=0; i<CountEmp; i++)
    {
        pAll = ArraEmp[i];
        cout << "\n" << i << "   " << pAll -> GetName() << "\t" << pAll -> GetLevel() << "\t" << pAll -> GetYear() << "\n";
    }
}
























