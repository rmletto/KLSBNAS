/**
 * 
 * 
 * 
 * 
 * 
 * 
 * */

#include <string>
#include <curses.h>
#include "Snake.h"

class Map{

    public:

    static Map* InitMap(std::string mapName = "");

    void loadMap(std::string mapName);

    private:
    /**
     * 
     * 
     * 
     * */
    Map(int xmax, int ymax, char* mapArray);

    void addChar(char c, int x, int y);

    //Upper bounds on the Map size
    int xmax;
    int ymax;
    char* mapArray[];


};