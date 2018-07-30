#include <iostream>
#include <string>

using namespace std;

class Maid
{
public:
	Maid(char sex,unsigned age,string country,int id) {Sex=sex;Age=age;Country=country;Id=id;}
	~Maid() {}
	void make();
	void sing();
public:
	char Sex;
	unsigned Age;
	string Country;
	int Id;
};

void Maid::make()
{
	cout << "I can cook for you!" << endl;
}
void Maid::sing()
{
	cout << "I can sing for you!" << endl;
}
int main()
{
    Maid Lily('f',20,"China",10010);
    cout << "I am Lily.\n" << "I am a beautiful girl!\n";
    cout << "I am "<< Lily.Age << " years old.\n" << "I come from " << Lily.Country <<".\n";
    cout << "My ID number is: " << Lily.Id << endl;
    cout << "I can do that: \n";
	Lily.make();
	Lily.sing();
    return 0;
}
