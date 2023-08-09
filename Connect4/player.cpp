#include "player.h"
#include <iostream>

using namespace std;

void Player::placeChip(){
    int choice,choice2;
    bool test = false;
    if(turn == 0){
        do{
            cout << player1 << " it is your turn. Please type a number (1-7) of which column you would like to place your chip in." << endl;
            cout << " 1 is the left most side, 7 is the right most side." << endl;
            cout << "Column: ";
            cin >> choice;
            if(cin.fail()){
                cout << "Please enter a NUMBER between 1 and 7 \n" << endl;
                cin.clear();
                cin.ignore();
                continue;
            }
            cout << "\n" << endl;
            test = checkValid(choice);
        }while(test != true);
        for(int i = 5; i >= 0; i--){
            if(pThere[i][choice - 1] == true){
                continue;
            }else if(pThere[i][choice - 1] == false){
                pChip[i][choice - 1] = 'X';
                pThere[i][choice - 1] = true;
                break;
            }
        }
        turn = 1;
    }else if(turn == 1){
        do{
            cout << player2 << " it is your turn. Please type a number (1-7) of which column you would like to place your chip in." << endl;
            cout << " 1 is the left most side, 7 is the right most side." << endl;
            cout << "Column: ";
            cin >> choice2;
            if(cin.fail()){
                cout << "Please enter a NUMBER between 1 and 7 \n" << endl;
                cin.clear();
                cin.ignore();
                continue;
            }
            cout << "\n" << endl;
            test = checkValid(choice2);
        }while(test != true);
        for(int i = 5; i >= 0; i--){
            if(pThere[i][choice2 - 1] == true){
                continue;
            }else if(pThere[i][choice2 - 1] == false){
                pChip[i][choice2 - 1] = 'O';
                pThere[i][choice2 - 1] = true;
                break;
            }
        }
        turn = 0;
    }
}

/*
string Player::getPlayer() const{
    return playerName;
}

void Player::setPlayer(string name){
    playerName = name;
}
*/