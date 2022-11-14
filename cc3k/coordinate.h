#ifndef __COORDINATE_H__
#define __COORDINATE_H__
#include <iostream>

struct Coordinate {
    int x;
    int y;
};

std::ostream& operator<<(std::ostream& out, Coordinate& cdn);

bool operator<(const Coordinate cdn1, const Coordinate cdn2);

#endif
