#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;
const double PI = 3.14;

class CShapes
{
public:
	double aera;
	virtual double CShapesAera() = 0;
	virtual void CPrintAera() = 0;
};

class CRec : public CShapes
{
public:
	int length, width;
	double aera;

	CRec(int l, int w, double a=0) : length(l), width(w), aera(a) { }
	~CRec() {}
	virtual double  CShapesAera()
	{
		aera = length * width;
		return aera;
	}
	virtual void CPrintAera()
	{
		cout << "Rectangle: " << CShapesAera() << endl;
	}
};

class CCircle : public CShapes
{
public:
	int r;
	double aera;
	CCircle(int r_, double aera_) : r(r_), aera(aera_) {}
	~CCircle() {}
	virtual double CShapesAera()
	{
		aera = PI * r * r;
		return aera;
	}
	virtual void CPrintAera()
	{
		cout << "Circle: " << CShapesAera() << endl;
	}
};

class CTriangle : public CShapes
{
public:
	int a, b, c;
	double aera;
	CTriangle(int a_, int b_, int c_, double aera_) : a(a_), b(b_), c(c_), aera(aera_) {}
	~CTriangle() {}
	virtual double CShapesAera()
	{
		double p = (a + b + c) / 2.0;
		aera = sqrt( p * (p-a) * (p-b) * (p-c) );
		return aera;
	}
	virtual void CPrintAera()
	{
		cout << "Triangle: " << CShapesAera() << endl;
	}

};

CShapes * pShapes[100];
int MyCompare(const void * s1, const void * s2);
int main()
{
	int n = 0, i = 0;
	CRec * pr; CCircle * pc; CTriangle * pt;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		switch(c)
		{
		case 'R':
			pr = new CRec(0, 0, 0.0);
			cin >> pr->length >> pr-> width;
			pShapes[i] = pr;
			break;
		case 'C':
			pc = new CCircle(0, 0.0);
			cin >> pc->r;
			pShapes[i] = pc;
			break;
		case 'T':
			pt = new CTriangle(0, 0, 0, 0);
			cin >> pt->a >> pt->b >> pt->c;
			pShapes[i] = pt;
			break;
		}
	}
	qsort(pShapes, n, sizeof(CShapes *), MyCompare);
	for(i=0; i < n; i++)
	{
		pShapes[i]->CPrintAera();
	}

    return 0;
}

int MyCompare(const void * s1, const void * s2)
{
	double a1, a2;
	CShapes ** p1;
	CShapes ** p2;
	p1 = (CShapes **) s1;
	p2 = (CShapes **) s2;
	a1 = (*p1)->aera;
	a2 = (*p2)->aera;

	if( a1 < a2 )  return -1;
	else if( a1 > a2 ) return 1;
	else return 0;
}

/*#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

class CShape
{
public:
	virtual double Area() = 0; //纯虚函数
	virtual void PrintInfo() = 0;
};

class CRectangle:public CShape
{
public:
	int w,h;
	virtual double Area();
	virtual void PrintInfo();
};

class CCircle:public CShape {
public:
	int r;
	virtual double Area();
	virtual void PrintInfo();
};

class CTriangle:public CShape {
public:
	int a,b,c;
	virtual double Area();
	virtual void PrintInfo();
};

double CRectangle::Area() {
return w * h;
}
void CRectangle::PrintInfo() {
cout << "Rectangle:" << Area() << endl;
}
double CCircle::Area() {
return 3.14 * r * r ;
}
void CCircle::PrintInfo() {
cout << "Circle:" << Area() << endl;
}
double CTriangle::Area() {
double p = ( a + b + c) / 2.0;
return sqrt(p * ( p - a)*(p- b)*(p - c));
}
void CTriangle::PrintInfo() {
cout << "Triangle:" << Area() << endl; }
CShape * pShapes[100];
int MyCompare(const void * s1, const void * s2);

int main()
{
int i; int n;
CRectangle * pr; CCircle * pc; CTriangle * pt;
cin >> n;
for( i = 0;i < n;i ++ ) {
char c;
cin >> c;
switch(c) {
case 'R':
pr = new CRectangle();
cin >> pr->w >> pr->h;
pShapes[i] = pr;
break;
case 'C':
pc = new CCircle();
cin >> pc->r;
pShapes[i] = pc;
break;
case 'T':
pt = new CTriangle();
cin >> pt->a >> pt->b >> pt->c;
pShapes[i] = pt;
break;
}
}
qsort(pShapes,n,sizeof( CShape*),MyCompare);
for( i = 0;i <n;i ++)
pShapes[i]->PrintInfo();
return 0;
}

int MyCompare(const void * s1, const void * s2)
{
double a1,a2;
CShape * * p1 ; // s1,s2 是 void * ，不可写 “* s1”来取得s1指向的内容
CShape * * p2;
p1 = ( CShape * * ) s1; //s1,s2指向pShapes数组中的元素，数组元素的类型是CShape *
p2 = ( CShape * * ) s2; // 故 p1,p2都是指向指针的指针，类型为 CShape **
a1 = (*p1)->Area(); // * p1 的类型是 Cshape * ,是基类指针，故此句为多态
a2 = (*p2)->Area();
if( a1 < a2 )
return -1;
else if ( a2 < a1 )
return 1;
else
return 0;
}*/


