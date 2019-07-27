#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>

int main(int argc, char** argv) {
    std::cout << "Hello World" << std::endl;
    
    if (argc != 1) {
        std::cout << "You entered " << argc << "arguments" << std::endl;
    }
    
    for (std::size_t i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
    
    std::cout << std::numeric_limits<unsigned short int>::max() << std::endl;
    std::cout << "Size of unsigned short int " << sizeof(unsigned short int) << " bytes" << std::endl;
    
    // float sum precision : 6 decimals
    float f1 = 1.11111111111;
    float f2 = 1.11111111111;
    float fsum = f1 + f2;
    
    printf("The result of the sum is : %.10f\n", fsum);
    
    // double sum precision : 10 decimals
    double d1 = 1.1111111111111111111111111;
    double d2 = 1.1111111111111111111111111;
    double dsum = d1 + d2;
    
    printf("The result of the sum is : %.20f\n", dsum);
    
    /** Strings & standard input*/
    
    std::string sQuestion("Enter a number : ");
    
    std::string s1, s2;
    std::cout << sQuestion;
    getline(std::cin, s1);
    std::cout << sQuestion;
    getline(std::cin, s2);
    
    int n1 = std::stoi(s1); // string to integer
    int n2 = std::stoi(s2);
    // stod = string to double
    
    printf("%d + %d = %d\n", n1, n2, n1+n2);
    printf("%d - %d = %d\n", n1, n2, n1-n2);
    printf("%d x %d = %d\n", n1, n2, n1*n2);
    printf("%d / %d = %d\n", n1, n2, n1/n2);
    printf("%d %% %d = %d\n", n1, n2, n1%n2);
    
    
    
    return 0;
}

