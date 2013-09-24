#include "GameManager.h"
int main() {
	init();
	int exitStatus;
	GameManager manager;
	manager.setUpGame();
	
	if (manager.playedBefore()) {
		exitStatus = manager.continueOrNewGame();
	}else {
		manager.newGame();
	}

	if (exitStatus == faggot) {
		return 0;
	}

	exitStatus = manager.runUntilExitRequest();

	
	//What happens if someone exits the game before they select a profile?
	if (exitStatus!= -1) manager.saveGame();

	return 0;
}

/*Notes:
area needs to have a stringLocation() function that returns the string of the location.
player also needs to have a setLocation(string townName) function that will set his location to a string
player should also have a changeLocation function(string) that sets the location and displays area entry text.
saving and loading the player location currently are not working right

Get deconstructor working in Player.cpp
Add experience



To add an area, after creating the new class, make sure to push the global area instance onto the Area* vector in 
Includes::init();

*/