#include "quadrilateral.h"
#include <iostream>
#include <cmath>

Quadrilateral::Quadrilateral()
: a(), b(), c(), d() {};

Quadrilateral::Quadrilateral(Point a, Point b, Point c, Point d)
: a(a), b(b), c(c), d(d) {};

Quadrilateral::Quadrilateral(const Quadrilateral &other) 
: a(other.a), b(other.b), c(other.c), d(other.d) {};

bool Quadrilateral::equals(const Quadrilateral &other) {
    return a.equals(other.a) && b.equals(other.b) && c.equals(other.c) && d.equals(other.d);
}

void Quadrilateral::flip() {
    a.flip();
    b.flip();
    c.flip();
    d.flip();
}

void Quadrilateral::move(double x, double y) {
    a.move(x, y);
    b.move(x, y);
    c.move(x, y);
    d.move(x, y);
}

double Quadrilateral::getSurface() {
    return fabs( a.getX() * (b.getY() - d.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (d.getY() - b.getY()) + d.getX() * (a.getY() - c.getY()) ) * 0.5;
}
    
std::string Quadrilateral::toString() {
    return "Quadrilateral(" + a.toString() + ", " + b.toString() + ", " + c.toString() + ", " + d.toString() +")";
}