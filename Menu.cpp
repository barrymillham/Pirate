#include "Menu.h"

int menu(string prompt,vector<string>& items)
{
	int numOfItems = items.size()+1;
	cout << prompt << endl;
	
	for (int i = 0; i < items.size(); i++)
	{
		cout << "[" << i+1 << "] " << items[i] << endl;
	}

	char c = ' ';
	while ((c-48) < 1 || (c-48) > (numOfItems-1))
	{
		c = getch();
	}
	cout << c-48 << endl;
	return c-48;
}
int menu(string prompt,int numOfChoices,...)
{
	va_list args;
	va_start(args,prompt);

	cout << prompt << endl;
	char* s;
	for (int i = 0; i < numOfChoices; i++)
	{
		s = va_arg(args,char*);
		cout << "[" << i+1 << "] " << s << endl;
	}
	va_end(args);

	char c = ' ';
	while ((c-48) < 1 || (c-48) > (numOfChoices))
	{
		c = getch();
	}
	cout << c-48 << endl;
	return c-48;
}