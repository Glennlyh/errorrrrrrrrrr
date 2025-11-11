#include <iostream>

bool isWithinArrivalWindow_OLD(int freightTime, int cargoDeadline) {
    int freightMinutes = (freightTime / 100) * 60 + (freightTime % 100);
    int cargoMinutes = (cargoDeadline / 100) * 60 + (cargoDeadline % 100);
    int difference = cargoMinutes - freightMinutes;
    return difference >= 0 && difference <= 15;
}

bool isWithinArrivalWindow_NEW(int freightTime, int cargoDeadline) {
    int freightMinutes = (freightTime / 100) * 60 + (freightTime % 100);
    int cargoMinutes = (cargoDeadline / 100) * 60 + (cargoDeadline % 100);
    int difference = freightMinutes - cargoMinutes;
    return difference <= 0 && difference >= -15;
}

void test_case(const char* desc, int freightTime, int cargoTime, bool expected) {
    bool old_result = isWithinArrivalWindow_OLD(freightTime, cargoTime);
    bool new_result = isWithinArrivalWindow_NEW(freightTime, cargoTime);
    
    std::cout << desc << std::endl;
    std::cout << "  Expected: " << (expected ? "MATCH" : "NO MATCH") << std::endl;
    std::cout << "  OLD logic: " << (old_result ? "MATCH" : "NO MATCH");
    if (old_result == expected) std::cout << " ✓"; else std::cout << " ✗";
    std::cout << std::endl;
    std::cout << "  NEW logic: " << (new_result ? "MATCH" : "NO MATCH");
    if (new_result == expected) std::cout << " ✓"; else std::cout << " ✗";
    std::cout << std::endl << std::endl;
}

int main() {
    test_case("F6 (9:15 AM) vs C8 (8:55 AM) - 20 min LATE", 915, 855, false);
    test_case("Freight 9:00 AM vs Cargo 9:00 AM - ON TIME", 900, 900, true);
    test_case("Freight 8:50 AM vs Cargo 9:00 AM - 10 min EARLY", 850, 900, true);
    test_case("Freight 8:45 AM vs Cargo 9:00 AM - 15 min EARLY", 845, 900, true);
    test_case("Freight 8:44 AM vs Cargo 9:00 AM - 16 min EARLY (too early)", 844, 900, false);
    test_case("Freight 9:01 AM vs Cargo 9:00 AM - 1 min LATE", 901, 900, false);
    
    return 0;
}
