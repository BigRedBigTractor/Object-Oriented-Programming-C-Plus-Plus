#include "RPG.h"
#include <iostream>

using namespace std; 

// Function to display the current stats of both characters 
void displayStats(RPG* p1, RPG* p2){
    cout << p1->getName() << " health: " << p1->getHealth() << " "; 
    cout << p2->getName() << " health: " << p2->getHealth() << endl; 
}

//function to run the game loop until one player is defeated 
void gameLoop(RPG* p1, RPG* p2){
    //Continue while both players are alive
    while (p1->isAlive() && p2->isAlive()){
        // Display stats
        displayStats(p1, p2); 

        //Player 1's turn 
        cout << p1->getName() << "'s turn" << endl; 
        p1->useSkill(p2);  
        cout <<"-----------------------------\n"; 

        // check if player 2 is still alive before their turn
        if (!p2->isAlive()) break; 

        displayStats(p1, p2); 

        //Player 2's turn 
        cout << p2->getName() << "'s turn" << endl; 
        p2->useSkill(p1); 
        cout <<"-----------------------------\n"; 
    }
}
//function to determine and display the winner
void displayEnd(RPG p1, RPG p2){
    if(p1.isAlive()){
        cout << p1.getName() << " defeated " << p2.getName() << "! Good game!\n"; 
    } else if (p2.isAlive()){
        cout << p2.getName() << " defeated " << p1.getName() << "! Good game!\n"; 
    } else {
        cout << "It's a draw! Both players have fallen.\n"; 
    }
}
int main(){
    RPG p1 = RPG("Wiz", 70, 45, 15, "mage"); 
    RPG p2 = RPG(); 

    gameLoop(&p1, &p2); 
    displayEnd(p1, p2); 

    return 0;
}