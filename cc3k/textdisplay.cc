#include <vector>
#include <iostream>
#include <memory>
#include "textdisplay.h"
#include "cell.h"
#include "subject.h"
#include "coordinate.h"
#include "termcodes.h"

TextDisplay::TextDisplay(std::vector<std::vector<std::shared_ptr<Cell>>>& g) {
    int height = g.size();
    for (int i = 0; i < height; i++) {
        int width = g[i].size();
        std::vector<char> tempRow;
        for (int j = 0; j < width; j++) {
            std::string name = g[i][j]->getName();
            if (name == "Wall") {
                int walltype = g[i][j]->state();
                if (walltype == 1) {
                    tempRow.emplace_back('|');
                } else if (walltype == 2) {
                    tempRow.emplace_back('-');
                } else if (walltype == 3) {
                    tempRow.emplace_back(' ');
                }
            } else if (name == "Passage") {
                int passagetype = g[i][j]->state();
                if (passagetype == 1) {
                    tempRow.emplace_back('#');
                } else if (passagetype == 2) {
                    tempRow.emplace_back('+');
                }
            } else if (name == "Floor") {
                tempRow.emplace_back('.');
            }
        }
        grid.emplace_back(tempRow);
    }
}

void TextDisplay::notify(Subject& whoNotified) {
    Coordinate cdn = whoNotified.getState().first;
    char updatedChar = whoNotified.getState().second;
    grid[cdn.x][cdn.y] = updatedChar;
}

std::ostream& operator<<(std::ostream& out, TextDisplay& td) {
    int height = td.grid.size();
    for (int i = 0; i < height; i++) {
        int width = td.grid[i].size();
        for (int j = 0; j < width; j++) {
            if (td.grid[i][j] == '@') {
                out << YELLOW << td.grid[i][j] << RESET;
            } else if (td.grid[i][j] == 'V' || td.grid[i][j] == 'W' ||td.grid[i][j] == 'N' ||td.grid[i][j] == 'M' ||td.grid[i][j] == 'D' ||td.grid[i][j] == 'X' ||td.grid[i][j] == 'T') {
                out << BOLDRED << td.grid[i][j] << RESET;
            } else if (td.grid[i][j] == 'G' || td.grid[i][j] == 'B') {
                out << BOLDGREEN << td.grid[i][j] << RESET;
            } else if (td.grid[i][j] == 'P') {
                out << BOLDCYAN << td.grid[i][j] << RESET;
            } else if (td.grid[i][j] == '\\') {
                out << BOLDWHITE << td.grid[i][j] << RESET;
            } else {
                out << td.grid[i][j];
            }
        }
        out << std::endl;
    }
    return out;
}


TextDisplay::~TextDisplay() {
    int height = grid.size();
    for (int i = 0; i < height; i++) {
        grid[i].clear();
    }
    grid.clear();
}

