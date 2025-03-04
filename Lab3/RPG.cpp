#include "RPG.h"
#include <iostream> 
using namespace std; 

// Default constructor 
RPG::RPG(){
    name = "NPC"; 
    health = 100; 
    strength = 10; 
    defense = 10; 
    type = "warrior"; 
    skills[0] = "slash"; 
    skills[1] = "parry"; 
}

RPG::RPG(string name, int health, int strength, int defense, string type) {
    this->name = name; 
    this->health = health; 
    this->strength = strength; 
    this->defense = defense; 
    this->type = type; 

    setSkills();
}

// Accessor method definitions
string RPG::getName() const {
    return name;
}

int RPG::getHealth() const {
    return health;
}

int RPG::getStrength() const {
    return strength;
}

int RPG::getDefense() const {
    return defense;
}

/**
 * @brief sets the skills based ont he RPG's Rle
 * 
 */
void RPG::setSkills(){
    if (type == "mage"){
        skills[0] = "fire"; 
        skills[1] = "thunder"; 
    } else if(type == "thief"){
        skills[0] = "pilfer"; 
        skills[1] = "jab";
    } else if(type == "archer"){
        skills[0] = "parry"; 
        skills[1] = "crossbow_attack";
    } else{
        skills[0] = "slash"; 
        skills[1] = "parry";
    }
}
// Print Action
void RPG::printAction(string skill, RPG opponent){
    printf("%s uesd %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str()); 
}
// Updates health
void RPG::updateHealth(int new_health){
    health = new_health; 
}
// CHecks if the character is alive 
bool RPG::isAlive() const{
    return health >0; 
}