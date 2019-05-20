#include <curses.h>
#include "Snake.h"
#include <chrono>
#include <thread>

#define KEY_ESC 27


/**Snake movement during the game
 * 
 * The Snake will move every moveTime milliseconds. This function allows a(n almost)
 * constant check for user input before moving the Snake on the map
 * 
 * @param yoThisSnakeDoTheMoveThingsYo: The Snake that is getting moved
 * @param moveTime: The amount of time the Snake spends before moving in milliseconds
 * 
 * */
void doTheMovementThing(Snake* yoThisSnakeDoTheMoveThingsYo, int moveTime);



int main() {
	//Welcome screen and window setup
    init();
	Snake* sneko = new Snake();
	//Wait for key press to continue
	int ch;
	for(;;) {
		if ((ch = getch()) == ERR) {
			/*
			  User has not pressed a key
			*/
		}
		else {
			//User has pressed a key, so break the loop
			break;
		}
	}
	
	erase();			//Clear the window
		
	///
	///MOVEMENT
	///
	doTheMovementThing(sneko, 100);

	//
	//CLEANUP
	//

	delete sneko;			//Clean up Snake object
  endwin();         //Required before end of program by ncurses
	return 0;
}



void doTheMovementThing(Snake* yoThisSnakeDoTheMoveThingsYo, int moveTime) {
	//Character obtained by getch(), can contain anything
	int ch;
	//A user-inputter character obtained from getch()
	int userInput;

	//This loop does the everything
	for(;;) {
		//This loop checks for input moveTime(ms)/10(ms) times
		for(int i = 0; i < moveTime/10; i++) {
			//Obtain move if it exists
			if ((ch = getch()) == ERR) {
				/*
			  	User has not responded
				*/
			}
			else if (ch == KEY_ESC) {
				//Quit the game by ending movement
				return;
			}
			else {
				//User pressed a thing
				userInput = ch;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		//Now do the move thing
		yoThisSnakeDoTheMoveThingsYo->move(userInput);
	}
}

