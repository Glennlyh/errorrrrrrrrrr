#include "functions.h"
#include <iostream>

int main() {
    // Test case from problem: F6 Bangkok (9:15 AM) vs C8 Bangkok (8:55 AM)
    int f6_time = 915;   // 9:15 AM
    int c8_time = 855;   // 8:55 AM
    
    std::cout << "Testing F6 (9:15 AM) vs C8 (8:55 AM):" << std::endl;
    std::cout << "F6 arrives 20 minutes AFTER C8 deadline" << std::endl;
    std::cout << "Expected: false (should NOT match)" << std::endl;
    std::cout << "Result: " << (isWithinArrivalWindow(f6_time, c8_time) ? "MATCH" : "NO MATCH") << std::endl;
    std::cout << std::endl;
    
    // Test case: Freight arrives on time
    std::cout << "Testing freight at 9:00 AM vs cargo at 9:00 AM:" << std::endl;
    std::cout << "Expected: true (on time)" << std::endl;
    std::cout << "Result: " << (isWithinArrivalWindow(900, 900) ? "MATCH" : "NO MATCH") << std::endl;
    std::cout << std::endl;
    
    // Test case: Freight arrives 10 minutes early
    std::cout << "Testing freight at 8:50 AM vs cargo at 9:00 AM:" << std::endl;
    std::cout << "Expected: true (10 min early, within 15 min window)" << std::endl;
    std::cout << "Result: " << (isWithinArrivalWindow(850, 900) ? "MATCH" : "NO MATCH") << std::endl;
    std::cout << std::endl;
    
    // Test case: Freight arrives 15 minutes early
    std::cout << "Testing freight at 8:45 AM vs cargo at 9:00 AM:" << std::endl;
    std::cout << "Expected: true (15 min early, at boundary)" << std::endl;
    std::cout << "Result: " << (isWithinArrivalWindow(845, 900) ? "MATCH" : "NO MATCH") << std::endl;
    std::cout << std::endl;
    
    // Test case: Freight arrives 16 minutes early (too early)
    std::cout << "Testing freight at 8:44 AM vs cargo at 9:00 AM:" << std::endl;
    std::cout << "Expected: false (16 min early, too early)" << std::endl;
    std::cout << "Result: " << (isWithinArrivalWindow(844, 900) ? "MATCH" : "NO MATCH") << std::endl;
    std::cout << std::endl;
    
    // Test case: Freight arrives 1 minute late
    std::cout << "Testing freight at 9:01 AM vs cargo at 9:00 AM:" << std::endl;
    std::cout << "Expected: false (1 min late)" << std::endl;
    std::cout << "Result: " << (isWithinArrivalWindow(901, 900) ? "MATCH" : "NO MATCH") << std::endl;
    
    return 0;
}
