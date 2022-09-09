#ifndef WITCH_H
#define WITCH_H

#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

class Witch : public Character {
public:
    //Witch's special ability is the witch's spells or witchcraft
    Witch();
    Witch(string _name, int _level, int _health, int _basic, int _chance, int _spell);
    ~Witch();
    void setAbility(int _spell) { spell = _spell; }; //Witch's special damage output
    int getAbility() { return spell; };
    int upgradeAbility() { return spell * 6; };    //Upgraded special when duel is won
    void quoteATT();
    void quoteDEF();
    void quoteSPE();
    void quoteWIN();

private:
    int spell;
};

Witch::Witch() : Character()
{
    spell = 6;
}

Witch::Witch(string _name, int _level, int _health, int _basic, int _chance, int _spell) : Character(_name, _level, _health, _basic, _chance)
{
    spell = _spell;
}

Witch::~Witch()
{
    cout << "Witch destroyed." << endl;
}

void Witch::quoteATT()
{
    cout << "HOCUS POCUS!" << endl;
}

void Witch::quoteDEF()
{
    cout << "SHIELD SHELL!!" << endl;
}

void Witch::quoteSPE()
{
    cout << "BLIZZARE STORM!!!" << endl;
}

void Witch::quoteWIN()
{
    cout << "No one can defeat me with my spells." << endl;
}

#endif