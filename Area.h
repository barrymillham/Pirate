#ifndef AREA_H
#define AREA_H

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"NPC.h"

using std::find;
using std::string;
using std::vector;


class Area {
public:
	virtual bool checkString(string text)=0;
	virtual string getEntryText()=0;
	virtual string getSimpleEntryText()=0;
	bool getSessionStatus(){return newSession;} /* Always set to true at start of a session, 
														Changes to false after first time visiting a
														location during that game session */
	void setSessionStatus(bool val) {newSession = val;};
	string getName() {return name;}

	//JAMES MCKAY ADDED THIS VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
	NPC* NPCPresent(string& name);
	void addNPC(NPC* pNPC){NPCS.push_back(pNPC);}
	void listNPCS();
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


protected:
	string name;
	bool newSession;
	string entryText;
	string simpleEntryText;
	vector<string> acceptedCommands;
	vector<string>::iterator iter;

	//JAMES MCKAY ADDED THIS VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
	vector<NPC*> NPCS;
	string description;
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

};


class Town : public Area {
public:
	Town();
	virtual bool checkString(string text);
	virtual string getEntryText(){return entryText;}
	virtual string getSimpleEntryText(){return simpleEntryText;}
	virtual bool getSessionStatus(){return newSession;}
	virtual void setSessionStatus(bool val) {newSession = val;}
private:
	bool newSession;
	string entryText;
	string simpleEntryText;
	vector<string> acceptedCommands;
};

class Water : public Area
{
public:
	bool checkString(string text){return true;}
	string getEntryText(){return entryText;}
	string getSimpleEntryText(){return simpleEntryText;}
};

class Shallows : public Water
{
public:
	Shallows(){name = "Shallows"; description = "Shallow water. Probably not too many decent fish here.";}
};

class DeepSea : public Water
{
public:
	DeepSea(){name = "Deep Sea"; description = "Open Ocean. Who knows what I could catch here?";}
};


#endif