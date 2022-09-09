#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
using namespace std;

class Character {
public:
    //The follwing are setters and getters for the character class which is the main body of the player
    Character();
    Character(string _name, int _level, int _health, int _basic, int _chance);
    void setName(string _name) { name = _name; };   //character's name
    void setLevel(int _level) { level = _level; };  //character's level
    void setHealth(int _health) { health = _health; };  //character's health
    void setBasic(int _basic) { basic = _basic; };     //character's basic damage output 
    void setChance(int _chance) { chance = _chance; }; //chanracter's chance of hitting their opentent with the special ability
    string getName() { return name; };
    int getLevel() { return level; };
    int getHealth() { return health; };
    int getBasic() { return basic; };
    int getChance() { return chance; };
    void increaseHealth();
    void increaseLevel();
    void increaseBasic();

    //virutal functions for quotes and creating/getting the player's special ability
    virtual void quoteATT() = 0;    //ATT means attack
    virtual void quoteDEF() = 0;    //DEF means defend
    virtual void quoteSPE() = 0;    //SPE means special
    virtual void quoteWIN() = 0;    //WIN means win
    virtual void setAbility(int) = 0;
    virtual int getAbility() = 0;
    virtual int upgradeAbility() = 0;
    virtual ~Character();

private:
    string name;
    int level, health, basic, chance;
};

Character::Character()
{
    name = "";
    level = 0;
    health = 20;
    basic = 1;
    chance = 1;
}

Character::Character(string _name, int _level, int _health, int _basic, int _chance)
{
    name = _name;
    level = _level;
    health = _health;
    basic = _basic;
    chance = _chance;
}

Character::~Character()
{
    cout << "Character destroyed." << endl;
}

void Character::increaseHealth() //increase health when 'defend' is chosen
{
    if(health < 100)
    {
        health++;
    }
}

void Character::increaseLevel() //increase level when duel is won
{
    if(level < 5)
    {
        level++;
    }
}

void Character::increaseBasic() //increase basic output when duel is won
{
    if(basic < 5)
    {
        basic++;
    }
}

#endif