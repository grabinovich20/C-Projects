#include "Triangle.h"
using namespace sf;
#include <iostream>
#include <list>
using namespace std;

void Triangle::setColor(const Color color){
    mcolor = color;
}

void Triangle::draw(RenderTarget& window){
    ConvexShape convex;
    convex.setPointCount(3);
    convex.setPoint(0,Vector2f(coordinates[0],coordinates[1]));
    convex.setPoint(1,Vector2f(coordinates[2],coordinates[3]));
    convex.setPoint(2,Vector2f(coordinates[4],coordinates[5]));
    convex.setFillColor(mcolor);
    window.draw(convex);
}

void Triangle::setList(vector<double> v){
    coordinates = v;
}