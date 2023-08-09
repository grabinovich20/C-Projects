#ifndef run
#define run

#include <iostream>
#include "Node.h"

using namespace std;

bool runGame(string &winningName, int &number1);
bool isWin(Node* pHead, int num_players);
void winnerName(Node* pHead, string& name);
#endif