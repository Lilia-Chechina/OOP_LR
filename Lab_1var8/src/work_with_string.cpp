#include "../include/work_with_string.h"

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
