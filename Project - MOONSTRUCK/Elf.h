#ifndef ELF_H
#define ELF_H

#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

class Elf : public Character {
public:
    //Elf's special ability is the Elf's bow and arrow
    Elf();
    Elf(string _name, int _level, int _health, int _basic, int _chance, int _bow);
    ~Elf();
    void setAbility(int _bow) { bow = _bow; }; //Elf's special damage output
    int getAbility() { return bow; };
    int upgradeAbility() { return bow * 3; };   //Upgraded special when duel is won
    void quoteATT();
    void quoteDEF();
    void quoteSPE();
    void quoteWIN();
    
private:
    int bow;
};

Elf::Elf() : Character()
{
    bow = 3;
}

Elf::Elf(string _name, int _level, int _health, int _basic, int _chance, int _bow) : Character(_name, _level, _health, _basic, _chance)
{
    bow = _bow;
}

Elf::~Elf()
{
    cout << "Elf destroyed." << endl;
}

void Elf::quoteATT()
{
    cout << "AIM, FIRE!" << endl;
}

void Elf::quoteDEF()
{
    cout << "Keep breathing, that's the key." << endl;
}

void Elf::quoteSPE()
{
    cout << "RAIN FIRE!!!" << endl;
}

void Elf::quoteWIN()
{
    cout << "Keep them coming." << endl;
}

#endif