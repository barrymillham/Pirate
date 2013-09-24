#include "NPC.h"

NPC::NPC(string name, string greeting)
{
	NPC::name = name;
	NPC::greeting = greeting;
}
void NPC::interact()
{
	cout << name << " : " << greeting << endl;
}

Rambler::Rambler(string name,int numOfTopics,...)
{
	Rambler::name = name;
	char* s;
	va_list args;
	va_start(args,numOfTopics);
	for (int i = 0; i < numOfTopics; i++)
	{
		s = va_arg(args,char*);
		topics.push_back(s);
		s = va_arg(args,char*);
		bodies.push_back(s);
	}
	va_end(args);
}
void Rambler::interact()
{
	cout << name << " : ";
	int choice = 1;
	choice = menu("What do you want to talk about?",Rambler::topics);
	cout << endl;
	cout << bodies[choice-1] << endl;
}

Douche::Douche(string name,int numOfTopics,...)
{
	Douche::name = name;
	char* s;
	va_list args;
	va_start(args,numOfTopics);
	for (int i = 0; i < numOfTopics; i++)
	{
		s = va_arg(args,char*);
		topics.push_back(s);
		s = va_arg(args,char*);
		bodies.push_back(s);
	}
	va_end(args);
}
void Douche::interact()
{
	cout << name << " : ";
	int choice = 1;
	choice = menu("What do you want to talk about?",Rambler::topics);
	char* s = new char[bodies[choice-1].size()];
	char* lastPercent;
	strcpy(s,bodies[choice-1].c_str());
	lastPercent = strpbrk(s,"%");
	if (lastPercent != NULL)
	{
		cout << strtok(s,"%") << endl;
		getch();
		lastPercent = strpbrk(lastPercent+1,"%");
		while (lastPercent != NULL)
		{
			cout << strtok(NULL,"%") << endl;
			lastPercent = strpbrk(lastPercent+1,"%");
			getch();
		}
		cout << strtok(NULL,"%") << endl;
	}
	else
		cout << s << endl;
	delete [] s;
}