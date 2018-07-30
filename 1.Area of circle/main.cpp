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
	double GetArea() const;  //��Ա��������Ϊֻ��

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
	cout << "Ĭ��Բ�İ뾶Ϊ��"<< Circle1.GetR() << endl;
	cout << "���Ĭ��Բ�����Ϊ��"<<Circle1.GetArea() << endl;

	cout << "��������һ��Բ�İ뾶r = ";
	cin >> r;
	cout << "��Բ�İ뾶Ϊ��" << r << endl;

	Circle Circle2(r);
	cout << "��Բ�����Ϊ��" << Circle2.GetArea() << endl;

	return 0;
}
