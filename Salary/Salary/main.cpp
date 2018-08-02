#include <iostream>
#include "salary.h"

//using namespace std;

int main()
{
    SalarySys sys;
    int a;
    while(1)
    {
        cout << "\n请输入正确的数字选择所需要的功能:\n"
             << "0  列出所有员工信息.\n"
             << "1  查找员工工资.\n"
             << "2  查找工资最高的员工.\n"
             << "3  输入新员工信息并存档.\n"
             << "9  退出系统.\n";
        if(cin >> a)
        {
            switch(a)
            {
                case 0:
                {
                    sys.ListAll();
                    break;
                }
                case 1:
                {
                    sys.FindSalary();
                    break;
                }
                case 2:
                {
                    Employee *pMax = sys.GetMaxSalary();
                    if(pMax != nullptr)
                    {
                        cout<<"\n工资最高的员工是："<<endl;
                        cout<<"名字："<<pMax->GetName()<<endl;
                        cout<<"工资："<<pMax->GetSalary() << endl;
                    }
                    break;
                }
                case 3:
                {
                    sys.Input();
                    break;
                }
                case 9:
                {
                    break;
                }
                default:
                {
                    cout << "输入有误,重新输入!\n";
                    break;
                }
            }

            if(a==9)  break;
        }
        else
        {
            cout << "请输入数字." << endl;
            cin.clear(); //将错误状态更改为有效状态
            //cin.sync();  //清空缓存区
            cin.ignore(); //忽略缓冲区中指定个数的字符
         }
    }

    return 0;
}
