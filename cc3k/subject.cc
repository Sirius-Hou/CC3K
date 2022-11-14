#include <utility>
#include "subject.h"

void Subject::notifyObserver() { ob->notify(*this); }

void Subject::attach(Observer* _ob) { ob = _ob; }

std::pair<Coordinate, char> Subject::getState() const { return state; }

void Subject::setState(std::pair<Coordinate, char> newState) { state = newState; }

