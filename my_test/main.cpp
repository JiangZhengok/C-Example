#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_map>
#include <algorithm>  //sort()

using namespace std;

template<typename T> void print(const T &container);
template<typename T> void printmap(const T &map);

int main()
{
	cout << "vector----------------------------------------" << endl;
	vector<int> a={3, 1, 2, 4, 7};				print(a);
	//capacity()   �����ܴ洢���ݵĸ���
	//size()       ����Ŀǰ���ڵ�Ԫ����
	cout << "size: " << a.size() << ".\tcapacity: " << a.capacity() << ".\n";// \t ������һ��tableλ��
	a.push_back(4);     //��ʱ�������ܹ��ṩ�Ŀռ�capacity()�������ˣ���Ҫ�������ݣ���������أ������Ĵ�СӦ������ǰ��2��
	cout << "size: " << a.size() << ".\tcapacity: " << a.capacity() << ".\n";

	//cbegin()��cend()��C++11�����ģ����Ƿ���һ��const�ĵ����������������޸�Ԫ�ء�
	a.insert(a.cbegin()+1, 9);					print(a);
	a.insert(a.cend(), 2, 8);					print(a); //��ĩβ��������8
	a.pop_back();								print(a);

	sort(a.begin(), a.end()); 					print(a);
	sort(a.begin(), a.end(), greater<int>());   print(a);//Ĭ�Ϸ�ʽ��������,����ͨ��ν�ʸ�Ϊ����greater<int>()

	vector<int>::const_iterator cp = find( a.cbegin(), a.cend(), 4 );
	if( cp!=a.cend() )
		cout << "the first pos. of 4 is:\t" << distance( a.cbegin(), cp ) << endl;
	else
		cout << '4' << "does not exist." << endl;
	cout << "the number of 4 is:\t" << count( a.cbegin(), a.cend(), 4 ) << endl; //count() ���������cbegin()��cend()
	a.erase(cp);								print(a); //ɾ��������cp��ָ���Ԫ��
	a.erase(a.cbegin()+1, a.cend()-1); 			print(a); //ɾ������������ǵķ�Χ�ڵ�Ԫ��
	//a.clear();									print(a);

	cout << "\ndeque---------------------------------------------\n";
	deque<int> a2{1, 4, 7, 3, 5, 9, 8};
	a2.push_front(9);							print(a2);

	cout << "\nlist----------------------------------------------\n";
	//print(a);
	list<int> b{1, 4, 2, 7, 8, 3, 6};			print(b);
	b.push_back(2);								print(b);
	b.insert( b.cbegin(), a.cbegin(), a.cbegin()+2 );	print(b); //�����a.  ()+2�ͻ����Խ��
	b.pop_front();								print(b);
	b.remove(2);								print(b); //�Ƴ�������Ԫ��
	b.sort();									print(b);

	cout << "\nforward_list--------------------------------------\n";
	forward_list<int> b2 = {1, 2, 3, 7, 8, 3};				print(b2);
	*b2.begin() = 9;										print(b2); //����Ԫ��
	b2.reverse();											print(b2); //��תԪ��

	cout << "\nset-----------------------------------------\n";
	set<int> c = {1, 4, 5, 6, 3, 2, 6, 7, 9};				print(c);
	cout << "size: " << c.size() << endl;
	c.insert(8);											print(c);

	cout << "\nmultiset------------------------------------\n";
	multiset<int> c2 = {1, 3, 4, 3, 5, 6, 1};				print(c2);
	cout << "the number of 3 is:\t" << c2.count(3) << endl;
	c2.erase(3);											print(c2);

	cout << "\nunordered_multiset--------------------------\n";


	return 0;
}

template<typename T>
void print(const T &container)
{
//	for( typename T::const_iterator cp=container.cbegin(); cp!=container.cend(); cp++ )
//		cout << *cp <<" ";
	for( auto &it:container )
		cout << it << " ";
	cout << endl;
}

template<typename T>
void printmap(const T &map)
{
	for( auto &it:map)
		cout << it.first << "\t-->\t" << it.second << endl;
	cout << endl;
}
