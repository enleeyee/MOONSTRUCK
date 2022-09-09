#include "Character.h"
#include "Wizard.h"
#include "Witch.h"
#include "Elf.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void menu() {
    string line = "";
    ifstream finImage;
    finImage.open("MOONSTRUCK_MENU.txt");
    if(finImage.is_open())
    {
        while(getline(finImage, line))
        {
            cout << line << endl;
        }
        cout << "Mountain credit to Joan Stark: https://www.asciiart.eu/nature/mountains" << endl;
    }
    else
    {
        cout << "File failed to display." << endl;
    }
    finImage.close();
}

void characterInfo(string type, string weapon, int damageOutput, int specialOutput, int chanceLevel) {
    cout << "****************************************" << endl;
    cout << "Type: " << type << endl;
    cout << "Weapon: " << weapon << endl;
    cout << "Damage Output: " << damageOutput << " (1:1 chance)" << endl;
    cout << "Special Ability Output: " << specialOutput << " (1:" << chanceLevel << " chance)" << endl;
    cout << "****************************************" << endl;
    cout << endl;
}

void gameIntro(string userType, string userName) {
    cout << "Darkness is forming on Mount Luna, a mountain formed when the evil Madame Thao struck onto Moonlight." << endl;
    cout << "Madame Thao is forming an army of clones with speical abilities and different version of herself." << endl;
    cout << "Madame Thao and her army have a secret plan to wipe everyone against her and become the ruler of Agartha." << endl;
    cout << "Sounds pretty simple, there are definitely no other secrets to be uncovered. Good luck " << userType << " " << userName << "." << endl;
    cout << endl;
}

void duelIntro(string userType, string userName, int userLevel, string enemyType, string enemyName, int enemyLevel) {
    cout << userType << " " << userName << " level " << userLevel;
    cout << " encountered " << enemyType << " " << enemyName << " level " << enemyLevel << endl;
}

void duelMenu(string userType, string enemyType, string userName, string enemyName, int userHealth, int enemyHealth) {
    cout << endl;
    cout << userType << " " << userName << "'s health: " << userHealth << endl;
    cout << enemyType << " " << enemyName << "'s health: " << enemyHealth << endl;
    cout << "****************************************" << endl;
    cout << "* 0 - Defend                           *" << endl;
    cout << "* 1 - Basic Attack                     *" << endl;
    cout << "* 2 - Special Attack                   *"<< endl;
    cout << "* 3 - Save and Quit                    *" << endl;
    cout << "****************************************" << endl;
}

void hitMessage(string type0, string name0, int damage0, string type1, string name1) {
    cout << type0 << " " << name0 << " dealt -" << damage0 << " damage towards "
        << type1 << " " << name1 << "." << endl;
    cout << endl;
}

void endMenu(string userType, string userName) {
    cout << "Congrats " << userType << " " << userName << ". You pushed back the forces of darkness once more, but there is still more work to be done.\n";
    cout << "Do you wish to continue? (Enter '0')" << endl;
    cout << "Quit (Enter any number)             " << endl;
}

int decreaseHealth(int health, int damage) {
    int newHealth = health - damage;
    return newHealth;
}

