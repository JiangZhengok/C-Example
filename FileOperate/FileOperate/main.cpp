#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int nYear, nMonth, nDay;
    ifstream fin("../Data.txt");
    if(fin.is_open())
    {
        fin >> nYear >> nMonth >> nDay;
        cout << "文件中记录的日期是:\t" << nYear << "-" << nMonth << "-" << nDay << endl;
        fin.close();
    }
    else
        cout << "无法打开文件并进行读取." << endl;

    cout << "请输入新日期:" << endl;
    cin >> nYear >> nMonth >> nDay;

    ofstream fout("../Data.txt");
    if(fout.is_open())
    {
        fout << nYear << " " << nMonth << " " << nDay;
        fout.close();
    }
    else
        cout << "无法打开文件并进行写入." << endl;

    return 0;
}

