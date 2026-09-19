#include "solution.cpp"
#include <iostream>
using namespace std;

void imprimir(string col) {
    Solution s;
    cout << col << " -> " << s.titleToNumber(col) << "\n";
}

int main() {
    cout << "=== Pruebas Excel Sheet Column Number ===\n";
    imprimir("A");
    imprimir("B");
    imprimir("Z");
    imprimir("AA");
    imprimir("AB");
    imprimir("ZY");
    return 0;
}
