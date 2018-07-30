#include <iostream>
#include <map>
using namespace std;

int main()
{
  int n, s;
  while ( cin >> n >> s )
  {
  	map<int, int> sell, buy;
  	char tmp;
  	int p,q;
  	for( int i=0; i<n; i++ )
	{
		cin >> tmp >> p >> q;
		if( tmp== 'S')
		{
			if( sell.find(p)==sell.end() )
				sell[p] = q;
			else
				sell[p] += q;
		}
		else
		{
			if( buy.find(p)==buy.end() )
				buy[p] = q;
			else
				buy[p] += q;
		}
	}

	int sCount = sell.size() < s ? sell.size() : s; //实际输出数量
	int bCount = buy.size() < s ? buy.size() : s;

	map<int,int>::iterator it = sell.begin();// 卖出后移
    for(int i = 0; i < sCount - 1; ++i) ++it;

    // 打印数据
    for(; sCount > 0; --it, --sCount)
        cout << "S " << it->first << " " << it->second << endl;
    for(map<int, int>::reverse_iterator it = buy.rbegin(); bCount > 0; ++it, --bCount)
        cout << "B" << " " << it->first << " " << it->second <<endl;
  }

  return 0;
}
