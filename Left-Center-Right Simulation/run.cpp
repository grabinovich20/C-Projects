#include "game.h"
#include "player.h"
#include <iostream>
#include <ctime>
#include <iomanip>


using namespace std;

//checks to see if there is a winner
bool isWin(Node* pHead, int num_players) {
    Node* pCurNode = pHead;
    int winCount = 0;
    for (int i=1; i <= num_players; i++) {
        if (pCurNode->value == 0) {
            winCount++;
        } 
        pCurNode = pCurNode->pNext;
    }

    return (winCount == num_players -1);
}

//find the winning player's name
void winnerName(Node* pHead, string& name) {
    Node* pCurNode = pHead;
    while (pCurNode != nullptr) {
        if (pCurNode->value != 0) {
          name =  pCurNode->name;
          break;
        } 
        pCurNode = pCurNode->pNext;
    }
}

//runs through the possible senarios of the game
bool runGame(string &winningName, int &number1){
    Node *pHead = nullptr;
    Node *pTail = nullptr;


    //Gets the number of players the user wants to play with

    int number = numberOfPlayers();
    number1 = number;
    vector<string> v = getName(number);

    //creates the amount of players while asking the user for a name

    for(int i = 0; i < number; i++){
        string name = v.at(i);
        linkedList(pHead, pTail, name);
    }
  

    Node* pturn = pHead;
    int chipCenter = 0;
    int direction = 1, rotation = 1, SIZE;
    srand(time(0));
    bool test = false;
  

    Player player;
    while(test != true){
            int skip = 0;
            string name = pturn->name;
            player.setPlayer(name);
            player.playerNumberOfChips(pturn->value); 
            cout << "================" << endl;
            cout << player.getPlayerName() << " has " << player.getPlayerNumberOfChips() << " chips left" << endl;
            vector<int> vSIZE = dieRandomNumber(player.getPlayerNumberOfChips());
            SIZE = vSIZE.size();
            if(SIZE >= 3){
                SIZE = 3;
                    cout << right << setw(13) << "Rolling " << SIZE << " dice" << endl;
            }else{
                    cout << right << setw(13) << "Rolling " << SIZE << " dice" << endl;
            }
            for(int i = 0; i < SIZE; i++){    
                    if(vSIZE.at(i) <= 2){
                        cout << right << setw(14) << "Rolled a " << vSIZE.at(i) << " - keep!" << endl;
                    }else if(vSIZE.at(i) == 3){
                        cout << right << setw(14) << "Rolled a " << vSIZE.at(i) << " - give left - ";
                        direction = 1;
                        player.giveChipToPlayer(pturn,direction);
                        player.setPlayer(name);
                        player.playerNumberOfChips(pturn->value);
                        cout << player.getPlayerName()  << " has " << player.getPlayerNumberOfChips() << " chips left";
                        player.setPlayer(pturn->pPrev->name);
                        player.playerNumberOfChips(pturn->pPrev->value);
                        cout <<  " - " << player.getPlayerName() << " has " << player.getPlayerNumberOfChips() << " chips left"<< endl;
                    }else if(vSIZE.at(i) == 4){
                        cout << right << setw(14) << "Rolled a " << vSIZE.at(i) << " give right - ";
                        direction = 0;
                        player.giveChipToPlayer(pturn,direction);
                        player.setPlayer(name);
                        player.playerNumberOfChips(pturn->value);
                        cout << player.getPlayerName()  << " has " << player.getPlayerNumberOfChips() << " chips left";
                        player.setPlayer(pturn->pNext->name);
                        player.playerNumberOfChips(pturn->pNext->value);
                        cout << " - " << player.getPlayerName() << " has " << player.getPlayerNumberOfChips() << " chips left"<< endl;
                    }else if(vSIZE.at(i) == 5){
                        cout << right << setw(14) << "Rolled a " << vSIZE.at(i) << " give center - ";
                        player.giveChipToCenter(pturn,chipCenter);
                        cout << "Center has " << chipCenter << " chips - ";
                        player.setPlayer(name);
                        player.playerNumberOfChips(pturn->value);
                        cout << player.getPlayerName()  << " has " << player.getPlayerNumberOfChips() << " chips left" << endl;
                    }else if(vSIZE.at(i) == 6){
                        cout << right << setw(14) << "Rolled a " << vSIZE.at(i) << " reverse!" << endl;
                            if(rotation == 1){
                                rotation = -1;
                            }else{
                                rotation = 1;
                            }
                    }else if(vSIZE.at(i) == 7){
                        cout << right << setw(14) << "Rolled a " << vSIZE.at(i) << " skip! Skipping 1 players" << endl;
                        skip++;
                    }
                }
            if(rotation == 1){
                if(skip == 3){
                    pturn = pturn->pNext->pNext->pNext->pNext;
                }else if(skip == 2){
                    pturn = pturn->pNext->pNext->pNext;
                }else if(skip == 1){
                    pturn = pturn->pNext->pNext;
                }else{
                    pturn = pturn->pNext;
                }
            }else if(rotation == -1){
                if(skip == 3){
                    pturn = pturn->pPrev->pPrev->pPrev->pPrev;
                }else if(skip == 2){
                    pturn = pturn->pPrev->pPrev->pPrev;
                }else if(skip == 1){
                            pturn = pturn->pPrev->pPrev;
                }else{
                    pturn = pturn->pPrev;
                }
            }
                bool found = false;
                while(found != true){
                    if(pturn->value == 0){
                        pturn = pturn->pNext;
                    }else{
                        found = true;
                    }
                }
                test = isWin(pHead, number); 
                if (test) {
                    winnerName(pHead, winningName);
                }
        }
    return true;
}




