#ifndef __OBJECT_H
#define __OBJECT_H

#include <iostream>
#include <string>

using std::string;
using std::cout;

class Object
{
protected:
	string name;
	string description;
public:
	Object(){;}
	string getName(){return name;}
	string getDescription(){return description;}
	void examine();
};

class CarryableObject : public Object
{
protected:
	int value;
public:
	CarryableObject(){;}
	CarryableObject(string name, string description, int value){CarryableObject::name = name; CarryableObject::description = description; CarryableObject::value = value;}
	virtual void interact(){;}
	int getValue(){return value;}
};

class Fish : public CarryableObject
{
public:
	Fish(int category = 0); //0 : any fish	1 : shallows fish	2 : deep sea fish
	Fish(string name, string description, int value);
};

class Food : public CarryableObject
{
protected:
	int nutritionValue;
public:
	Food(){;}
	Food(string name, string description, int value, int nutrition){Food::name = name; Food::description = description; Food::value = value; Food::nutritionValue = nutrition;}
	void consume(){cout << "Mmm. That was good" << std::endl;}
};

#endif