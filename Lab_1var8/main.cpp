#include <iostream>
#include "include/work_with_string.h"

int main(){
    std::string source_digit;
    std::cout << "Enter binary digit:\n";
    std::cin >> source_digit;
    std::cout << "Result: " << eliminate_unset_bits(source_digit) << "\n";
    return 0;
}