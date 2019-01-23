#include <curses.h>
#include "snake.h"

#define esc 27				//Defining the escape key



int main() {
    init();                 		//Welcome screen and window setup
	Snake* sneko = new Snake();		//Make a Snake object with default params
	getch();						//Pause on title screen
	
	erase();			//Clear the window
	sneko->updatePos();	//Fixes the Snake position after the window clear
	
	int ch = 0;			//Variable for keyboard input
	
	///
	///MOVEMENT TESTING
	///
	for (int i = 0; i < 30; i++)
	{
		ch = getch();
		sneko->move(ch);
	}

	delete sneko;			//Clean up Snake object
    endwin();               //Required before end of program
    return 0;
}

