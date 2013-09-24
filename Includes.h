#ifndef INCLUDES_H
#define INCLUDES_H
#include"Area.h"
#include<vector>
using std::vector;

Town town;

vector<Area*> areas;
void init() {
	areas.push_back(&town);
}


//_________________________________________________________________
//-------------------------Starting-Info-------------------------

const int STARTING_GOLD = 20;
const int STARTING_AGE = 0;
Area* STARTING_TOWN = &town;


//_________________________________________________________________
//---------------------Gameplay Variables------------------------
//std::vector<Area*, std::string>


//_________________________________________________________________
//-------------------------Fish----------------------------------






#endif