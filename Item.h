#ifndef __ITEM_H
#define __ITEM_H

#include<iostream>
#include<string>

using std::string;

class Item {
public:
	string getName(){return name;}
	int getValue(){return value;}

private:
	string name;
	int value;
};




#endif