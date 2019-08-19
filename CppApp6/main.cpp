#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath> 
#include <ctime> 
#include <numeric>
#include <algorithm>

void bubbleSort(std::vector<int> &vec);
unsigned long long getFactorial(int n);

int main(int argc, char** argv) {
    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(78);
    vec.push_back(1);
    vec.push_back(31);
    bubbleSort(vec);
    for (auto e : vec) std::cout << e << std::endl;
    std::string number;
    std::cout << "Enter a number " << std::endl;
    std::cin >> number;
    long n = std::stoi(number);
    std::cout << number + "! = " << getFactorial(n) << std::endl;
    
    return 0;
}

void bubbleSort(std::vector<int> &vec){
    for (int i=vec.size()-1; i>=0; i--) {
        for (int j=0; j<i; j++) {
            if (vec[j+1] < vec[j]) {
                auto tmp = vec[j+1];
                vec[j+1] = vec[j];
                vec[j] = tmp;
            }
        }
    }
}

unsigned long long getFactorial(int n) {
    if (n == 0 or n == 1) return 1;
    std::vector<unsigned long long> memo = {1};
    for (int i=2; i <= n; i++) {
        unsigned long long tmp = memo.back();
        memo.push_back(tmp*i);
    }
    return memo.back();
}
