#ifndef ISC_H
#define ISC_H

#include "Triangle.h"

class IsoscelesTriangle : public Triangle{
    bool setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3) override;
};

#endif