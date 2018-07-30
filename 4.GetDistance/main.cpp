#include<iostream>
#include<cmath>

using namespace std;

class Point
{
  public:
     Point(int xx=0,int yy=0) { X=xx; Y=yy; }
     int GetX() { return X; }
     int GetY() { return Y; }
     friend float fDist(Point &p1,Point &p2); //��Ԫ��������

  private:
     int X,Y;
};

float fDist(Point &p1,Point &p2)//��Ԫ����ʵ��
{
     double x=double(p1.X-p2.X);  //ͨ���������˽�����ݳ�Ա
     double y=double(p1.Y-p2.Y);

     return float(sqrt(x*x+y*y));
}

int main()
{
     int x1,y1,x2,y2;
     Point myp1(1,1),myp2(4,5);//����Point��Ķ���
     cout<<"The distance is : "<<fDist(myp1,myp2)<<endl<<endl;//���������ľ���

     cout<<"�������һ��������꣨x1,y1���� ";
     cin>>x1>>y1;
     cout<<"������ڶ���������꣨x2,y2���� ";
     cin>>x2>>y2;
     Point youp1(x1,y1),youp2(x2,y2);
     cout<<"The distance is : "<<fDist(youp1,youp2)<<endl;//���������ľ���

     return 0;
}
