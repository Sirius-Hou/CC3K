#include <iostream>
#include "coordinate.h"

std::ostream& operator<<(std::ostream& out, Coordinate& cdn) {
    out << "(" << cdn.x << "," << cdn.y << ")";
    return out;
}


bool operator<(const Coordinate cdn1, const Coordinate cdn2) {
    return (cdn1.x + cdn1.y) < (cdn2.x + cdn2.y);
}
