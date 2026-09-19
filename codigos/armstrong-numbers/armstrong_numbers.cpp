#include "armstrong_numbers.h"
#include <cmath>

namespace armstrong_numbers {

bool is_armstrong_number(int number) {
    // 1. Contar el número de dígitos del número original.
    int digit_count = 0;
    for (int n = number; n != 0; n /= 10) {
        ++digit_count;
    }
    if (digit_count == 0) digit_count = 1;  // caso especial: number == 0

    // 2. Sumar cada dígito elevado a la cantidad de dígitos.
    long long sum = 0;
    for (int n = number; n != 0; n /= 10) {
        int digit = n % 10;
        sum += static_cast<long long>(std::pow(digit, digit_count));
    }

    // 3. Comparar la suma con el número original.
    return sum == number;
}

}  // namespace armstrong_numbers
