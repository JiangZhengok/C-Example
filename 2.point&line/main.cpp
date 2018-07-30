#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
	Point(int xx=0, int yy=0) {X=xx;Y=yy;}
	//Point(Point &p); //��������
	//~Point() {cout << "��������������1" << endl;}
	int GetX() {return X;}
	int GetY() {return Y;}
private:
	int X,Y;
};

//Point::Point(Point &p)
//{
//	X = p.X;
//	Y = p.Y;
//	cout << "�ѿ���" << endl;
//}
//������
class Line
{
public:
	Line(Point xp1, Point xp2);//���캯��
	Line(Line &p);  //��������
	//~Line() {cout << "��������������2" << endl;}
	double GetLen() {return len;}

private:
	Point p1,p2;
	double len;
};
//��������๹�캯��
Line::Line(Point xp1, Point xp2):p1(xp1),p2(xp2)
{
	cout << "Line���캯��������" << endl;
	double x = double(p1.GetX()-p2.GetX());
	double y = double(p1.GetY()-p2.GetY());
	len = sqrt(x*x+y*y);
}
//����࿽������ʵ��
Line::Line(Line &L):p1(L.p1),p2(L.p2)
{
	cout << "Line��������������" << endl;
	len =L.len;
}

int main()
{
    Point myp1(1,1),myp2(4,5);
    Line myline1(myp1,myp2);
    Line myline2(myline1);

	cout << "myline1����ʼ�������ֹ����Ϊ��(" << myp1.GetX() << "," << myp1.GetY() <<")  "
										   "(" << myp2.GetX() << "," << myp2.GetY() <<")"<<endl;
    cout << "myline1�ĳ����ǣ�"<< myline1.GetLen()<< endl;
    cout << "myline2����ʼ�������ֹ����Ϊ��(" << myp1.GetX() << "," << myp1.GetY() <<")  "
										   "(" << myp2.GetX() << "," << myp2.GetY() <<")"<<endl;
    cout << "myline2�ĳ����ǣ�"<< myline2.GetLen()<< endl;
    return 0;
}
