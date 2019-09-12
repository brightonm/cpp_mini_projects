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
#include <memory>

/*
 * Smart pointers
 */

int main(int argc, char** argv) {
    
    int amtToStore;
    std::cout << "How many numbers do you want to store ? ";
    std::cin >> amtToStore;

    
    /* Allocate memory before smart pointers came out*/
//    int *pNums = new int[amtToStore];
    
     // unique_ptr is a smart pointer that disposes of
    // a pointer when it is no longer in use
    // It could not be duplicated ou shared!
    /* Since c++11 */
    std::unique_ptr<int[]> pNums(new int[amtToStore]);
    
    if (pNums != NULL) {
        int i = 0;
        while (i < amtToStore){
            std::cout << "Enter a number : ";
            std::cin >> pNums[i];
            i++;
        }
    }
    
    std::cout << "You've entered the following numbers : " << std::endl;
    for (int i = 0; i < amtToStore; i++){
        std::cout << pNums[i] << std::endl;
    }
    
    /* Allocate memory before smart pointers came out*/
//    free(pNums);
    return 0;
}

