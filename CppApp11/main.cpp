#include <cmath> 
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime> 
#include <numeric>
#include <string>
#include <algorithm>
#include <fstream>

/*
 * Operator overloading and File I/O
 */
class Box{
public:
    double length, width, breadth;
    
    // Used to hold a string representation of the array
    std::string boxString;
    
    Box(){
        length=1, width=1, breadth=1;
    }
    Box(double l, double w, double b) {
        length=l, width=w, breadth=b;
    }
    // Unary Operators
    Box& operator ++() {
        length++;
        width++;
        breadth++;
        return *this;
    }
    
    // Creates a C string representation which is a
    // pointer to an array that is null terminated
    operator const char*() {
        // Creates a stream that can be loaded with 
        // characters that can then be accessed as
        // a string object
        std::ostringstream boxStream;
        boxStream << "Box : " <<
                length << ", " <<
                width << ", " <<
                breadth;
        
        // Return a string representation of the stream
        boxString = boxStream.str();
        
        // Returns the pointer to the string array
        return boxString.c_str();
    }
    // Binary operators
    
    Box operator + (const Box& box2){
        Box boxSum;
        boxSum.length = length + box2.length;
        boxSum.width = width + box2.width;
        boxSum.breadth = breadth + box2.breadth;
        return boxSum;
    }
   
        // Check for box equality
    bool operator == (const Box& box2){
        return ((length == box2.length) &&
                (width == box2.width) &&
                (breadth == box2.breadth));
    }
    
    // Check for which is bigger
    bool operator < (const Box& box2){
        double thisSize = length + width + breadth;
        double box2Size = box2.length + box2.width +
        box2.breadth;
        if (thisSize < box2Size){
            return true;
        } else {
            return false;
        }
    }
    
    bool operator > (const Box& box2){
        double thisSize = length + width + breadth;
        double box2Size = box2.length + box2.width +
        box2.breadth;
        if (thisSize > box2Size){
            return true;
        } else {
            return false;
        }
    }
    
     // Access items using a subscript operator
    double operator [] (int x){
        if(x == 0){
            return length;
        } else if(x == 1){
            return width;
        } else if(x == 2){
            return breadth;
        } else {
            return 0;
        }
    }
    
    
    // Overload the assignment operator
    void operator = (const Box& boxToCopy){
        length = boxToCopy.length;
        width = boxToCopy.width;
        breadth = boxToCopy.breadth;
    }
    
    
};

int main(int argc, char** argv) {
    
    Box box(10,10,10);
    
    // Will increment all values in the box by 1
    ++box;
    std::cout << box << "\n";
    
    // Add boxes
    Box box2(5,5,5);
    std::cout << "Box1 + Box2 = " <<
            box + box2 << "\n";
    
    // Access data with subscript operator
    std::cout << "Box Length : " <<
            box[0] << "\n";
    
    // Displays true or false for bolleans
    std::cout << std::boolalpha;
    std::cout << "Are boxes equal : " <<
            (box == box2) << "\n";
    
    // Is box < box2
    std::cout << "Is box < box2 : " <<
            (box < box2) << "\n";
    
    // Is box > box2
    std::cout << "Is box < box2 : " <<
            (box > box2) << "\n";
    
    box = box2;
    std::cout << box << "\n";
    
    
    // FILE I/O
    
    std::ofstream writeToFile;
    std::ifstream readFromFile;
    std::string txtToWrite = "";
    std::string txtFromFile = "";
     // We open the file by providing a name and then either
    // ios::app : Append to the end of the file
    // ios::trunc : If the exists delete content
    // ios::in : Open file for reading
    // ios::out : Open file for writing
    // ios::ate : Open writing and move to the end of the file
    writeToFile.open("test.txt", std::ios_base::out | std::ios_base::trunc);
    if (writeToFile.is_open()) {
        writeToFile << "Beginning of File\n";
        std::cout << "Enter data to write : ";
        getline(std::cin, txtToWrite);
        writeToFile << txtToWrite;
        writeToFile.close();
    }

    readFromFile.open("test.txt", std::ios_base::in);
    if(readFromFile.is_open()){
        while(readFromFile.good()) {
            getline(readFromFile, txtFromFile);
            std::cout << txtFromFile << std::endl;
        }
        readFromFile.close();
    }
    
    
    
    
    return 0;
}

