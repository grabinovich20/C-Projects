#ifndef TRI_H
#define TRI_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;

class Triangle{
    public:
        void setColor(const Color color);
        void draw(RenderTarget& window);
        virtual bool setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3) = 0;
        void setList(std::vector<double> v);
    protected:
        int verticies;
        std::vector<double> coordinates;
    private:
        Color mcolor;
};

#endif
