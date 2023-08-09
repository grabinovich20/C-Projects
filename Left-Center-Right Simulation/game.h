#ifndef game
#define game

#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

int numberOfPlayers();
vector<string> getName(int number);
vector<int> dieRandomNumber(int VALUE);
Node* linked_list_make_node(int VALUE, string playerName);
void linked_list_add_value_to_back(Node*& pHead, Node*& pTail, int VALUE, string playerName);
void linkedList(Node*& pHead, Node*& pTail, string playerName);


#endif 