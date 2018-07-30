#include<iostream>
#include<cmath>

using namespace std;

class Point
{
  public:
     Point(int xx=0,int yy=0) { X=xx; Y=yy; }
     int GetX() { return X; }
     int GetY() { return Y; }
     friend float fDist(Point &p1,Point &p2); //友元函数声明

  private:
     int X,Y;
};

float fDist(Point &p1,Point &p2)//友元函数实现
{
     double x=double(p1.X-p2.X);  //通过对象访问私有数据成员
     double y=double(p1.Y-p2.Y);

     return float(sqrt(x*x+y*y));
}

int main()
{
     int x1,y1,x2,y2;
     Point myp1(1,1),myp2(4,5);//定义Point类的对象
     cout<<"The distance is : "<<fDist(myp1,myp2)<<endl<<endl;//计算两点间的距离

     cout<<"请输入第一个点的坐标（x1,y1）： ";
     cin>>x1>>y1;
     cout<<"请输入第二个点的坐标（x2,y2）： ";
     cin>>x2>>y2;
     Point youp1(x1,y1),youp2(x2,y2);
     cout<<"The distance is : "<<fDist(youp1,youp2)<<endl;//计算两点间的距离

     return 0;
}
