#include <iostream>
#include <fstream>
#include "maze.h"
#include <queue>
#include <stack>

using namespace std;

bool openMaze(ifstream &in, string &name){
    string c;
    cout << "Please enter the name of your file that contains the maze (add the .maze!): ";
    cin >> c;
    name = c;
    cout << "\n Opening file " << name << endl;

    string directory = "mazePack/" + name;
    in.open(directory);
    if(in.fail() ) {
        cerr << "Error opening input file" << endl;
        return false;
    }else{
        cout << "File opened successfully!" << endl;
        return true;
    }
}


void readMaze(ifstream &in, char **&pArray, bool **&visited, int &R, int &C, int &x, int &y){
    in >> R >> C;
    x = R;
    y = C;
    pArray = new char*[R];
    for(int i = 0; i < R; i++){
        pArray[i] = new char[C];
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            in >> pArray[i][j];
        }
    }
    visited = new bool*[R];
    for(int i = 0; i < R; i++){
        visited[i] = new bool[C];
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            visited[i][j] = false;
        }
    }  
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(pArray[i][j] == 'S'){
                R = i;
                C = j;
                break;
            }
        }
    } 
}


bool checkValid(bool **&visited, char **&pArray, int R, int C){ 
    int r = R, c = C;
    if(R < 0 || C < 0 || R > r || C > c){
        return false;
    }
    if (visited[R][C] == true){
        return false;
    }
    if(pArray[R][C] == '#'){
        return false;
    }
    return true;
}

void text(ofstream &out, char **&pArray, int x, int y){
    out.open("soluiton.txt");
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            out << pArray[i][j];
            if(j == y - 1){
                out << "\n";
            }
        }
    }
}

void text2(char **&pArray, int x, int y){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cout << pArray[i][j];
            if(j == y - 1){
                cout << "\n";
            }
        }
    }
}

void BFS(bool **&visited, char **&pArray, int &R, int &C){
    int dR[] = { -1, 0, 1, 0 };
    int dC[] = { 0, 1, 0, -1 };
    queue<pair<int, int> > q;
    q.push({R,C});
    visited[R][C] = true;

    while(!q.empty()){
        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int adjx = x + dR[i];
            int adjy = y + dC[i];
            if(checkValid(visited,pArray,adjx,adjy) == true){
                if(pArray[adjx][adjy] == 'E'){
                    cout << "End was reached!" << endl;
                    return;
                }
                q.push({ adjx, adjy });
                visited[adjx][adjy] = true;
                pArray[adjx][adjy] = '@';
            } 
        }
    }
    cout << "End can not be reached!" << endl;
}

void DFS(bool **&visited, char **&pArray, int &R, int &C){
    int dR[] = { 0, 1, 0, -1 };
    int dC[] = { -1, 0, 1, 0 };
    stack<pair<int, int> > s;
    s.push({R,C});
    while(!s.empty()){
        pair<int, int> cell = s.top();
        s.pop();
        int row = cell.first;
        int col = cell.second;
        if(checkValid(visited,pArray,row,col) == true){
            if(pArray[row][col] == 'E'){
                cout << "End was reached!" << endl;
                return;
            }
            if(pArray[row][col] != 'S'){
                pArray[row][col] = '@';
            }
            visited[row][col] = true;
            for(int i = 0; i < 4; i++){
                int adjx = row + dR[i];
                int adjy = col + dC[i];
                s.push({ adjx, adjy });
            }
        }       
    }
    cout << "End can not be reached!" << endl;
}
