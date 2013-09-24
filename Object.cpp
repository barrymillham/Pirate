#include "Object.h"

Fish::Fish(int category)
{
	int numberOfVarieties = 5;
	int numberOfShallows = 3;
	int range;

	switch(category)
	{
	case 0:		//ANY KIND OF FISH
		range = rand()%numberOfVarieties;
		break;
	case 1:		//SHALLOWS FISH
		range = rand()%numberOfShallows;
		break;
	case 2:		//DEEP SEA FISH
		range = rand()%(numberOfVarieties-numberOfShallows)+numberOfShallows;
		break;
	}

	switch(range)
	{
	case 0:
		*this = Fish("Trout","A tasty trout.",2);
		break;
	case 1:
		*this = Fish("Boot","This seems like it might taste a little leathery.",0);
		break;
	case 2:
		*this = Fish("Minnow","I'm not sure how this guy even bit the hook...",1);
		break;
	case 3:
		*this = Fish("Turncoat","Aparently this fish's name means traitor?",3);
		break;
	case 4:
		*this = Fish("Scapegoat","Dude. Now all your problems can be someone else's.",4);
		break;
	}
}

Fish::Fish(string name, string description, int value)
{
	Fish::name = name;
	Fish::description = description;
	Fish::value = value;
}