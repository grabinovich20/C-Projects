/* CSCI200 Final Project: Connect Four
 *
 * Gary Rabinovich
 * 
 * For this assignment, we will write a program that allows two players
 * to compete with each other in a game of Connect Four.
 *
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "connect.h"
#include "player.h"

using namespace std;

int main(){
    Player one;
    string player1,player2,winner,yN,yN2,file;
    bool test = false;
    int turn;

    cout << "Welcome to the Connect Four Game! For this game two players are needed. \n" 
    << "When it is your turn, please enter the column you would like to place your chip into \n";
    cout << "A '*' means the space is free, 'X' and 'O' means it is occupied! \n" << endl;
 
    cout << "We will save each move to the game in a file. Would you like to name your file? \n" 
         << "If no is selcted the file will be named results. If yes, type Y, if no, type N: ";
    cin >> yN2;
    if(yN2 == "Y" || yN2 == "y"){
        cout << "\n What would you like to name your file: ";
        cin >> file;
        file = file + ".txt";
    }else if(yN2 == "N" || yN2 == "n"){
        cout << "\n Your file will be named results \n" << endl;
        file = "results.txt";
    }else{
        cout << "\n Neither Y or N was typed, the file will be named results! \n" << endl;
        file = "results.txt";
    }
    ofstream out;
    out.open(file);
    if(out.fail()){
        cerr << "Could not open file!" << endl; 
    }

    cout << "Player 1 please enter your name: ";
    cin >> player1;
    cout << "Your symbol is X" << endl;
    cout << "\n" << endl;

    cout << "Player 2 please enter your name: ";
    cin >> player2;
    cout << "Your symbol is O" << endl;
    cout << "\n" << endl;

    one.setThere();
    one.setChip();
    one.setPlayers(player1,player2);
    one.setTurn(0);
    one.displayGame(out);
    cout << "\n" << endl;
    out << "\n";
    while(test != true){
        one.placeChip();
        one.displayGame(out);
        cout << "\n" << endl;
        out << "\n";
        test = one.checkWin();
        if(one.checkDraw()){
            cout << "It's a draw! \n" << endl;
            out << "It's a draw! \n";
            return 0;
        }
    }
    turn = one.getTurn();
    if(turn == 0){
        winner = player2;
    }else if(turn == 1){
        winner = player1;
    }
    cout << winner <<" wins! \n" << endl;
    out << winner <<" wins! \n";
    out.close();
    cout << "Do you want to play agin? Enter Y for yes and N for no: ";
    cin >> yN;
    if(yN == "Y" || yN == "y"){
        main();
    }else if(yN == "N" || yN == "n"){
        cout << "\n Thank you for playing! \n" << endl;
    }else{
        cout << "\n Neither Y or N was typed, the game will be reset! \n" << endl;
    }
    return 0;
}