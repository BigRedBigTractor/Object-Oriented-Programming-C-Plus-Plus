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
    printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str()); 
}
// Updates health
void RPG::updateHealth(int new_health){
    health = new_health; 
}
// CHecks if the character is alive 
bool RPG::isAlive() const{
    return health >0; 
}
void RPG::attack(RPG * opponent){
    // Calculate damage considering strength and opponent's defense 
    int damage = strength - opponent->getDefense(); 

    //ensure damage is not negative 
    if (damage < 0) damage = 0; 

    // calculate new health of the opponent
    int new_health = opponent->getHealth() - damage; 

    // Ensure health does not drop below zero
    if (new_health < 0) new_health = 0; 

    //update opponent's health 
    opponent->updateHealth(new_health); 

    // display attack message 
    // cout << name << " attacks " << opponent->getName() << " for " << damage << " damage!" << endl; 
}
void RPG::useSkill(RPG * opponent){
    // Display available skills
    for (int i = 0; i < SKILL_SIZE; i++){
        printf("Skill %i: %s\n", i, skills[i].c_str());
    }
    //prompt the user to select skill
    int chosen_skill_index; 
    cout << "Choose a skill to use: Enter 0 or 1\n"; 
    cin >> chosen_skill_index; 

    //validate input
    if (chosen_skill_index < 0 || chosen_skill_index >= SKILL_SIZE){
        cout << "Invalid choice! Defaulting to skill 0.\n"; 
        chosen_skill_index = 0; 
    } 

    //get chosen skill
    string chosen_skill = skills[chosen_skill_index];

    //call printAction() to display the action
    printAction(chosen_skill, *opponent); 
    
    // call attack() on the opponent 
    attack(opponent); 
}
