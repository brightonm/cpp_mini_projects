#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <ctime>
 
#include <deque>
#include <list>
#include<forward_list>

bool isEven(const int& val){
    return (val % 2) == 0;
}

int main(int argc, char** argv) {

    std::deque<int> deq1;
    deq1.assign({11, 12}); // overwrite values
    deq1.push_back(5);
    deq1.push_front(1);
    std::cout << "Size  : " << deq1.size() << std::endl;
    std::cout << deq1[0] << std::endl;
    std::cout << deq1.at(1) << std::endl;
    std::deque<int>::iterator it = deq1.begin() + 1;
    deq1.insert(it, 3);
    int tempArr[5] = {6, 7, 8, 9, 10};
    deq1.insert(deq1.end(), tempArr, tempArr+5);
    deq1.erase(deq1.end());
    deq1.erase(deq1.begin(), deq1.begin()+2);
    deq1.pop_front();
    deq1.pop_back();
    std::deque<int> deq2(2, 50);
    deq1.swap(deq2);
//    deq1.clear();
    
    for (int e : deq1){
        std::cout << "Deque : " << e << std::endl;
    }
    
    // List are the most efficent at inserting moving elements of all of the containers
    // List are implemented like a DOUBLY LINKED LIST
    // MORE efficient containers are forward list 
    // BUT they lack the ability to directly access elements
    int arr[5] = {1, 2, 3, 4, 5};
    std::list<int> list1;
    list1.insert(list1.begin(), arr, arr+5);
//    list1.assign({10, 20, 30});
    list1.push_back(5);
    list1.push_front(0);
    // inserting element
    std::list<int>::iterator it2 = list1.begin();
    std::advance(it2, 1);
    std::cout << "2nd index : " << *it2 << std::endl;
    list1.insert(it2, 8);
    it2 = list1.begin(); 
    list1.erase(list1.begin());
    list1.pop_front();
    list1.pop_back();
    int arr2[5] = {10, 7, 78, 6, 6};
    std::list<int> list2;
    list2.insert(list2.begin(), arr2, arr2 + 5);
    
    list2.sort();
    list2.reverse();
    list2.unique();
    list2.remove(6);
    list2.remove_if(isEven);
//    list2.merge(list1);
    
    for (int e : list1){
        std::cout << "List : " << e << std::endl;
    }
    
    for (int e : list2){
        std::cout << "List2 : " << e << std::endl;
    }
    
    
    // forward list (LINKED LIST)
    std::forward_list<int> flist;
    flist.assign({4,1,45,8, 9,10});
    flist.push_front(0);
    //flist.push_back(0); DO NOT WORK
    std::cout << "Front : " << flist.front()<< std::endl;
    std::forward_list<int>::iterator it4 = flist.begin();
    it4 = flist.insert_after(it4, 5);
    it4 = flist.erase_after(flist.begin());
    flist.emplace_front(6);
    flist.remove(6);
    flist.remove_if(isEven);
    std::forward_list<int> flist2;
    flist2.assign({4,1,45,8, 9,10});
    flist2.reverse();
    flist2.sort();
    flist2.unique();
    flist.merge(flist2);
    flist2.clear();
    
    for (int e : flist){
        std::cout << "Forward list : " << e << std::endl;
    }
    
    
    return 0;
}

