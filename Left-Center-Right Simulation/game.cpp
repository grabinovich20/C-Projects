#include "player.h"
#include "Node.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

int chipCenter = 0;

int numberOfPlayers(){
    int number;
    bool test = true;
    while(test != false){
        cout<< "How many players are playing (must be three or more): ";
        cin >> number;
        if(cin.fail() || number < 3){
            cerr << "Invalid input" << endl;
        }else{
            test = false;
        }
    }
    return number;
}

vector<string> getName(int number){
    vector<string> v;
    string playerName;
    bool test1 = true;
    for(int i = 1; i <= number; i++){
        do{
            cout<<"Player " << i << " please enter your name: ";
            cin >> playerName;
            if(cin.fail()){
                cerr << "Invalid input" << endl;
            }else{
                test1 = false;
            }
        }while(test1 != false);
        v.push_back(playerName);
    }
    return v;
}

vector<int> dieRandomNumber(int VALUE){
    vector<int> v;
    int randomNumber;
    rand();
    for(int i = 0; i < VALUE; i++){
        randomNumber = rand()%8;
        v.push_back(randomNumber);
    }
    return v;
}

Node* linked_list_make_node(int VALUE, string playerName) {
    Node* pNode = new Node;
    pNode->value = VALUE;
    pNode->name = playerName;
    pNode->pNext = nullptr;
    pNode->pPrev = nullptr;
    return pNode;
}

void linked_list_add_value_to_back(Node*& pHead, Node*& pTail, int VALUE, string playerName) {
    // make new node
    Node* pNewNode = linked_list_make_node(VALUE, playerName);
    // if list is initially empty
    
        // head and tail are the new node                       
    if(pHead == nullptr){
        pHead = pNewNode;
        pTail = pNewNode;
    }else{
        pNewNode->pNext = nullptr;
        pNewNode->pPrev = pTail;
        pTail->pNext = pNewNode;
        pTail = pNewNode;
    }
}

void linkedList(Node*& pHead, Node*& pTail, string playerName){
    linked_list_add_value_to_back(pHead, pTail,3,playerName);
    pTail->pNext = pHead;
    pHead->pPrev = pTail;

}
