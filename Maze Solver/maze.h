#ifndef MAZE
#define MAZE

#include <iostream>
#include <fstream>

using namespace std;

bool openMaze(ifstream &in, string &name);
void readMaze(ifstream &in, char **&pArray, bool **&visited, int &R, int &C, int &x, int &y);
bool checkValid(bool **&visited, char **&pArray, int R, int C);
void text(ofstream &out, char **&pArray, int x, int y);
void text2(char **&pArray, int x, int y);
void BFS(bool **&visited, char **&pArray, int &R, int &C);
void DFS(bool **&visited, char **&pArray, int &R, int &C);

#endif