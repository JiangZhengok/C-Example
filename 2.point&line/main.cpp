#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
	Point(int xx=0, int yy=0) {X=xx;Y=yy;}
	//Point(Point &p); //拷贝函数
	//~Point() {cout << "析构函数被调用1" << endl;}
	int GetX() {return X;}
	int GetY() {return Y;}
private:
	int X,Y;
};

//Point::Point(Point &p)
//{
//	X = p.X;
//	Y = p.Y;
//	cout << "已拷贝" << endl;
//}
//类的组合
class Line
{
public:
	Line(Point xp1, Point xp2);//构造函数
	Line(Line &p);  //拷贝函数
	//~Line() {cout << "析构函数被调用2" << endl;}
	double GetLen() {return len;}

private:
	Point p1,p2;
	double len;
};
//定义组合类构造函数
Line::Line(Point xp1, Point xp2):p1(xp1),p2(xp2)
{
	cout << "Line构造函数被调用" << endl;
	double x = double(p1.GetX()-p2.GetX());
	double y = double(p1.GetY()-p2.GetY());
	len = sqrt(x*x+y*y);
}
//组合类拷贝函数实现
Line::Line(Line &L):p1(L.p1),p2(L.p2)
{
	cout << "Line拷贝函数被调用" << endl;
	len =L.len;
}

int main()
{
    Point myp1(1,1),myp2(4,5);
    Line myline1(myp1,myp2);
    Line myline2(myline1);

	cout << "myline1的起始坐标和终止坐标为：(" << myp1.GetX() << "," << myp1.GetY() <<")  "
										   "(" << myp2.GetX() << "," << myp2.GetY() <<")"<<endl;
    cout << "myline1的长度是："<< myline1.GetLen()<< endl;
    cout << "myline2的起始坐标和终止坐标为：(" << myp1.GetX() << "," << myp1.GetY() <<")  "
										   "(" << myp2.GetX() << "," << myp2.GetY() <<")"<<endl;
    cout << "myline2的长度是："<< myline2.GetLen()<< endl;
    return 0;
}
