#include "armstrong_numbers.h"
#include <iostream>
#include <iomanip>

void check(int number, bool expected) {
    bool result = armstrong_numbers::is_armstrong_number(number);
    std::cout << std::setw(6) << number << " -> "
              << (result ? "true " : "false") << "  (esperado: "
              << (expected ? "true " : "false") << ")  "
              << (result == expected ? "OK" : "FALLO") << '\n';
}

int main() {
    std::cout << "=== Pruebas Armstrong Numbers ===\n";
    check(5, true);       // numero de 1 digito
    check(9, true);
    check(10, false);
    check(153, true);
    check(154, false);
    check(1634, true);    // 4 digitos: 1^4+6^4+3^4+4^4 = 1634
    check(9474, true);
    check(9475, false);
    check(0, true);
    check(89, false);
    check(146, false);
    return 0;
}
