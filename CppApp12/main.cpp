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

double MultBy2(double num){
    return num*2;
}

double DoMath(std::function<double(double)> func, double num) {
    return func(num);
}

double MultBy3(double num) {
    return num * 3;
}

bool IsItOdd(int n) {
    return n%2 == 1;
}

std::vector<char> GetHTList(std::vector<char> possibleValues, int nb) {
    srand(time(NULL));
    int size = possibleValues.size();
    std::vector<char> htList;
    for (int i = 0; i < nb; i++) {
         htList.push_back(possibleValues[std::rand() % size]);         
    }
    return htList;
    
}

std::vector<int> ChangeList(std::vector<int> nums, std::function<bool(int)> func) {
    std::vector<int> oddNumbers;
    for (auto num : nums) {
        if (func(num)) oddNumbers.push_back(num);
    }
    return oddNumbers;
}

int GetNumberOfMatches(std::vector<char> htList, char match) {
    int res(0);
    for (auto elem : htList) {
        if (elem == match) res++;
    }
    return res;
}

int main(int argc, char** argv) {

    auto times2 = MultBy2;
    std::cout << "5*2 = " << times2(5) << std::endl;
    std::cout << "6*2 = " << DoMath(times2, 6) << std::endl;
    std::vector<std::function<double(double)>> funcs(2);
    funcs[0] = MultBy2;
    funcs[1] = MultBy3;
    std::cout << "2 *10 = " << funcs[0](10) <<std::endl;
    
    std::vector<int> listOfNums {1, 2, 3, 4, 5};
    std::vector<int> oddList = ChangeList(listOfNums, IsItOdd);
    std::cout << "List of Odds\n";
    for (auto i : oddList) {
        std::cout << i << std::endl;
    }    
    
    std::cout << "Heads and Tails exercises" << std::endl;
    std::vector<char> possibleValues {'H', 'T'};
    std::vector<char> htList = GetHTList(possibleValues, 100);
    std::cout << "Number Of Heads : " << GetNumberOfMatches(htList, 'H') << std::endl;
    std::cout << "Number Of Tails : " << GetNumberOfMatches(htList, 'T') << std::endl;
    
    return 0;
}

