#include"Area.h"

NPC* Area::NPCPresent(string& name)
{
	for (int i = 0; i < NPCS.size(); i++)
	{
		if (NPCS[i]->getName() == name)
			return NPCS[i];
	}
	return NULL;
}

void Area::listNPCS()
{
	if (NPCS.empty())
		cout << "There is no one here" << endl;
	else
	{
		cout << "This is who I can see here" << endl;
		for (int i = 0; i < NPCS.size(); i++)
		{
			cout << "\t" << NPCS[i]->getName() << endl;
		}
	}
}


Town::Town() {
	name="town";
	newSession = true;
	entryText = "You are in the town";
	simpleEntryText = "In town.";
	acceptedCommands.push_back("go to dock");
	acceptedCommands.push_back("go to store");
	acceptedCommands.push_back("where am i");
}

bool  Town::checkString(string text){
	std::cout<<"but here"<<std::endl;
	bool boolean = (find(acceptedCommands.begin(), acceptedCommands.end(), text) != acceptedCommands.end());
	std::cout << "boolean = " << boolean;
	system("pause");
	return boolean;
}
