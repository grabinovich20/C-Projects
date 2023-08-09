/* CSCI200 Assignment 6: SFML: Triangle Land
 *
 * Gary Rabinovich
 * 
 * For this assignment, we will write a program to read in a list of triangle data 
 * and draw an image comprised of those triangles.
 *
 */

#include <iostream>
using namespace std;
#include "Scalene.h"
#include "Triangle.h"
#include "Isosceles.h"
#include "Equilateral.h"
#include <vector>
#include <fstream>
using namespace sf;



int main(){
    vector<Triangle*> list;
    vector<vector<double>> v;
    vector<Color> color;
    ifstream in;
    char T;
    int r,g,b;
    double x1,y1,x2,y2,x3,y3;
    in.open("triangles.dat.txt");
    if(in.fail()){
        cerr << "Couldn't open file" << endl;
        return -1;
    }
    while(!in.eof()){
        in >> T >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> r >> g >> b;
        Triangle *pTriangle = nullptr;
        if(T == 'E'){
            pTriangle = new EquilateralTriangle;
        }else if(T == 'S'){
            pTriangle = new ScaleneTriangle;
        }else if(T == 'I'){
            pTriangle = new IsoscelesTriangle;
        }
        if(pTriangle->setCoordinates(x1,y1,x2,y2,x3,y3)){
            //pTriangle->setColor(Color(r,g,b));
            list.push_back(pTriangle);
            vector<double> temp;
            temp.push_back(x1);
            temp.push_back(y1);
            temp.push_back(x2);
            temp.push_back(y2);
            temp.push_back(x3);
            temp.push_back(y3);
            color.push_back(Color(r,g,b));
            v.push_back(temp);
            pTriangle = nullptr;
        }else{
            cout << "triangle is invalid - " << T << " " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << " " << r << " " << g << " " << b << endl;
        }
    }

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING
    RenderWindow window( VideoMode(620,620), "SFML Test" );
    // perform any file processing once before draw loop begins

    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // create an event object once to store future events
    Event event;

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();

        /////////////////////////////////////
        // BEGIN DRAWING HERE
        for(int i = 0; i < list.size(); i++){
            Triangle *tri = list.at(i);
            tri->setList(v.at(i));
            tri->setColor(color.at(i));
            tri->draw(window);
        }

        // place any draw commands here to display in the window

        //  END  DRAWING HERE
        /////////////////////////////////////


        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }

    return 0;
}
