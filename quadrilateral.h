#ifndef QUADRILATERAL
#define  QUADRILATERAL
#include "point.h"
#include "triangle.h"
#include <iostream>

class Quadrilateral {
private:
    Point a;
    Point b;
    Point c;
    Point d;
public:
    Quadrilateral();

    Quadrilateral(Point a, Point b, Point c, Point d);

    Quadrilateral(const Quadrilateral &other);

    bool equals(const Quadrilateral &other);

    void flip();

    void move(double x, double y);

    double getSurface();
    
    std::string toString();
};

#endif