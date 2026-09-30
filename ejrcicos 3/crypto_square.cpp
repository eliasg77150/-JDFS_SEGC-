#include "crypto_square.h"
#include <cctype>
#include <cmath>
#include <vector>
#include <sstream>

namespace crypto_square {

cipher::cipher(const std::string& input) : plain_text_(input) {}

std::string cipher::normalized_cipher_text() const {
    // 1. Normalizar: pasar a minusculas y quitar todo lo que no sea alfanumerico.
    std::string normalizado;
    for (char c : plain_text_) {
        if (std::isalnum(static_cast<unsigned char>(c))) {
            normalizado += std::tolower(static_cast<unsigned char>(c));
        }
    }

    if (normalizado.empty()) {
        return "";
    }

    // 2. Calcular las dimensiones del rectangulo: c >= r, c - r <= 1, c * r >= longitud.
    int longitud = static_cast<int>(normalizado.size());
    int c = static_cast<int>(std::ceil(std::sqrt(static_cast<double>(longitud))));
    int r = static_cast<int>(std::ceil(static_cast<double>(longitud) / c));

    // 3. Rellenar con espacios hasta completar r * c caracteres.
    std::string rellenado = normalizado;
    rellenado.resize(static_cast<size_t>(r) * c, ' ');

    // 4. Leer por columnas para construir cada "palabra" del texto cifrado.
    std::vector<std::string> columnas(c);
    for (int fila = 0; fila < r; ++fila) {
        for (int col = 0; col < c; ++col) {
            columnas[col] += rellenado[fila * c + col];
        }
    }

    // 5. Unir las columnas separadas por un espacio.
    std::ostringstream salida;
    for (int col = 0; col < c; ++col) {
        if (col != 0) salida << ' ';
        salida << columnas[col];
    }

    return salida.str();
}

}  // namespace crypto_square
