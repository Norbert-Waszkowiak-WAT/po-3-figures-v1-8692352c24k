#include "group.h"
#include <iostream>
#include <vector>

Group::Group()
: lines({}), triangles({}), quadrilaterals({}) {};

Group::Group(const Group &other) 
: lines(other.lines), triangles(other.triangles), quadrilaterals(other.quadrilaterals) {};

bool Group::equals(Group &other) {
    int sizelines = lines.size();
    int sizetriangles = triangles.size();
    int sizequadrilaterals = quadrilaterals.size();

    for (int i = 0; i < sizelines; i++) {
        for (int j = 0; j < sizelines; j++) {
            if (!lines[i].equals(other.lines[j]))
                return false;
        }
    }
    for (int i = 0; i < sizetriangles; i++) {
        for (int j = 0; j < sizetriangles; j++) {
            if (!triangles[i].equals(other.triangles[j]))
                return false;
        }
    }
    for (int i = 0; i < sizequadrilaterals; i++) {
        for (int j = 0; j < sizequadrilaterals; j++) {
            if (!quadrilaterals[i].equals(other.quadrilaterals[j]))
                return false;
        }
    }
    return true;
}

void Group::remove(Line l) {
     int index = -1;
   for (std::vector<Line>::size_type i = 0; i < lines.size(); ++i) {
       if (lines[i].equals(l))
           index = i;
        break;
   }
   
   if (index != -1)
       lines.erase(lines.begin() + index);
}

void Group::remove(Triangle t) {
    int index = -1;
   for (std::vector<Triangle>::size_type i = 0; i < triangles.size(); ++i) {
       if (triangles[i].equals(t))
           index = i;
        break;
   }
   
   if (index != -1)
       triangles.erase(triangles.begin() + index);
}

void Group::remove(Quadrilateral q) {
    int index = -1;
   for (std::vector<Quadrilateral>::size_type i = 0; i < quadrilaterals.size(); ++i) {
       if (quadrilaterals[i].equals(q))
           index = i;
        break;
   }
   
   if (index != -1)
       quadrilaterals.erase(quadrilaterals.begin() + index);
}

void Group::add(Line l) {
    lines.push_back(l);
}

void Group::add(Triangle t) {
    triangles.push_back(t);
}

void Group::add(Quadrilateral q) {
    quadrilaterals.push_back(q);
}

double Group::getSurface() {
    double result = 0;
    for (auto triangle : triangles)
        result += triangle.getSurface();
    
    for (auto quadrilateral : quadrilaterals)
        result += quadrilateral.getSurface();
   
    return result;
}

void Group::flip() {
    for (auto& line : lines) {
        line.flip();
    }

    for (auto& triangle : triangles) {
        triangle.flip();
    }

    for (auto& quadrilateral : quadrilaterals) {
        quadrilateral.flip();
    }
}

void Group::move(double x, double y) {
    for (auto& line : lines) {
        line.move(x, y);
    }

    for (auto& triangle : triangles) {
        triangle.move(x, y);
    }

    for (auto& quadrilateral : quadrilaterals) {
        quadrilateral.move(x, y);
    }
}

std::string Group::toString() {
    std::string result = "Group(";

    for (auto line : lines) {
        result += line.toString() + ", ";
    }

    for (auto triangle : triangles) {
        result += triangle.toString() + ", ";
    }

    for (auto quadrilateral : quadrilaterals) {
        result += quadrilateral.toString() + ", ";
    }

    result += ")";
    return result;
}