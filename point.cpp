#include <sstream>
#include <iomanip> 
#include "point.h"

Point::Point()
: x(), y() {};

Point::Point(double x, double y) 
: x(x), y(y) {};

Point::Point(const Point &other)
: x(other.x), y(other.y) {};

bool Point::equals(const Point &other) {
    return other.x == x && other.y == y;
}

double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}

void Point::flip() {
    x *= -1;
    y *= -1;
}

void Point::move(double x, double y){
    this->x += x;
    this->y += y;
}

std::string Point::toString(){
    std::ostringstream oss; 
    oss << std::fixed << std::setprecision(1);
    oss << "Point(" << x << ", " << y << ")";
    return oss.str();
}