#include <cmath> 
#include <cstdlib>
#include <iostream>
#include <vector>
#include <functional>
#include <sstream>
#include <ctime> 
#include <numeric>
#include <string>
#include <algorithm>

std::vector<int> GenerateRandVec(int numOfNums, int min, int max);

int main(int argc, char** argv) {
    
    std::vector<int> vecVals = GenerateRandVec(10, 1, 50);
    for (auto e : vecVals)
        std::cout << e << std::endl;
    
    std::sort(vecVals.begin(), vecVals.end(), [](int x, int y) {return x < y;});
    
    std::cout << "Vector sorted" << std::endl;
    for (auto e : vecVals)
        std::cout << e << std::endl;
    
    std::vector<int> evenVecVals;
    /* This function is similar to python filter */
    std::copy_if(vecVals.begin(), vecVals.end(), std::back_inserter(evenVecVals),
            [](int x){return x % 2 == 0;});
    
    std::cout << "Vector filtered" << std::endl;
    for (auto e : evenVecVals)
        std::cout << e << std::endl;
    
    int sum = 0;
    std::for_each(vecVals.begin(), vecVals.end(),
            [&](int x){sum +=x;});
            
    std::cout << "Sum of the vector" << std::endl;
    std::cout << sum << std::endl;
    
    int divisor;
    std::vector<int> vecValsDiv;
    std::cout << "List of Values divisable by : " << std::endl;
    std::cin >> divisor;
    
    std::copy_if(vecVals.begin(), vecVals.end(), std::back_inserter(vecValsDiv),
            [&divisor](int x){return x % divisor == 0;});
    
    std::cout << "Vector filtered by number divisable by " << divisor << std::endl;
    for (auto e : vecValsDiv)
        std::cout << e << std::endl;
     
    std::vector<int> doubleVec;
    std::for_each(vecVals.begin(), vecVals.end(), 
            [&](int x){doubleVec.push_back(x*2);});
    
    std::cout << "Multiply vector by 2 " << std::endl;
    for (auto e : doubleVec)
        std::cout << e << std::endl;
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    std::vector<int> vec3(5);
    
    transform(vec1.begin(), vec1.end(),
            vec2.begin(), vec3.begin(),
            [](int x, int y) {return x + y;});
    std::cout << "Add two vectors" << std::endl;
    for (auto e : vec3)
        std::cout << e << std::endl;
    
    int age = 22;
    bool canIVote = (age >= 18) ? true : false;
    /*Print out boolean as true or false instead of 0 or 1*/
    std::cout.setf(std::ios::boolalpha);
    std::cout << "Can Brighton Vote : " << canIVote << std::endl;
       
    /* Recursive lambda function*/
    
    std::function<int(int)> Fib = [&Fib](int n) {return n < 2 ? n : Fib(n-1) + Fib(n-2);};
    
    std::cout << "Fib 4 : " << Fib(4) << std::endl;
    
    
    return 0;
}

std::vector<int> GenerateRandVec(int numOfNums, int min, int max){
    std::vector<int> vecValues;
    srand(time(NULL));
    int randVal;
    for (int i=0; i < numOfNums; i++) {
        randVal = min + std::rand() % ((max+1) - min);
        vecValues.push_back(randVal);        
    }
    return vecValues;
}
