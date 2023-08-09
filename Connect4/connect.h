#ifndef CONN_H
#define CONN_H

#include <iostream>
#include <fstream>

class ConnectFour{
    public:
        virtual void placeChip() = 0;
        bool checkValid(int col);
        bool checkWin();
        bool checkDraw();
        void displayGame(std::ofstream &out);
        void setThere();
        bool getThere(int R, int C) const;
        void setChip();
        char getChip(int R, int C) const;
        void setPlayers(std::string p1, std::string p2);
        void setTurn(int num);
        int getTurn() const;
    protected:
        bool **pThere;
        char **pChip;
        std::string player1;
        std::string player2;
        int turn;
};

#endif