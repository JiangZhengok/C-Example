/*********** 1 *****************/
/*#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
	Complex &operator = (const string &s)
	{
		int position = s.find("+", 0);
		string firstpart = s.substr(0, position);
		string secondpart = s.substr(position+1, s.size() - position - 2);
		r = atof(firstpart.c_str());
		i = atof(secondpart.c_str());
		return *this;
	}
};

int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}*/

/*********** 2 ***************/
/*#include <iostream>

using namespace std;

class MyInt {
    int nVal;
    public:
        MyInt(int n) { nVal = n; }
        int ReturnVal() { return nVal; }
// 在此处补充你的代码
	MyInt &operator - (const int &obj)
	{
		nVal -= obj;
		return *this;
	}

};

int main () {
    MyInt objInt(10);
    objInt-2-1-3;
    cout << objInt.ReturnVal();
    cout <<",";
    objInt-2-1;
    cout << objInt.ReturnVal();
    return 0;
}*/

/************ 3 **************/
/*#include <iostream>
#include <cstring>

using namespace std;

// 在此处补充你的代码
class Array2 {
private:
    int * a;
    int i, j;
public:
    Array2() {a = NULL;}
    Array2(int i_, int j_) {
        i = i_;
        j = j_;
        a = new int[i*j];
    }
    Array2(Array2 &t){
        i = t.i;
        j = t.j;
        a = new int[i * j];
        memcpy(a, t.a, sizeof(int)*i*j);
    }
    Array2 & operator=(const Array2 &t) {
        if (a != NULL) delete []a;
        i = t.i;
        j = t.j;
        a = new int[i*j];
        memcpy(a, t.a, sizeof(int)*i*j);
        return *this;
    }
    ~Array2() {if (a != NULL) delete []a;}
    // 将返回值设为int的指针，则可以应用第二个【】，不用重载第二个【】操作符
    int *operator[](int i_) {
        return a+i_*j;
    }
    int &operator()(int i_, int j_) {
        return a[i_*j + j_];
    }
};

int main()
{
    Array2 a(3,4);

    int i,j;
    for( i = 0;i < 3; ++i )
        for( j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;

    for( i = 0;i < 3; ++i )
	{
        for( j = 0; j < 4; j ++ )
            cout << a(i,j) << ",";

        cout << endl;
    }
    cout << "next" << endl;

    Array2 b;
	b = a;
    for( i = 0;i < 3; ++i )
	{
        for( j = 0; j < 4; j ++ )
            cout << b[i][j] << ",";
        cout << endl;
    }
    return 0;
}*/











