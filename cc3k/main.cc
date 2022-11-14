#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <chrono>
#include <algorithm>
#include <random>
#include <iomanip>
#include "grid.h"
#include "termcodes.h"
#include "pc.h"
#include "merchant.h"
#include "coordinate.h"
using namespace std;

// Helper
void printIntroMsg() {
	std::cout << "Please select your PC character:" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "(1) Human" << YELLOW << "(h)" << RESET << ": HP:140  Attack:20  Defence:20" << std::endl;
    std::cout << "(2) Dwarf" << YELLOW << "(d)" << RESET << ": HP:100  Attack:20  Defence:30    <gold X2>" << std::endl;
    std::cout << "(3) Elves" << YELLOW << "(e)" << RESET << ": HP:140  Attack:30  Defence:10    <negative potions have positive effects>" << std::endl;
    std::cout << "(4) Orc  " << YELLOW << "(o)" << RESET << ": HP:180  Attack:30  Defence:25    <gold X0.5>" << std::endl;
    std::cout << ">>> Please enter 'h', 'd', 'e', or 'o'" << std::endl;
}





int main(int argc, char* argv[]) {
    string fileName = "defaultFloor.txt";
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	if (argc >= 2) {
		fileName = argv[1];
	}
	if (argc >= 3) {
		istringstream iss{argv[2]};
		iss >> seed;
	}
	vector<string> flags;
	if (argc > 3) {
		for (int i = 3; i < argc; i++) {
			string s = argv[i];
			flags.emplace_back(s);
		}
	}

	

    // Step 1: Read in maps and store them in vector<vetor<string>> maps where each string represents each line
    std::ifstream ifs;
    ifs.open(fileName, std::ios::in);
    string s;
	std::vector<string> tempRecord;
	while (getline(ifs, s)) {
		tempRecord.emplace_back(s);
	}
	cin.clear();

    string startLine;
    vector<vector<string>> maps;
    int floorIndex = 1;
    int PCFloorIndex = 6;
	bool foundPC = false;
	bool foundBS = false;
    int index = 0;
    vector<string> tempMap;


	for (size_t i = 0; i < tempRecord.size(); i++) {
		s = tempRecord[i];
		if (index == 0) {
			startLine = s;
		} else if (s == startLine) {
			tempMap.emplace_back(s);
			maps.emplace_back(tempMap);
			tempMap.clear();
			floorIndex++;
			index = 0;
			if (foundBS && !foundPC) {
				foundBS = false;
			}
			continue;
		}

		if (!foundPC) {
			for (size_t j = 0; j < tempRecord[i].size(); j++) {
				if (tempRecord[i][j] == '@') {
					PCFloorIndex = floorIndex;
					foundPC = true;
				} else if (tempRecord[i][j] == 'B') {
					foundBS = true;
				}
			}
		}
		tempMap.emplace_back(s);
		index++;
    }




	// Step 2: Call the corresponding constructor to initialize the game Grid
	// Print out welcome message
	std::cout << "WELCOME TO THE GAME OF CHAMBERCRAWLER3000+!" << std::endl;
	printIntroMsg();
	char pc;
	// Player character selection
	while (cin >> pc) {
		if (pc == 'h' || pc == 'd' || pc == 'e' || pc == 'o') {
			break;
		} else {
			std::cout << "Invalid input, please input the correct character" << std::endl;
		}
	}


	int currFloor = 1; // Current floor number
	if (foundPC) {
		currFloor = PCFloorIndex;
	}
 
	int barrierFloor = 0;
	if (foundPC && !foundBS && PCFloorIndex != 5) {
		std::vector<int> n; 
		for (int i = PCFloorIndex; i <= 5; i++) {
			n.emplace_back(i);
		}
		std::shuffle(n.begin(), n.end(), std::default_random_engine{seed});
		barrierFloor = n[0];
		n.clear();
	} else if (!foundPC) {
		std::vector<int> n; 
		for (int i = 1; i <= 5; i++) {
			n.emplace_back(i);
		}
		std::shuffle(n.begin(), n.end(), std::default_random_engine{seed});
		barrierFloor = n[0];
		n.clear();
	}

	// Create new Grid object (game)
	std::shared_ptr<Grid> g;

	if (!foundPC) {
		g = std::make_shared<Grid> (maps[0], seed, pc, currFloor == barrierFloor, &flags);
	} else {
		g = std::make_shared<Grid> (maps[PCFloorIndex - 1], seed, pc, &flags);
	}
	g->printState(currFloor);


	// Game starts
	char cmd;
	while (cin >> cmd) {
		// Moving Player Character
		if (cmd == 'n' || cmd == 's' || cmd == 'e' || cmd == 'w') {
			try {
				string direction = "";
				direction += cmd;
				cin >> cmd;
				if (cin.fail()) throw runtime_error("Incorrect direction format!");
				direction += cmd;
				Coordinate destination = convertCdn(g->getPCLocation(), direction);
				if (g->moveTo(destination)) {
					if (currFloor == 5) {
						g->actionLog.emplace_back("You Win!");
						break;
					}

					currFloor += 1;
					std::cout << GREEN << "You found the stairs! ENTERING LEVEL " << currFloor << " >>>" << RESET << std::endl;
					Merchant::resetHatred();
					g = std::make_shared<Grid> (maps[currFloor - 1], ++seed, pc, currFloor == barrierFloor, &flags);
					
					g->printState(currFloor);
				}
			} catch (runtime_error& errorMsg) {
				cout << errorMsg.what() << endl;
				continue;
			}
		} else if (cmd == 'u') {
			try{
				string direction;
				cin >> direction;
				if (cin.fail()) throw runtime_error("Incorrect direction format!");
				Coordinate destination = convertCdn(g->getPCLocation(), direction);
				g->usePotion(destination);
			} catch (runtime_error& errorMsg) {
				cout << errorMsg.what() << endl;
				continue;
			}

		} else if (cmd == 'a') {
			try{
				string dir;
				cin >> dir;
				if (cin.fail() || (dir != "no" && dir != "so" && dir != "we" && dir != "ea" && dir != "nw" && dir != "ne" && dir != "sw" && dir != "se")) {
					throw runtime_error("Incorrect direction format!");
				}
				Coordinate destination = convertCdn(g->getPCLocation(), dir);
				g->PCAttack(destination);
			} catch (runtime_error& errorMsg) {
				cout << errorMsg.what() << endl;
				continue;
			}

		} else if (cmd == 'q') {
			std::cout << CYAN << "##### " << left << setw(45) << setfill(' ') << "GAME OVER! Defeated! (Player quits the game)" << right << setw(5) << "#####" << std::endl;
			std::cout << "##### TOTAL SCORE: " << left << setw(32) << setfill(' ')  << PC::totalCoin << right << setw(5) << "#####" << RESET << std::endl;
			break;


		} else if (cmd == 'r') {
			currFloor = 1;
			if (PCFloorIndex != 6) {
				currFloor = PCFloorIndex;
			}

			std::vector<int> n;
			for (int i = 1; i <= 5; i++) {
				n.emplace_back(i + 1);
			}
			std::shuffle(n.begin(), n.end(), std::default_random_engine{seed});
			int barrierFloor = n[0];
			n.clear();
			printIntroMsg();
			// Player character reselection
			while (cin >> pc) {
				if (pc == 'h' || pc == 'd' || pc == 'e' || pc == 'o') {
					break;
				} else {
					std::cout << "Invalid input, please input the correct character" << std::endl;
				}
			}
			if (!foundPC) {
				g = std::make_shared<Grid> (maps[currFloor - 1], seed, pc, currFloor == barrierFloor, &flags);
			} else {
				g = std::make_shared<Grid> (maps[currFloor - 1], seed, pc, &flags);
			}
			g->printState(currFloor);
			continue;
		}
		
		else if (cmd == 'b') {
			string s = "";
			try {
				cin >> cmd;
				s += cmd;
				cin >> cmd;
				s += cmd;
				g->buyPotion(s);
				//g->updateGrid();
			} catch (std::runtime_error& msg) {
				std::cout << msg.what() << std::endl;
				continue;
			}
		}
		
		else if (cmd == '+') {
			string f;
			cin >> f;
			flags.emplace_back(f);
			std::cout << "New flag: \"" << f << "\" has been deployed." << std::endl;
			g->printState(currFloor);
			continue;
		}

		else if (cmd == '-') {
			string f;
			cin >> f;
			bool found = false;
			for (size_t i = 0; i < flags.size(); i++) {
				if (flags[i] == f) {
					flags.erase(flags.begin() + i);
					std::cout << "Flag: \"" << f << "\" has been undeployed." << std::endl;
					found = true;
					break;
				}
			}
			if (!found) {
				std::cout << "No flag called \"" << f << "\" has been deployed, please check your spelling." << std::endl;
			}
			g->printState(currFloor);
			continue;
		}
		
		
		else {
			std::cout << "Invalid command, please try again!" << std::endl;
			continue;
		}

		// NPC's round & Grid update
		g->updateGrid();
		g->printState(currFloor);
		std::cout << "Actions:" << std::endl;
		for (size_t i = 0; i < g->actionLog.size(); i++) {
			std::cout << g->actionLog[i] << std::endl;
		}
		g->actionLog.clear();

		if (PC::HP == 0) {
			std::cout << CYAN << "##### " << left << setw(22) << setfill(' ') << "GAME OVER! Defeated!" << right << setw(5) << "#####" << std::endl;
			std::cout << "##### TOTAL SCORE: " << left << setw(9) << setfill(' ')  << PC::totalCoin << right << setw(5) << "#####" << RESET << std::endl;
			break;
		}
	}
	return 0;

}
