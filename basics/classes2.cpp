
// Example of randomized results:
/*
Thor attacks Hulk and deals 45 damage
Hulk is down to 5 health
...
Hulk has Died and Thor is Victorious
Game Over
*/
#define DAMAGE_MESSAGE "%s attacks %s: damage %d\n"
#define HEALTH_MESSAGE "%s health: %d\n"
#define VICTORY_MESSAGE "LOSER: %s  WINNER: %s \n"
#define END_MESSAGE "Game Over"
#define CONTINUE_MESSAGE "Fight Again"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>

class Fighter{
private:
    int attackMax;
    int blockMax;

public:
    std::string name;
    int health;

    Fighter(std::string name, int health, int attackMax, int blockMax){
        this->name = name;
        this->health = health;
        this->attackMax = attackMax;
        this->blockMax = blockMax;
    }

    // The attack and block amount will be random
    int Attack(){
        return std::rand() % this->attackMax;
    }
    int Block(){
        return std::rand() % this->blockMax;
    }
};

class Battle{
public:
    // Loop exits when a fighter's health < 0
    static void StartFight(Fighter& fighter1, Fighter& fighter2){
        while(true){
            if(Battle::GetAttackResult(fighter1, fighter2).compare(END_MESSAGE) == 0){
                std::cout << END_MESSAGE << "\n";
                break;
            }
            if(Battle::GetAttackResult(fighter2, fighter1).compare(END_MESSAGE) == 0){
                std::cout << END_MESSAGE << "\n";
                break;
            }
        }
    }

    static std::string GetAttackResult(Fighter& fighterOne,
                                       Fighter& fighterTwo){
        // Get fighter damage
        int fighterOneAttack = fighterOne.Attack();
        int fighterTwoBlock = fighterTwo.Block();
        int fighterTwoDamage = ceil(fighterOneAttack - fighterTwoBlock);

        // Change health total (avoid infinite loop where health < 0)
        fighterTwoDamage = (fighterTwoDamage <= 0) ? 0 : fighterTwoDamage;
        fighterTwo.health = fighterTwo.health - fighterTwoDamage;
        printf(DAMAGE_MESSAGE,
                fighterOne.name.c_str(), fighterTwo.name.c_str(), fighterTwoDamage);
        printf(HEALTH_MESSAGE,
                fighterTwo.name.c_str(), fighterTwo.health);

        // End game if health < 0
        if(fighterTwo.health <= 0){
            printf(VICTORY_MESSAGE,
                   fighterTwo.name.c_str(), fighterOne.name.c_str());
            return END_MESSAGE;
        } else {
            return CONTINUE_MESSAGE;
        }
    }
};

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create fighters: name, health, attackMax, blockMax
    Fighter thor("Thor", 100, 50, 5);
    Fighter hulk("Hulk", 50, 50, 5);

    // Create battle and fight to death!
    Battle::StartFight(thor, hulk);

    return 0;
}