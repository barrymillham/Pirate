#ifndef __MENU_H
#define __MENU_H

#include <iostream>
#include <cstdarg>
#include <string>
#include <conio.h>
#include <vector>

using namespace std;

int menu(string prompt,int numOfChoices,...);
int menu(string prompt,vector<string>&);

#endif