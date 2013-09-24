#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include<string>
#include"Area.h"
#include"Includes.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;

extern Town town;
const extern int STARTING_GOLD;
const extern int STARTING_AGE;
extern Area* STARTING_TOWN;
extern vector<Area*> areas;

class Player {
public:
	~Player(){/*delete loc;*/};		//MEMORY LEAK - change this so it works
	void build(string fileName);

	void saveFirstTimeInfo(); /* Give player the starting items and stats */
	void setIntroInfo(string n, string d){name = n; descriptor = d;}
	Area* location(){cout<<"returning loc"<<endl;return loc;}
	void displayLocation();

	string getName()	{return name;}

	int  getAge()		{return age;}
	void setAge(int a)	{age = a;}

	string getDescriptor(){return descriptor;}
	void   setDescriptor(string d){descriptor = d;}
	
	int  getGold()		{return gold;}
	void setGold(int g)	{gold = g;}
	void addGold(int g)	{gold += g;}

	void setLocation(string location);
	void changeLocation(string location) {setLocation(location);displayLocation();}
	string getLocation() {return loc->getName();}

private:
	string name;
	int age;
	string descriptor;
	int gold;
	Area* loc;
};

void Player::displayLocation() {
	if (loc->getSessionStatus()) {
		cout << loc->getEntryText();
		loc->setSessionStatus(false);
	} else {
		cout << loc->getSimpleEntryText() << endl;
	}


}

void Player::saveFirstTimeInfo()
{
	age = STARTING_AGE;
	gold = STARTING_GOLD;
	loc = STARTING_TOWN;
}

void Player::setLocation(string location) 
{
	Player::loc=NULL;
	for (int i = 0; i < areas.size(); i++) {
		if (areas[i]->getName() == location)  {
			Player::loc=areas[i];
			break;
		}
	}
	if (Player::loc==NULL) {Player::loc = &town;}
}



#endif