//
// Created by Ryan Letto on 2019-01-17.
//

#ifndef KLSBNAS_UTILS_H
#define KLSBNAS_UTILS_H

#include <curses.h>
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
std::string slurp(std::ifstream& file);



/*
 * Prints a border around a window
 *
 * @params win		Window to create the border around
 *
 * @returns nothing
 */
void printborder (WINDOW* win);


#endif //KLSBNAS_UTILS_H
