/* Wild Left-Center-Right Simulation
 *
 * Gary Rabinovich
 * 
 * We're going to create a game simulation of several people 
 * playing Left-Center-Right.
 *
*/

#include <iostream>
#include "run.h"
#include "player.h"
#include "game.h"

using namespace std;



int main(){
    int number = 0;
    string winningName = "";
    if(runGame(winningName, number)){
        cout << winningName << " wins!" << endl;
    }
    return 0;
}