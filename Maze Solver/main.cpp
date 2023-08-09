/* CSCI200 Assignment 5: a-MAZE-ing
 *
 * Gary Rabinovich
 * 
 * We will now combine the two-dimensional lists, stacks, and queues 
 * to implement a Maze solver using Breadth-First Search and Depth-First Search.
 *
 */

#include "maze.h"

int main(){
    int R,C,choice,x,y;
    ifstream in;
    ofstream out;
    string name;
    char **pArray = nullptr;
    bool **visited = nullptr;
    if(!openMaze(in,name)){
        return -1;
    }
    readMaze(in,pArray,visited,R,C,x,y);
    checkValid(visited,pArray,R,C);

    cout << "Enter 1 to search via BFS. \n" << "Enter 2 to search via DFS. \n" << "Choice: ";
    cin >> choice;
    if(choice == 1){
        BFS(visited,pArray,R,C);
        text(out,pArray,x,y);
        text2(pArray,x,y);
    }else if(choice == 2){
        DFS(visited,pArray,R,C);
        text(out,pArray,x,y);
        text2(pArray,x,y);
    }else{
        cerr << "Plese enter 1 or 2" << endl;
        return -1;
    }
    return 0;
}