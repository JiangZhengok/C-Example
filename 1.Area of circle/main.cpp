#include <iostream>
#include <string>
#define pi 3.14

using namespace std;

class Circle
{
public:
	Circle(double radius) {Radius = radius;}
	Circle(Circle &C);
	~Circle() { };

	double GetR() {return Radius;}
	double GetArea() const;  //成员函数设置为只读

private:
	double Radius;
};

Circle::Circle(Circle &C)
{
	C.Radius = Radius;
}

double Circle::GetArea() const
{
	return pi*Radius*Radius;
}
int main()
{
	double r;
	Circle Circle1(2);
	cout << "默认圆的半径为："<< Circle1.GetR() << endl;
	cout << "求得默认圆的面积为："<<Circle1.GetArea() << endl;

	cout << "请输入另一个圆的半径r = ";
	cin >> r;
	cout << "此圆的半径为：" << r << endl;

	Circle Circle2(r);
	cout << "此圆的面积为：" << Circle2.GetArea() << endl;

	return 0;
}
