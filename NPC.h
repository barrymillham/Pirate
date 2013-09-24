#ifndef __NPC_H
#define __NPC_H

#include <iostream>
#include <cstdarg>
#include <string>
#include <vector>
#include <cstdarg>
#include "Menu.h"

using std::vector;
using std::string;


class NPC
{
protected:
	string greeting;
	string name;
public:
	NPC(){;}
	NPC(string name,string greeting);
	string getName(){return name;}
	virtual void interact();
};

class Rambler : public NPC
{
protected:
	vector<string> topics;
	vector<string> bodies;
public:
	Rambler(){;}
	Rambler(string name,int numOfTopics,...);

	void interact();
};

class Douche : public Rambler
{
public:
	Douche(){;}
	Douche(string name,int numOfTopics,...);
	void interact();
};

#endif