#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int &n1, int &n2)
{
	int temp;
	temp = n1;
	n1 = n2;
	n2 = temp;
}

/********冒泡排序*******/
void BubbleSort(vector<int> arr[], int num)
{
	int i, j;
	for(i=0; i<num; i++)
		for(j=1; j<num-i; j++)
	{
		if(arr[j-1] > arr[j])
		{
			swap(arr[j-1], arr[j]);
		}
	}

}

int main()
{
	cout << "Please input yout number:" << endl;
	vector<int> nArr;
	int x;
	while(cin >> x)           //如果不确定输入数字个数，可以用这种方式
        nArr.push_back(x);   //填充数据
	cout << "input over:" << endl;
	for (int i=0;i<nArr.size();i++)
    {
		cout << nArr[i] << " ";
	}
	cout <<endl;
	sort(nArr.begin(),nArr.end());
	//BubbleSort( &nArr, nArr.size() );
	for(int x : nArr)
		cout << x << " ";
	cout <<endl;
    return 0;
}
