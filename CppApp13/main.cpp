#include <cstdlib>
#include <cmath> 
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime> 
#include <numeric>
#include <string>
#include <functional>
#include <algorithm>
#include <fstream>
#include <iterator>
#include "Animal.h"

#define PI 3.14159 // macro constant
#define AREA_CIRCLE(radius) (PI * (std::pow(radius, 2))) // macro function

/* Template and iterators */

template<typename T>
void Time2 (T val) {
    std::cout << val << " * 2 = " << val * 2 << std::endl;
}

template<typename T>
T Add(T val, T val2) {
    return val + val2;
}

template<typename T>
T Max(T val, T val2) {
    return (val < val2) ? val2 : val;
}

template<typename T, typename U>
class Person {
    public:
        T height;
        U weight;
        static int numOfPeople;
        Person(T h, U w) {
            height = h, weight = w; 
            numOfPeople++;
        }
        void GetData() {
            std::cout << "Height : " << height << " and Weight : " << weight << std::endl;
        }
};

// You have to initialize static class members
template<typename T, typename U> int Person<T, U>::numOfPeople;

int main(int argc, char** argv) {
    
    // header files and import 
    Animal spot = Animal();
    spot.name = "Spot";
    std::cout << "The Animal is named " << spot.name << std::endl;
    
    // preprocessing 
    std::cout << "Circle Area : " << AREA_CIRCLE(5) << std::endl;
    
    // template
    Time2(5);
    Time2(5.2);
    Time2(0x00A);
    
    std::cout << "5 + 4 = " << Add(5.5, 5.4) << std::endl;
    std::string s1("Le 83");
    std::string s2(" est la plus belle région du monde.");
    std::cout << Add(s1, s2) << std::endl; 
    
    Person <double, int> mikeTyson(5.83, 216);
    mikeTyson.GetData();
    
    // You access static values using the object
    // and not the class
    std::cout << "Number of people : " <<
            mikeTyson.numOfPeople << std::endl;
   
    
    // Iterators
    std::vector<int> num2 = {1, 2, 3, 4};
    std::vector<int>::iterator itr; 
    for (itr = num2.begin(); itr < num2.end(); itr++){
        std::cout << *itr << std::endl; 
    }
    
    
    std::vector<int>::iterator itr2 = num2.begin();
    advance(itr2, 2);
    std::cout << *itr2 << std::endl;
    
    auto itr3 = next(itr2, 1); // same as advance but returns an iterator
    std::cout << *itr3 << std::endl;
    
    auto itr4 = prev(itr2, 1);
    std::cout << *itr4 << std::endl;
    
    std::vector<int> num3 = {1, 4, 5, 6};
    std::vector<int> num4 = {2, 3};

    auto itr5 = num3.begin();
    advance(itr5, 1);
    copy(num4.begin(), num4.end(), inserter(num3, itr5));
    for (int i : num3) {
        std::cout << i << std::endl;
    }
    
    return 0;
}

