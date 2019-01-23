//
// Created by Ryan Letto on 2019-01-17.
//

#include "utils.h"
#include <string>
#include <fstream>
#include <sstream>

/*
 * Dumps a file's contents into a string, mainly used for printing things to console
 *
 * @params file     The file to be stringified
 *
 * @returns a string containing the file's contents
 */
std::string slurp(std::ifstream& file)
{
    std::stringstream sstr;
    sstr << file.rdbuf();
    return sstr.str();
}



/*
 * Prints a border around a window
 *
 * @params win		Window to create the border around
 *
 * @returns nothing
 */
void printborder (WINDOW* win)
{
	//Variables to store width and height of window
	int width = 0;
	int height = 0;
	getmaxyx(win,height,width);	//Gets size of current window to print the border
	
	
	wmove(win, 0, 0);		//Top left corner positioning
	waddch(win, '+');		//Print top left corner
	//Print a horizontal line of - across the top
	for (int i = 0; i < width - 2; i++)	//i < width - 2 because printing the corner updates x to 1
	{
		waddch(win, '-');
	}
	waddch(win, '+');		//Print top right corner
	
	
	wmove(win, height - 1, 0);//Bottom left corner positioning
	waddch(win, '+');		//Print bottom left corner
	//Print a horizontal line of - across the bottom
	for (int i = 0; i < width - 2; i++)	//i < width - 2 because printing the corner updates x to 1
	{
		waddch(win, '-');
	}
	waddch(win, '+');		//Print bottom right corner
	
	//Print vertical lines of | across the left and right
	for (int i = 1; i < height-1; i++)
	{
		wmove(win, i, 0);	//Move cursor to left side of screen
		waddch(win, '|');	//Print | on left
		wmove(win, i, width-1);	//Move cursor to right side of screen
		waddch(win, '|');	//Print | on right
	}
	
	wrefresh(win);			//Refresh the window to display change
	wmove (win, 1, 1);		//Set cursor inside the border
}
