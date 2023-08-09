#include "player.h"

int chipsCenter = 0;

//gives player name
void Player::setPlayer(string pName){
    playerName = pName;
}

//gives number of chips of a player
void Player::playerNumberOfChips(int VALUE){
     value = VALUE;
}

//gives the chip to the proper player, takes away from the other
void Player::giveChipToPlayer(Node* pturn, int direction){
        if(direction == 0){
            pturn->pNext->value += 1; 
            pturn->value -= 1;
        }else if(direction == 1){
            pturn->pPrev->value += 1; 
            pturn->value -= 1;
        }
}

// gives the chip to the center
int Player::giveChipToCenter(Node* pturn, int &chipsCenter){
    pturn->value -= 1;
    chipsCenter++;
    return pturn->value;
}

//returns the player name
string Player::getPlayerName() {
    return playerName;
}

//returns the amount of chips the player has
int Player::getPlayerNumberOfChips() {
    return value;
}
