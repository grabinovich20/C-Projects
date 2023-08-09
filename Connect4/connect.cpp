#include "connect.h"

using namespace std;

bool ConnectFour::checkValid(int col){
    if(col <= 0 || col > 7){
        cout << "The column entered is not in between 1 and 7" << endl;
        return false;
    }else if(pThere[0][col-1] == true){
        cout << "This column is already full, please enter in a different one" << endl;
        return false;
    }
    return true;
}

bool ConnectFour::checkWin(){
    char symbol;
    if(turn == 1){
        symbol = 'X';
    }else if(turn == 0){
        symbol = 'O';
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
                if(i+1 < 6 && j+1 < 7 && i+2 < 6 && j+2 < 7 && i+3 < 6 && j+3 < 7){
                    if(pChip[i][j] == symbol && pChip[i+1][j+1] == symbol && pChip[i+2][j+2] == symbol && pChip[i+3][j+3] == symbol){
                        return true;
                    }
                }
                if(i+1 < 6 && j-1 >= 0 && i+2 < 6 && j-2 >=0 && i+3 < 6 && j-3 >= 0){ 
                    if(pChip[i][j] == symbol && pChip[i+1][j-1] == symbol && pChip[i+2][j-2] == symbol && pChip[i+3][j-3] == symbol){
                        return true;
                    }
                }
                if(j-1 >= 0 && j-2 >= 0 && j-3 >= 0){
                    if(pChip[i][j] == symbol && pChip[i][j-1] == symbol && pChip[i][j-2] == symbol && pChip[i][j-3] == symbol){
                        return true;
                    }
                }
                if(i+1 < 6 && i+2 < 6 && i+3 < 6){
                    if(pChip[i][j] == symbol && pChip[i+1][j] == symbol && pChip[i+2][j] == symbol && pChip[i+3][j] == symbol){
                        return true;
                    }
                }
        }
    }
    return false;
}

bool ConnectFour::checkDraw(){
    int count = 0;
    for(int i = 0; i < 7; i++){
        if(pThere[0][i] == true){
            count++;
        }
        if(count == 7){
            return true;
        }
    }
    return false;
}

void ConnectFour::displayGame(ofstream &out){
    cout << "  1  2  3  4  5  6  7  " << endl;
    for(int i = 0; i < 6; i++){
		cout << "|";
        out << "|";
		for(int j = 0; j < 7; j++){
			if(pChip[i][j] != 'X' && pChip[i][j] != 'O'){
				pChip[i][j] = '*';
            }
            
			cout << " " << pChip[i][j] << " ";
            out << " " << pChip[i][j] << " ";
			
		}

		cout << "|" << endl;
        out << "|" << endl;
	}
}

void ConnectFour::setThere(){
    bool **visited = new bool*[6];
    for(int i = 0; i < 6; i++){
        visited[i] = new bool[7];
    }

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            visited[i][j] = false;
        }
    } 
    pThere = visited;
}

bool ConnectFour::getThere(int R, int C) const{
    return pThere[R][C];
}

void ConnectFour::setChip(){
    char **set = new char*[6];
    for(int i = 0; i < 6; i++){
        set[i] = new char[7];
    }

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            set[i][j] = ' ';
        }
    } 
    pChip = set;
}

char ConnectFour::getChip(int R, int C) const{
    return pChip[R][C];
}

void ConnectFour::setPlayers(string p1, string p2){
    player1 = p1;
    player2 = p2;
}

void ConnectFour::setTurn(int num){
    turn = num;
}

int ConnectFour::getTurn() const{
    return turn;
}