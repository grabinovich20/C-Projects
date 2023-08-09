#ifndef SCA_H
#define SCA_H

#include "Triangle.h"

class ScaleneTriangle : public Triangle{
    bool setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3) override;
};

#endif
