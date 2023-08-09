#ifndef ONE_H
#define ONE_H

#include "connect.h"
#include <iostream>

class Player : public ConnectFour{
    public:
        void placeChip() override;
        //std::string getPlayer() const;
        //void setPlayer(std::string name);
    //private:
        //std::string playerName;
};

#endif