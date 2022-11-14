#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <vector>
#include <memory>
#include <iostream>
#include "observer.h"

class Subject;
class Cell;

class TextDisplay: public Observer {
    std::vector<std::vector<char>> grid;
public:
    TextDisplay(std::vector<std::vector<std::shared_ptr<Cell>>>& g);
    void notify(Subject& whoNotified) override;
    ~TextDisplay();
    
    friend std::ostream& operator<<(std::ostream& out, TextDisplay& td);
};


#endif
