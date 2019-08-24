#include <cmath> 
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime> 
#include <numeric>
#include <string>
#include <algorithm>


class Warrior {
private:
    std::string name;
    int health;
    int ack;
    int block;
public:
    std::string getName(){return this->name;}
    void setName(std::string name) {this->name = name;}
    
    int getHealth(){return this->health;}
    void setHealth(int health) {this->health = health > 0 ? health : 0;}
    
    int getAck(){return this->ack;}
    void setAck(int ack) {this->ack = ack;}
    
    int getBlock(){return this->block;}
    void setBlock(int block) {this->block = block;}
    
    Warrior();
    Warrior(std::string, int, int, int);
    ~Warrior();
    
    void attack(Warrior&);
};

Warrior::Warrior() {
    this->name = "";
    this->health = 0;
    this->ack = 0;
    this->block = 0;
}

Warrior::Warrior(std::string name, int health, int ack, int block) {
    this->name = name;
    this->health = health;
    this->ack = ack;
    this->block = block;
}

Warrior::~Warrior(){std::cout << this->name << " has been destroyed" <<std::endl;}

void Warrior::attack(Warrior &w) {
    int damageComputation = (std::rand()%this->ack + 1)-w.getBlock();
    int damage = damageComputation > 0 ? damageComputation : 0;
    std::cout << this->name << " attacks " << w.getName() << " and deals " << damage << " damage" << std::endl;
    w.setHealth(w.getHealth()-damage);
    std::cout << w.getName() << " is down to " << w.getHealth() << " health" << std::endl;
}


class Battle{    
public:
    ~Battle(){std::cout << "Game Over"<< std::endl;}
    static void startFight(Warrior&, Warrior&);
};



void Battle::startFight(Warrior &w1, Warrior &w2) {
    int tmp = std::rand()%2;
    Warrior& beginner = tmp == 0 ? w1 : w2;
    Warrior& follower = tmp == 0 ? w2 : w1;
    while (beginner.getHealth() > 0 && follower.getHealth() > 0) {
        beginner.attack(follower);
        if (follower.getHealth() <= 0) {
            std::cout << follower.getName() << " has died and "<< beginner.getName() << " is victorious"<< std::endl;
            return;
        }
        else {
            follower.attack(beginner);
             if (beginner.getHealth() <= 0) {
               std::cout << beginner.getName() << " has died and "<< follower.getName() << " is victorious"<< std::endl;
               return;
            }
        }
    }
    
}


int main(int argc, char** argv) {

    srand(time(NULL));
    /* Health amount, Ack Amount , Block amount*/
    Warrior thor("Thor", 100, 30, 15);
    Warrior hulk("Hulk", 135, 25, 10);
    
    Battle::startFight(thor, hulk);
    
    return 0;
}

