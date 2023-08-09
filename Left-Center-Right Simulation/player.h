#ifndef PLAYER_H
#define PLAYER_H

#include "Node.h"
#include "game.h"
#include <iostream>
#include <string>

using namespace std;

class Player{
    public:
        void setPlayer(string pName);
        void playerNumberOfChips(int VALUE);
        void giveChipToPlayer(Node* pturn, int direction);
        int giveChipToCenter(Node* pturn, int &chipsCenter);
        string getPlayerName();
        int getPlayerNumberOfChips();
    private:
        int value;
        string playerName;
};
#endif


