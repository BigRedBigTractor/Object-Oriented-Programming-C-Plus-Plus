#ifndef RPG_H
#define RPG_H
#include <string>
using namespace std; 

const int SKILL_SIZE = 2; 

class RPG{
    public:
    //---------Constructors-----------
    RPG(); 
    RPG(string name, int health, int strength, int defense, string type);
    //--------Mutators-----------
    void setSkills(); 
    void updateHealth(int); 

    // Commenting out unimplemented functions
    void printAction(string, RPG); 
    void attack(RPG *); 
    void useSkill(RPG *);

    //--------Accessors-------
    string getName() const; 
    bool isAlive() const; 
    int getHealth() const; 
    int getStrength() const; 
    int getDefense() const; 

    private: 
    string name;
    int health; 
    int defense; 
    int strength;
    string type; // warrior, mage, thief archer
    string skills[SKILL_SIZE];  
};
#endif