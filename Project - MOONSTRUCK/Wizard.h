#ifndef WIZARD_H
#define WIZARD_H

#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

class Wizard : public Character {
public:
    //Wizard's special ability is the wizard's wand or magic
    Wizard();
    Wizard(string _name, int _level, int _health, int _basic, int _chance, int _wand);
    ~Wizard();
    void setAbility(int _wand) { wand = _wand; };   //Wizard's special damage output
    int getAbility() { return wand; };  
    int upgradeAbility() { return wand * 5; };  //Upgraded special when duel is won
    void quoteATT();
    void quoteDEF();
    void quoteSPE();
    void quoteWIN();

private:
    int wand;
};

Wizard::Wizard() : Character()
{
    wand = 5;
}

Wizard::Wizard(string _name, int _level, int _health, int _basic, int _chance, int _wand) : Character(_name, _level, _health, _basic, _chance)
{
    wand = _wand;
}

Wizard::~Wizard()
{
    cout << "Wizard destroyed." << endl;
}

void Wizard::quoteATT()
{
    cout << "ELECTRIC WIRE!" << endl;
}

void Wizard::quoteDEF()
{
    cout << "SHIELD BLAST!!" << endl;
}

void Wizard::quoteSPE()
{
    cout << "LIGHTING STRIKE!!!" << endl;
}

void Wizard::quoteWIN()
{
    cout << "None shall defeat me!" << endl;
}

#endif