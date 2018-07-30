#include <iostream>
#include <string>

using namespace std;

class Students
{
private:
	string name;
	unsigned int age;
	string id;
	unsigned int score_1, score_2, score_3, score_4, scoreAdv;
public:
	Students(string name_, unsigned int age_, string id_, unsigned int s1, unsigned int s2, unsigned int s3, unsigned int s4, unsigned int sAdv):
		name(name_), age(age_), id(id_), score_1(s1), score_2(s2), score_3(s3), score_4(s4), scoreAdv(sAdv){ }
	~Students() { }
	void Set(string name_, unsigned int age_, string id_, unsigned int s1, unsigned int s2, unsigned int s3, unsigned int s4)
	{
		name=name_;
		age=age_ ;
		id=id_ ;
		score_1=s1;
		score_2=s2;
		score_3=s3;
		score_4=s4;
	}

	void Adv()
	{
		scoreAdv =( (score_1+score_2) + (score_3+score_4) ) / 4;
		cout << name <<" " << age << " "<< id<< " " << "scoreAdv = " << scoreAdv;
	}
};

int main()
{
    cout << "Pleasr input!" << endl;
    Students A("jiang",20,"222017",0,0,0,0,0);//("jiang",20,"222017",0,0,0,0,0)
	string Name;
	unsigned int Age;
	string Id;
	unsigned int Score_1=0, Score_2=0, Score_3=0, Score_4=0;
    cin >> Name >> Age >> Id >> Score_1 >> Score_2 >> Score_3 >> Score_4;
    A.Set(Name, Age, Id, Score_1, Score_2, Score_3, Score_4);
    A.Adv();
    return 0;
}