int main() {
    //variables for the user, enemy, and the game loop
    string runGame = "start", option = "", userName = "", enemyName = "", userType = "", enemyType = "";
    int userLevel = 0, userHealth = 0, userBasic = 0, userChance = 0, userAbility = 0, userOption = 0;
    int enemyLevel = 0, enemyHealth = 0, enemyBasic = 0, enemyChance = 0, enemyAbility = 0, enemyOption = 0;
    
    Character *c[2]; //character pointer to access all ploymorph functions and setters/getters
    srand(time(0)); //new random seed for every game
    menu(); //menu function for the start of every game
    while(runGame != "quit")
    {
        while(runGame == "start")
        {
            cin >> option;
            cout << endl;
            if(option == "N")
            {
                //character info for every type for new players
                cout << "Choose your character: " << endl;
                cout << "Type: 0" << endl;
                characterInfo("Wizard", "Staff", 2, 5, 5);
                cout << "Type: 1" << endl;
                characterInfo("Witch", "Wand", 2, 6, 6);
                cout << "Type: 2" << endl;
                characterInfo("Elf", "Bow", 2, 4, 3);
                cout << "Enter your character type: ";
                cin >> userOption;
                if(userOption < 0 || userOption > 2)
                {
                    while(userOption < 0 || userOption > 2)
                    {
                        cout << "Please enter another character type: " << endl;
                        cin >> userOption;
                    }
                }
                cout << "Please enter your character name: " << endl;
                cin >> userName;                
                if(userOption == 0)
                {
                    c[0] = new Wizard(userName, 1, 100, 2, 5, 5);
                    userType = "Wizard";
                    userChance = 5;
                }
                if(userOption == 1)
                {
                    c[0] = new Witch(userName, 1, 100, 2, 6, 6);
                    userType = "Witch";
                    userChance = 6;
                }
                if(userOption == 2)
                {
                    c[0] = new Elf(userName, 1, 100, 2, 4, 3);
                    userType = "Elf";
                    userChance = 3;       
                }
                runGame = "newGame";
            }
            else if(option == "S")
            {
                //saved option for old players
                ifstream fin;
                fin.open("GAMEFILE1024.txt");
                if(!fin.is_open())
                {
                    cout << "File not found" << endl;
                    return 1;
                }
                else
                {
                    getline(fin, userName);
                    fin >> userLevel >> userHealth >> userBasic >> userChance >> userAbility;
                    fin.ignore();
                    getline(fin, userType);
                    if(userType == "Wizard")
                    {
                        c[0] = new Wizard(userName, userLevel, userHealth, userBasic, userChance, userAbility);
                    }
                    if(userType == "Witch")
                    {
                        c[0] = new Witch(userName, userLevel, userHealth, userBasic, userChance, userAbility);
                    }
                    if(userType == "Elf")
                    {
                        c[0] = new Elf(userName, userLevel, userHealth, userBasic, userChance, userAbility);
                    }
                    getline(fin, enemyName);
                    if(enemyName == "THAO")
                    {
                        //continuing duel 
                        fin >> enemyLevel >> enemyHealth >> enemyBasic >> enemyChance >> enemyAbility;
                        fin.ignore();
                        getline(fin, enemyType);
                        if(enemyType == "Wizard")
                        {
                            c[1] = new Wizard(enemyName, enemyLevel, enemyHealth, enemyBasic, enemyChance, enemyAbility);
                        }
                        if(enemyType == "Witch")
                        {
                            c[1] = new Witch(enemyName, enemyLevel, enemyHealth, enemyBasic, enemyChance, enemyAbility);
                        }
                        if(enemyType == "Elf")
                        {
                            c[1] = new Elf(enemyName, enemyLevel, enemyHealth, enemyBasic, enemyChance, enemyAbility);
                        }
                        runGame = "startDuel";      
                    }
                    else
                    {
                        //new duel
                        runGame = "newDuel";
                    }
                    fin.close();                   
                }
            }
            else
            {
                cout << "Please enter another option: " << endl;
                cin >> option;
            }
        }

        if(runGame == "newGame")
        {
            gameIntro(userType, c[0]->getName()); //game introduction for new players
            runGame = "newDuel";
        }
        if(runGame == "newDuel")
        {
            //new enemy is created at random for new duels or new players
            enemyOption = rand() % 3;
            enemyName = "THAO";
            enemyLevel = c[0]->getLevel();
            enemyHealth = 100;
            enemyBasic = c[0]->getBasic();
            if(enemyOption == 0)
            {
                enemyChance = 5;
                enemyAbility = c[0]->getLevel() * 5;
                c[1] = new Wizard(enemyName, enemyLevel, enemyHealth, enemyBasic, enemyChance, enemyAbility);
                enemyType = "Wizard";               
            }
            if(enemyOption == 1)
            {
                enemyChance = 6;
                enemyAbility = c[0]->getLevel() * 6;
                c[1] = new Witch(enemyName, enemyLevel, enemyHealth, enemyBasic, enemyChance, enemyAbility);   
                enemyType = "Witch";                              
            }
            if(enemyOption == 2)
            {
                enemyChance = 2;
                enemyAbility = c[0]->getLevel() * 3;
                c[1] = new Elf(enemyName, enemyLevel, enemyHealth, enemyBasic, enemyChance, enemyAbility);    
                enemyType = "Elf";                             
            }
            runGame = "startDuel";
        }
        
        //duel starts with an encountered statement
        duelIntro(userType, c[0]->getName(), c[0]->getLevel(), enemyType, c[1]->getName(), c[1]->getLevel());
        while(runGame == "startDuel")
        {
            //duel menu is repeated until the player quits or wins
            duelMenu(userType, enemyType, c[0]->getName(), c[1]->getName(), c[0]->getHealth(), c[1]->getHealth());
            cin >> userOption;
            enemyOption = rand() % 3;
            if(userOption < 0 || userOption > 3)
            {
                while(userOption < 0 || userOption > 3)
                {
                    cout << "Please enter another option: " << endl;
                    cin >> userOption;  
                }
            }             
            //option 0 means defense has a 1:2 chance of working if it works then the player/enemy heals 
            if(userOption == 0)
            {
                if(rand() % 2 == 0)
                {
                    c[0]->quoteDEF();
                    c[0]->increaseHealth();
                    cout << userType << " " << c[0]->getName() << " regained health." << endl; //quote for it worked
                
                }
                else
                {
                    cout << userType << " " << c[0]->getName() << "'s defense failed." << endl; //quote for it failed
                }
            }
            if(enemyOption == 0)
            {
                if(rand() % 1 == 0)
                {
                    c[1]->quoteDEF();
                    c[1]->increaseHealth();
                    cout << enemyType << " " << c[1]->getName() << " regained health." << endl;
                }
                else
                {
                    cout << enemyType << " " << c[1]->getName() << "'s defense failed." << endl;
                }
            }      
            //option 1 means the basic attack is used and a hit is guaranteed 
            if(userOption == 1)
            {
                c[1]->setHealth( decreaseHealth(c[1]->getHealth(), c[0]->getBasic()) ); //a function to decrease and set the new health
                c[0]->quoteATT(); 
                hitMessage(userType, c[0]->getName(), c[0]->getBasic(), enemyType, c[1]->getName()); //quote for direct hit
            }
            if(enemyOption == 1)
            {
                c[0]->setHealth( decreaseHealth(c[0]->getHealth(), c[1]->getBasic()) );
                c[1]->quoteATT();
                hitMessage(enemyType, c[1]->getName(), c[1]->getBasic(), userType, c[0]->getName());
            }           
            //option 2 means special ability is used with a certain chance depending on the type 
            if(userOption == 2)
            {
                if(rand() % (userChance + 1) == userChance)
                {
                    c[0]->quoteSPE(); //poly quote is called as previously seen 
                    c[1]->setHealth( decreaseHealth( c[1]->getHealth(), c[0]->getAbility() ) );
                    hitMessage(userType, c[0]->getName(), c[0]->getAbility(), enemyType, c[1]->getName());
                }
                else
                {
                    cout << userType << " " << c[0]->getName() << " missed." << endl; //quote for a miss
                }
            }
            if(enemyOption == 2)
            {
                if(rand() % (enemyChance + 1) == enemyChance)
                {
                    c[1]->quoteSPE();
                    c[0]->setHealth( decreaseHealth( c[0]->getHealth(), c[1]->getAbility() ) );
                    hitMessage(enemyType, c[1]->getName(), c[1]->getAbility(), userType, c[0]->getName());
                }
                else
                {
                    cout << enemyType << " " << c[1]->getName() << " missed." << endl;
                }
            }
            //option 3 means the player is saving the current duel the player is in
            if(userOption == 3)
            {
                ofstream fout("GAMEFILE1024.txt");
                fout << c[0]->getName() << "\n" << c[0]->getLevel() << "\n" << c[0]->getHealth() << "\n"
                    << c[0]->getBasic() << "\n" << c[0]->getChance() << "\n" << c[0]->getAbility() << "\n"
                    << userType << endl;

                fout << c[1]->getName() << "\n" << c[1]->getLevel() << "\n" << c[1]->getHealth() << "\n"
                    << c[1]->getBasic() << "\n" << c[1]->getChance() << "\n" << c[1]->getAbility() << "\n"
                    << userType << endl;
                fout.close();
                cout << "Game saved" << endl;
                runGame = "quit";
            }

            //the enemy won and the game ends
            if(c[0]->getHealth() <= 0)
            {
                c[1]->quoteWIN();
                cout << endl;
                cout << "You have been defeat and the forces of darkness have taken over. ";
                cout << "Everyone believed in you, but you have failed us all..." << endl;
                cout << "Try again in another game life." << endl;
                cout << "Game terminated." << endl;
                runGame = "quit";
            }

            //the player won and the upgraded character is saved
            if(c[1]->getHealth() <= 0)
            {
                cout << endl;
                c[0]->quoteWIN();
                c[0]->setHealth(100);
                if(c[0]->getLevel() < 5)
                {
                    cout << "Your level has increased +1 level, +1 basic, special now deals "<< c[0]->upgradeAbility() <<" damage." << endl;
                    c[0]->increaseLevel();
                    c[0]->increaseBasic();
                    c[0]->setAbility( c[0]->upgradeAbility() );
                }
                ofstream fout("GAMEFILE1024.txt");
                fout << c[0]->getName() << "\n" << c[0]->getLevel() << "\n" << c[0]->getHealth() << "\n"
                    << c[0]->getBasic() << "\n" << c[0]->getChance() << "\n" << c[0]->getAbility() << "\n"
                    << userType << "\n " << endl;
                fout.close();
                cout << "Game saved." << endl;

                //end menu is shown with the option to continue or quit
                endMenu(userType, c[0]->getName());
                cout << "Enter your option: " << endl;
                cin >> runGame;
                if(runGame == "0")
                {
                    runGame = "newDuel";
                }
                else
                {
                    runGame = "quit";
                }
            }
        }
    }

    //delete character array
    for(int i = 0; i < 3; i++)
    {
        delete c[i];
    }

    return 0;
}