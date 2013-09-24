#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include"Player.h"
#include"Area.h"
#include"Menu.h"


using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;

const string SAVEGAMES_LIST_FILE = "list.txt";

class GameManager {
public:
	~GameManager();
	void setUpGame();
	int continueOrNewGame();
	void newGame();
	void newGameScreen();
	void introInformation();
	int runUntilExitRequest();
	void saveGame();/*Goes through everything that needs to be saved, and saves it.*/
	void loadGame(string playerName);/*Write a good parser for the file. Load all file data into the variables.*/;
	void deleteGame();
	void saveFileNames(vector<string> names);
	vector<string> loadFileNames();
	string getPlayerInput();
	void respondTo(string action);
	
	void continueGame();
	bool playedBefore() { return true;/*return fexists(dataFile.c_str());*/} // Everyone's played Pirate before!
	void endOfPane() {system("pause>nul");system("cls");}
	void pause() {system("pause>nul");}
	void clear() {system("cls");}
	void clearInputStream() {cin.clear();cin.sync();FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));cin.ignore(cin.rdbuf()->in_avail());	}
	string getAction();

	void goFish();
	

private:
	string dataFile;
	Player player;
};

void GameManager::setUpGame() {
	system("title Pirate v1.0");
	dataFile = "lastgame.log";
}

GameManager::~GameManager()
{
	saveGame();
}

void GameManager::saveGame()
{
	ofstream fout;
	fout.open(player.getName() + ".txt");

	if (fout.fail())
	{
		fout.close();
		cout << "Save error: file " << player.getName() + ".txt failed to open." << endl;
		return;
	}

	
	fout << "age "  << player.getAge()  << endl;
	fout << "desc " << player.getDescriptor() << endl;
	fout << "gold " << player.getGold() << endl;
	fout << "location " << player.getLocation() << endl;

	fout.close();
	return;
}

void GameManager::loadGame(string playerName)
{
	ifstream fin;
	fin.open(playerName + ".txt");
	
	if (fin.fail())
	{
		fin.close();
		cout << "File load error: failed to open \"" << playerName << ".txt\"";
		return;
	}

	string dummy; 
	int age;
	string desc;
	int gold;
	string location;

	fin >> dummy >> age;
	fin >> dummy >> desc;
	fin >> dummy >> gold;
	fin >> dummy >> location;
	
	player.setAge(age);
	player.setDescriptor(desc);
	player.setGold(gold);
	player.setLocation(location);
	fin.close();
}

vector<string> GameManager::loadFileNames()
{
	vector<string> names;
	string n;

	ifstream fin;
	fin.open(SAVEGAMES_LIST_FILE);

	if (!fin.fail())
	{
		fin >> n;
		while (!fin.eof())
		{
			names.push_back(n);
			fin >> n;
		}
	}

	fin.close();

	return names;
}

void GameManager::saveFileNames(vector<string> names)
{
	ofstream fout;
	fout.open(SAVEGAMES_LIST_FILE);

	for (int i = 0; i < names.size(); i++)
		fout << names[i] << "\n";

	return;
}

int GameManager::continueOrNewGame() {
	int choice = 0;
	while (choice != 1) {
		cout << endl << "              PIRATE!" << endl;
		cout << endl <<
		"                 ;~					" << endl << 
		"               ./|\\.					" << endl << 
		"             ./ /|`\\.					" << endl << 
		"            /  | |  `\\.				" << endl << 
		"           |   | |    `\\.				" << endl << 
		"           |   \\|     `\\.			" << endl << 
		"         .  `----|________\\.			" << endl << 
		"         \\-----''----.....___			" << endl << 
		"          \\               ""/			" << endl << 
		"      ~^~^~^~^~^`~^~^`^~^~^`^~^~^		" << endl << 
		"       ~^~^~`~~^~^`~^~^~`~~^~^~		" << endl << endl << endl;

		choice = menu("Welcome to Pirate!", 4, "Play", "Instructions", "Credits", "Quit");
		if (choice == 2) {
			clear();
			cout << "No one has ever attempted to catch the legendary creature Randy and lived to " <<
				"tell about it. You, a shirtless nerd with naught but some trusty swim trunks, must " <<
				"rise to the challenge and attempt to cage him. " << endl <<
				"The journey will be thrilling, lucrative, and above all - dangerous. " << endl << endl <<
				"Begin by fishing in the shallows. The market pays pretty good money for even " <<
				"the smaller catches. As you become more experienced and upgrade your vessel, " <<
				"you can move on to deeper waters to catch bigger fish. And after a very long " <<
				"time, when you feel ready, you may even attempt to catch Randy... Hah. Good luck." << endl << endl;
		}else if (choice == 3) {
			clear();
			cout << "Graphics\tJoan Stark\thttp://www.geocities.com/spunk1111/aquatic.htm" <<endl;
			cout << "Everything else:\n" << 
				endl <<"\tJames Mart" <<
				endl <<"\tNick Halvorsen" <<
				endl <<"\tEthan Johnson" <<
				endl <<"\tSteve Patterson" <<
				endl <<"\tJames McKay" << endl;
		}
		else if (choice == 4) {
			return -1;
		}

		if (choice == 1)
			clear();
		else
			endOfPane();
	}

		choice = menu("Choose a game option:",3, "Continue a game","Create a new game","Delete a previous game");
		if (choice == 1) continueGame();
		if (choice == 2) newGame();
		if (choice == 3) {deleteGame(); continueOrNewGame();}	

}

