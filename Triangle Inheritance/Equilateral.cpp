#include "Equilateral.h"
#include <cmath>

using namespace std;

bool EquilateralTriangle::setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3){
    int l1,l2,l3;
    l1 = sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
    l2 = sqrt(pow((x3 - x1),2) + pow((y3 - y1),2));
    l3 = sqrt(pow((x3 - x2),2) + pow((y3 - y2),2));
    if(l1 > 0 && l2 > 0 && l3 > 0 && l1 + l2 > l3 && l2 + l3 > l1 && l3 + l1 > l2){
        if((l1 == l2 && l2 == l3)){
            return true;
        }
    }
    return false;
}