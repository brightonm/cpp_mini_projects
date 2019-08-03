#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <ctime>


std::string createString(int const& space,int const& sharp);

std::string createString(int const& space,int const& sharp) {
    std::string res = "";
    for(int i=0; i < space; i++) res += " ";
    for (int i=0; i < sharp; i++) res += "#";
    for(int i=0; i < space; i++) res += " ";
    return res;
}
/*
 * Exercice 1:
 How tall is the tree : 5
    #    
   ###   
  #####  
 ####### 
#########
    #   
 
 */


int main(int argc, char** argv) {
    /* Exercice 1*/
    int size;
    std::cout << "How tall is the tree : ";
    std::cin >> size;
    
    int i = 1;
    while(i <= size) {
        std::cout << createString(size-i, i*2-1) << std::endl;
        i++;
    }
    std::cout << createString(size-1, 1) << std::endl;
    
    /* Exception example 1*/
    float num1, num2;
    std::cout << "Enter a number : " ;
    std::cin >> num1;
    std::cout << "Enter a number : " ;
    std::cin >> num2;
    try {
        if (num2 == 0) {
            throw "Division by zero";
        }
        else {
            printf("%.2f / %.2f = %.2f\n", num1, num2, num1/num2);
        }
    }
    catch (const char* exp) {
        std::cout << "Error : " << exp << std::endl;
    }
    
    /* Exception example 2*/
    
    try {
        std::cout << "Throwing exception\n";
        throw std::runtime_error("Error Occured\n");
        std::cout << "Can you print me?\n";
    }
    catch (std::exception &exp) {
        std::cout << "Handled Exception : " << exp.what() << std::endl; 
    }
    
    catch(...) {
        std::cout << "Default Exception\n";
    }
    
    /* Example random / do while loop*/
    srand(time(NULL)); // seed
    int secretNum = std::rand() % 11; // 0 to 10
    int guess;
    do{
        std::cout << "Guess the number : ";
        std::cin >> guess;
        if (guess < secretNum) std::cout << "Too small\n";
        if (guess > secretNum) std::cout << "Too Big\n";
    } while (guess != secretNum); // SEMI COLON
    
    std::cout << "You guessed it !\n";
    
    
    
    return 0;
}