bool fexists(const char *filename)
{
  ifstream ifile(filename);
  return static_cast<bool>(ifile);
}

void GameManager::newGameScreen() {
	clear();
	cout << "Ohoho!" << " Velcome to PIRATE! Arrr!" << endl;

	cout << "\n\n\nPress any key to start your adventure!" << endl;
	endOfPane();
}

void GameManager::newGame() {
	newGameScreen();
	introInformation();
	player.saveFirstTimeInfo();

	// add player's name to list of files
	vector<string> list = loadFileNames();
	list.push_back(player.getName());
	saveFileNames(list);

	saveGame();
}

void GameManager::continueGame()
{
	vector<string> list = loadFileNames();

	if (list.size() == 0)
	{
		cout << "No profiles found." << endl;
		cout << "Starting new game." << endl;
		pause();
		newGame();
		return;
	}

	clear();

	int choice = menu("Select your name from the list, yo", list);
	loadGame(list[choice-1]);

}

void GameManager::deleteGame()
{
	vector<string> list = loadFileNames();

	if (list.size() == 0)
	{
		cout << "No previous games found." << endl;
		endOfPane();
		return;
	}

	clear();

	int choice = menu("Which file would you like to delete?", list);
	string dummy="";
	dummy.append("Are you sure you want to delete ").append(list[choice-1]).append("?");
	int yn = menu(dummy,2,"Yes","No");	

	if (yn == 1) {
		cout << "Phew.";
		endOfPane();
		return;
	} else	{
		string filename = list[choice-1] + ".txt";
		vector<string>::iterator dominoes;
		for (dominoes = list.begin(); dominoes != list.end(); dominoes++)
			if (*dominoes == list[choice-1])
			{
				list.erase(dominoes);
				break;
			}

		saveFileNames(list);
		cout << "Okay - done (:" << endl;
	}
	endOfPane();
	return;

}

void GameManager::introInformation() {

	string name = "";
	string descriptor = "";
	vector<string> usedNames = loadFileNames();

	bool badName = true;

	while (badName)
	{
		cout << "What is your name, sailor? ";
		cin >> name;

		for (int i = 0; i < name.size(); i++)
		{
			badName = false;
			if (!isalpha(name[i]) && !isspace(name[i]))
				badName = true;
		}
		for (int ii = 0; ii < usedNames.size(); ii++)
		{
			if (usedNames[ii] == name)
			{
				badName = true;
				cout << "Some guy already took that name." << endl;
			}
			
		}

		if (name.size() == 0)
			badName = true;

		if (badName)
			cout << "Is that really your name???" << endl << endl;
	}
	badName = true;
	while (badName)
	{
		cout << "Describe yourself in one word: ";
		cin >> descriptor;
		
		badName = false;

		for (int i = 0; i < name.size(); i++)
		{
			if (!isalpha(name[i]) && !isspace(name[i]))
				badName = true;
		}
		if (badName) cout << "You lie. Try again." << endl << endl;
	}

	player.setIntroInfo(name, descriptor);
	clear();
	cout << endl << "Some general purpose rules and information go here." << endl;
	pause();
	cout << "You are now ready to start your adventure!" << endl;
	endOfPane();
}

int GameManager::runUntilExitRequest() {
	cout << "Made it." << endl;
	bool wantsToPlay = true;
	while (wantsToPlay) {
		string action;
		action = getPlayerInput();
		if (action == "stop") wantsToPlay = false;
		else {
			respondTo(action);
		}
	}
	return 0;
}

string GameManager::getPlayerInput() {
	bool validInput = false;
	string action;
	while (!validInput) {
		clearInputStream();
		getline(cin, action);
		if (action == "") {}
		else if ((player.location()->checkString(action)) || (action == "stop")) { 
			validInput = true;
			return action;}
		else {
			cout << "Unrecognized command. Try again: " << endl;
		}
	}
	return action;
}

void GameManager::respondTo(string action) {
	return;
}

void GameManager::goFish()
{


}


#endif