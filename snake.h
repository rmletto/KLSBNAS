//
// Created by Ryan Letto on 2019-01-17.
//

#ifndef KLSBNAS_SNAKE_H
#define KLSBNAS_SNAKE_H

#include <curses.h>


/*
 * Enumeration for keeping track of the direction that the Snake is facing
 */
enum class Direction
{
	Up, Down, Left, Right
};



class Snake
{
public:
	/**
	 * Constructor for making a Snake object
	 *
	 * @params	startingX - Starting x position for the Snake (default 1)
	 *			startingY - Starting y position for the Snake (default 1)
	 *			startingDir - Starting direction for the Snake (default Right)
	 *			gameWin - The window that the Snake game is taking place in (default stdscr)
	 */
	Snake(int startingX = 1, int startingY = 1, WINDOW* gameWin = stdscr);
	
	
	
	/**
	 * Method to move the Snake on the map
	 * @params	moveInput - The inputted direction of movement from getch()
	 *
	 * @modifies Updates the Snake's x position, y position and direction
	 *
	 * @returns nothing
	 */
	void move(int moveInput);
	
	
	

	
private:
	int snakeXpos;		//X coordinate of the Snake
	int snakeYpos;		//Y coordinate of the Snake
	WINDOW* snakeWin;	//Window that the snake is on
	int lastInput = 'd';

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
	void updatePos(int input, char direction);
};

/**
 * Function to initialize console for Snake game
 *
 * Sets up all curses options needed and prints a welcome message to the terminal.
 *
 * @returns nothing
 */
void init();

#endif //KLSBNAS_SNAKE_H
