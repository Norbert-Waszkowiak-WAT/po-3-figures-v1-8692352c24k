#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include <vector>
#include "line.h"
#include "triangle.h"
#include "quadrilateral.h"

class Group {
private:
    std::vector <Line> lines;
    std::vector <Triangle> triangles;
    std::vector <Quadrilateral> quadrilaterals;
public:
    Group();

    Group(const Group &other);

    bool equals(Group &other);

    void remove(Line t);

    void remove(Triangle t);

    void remove(Quadrilateral t);

    void add(Line t);

    void add(Triangle t);

    void add(Quadrilateral t);

    double getSurface();

    void flip();

    void move(double x, double y);

    std::string toString();
};

#endif