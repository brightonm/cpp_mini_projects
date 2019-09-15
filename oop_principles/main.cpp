#include <cmath> 
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime> 
#include <numeric>
#include <string>
#include <algorithm>

class Animal{
/* Only accessible inside our class */
private: 
    std::string name;
    double height;
    double weight; 
    
    /*Share and same value of all the instances of our class*/
    static int numOfAnimals;
    
/* Accessible anywhere the object is accessible (so outside our function) */
public:
    std::string getName(){return name;}
    void setName(std::string name) {this->name = name;}
    double getHeight(){return height;}
    void setHeight(double height) {this->height = height;}
    double getWeight(){return weight;}
    void setWeight(double weight) {this->weight = weight;}
    
    void setAll(std::string, double, double); 
    /* Constructor */
    Animal(std::string, double, double);
    Animal();
    ~Animal();
    /* Static methods can only access static fields*/
    static int getNumOfAnimals() {return numOfAnimals;}
    std::string toString();
    
};

int Animal::numOfAnimals = 0;
void Animal::setAll(std::string name, double height, double weight) {
    this->name = name;
    this->height = height;
    this->weight = weight;
}

Animal::Animal(std::string name, double height, double weight){
    this->name = name;
    this->height = height;
    this->weight = weight;
    Animal::numOfAnimals++;
}

Animal::Animal(){
    this->name = "";
    this->height = 0;
    this->weight = 0;
    Animal::numOfAnimals++;
}

Animal::~Animal(){
    std::cout << "Animal " << this->name << " is destroyed " << std::endl;
    Animal::numOfAnimals--;
}

std::string Animal::toString() {
    return this->name + " is " + std::to_string(this->height) + " cms tall and " + std::to_string(this->weight)
            + " kgs in weight\n";
}


class Dog : public Animal{
private:
    std::string sound = "Woof";
public:
    void makeSound(){
       std::cout << "The dog " << this->getName() << " says " << this->sound <<
               std::endl;
    }
    Dog(std::string, double, double, std::string);
    Dog(): Animal(){};
    std::string toString();
};

Dog::Dog(std::string name, double height, double weight, std::string sound) : Animal(name, height, weight) {
    this->sound=sound;
}

std::string Dog::toString(){
    return this->getName() + " is " + std::to_string(this->getHeight()) + " cms and " + std::to_string(this->getWeight()) + " kgs in weight and says "+ this->sound + "\n";
    
}


int main(int argc, char** argv) {
    
    Animal fred;
    std::cout << fred.toString() << std::endl;
    fred.setHeight(30);
    fred.setWeight(40);
    fred.setName("Fred");
    std::cout << fred.toString() << std::endl;
    
    Animal tom("Tom", 50, 15);
    std::cout << tom.toString() << std::endl;
    
    Dog spot("Spot", 38, 16, "WOooooooof");
    std::cout << spot.toString() << std::endl;
    
    std::cout << "Number of Animals " << Animal::getNumOfAnimals() << std::endl;
    
    
    return 0;
}

