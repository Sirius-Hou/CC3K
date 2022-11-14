#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include "observer.h"
#include "coordinate.h"

class Subject {
    Observer* ob;
    std::pair<Coordinate, char> state; // state pair格式: <发生更改的cell的坐标, 更新后的char>
public:
    void notifyObserver();
    void attach(Observer* _ob);
    std::pair<Coordinate, char> getState() const;
    void setState(std::pair<Coordinate, char> newState);

};

#endif
