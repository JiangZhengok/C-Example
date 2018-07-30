#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
     enum color{ red,yellow,blue,white,black };
     enum color pri;
     int n,loop,i,j,k;
     n=0;

     for(i=red;i<=black;i++)
        for(j=red;j<=black;j++)
           if(i!=j)
           {
              for(k=red;k<=black;k++)
                 if(k!=i&&k!=j)//三种不同颜色的球
                 {
                    n++;
                    cout.width(4);
                    cout<<n;

                    for(loop=1;loop<=3;loop++)
                    {
                       switch(loop)
                       {
                          case 1 : pri=(enum color)i; break;
                          case 2 : pri=(enum color)j; break;
                          case 3 : pri=(enum color)k; break;
                          default: break;
                       }

                       switch(pri)
                       {
                          case red: cout<<setw(8)<<"red";       break;
                          case yellow: cout<<setw(8)<<"yellow"; break;
                          case blue: cout<<setw(8)<<"blue";     break;
                          case white: cout<<setw(8)<<"white";   break;
                          case black: cout<<setw(8)<<"black";   break;
                          default: break;
                       }
                    }
                    cout<<endl;
                 }
           }
           cout<<"total: "<<n<<endl;

           return(0);
}
