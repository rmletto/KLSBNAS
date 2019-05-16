#include <curses.h>
#include "snake.h"
#include <chrono>
#include <thread>

#define KEY_ESC 27

void testThread(int z) {
	int x = 1;
}

/** Movement thread
 * 
 * Program waits for 500 milliseconds then executes a move based
 * on the value stored in input
 * 
 * @param input: Reference to the keyboard input
 * @param snakeObj: A pointer to the snake object
 * 
 * */
void movement(int* input, Snake* snakeObj) {
	while(*input != KEY_ESC) {
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		snakeObj->move(*input);
	}
}

/** Thread that gets input from keyboard
 * 
 * @param input: Reference to the keyboard input
 * 
 * */
void getInput(int* input){
	int ch;
	for(;;) {
		ch = getch();
		if (ch == ERR) {
			// Do nothing - no keyboard press
		}
		else {
			*input = ch;
		}
	}
}

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
	//sneko->updatePos();	//Fixes the Snake position after the window clear
		
	///
	///MOVEMENT TESTING
	///

	for (int i = 0; i < 200; i++)
	{
		ch = getch();
		if (ch == KEY_ESC) {
			break;
		}
		sneko->move(ch);
	}

    // int* input = new int;
	// *input = 's';
	// // Keyboard input thread - constantly checks for keyboard input
	// // Loops until escape key is pressed
	// std::thread inputThread ([input]() { return getInput(input); });
	// // Movement delay thread - only executes a movement every half a second
	// // Loops until escape key is pressed
	// std::thread movementThread ([input, sneko]() { return movement(input, sneko); });

	// inputThread.join();
	// movementThread.join();

	delete sneko;			//Clean up Snake object
    endwin();               //Required before end of program
    return 0;
}



//std::thread readTestingData([this,&dataset]() { return processFile(dataset.train.filename, training_data); });
