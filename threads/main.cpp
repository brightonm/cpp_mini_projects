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
#include <thread>
#include <chrono>
#include <mutex>
#include <fstream>
#include <iterator>
#include <memory>


/* Threads */


int GetRandom(int max) {
    srand(time(NULL));
    return rand() % max;
}

void ExecuteThread(int id) {
    auto now = std::chrono::system_clock::now(); // current time in milliseconds 
    std::time_t sleepTime = std::chrono::system_clock::to_time_t(now);
    tm myLocalTime = *localtime(&sleepTime);
    
    std::cout << "Thread" << id << "Sleep Time : " << std::ctime(&sleepTime) << "\n"; 
    
    std::cout << "Month : " <<
            myLocalTime.tm_mon << "\n";
    std::cout << "Day : " <<
            myLocalTime.tm_mday << "\n";
    std::cout << "Year : " <<
            myLocalTime.tm_year + 1900 << "\n";
    std::cout << "Hours : " <<
            myLocalTime.tm_hour << "\n";
    std::cout << "Minutes : " <<
            myLocalTime.tm_min << "\n";
    std::cout << "Seconds : " <<
            myLocalTime.tm_sec << "\n\n";
    
    std::this_thread::sleep_for(std::chrono::seconds(GetRandom(3)));
    now = std::chrono::system_clock::now();
    sleepTime = std::chrono::system_clock::to_time_t(now);
    
    std::cout << "Thread" << id << "Awake Time : " << std::ctime(&sleepTime) << "\n"; 

    
}

std::string GetTime(){
    auto now = std::chrono::system_clock::now(); // current time in milliseconds 
    std::time_t sleepTime = std::chrono::system_clock::to_time_t(now);
    return std::ctime(&sleepTime);
}

double acctBalance = 100;

std::mutex acctLock; // protect share data to be access at the same time

void GetMoney(int id, double withdrawal){
    // The exception safe way to protect access
    // to code within its scope. The lock is released 
    // after execution leaves this scope
    std::lock_guard<std::mutex> lock(acctLock);
    //    acctLock.lock();
    // Blocks access between lock and unlock
    // until execution completes
    // This isn't good to use however if an error 
    // occurs between lock and unlock
    //    acctLock.unlock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << id << " tries to withdrawal $" << withdrawal << " on " <<
            GetTime() << "\n";
    if ((acctBalance - withdrawal) >= 0){
        acctBalance -= withdrawal;
        std::cout << "New Account Balance is $" << acctBalance << "\n";
    } else {
        std::cout << "Not Enough Money in Account\n";
        std::cout << "Current Balance is $" << acctBalance << "\n";
    }
}


void FindPrimes(unsigned int start, unsigned int end, std::vector<unsigned int>& vect){
    for (unsigned int x = start; x <= end; x += 2){
        for (unsigned int y = 2; y < x; y++) {
            if ((x%y) == 0){
                break;
            } else if((y + 1) == x){
                vect.push_back(x);
            }
        }
    }
}

std::mutex vectLock;
std::vector<unsigned int> primeVect2;

void FindPrimes2(unsigned int start, unsigned int end){
    for (unsigned int x = start; x <= end; x += 2){
        for (unsigned int y = 2; y < x; y++) {
            if ((x%y) == 0){
                break;
            } else if((y + 1) == x){
                vectLock.lock();
                primeVect2.push_back(x);
                vectLock.unlock();
            }
        }
    }
}

void FindPrimesWithThreads(unsigned int start, unsigned int end, unsigned numThreads){
    std::vector<std::thread> threadVect;
    unsigned int threadSpread = end / numThreads;
    unsigned int newEnd = start + threadSpread - 1;
    for(unsigned int x = 0; x < numThreads; x++){
        threadVect.emplace_back(FindPrimes2, start, newEnd);
        start += threadSpread;
        newEnd += threadSpread;
    }
    // join the threads all together
    for(auto& t : threadVect){
        t.join();
    }
}

int main(int argc, char** argv) {
    
    std::thread th1 (ExecuteThread, 1);
    th1.join();
    std::thread th2 (ExecuteThread, 2);
    th2.join();
    
    // Join the thread to the main thread
    // meaning main waits for this thread to
    // stop executing before continuing execution
    // of code in main
    
    std::thread threads[10]; // create a pool of thread
    for (int i = 0; i < 10; i++){
        threads[i] = std::thread(GetMoney, i, 15);
    }
    for (int i = 0; i < 10; i++){
        threads[i].join();
    }
    
    std::vector<unsigned int> primeVect;
    int startTime = clock();
    FindPrimes(1, 100000, primeVect);
    for (auto i : primeVect){
        std::cout << i << std::endl;
    }
    int endTime = clock();
    std::cout << "Execution Time : " << (endTime - startTime)/double(CLOCKS_PER_SEC)
    << std::endl;
    
    int startTime2 = clock();
    FindPrimesWithThreads(1, 100000, 3);
    for (auto i : primeVect2){
        std::cout << i << std::endl;
    }
    int endTime2 = clock();
    std::cout << "Execution Time : " << (endTime2 - startTime2)/double(CLOCKS_PER_SEC)
    << std::endl;
    
    return 0;
}

