//
// Created by Ryan Letto on 2019-01-17.
//
#include "Snake.h"
#include "utils.h"
#include <curses.h>
#include <string>
#include <fstream>

/**
 * Constructor for making a Snake object
 *
 * @params	startingX - Starting x position for the Snake (default 1)
 *			startingY - Starting y position for the Snake (default 1)
 *			gameWin - The window that the Snake game is taking place in (default stdscr)
 */
Snake::Snake(int startingX, int startingY, WINDOW* gameWin)
: snakeXpos(startingX), snakeYpos(startingY), snakeWin(gameWin)
{
	//Move the cursor to the start
	wmove(snakeWin, snakeYpos, snakeXpos);
}



/**
 * Method to move the snake on the map
 * @params	moveInput - The inputted direction of movement from getch()
 *						@pre is the integer value for w, a, s or d
 *
 * @modifies Updates the Snake's x position, y position and direction
 *
 * @returns nothing
 */
void Snake::move(int moveInput)
{
	switch(moveInput)
	{
		///UP CONDITION
		case 'w' :
			snakeYpos--;	//Decrement the Snake Y position, which moves it up
			updatePos(moveInput, '^');
			break;
		
		///RIGHT CONDITION
		case 'd' :
			snakeXpos++;	//Increment the Snake X position
			updatePos(moveInput, '>');
			break;
			
		///DOWN CONDITION
		case 's' :
			snakeYpos++;	//Increment the Snake Y position, which moves it down
			updatePos(moveInput, 'v');
			break;
		
		///LEFT CONDITION
		case 'a' :
			snakeXpos--;	//Decrement the Snake X position
			updatePos(moveInput, '<');
			break;
		
		//DEFAULT CASE: MOVE WITH RESPECT TO LAST INPUTTED DIRECTION
		default:
			move(lastInput);
			break;
	}

}



/** Update the Snake's position on the map
 *
 * After determining where the Snake has to move by fixing up it's coordinates,
 * this method gets called. This method handles all of the ncurses shenanigans
 * required to get the Snake to show up properly on the map.
 *
 * @param input: A valid user input received from getch()
 * @param direction: The 'arrow' that indicates which direction the Snake is facing
 *
 */
void Snake::updatePos(int input, char direction)
{
	//Add a character to the Snake's body
	waddch(snakeWin, '*');

	lastInput = input;
	//Update the Snake's cursor position on the map to where it's head is supposed to be
	wmove(snakeWin, snakeYpos, snakeXpos);
	//Add the Snake's head, pushes cursor forward
	waddch(snakeWin, direction);
	//Set the cursor back on top of the Snake's head
	wmove(snakeWin, snakeYpos, snakeXpos);
	//Update curses so that the changes can be seen on screen
	wrefresh(snakeWin);
}



/*
 * Function to initialize snake game
 *
 * Sets up all curses options needed and prints a welcome message to the terminal.
 *
 * @returns nothing
 */
void init()
{
    initscr();              //Initialize curses
    cbreak();               //getch() will not buffer characters and wait for a newline
    keypad(stdscr, true);   //Allow the program to capture special keystrokes such as arrow keys
	nodelay(stdscr, true);	//getch() will not wait for a character to be hit
    noecho();				//Prevents characters from printing to the terminal

    /*
     * Printing the welcome message
     */
    std::ifstream welcomeFile("maps/welcome.txt",std::ifstream::in); //Opens the welcome message as a filestream object
    std::string welcomeMessage = slurp(welcomeFile);            //Save the file contents to a string
    welcomeFile.close();                //Close the welcome file
    printw(welcomeMessage.c_str());     //Print the welcome message to the console

}
