#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include <algorithm>

/* Strings and Maths */
using namespace std;

int main(int argc, char** argv) {
    
    std::vector<std::string> strVec(10);
    
    std::string str("I'm a string");
    strVec[0] = str;
    
    std::cout << str[0] << "\n";
    std::cout << str.at(0) << "\n";
    std::cout << str.front() << " "<< str.back() << std::endl;
    std::cout << "Length : " << str.length() << "\n";
    std::string str2(str);
    strVec[1] = str2;
    std::string str3(str, 4); // copy all after the 4th character
    strVec[2] = str3;
    std::string str4(4, 'x'); // copy character 'x' four times
    strVec[3] = str4;
    strVec[4] = str.append(" and your not ");
    strVec[4] += " and your not ";
    strVec[5] = str.append(str, 1, 10);
    strVec[6] = str.erase(13, str.length()-1);
    
    
    if (str.find("string") != std::string::npos) {
        std::cout << "1st index " << str.find("string") << std::endl;
    }
    
    for (auto y : strVec) {
        std::cout << y << std::endl;
    }
    
    std::cout << "Substring : " << str.substr(6, 6) << std::endl;
    reverse(str.begin(), str.end());
    std::cout << "String reversed : " << str << std::endl;
    
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    std::cout << "Upper : " << str2 << std::endl;
    
    std::string strNum = std::to_string(4+12.0);
    std::cout << "String : " << strNum << std::endl;
    
    
    
    return 0;
}

