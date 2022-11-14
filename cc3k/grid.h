#ifndef __GRID_H_
#define __GRID_H_
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <chrono>
#include <string>
#include "info.h"
#include "coordinate.h"
#include "subject.h"

class Cell;
class TextDisplay;

class Grid: public Subject {
    std::vector<std::vector<std::shared_ptr<Cell>>> theGrid;
    std::vector<std::vector<Coordinate>> chambers;
    int h, w;
    std::string race;
    Coordinate PCLocation;
    Coordinate StairLocation;
    std::shared_ptr<TextDisplay> td;
	unsigned seed;
	int gameDiffLevel;
	// 0: easy mode (more gold, NPC 1/2 HP)
	// 1: medium mode (normal mode)
	// 2: hard mode (less gold, NPC 1.5X Atk) (to be implemented)

    void addChamber(std::vector<std::vector<std::shared_ptr<Cell>>> &tempGrid, Coordinate c, std::vector<Coordinate>& tempChamber);
    std::vector<Coordinate> countNeighbour(Coordinate& cdn);
    void countNeighbour(Coordinate& cdn, std::vector<Coordinate>& v);
    std::vector<std::string> *flags;
public:
    std::vector<std::string> actionLog;
    Grid(std::vector<std::string>& theFloor, unsigned seed, char PCName, bool barrierSuit, std::vector<std::string> *flags);
    Grid(std::vector<std::string>& theFloor, unsigned seed, char PCName, std::vector<std::string> *flags);
    void init(char c);
    Coordinate& getPCLocation();
    void updatePlayer();
    void updateGrid();
    bool canMoveTo(Coordinate cdn);
    bool canMoveToNPC(Coordinate cdn);
    bool moveTo(Coordinate newCdn);
    void usePotion(Coordinate cdn);
    void PCAttack(Coordinate cdn);
    void printState(int floorNum) const;
    ~Grid();
    void buyPotion(std::string s);
};
Coordinate convertCdn(const Coordinate& oldCdn, std::string direction);
#endif

