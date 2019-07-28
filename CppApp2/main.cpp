#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include <limits>

/*
 * Vectors (resizable array) & Strings in C++ & Pointers & Functions
 */

// Functions prototypes

double addNumbers(double const& num1, double const& num2);
void assign(int& n);

int main(int argc, char** argv) {
    std::vector<int> vectExample(2);
    vectExample[0] = 1;
    vectExample[1] = 10;
    vectExample.push_back(33);
    std::cout <<
            "Last element of the array " << 
            vectExample[vectExample.size() - 1] << std::endl;
    
    // Converting string to vector
    
    std::string sSentence = "This is a sentence";
    std::vector<std::string> vecWords;
    std::stringstream ss(sSentence);
    std::string sIndivStr;
    const char cSpace = ' ';
    
    while (getline(ss, sIndivStr, cSpace)) {
        vecWords.push_back(sIndivStr); 
    }
    
    for (int i = 0; i < vecWords.size(); i++) {
        std::cout << vecWords[i] << std::endl;
    }
    
    std::vector<int> myVec(10);
    // populate my vector with
    std::iota(std::begin(myVec), std::end(myVec), 0);
    for (int i=0; i < myVec.size(); ++i) {
        std::cout << myVec[i] << std::endl;
    }
    // quicker iteration
    for (auto y : myVec) std::cout << y << std::endl;
    
    // test functions
    double num1, num2;
    std::cout << "Enter Num 1 : ";
    std::cin >> num1;
    std::cout << "Enter Num 2 : ";
    std::cin >> num2;
    std::cout << addNumbers(num1, num2) << std::endl;
    
    int x = 19;
    assign(x);
    std::cout << x << std::endl;
    
    return 0;
    
}

// FUNCTIONS IMPLEMENTATION

double addNumbers(double const& num1, double const& num2) {
    return num1 + num2;
}

void assign(int& n) {
    n = 14;
}



// END OF FUNCTIONS IMPLEMENTATIONS
