//
// Created by Ryan Letto on 2019-01-17.
//
#include "snake.h"
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
{}



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
	waddch(snakeWin, '*');	//Add a character to the snake's body
	switch(moveInput)
	{
		///UP CONDITION
		case 'w' :
			lastInput = moveInput;
			snakeYpos--;	//Decrement the Snake Y position, which moves it up
			wmove(snakeWin, snakeYpos, snakeXpos);	//Update position on map
			waddch(snakeWin, '^');	//Show Snake direction
			break;
		
		///RIGHT CONDITION
		case 'd' :
			lastInput = moveInput;
			snakeXpos++;	//Increment the Snake X position
			wmove(snakeWin, snakeYpos, snakeXpos);	//Update position on map
			waddch(snakeWin, '>');	//Show Snake direction
			break;
			
		///DOWN CONDITION
		case 's' :
			lastInput = moveInput;
			snakeYpos++;	//Increment the Snake Y position, which moves it down
			wmove(snakeWin, snakeYpos, snakeXpos);	//Update position on map
			waddch(snakeWin, 'v');	//Show Snake direction
			break;
		
		///LEFT CONDITION
		case 'a' :
			lastInput = moveInput;
			snakeXpos--;	//Decrement the Snake X position
			wmove(snakeWin, snakeYpos, snakeXpos);	//Update position on map
			waddch(snakeWin, '<');	//Show Snake direction
			break;
		
		//DEFAULT CASE: MOVE WITH RESPECT TO LAST INPUTTED DIRECTION
		default:
			move(lastInput);
			return;
	}
	//If the x position or y position exceeds the bounds of the map, do nothing

	wmove(snakeWin, snakeYpos, snakeXpos);	//Update Snake position after printing direction
	wrefresh(snakeWin);						//Refresh the window to show changes
}



/**
 * Method to update the Snake's position on the map
 * Switching/clearing terminals with Curses can mess with cursor position,
 * so this method is to help fix those issues
 *
 * DOES NOT UPDATE SCREEN AUTOMATICALLY
 *
 * @params none
 *
 * @returns none
 */
void Snake::updatePos()
{
	wmove(snakeWin, snakeYpos, snakeXpos);
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
	//nodelay(stdscr, true);	//getch() will not wait for a character to be hit
    noecho();				//Prevents characters from printing to the terminal

    /*
     * Printing the welcome message
     */
    std::ifstream welcomeFile("maps/welcome.txt",std::ifstream::in); //Opens the welcome message as a filestream object
    std::string welcomeMessage = slurp(welcomeFile);            //Save the file contents to a string
    welcomeFile.close();                //Close the welcome file
    printw(welcomeMessage.c_str());     //Print the welcome message to the console

}
