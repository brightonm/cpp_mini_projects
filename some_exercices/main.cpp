#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include <algorithm>

std::vector<std::string> StringToVector(std::string theString, char separator);

std::string replaceAllSubstring(std::string theString, std::string s, std::string replace);

std::vector<int> findSubstringMatches(std::string theString, std::string match);

std::string VectorToString(std::vector<std::string> vect, char separator);

std::string TrimWhitespace(std::string theString);

int main(int argc, char** argv) {
    std::vector<std::string> vec = StringToVector("This is a random string", ' ');
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << std::endl;
    }
    
    std::vector<std::string> vCusts(3);
    vCusts[0] = "Bob";
    vCusts[1] = "Sue";
    vCusts[2] = "Tom";
    std::string sCusts = VectorToString(vCusts, ' ');
    std::cout << sCusts << "\n";
    
    std::string aStr = "   Just a string    ";
    aStr = TrimWhitespace(aStr);
    std::cout << "*" << aStr << "*\n";
    
    std::string phrase = "To be or not to be";
    std::vector<int> matches = findSubstringMatches(phrase, "be");
    for (auto e : matches) {
        std::cout << e << std::endl;
    }
    
    std::string s = replaceAllSubstring(phrase, "be", "know");
    std::cout << s << std::endl;
    
    return 0;
}

std::vector<std::string> StringToVector(std::string theString, char separator) {
    std::vector<std::string> vecsWords;
    std::stringstream ss(theString);
    std::string sIndiv;
    while(getline(ss, sIndiv, separator)) {
        vecsWords.push_back(sIndiv);
    }
    return vecsWords;
}

std::string VectorToString(std::vector<std::string> vect, char separator) {
    std::string res("");
    for(auto s : vect) {
        res += s + separator;
    }
    res = res.substr(0, res.size()-1);
    return res;
}

std::string TrimWhitespace(std::string theString) {
    std::string whitespaces(" \f\n\r\t");
    theString.erase(theString.find_last_not_of(whitespaces)+1);
    theString.erase(0, theString.find_first_not_of(whitespaces));
    return theString;
}

std::vector<int> findSubstringMatches(std::string theString, std::string match) {
    std::vector<int> vIndexes;
    for(int i = 0; i < theString.size() - match.size()+1; i++) {
        for (int j=0; j < match.size(); j++) {
            if(theString[i+j] != match[j]){
                break;
            }
            else if (theString[i+j] == match[j] && j==match.size()-1) {
                vIndexes.push_back(i);
            }
        }
    }
    return vIndexes;
}

std::string replaceAllSubstring(std::string theString, std::string s, std::string replace) {
    std::vector<int> vecIndexes = findSubstringMatches(theString, s);
    for (auto e : vecIndexes) {
        theString.replace(e, replace.size(), replace);
    }
    return theString;
}