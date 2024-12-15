#include <iostream>
#include <string>


long eliminate_unset_bits(std::string number) {
    std::string result = "";
    for (char bit : number) {
        if (bit == '1')
            result += bit;
    }
    if (result.empty())
        return 0;
    else
        return stol(result, nullptr, 2);
}

int main(){
    std::string source_digit;
    std::cout << "Enter binary digit: ";
    std::cin >> source_digit;
    std::cout << "Result: " << eliminate_unset_bits(source_digit) << "\n";
    return 0;
}