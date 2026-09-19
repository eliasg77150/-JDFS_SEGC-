#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string tituloDeColumna) {
        int resultado = 0;

        for (char letra : tituloDeColumna) {
            int valor = letra - 'A' + 1;
            resultado = resultado * 26 + valor;
        }

        return resultado;
    }
};
