#include "hamming.h"
#include <iostream>
using namespace std;

void imprimir(string a, string b) {
    try {
        int d = hamming::compute(a, b);
        cout << a << " vs " << b << "  ->  distancia = " << d << "\n";
    } catch (const domain_error& e) {
        cout << a << " vs " << b << "  ->  error: " << e.what() << "\n";
    }
}

int main() {
    cout << "=== Pruebas Hamming Distance ===\n";
    imprimir("GGACTGA", "GGACTGA");
    imprimir("GGACGGATTCTG", "GGACGGATTCTG");
    imprimir("ACT", "GGA");
    imprimir("GAGCCTACTAACGGGAT", "CATCGTAATGACGGCCT");
    imprimir("AGA", "AGGA"); // longitudes distintas -> error
    return 0;
}
