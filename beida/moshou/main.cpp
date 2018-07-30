#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string inputOrder[5] = { "dragon","ninja","iceman","lion","wolf" }; //输入顺序
string redWarrior[5] = { "iceman","lion","wolf","ninja","dragon" }; //红军武士出生顺序
int redInitialStrength[5];   //红军武士生命值
string blueWarrior[5] = { "lion","dragon","ninja","iceman","wolf" };//蓝军武士出生顺序
int blueInitialStrength[5];  //蓝军武士生命值

class Warrior  //武士类
{
private:
	int id;
	int strength;  //武士生命值
	int attack;
	string classes; //武士类别
public:
	Warrior() {}
	Warrior(int id, int s, int atk, string classes) :
		id(id), strength(s), attack(atk), classes(classes) {}
	int getStrength()
	{
		return strength;
	}
	string getClasses()
	{
		return classes;
	}
};

class Headquater  //军团类
{
private:
	string alliance;
	static int redTotalStrength; //红军总生命元（静态变量）
	static int blueTotalStrength;//蓝军总生命元（静态变量）
	static int redWarriorCount;  //红军武士计数
	static int blueWarriorCount; //蓝军武士计数
	int numOfEachClasses[5] = { 0 }; //各类武士计数
	int warriorIndex;			//武士索引
	Warrior warrior[1000];      //武士实例
public:
	Headquater(string a) :alliance(a), warriorIndex(0) {}
	static void SetToalStrength(int strength) //静态成员函数，设置军队总生命元
	{
		redTotalStrength = strength;
		blueTotalStrength = strength;
	}
	static void ResetWarriorCount() //静态成员函数，复位武士计数
	{
		redWarriorCount = 0;
		blueWarriorCount = 0;
	}
	int makeWarrior();     //制造武士
};

//初始化武士计数值，及军队总生命元
int Headquater::redWarriorCount = 0;
int Headquater::blueWarriorCount = 0;
int Headquater::redTotalStrength = 0;
int Headquater::blueTotalStrength = 0;

int Headquater::makeWarrior() //制造武士方法
{
	static int notMadeCount = 0;
	if (alliance == "red") //如果是红军
	{
		string classes = redWarrior[warriorIndex];
		int strength = redInitialStrength[warriorIndex];
		if (redTotalStrength - strength >= 0)
		{
			notMadeCount = 0;
			redTotalStrength -= strength;
			warrior[redWarriorCount] = { redWarriorCount,strength,0,classes };
			redWarriorCount++;
			numOfEachClasses[warriorIndex]++;
			cout << "red " << classes << " " << redWarriorCount << " born with strength " << strength << ","
			<< numOfEachClasses[warriorIndex] << " " << classes << " in red headquarter" << endl;
			++warriorIndex %= 5; //？？？？？？
			return true;
		}
		else
		{
			notMadeCount++;
			++warriorIndex %= 5;
			if (notMadeCount > 5)
			{
				notMadeCount = 0;
				return false;
			}
			return this->makeWarrior();

		}
	}
	else if (alliance == "blue")
	{
		string classes = blueWarrior[warriorIndex];
		int strength = blueInitialStrength[warriorIndex];
		if (blueTotalStrength - strength >= 0)
		{
			notMadeCount = 0;
			blueTotalStrength -= strength;
			warrior[blueWarriorCount] = { blueWarriorCount,strength,0,classes };
			blueWarriorCount++;
			numOfEachClasses[warriorIndex]++;
			cout << "blue " << classes << " " << blueWarriorCount << " born with strength " << strength << ","
			<< numOfEachClasses[warriorIndex] << " " << classes << " in blue headquarter" << endl;
			++warriorIndex %= 5;
		}
		else
		{
			notMadeCount++;
			++warriorIndex %= 5;
			if (notMadeCount > 5)
			{
				notMadeCount = 0;
				return false;
			}
			return this->makeWarrior();
		}
	}
}

int main()
{
	int numOfTest = 0;
	cin >> numOfTest;

	for (int i = 1; i <= numOfTest; i++)
	{
		int M = 0;
		cin >> M;
		Headquater red("red"), blue("blue");
		Headquater::SetToalStrength(M);
		Headquater::ResetWarriorCount();

		for (int j = 0; j < 5; j++)
		{
			int strength;
			cin >> strength;
			for (int k = 0; k < 5; k++)
			{
				if (inputOrder[j] == redWarrior[k])
				{
					redInitialStrength[k] = strength;
				}
			}
			for (int k = 0; k < 5; k++)
			{
				if (inputOrder[j] == blueWarrior[k])
				{
					blueInitialStrength[k] = strength;
				}
			}
		}

		cout << "Case:" << i << endl;
		bool redStop = false;
		bool blueStop = false;
		int time = 0;
		while (true)
		{
			if (!redStop)
			{
				cout << setw(3) << setfill('0') << time << " ";
				redStop = !red.makeWarrior();
				if (redStop)
				{
					cout << "red headquarter stops making warriors" << endl;
				}

			}
			if (!blueStop)
			{
				cout << setw(3) << setfill('0') << time << " ";
				blueStop = !blue.makeWarrior();
				if (blueStop)
				{
					cout << "blue headquarter stops making warriors" << endl;
				}
			}
			if (redStop && blueStop)
			{
				break;
			}
			time++;
		}
	}
	return 0;
}











