#include "RPG.h"
#include <iostream>

using namespace std; 

int main(){
    // Create an RPG object using the default construcutor 
    RPG character1; 
    
    // Create an RPG object using the overload constructor 
    RPG character2("Hero", 150, 20, 15, "mage"); 

    // Test accessor Functions 
    cout << "Is " << "Character 1: " << character1.getName() << "| Health: " << character1.getHealth()<< endl; 
    cout << "Is " << "Character 2: " << character2.getName() << "| Health: " << character2.getHealth()<< endl; 

    // Check if characters are alive 
    cout << "Is " << character1.getName() << " alive? " << (character1.isAlive() ? "Yes" : "No") << endl; 
    cout << "Is " << character2.getName() << " alive? " << (character2.isAlive() ? "Yes" : "No") << endl; 

    // Test updateHealth()
    cout << "Updating " << character1.getName() << "'s health to 0..." << endl; 
    character1.updateHealth(0); 

    cout << "Is " << character1.getName() << " alive now?" << (character1.isAlive() ? "Yes" : "NO") << endl; 

    return 0;
}