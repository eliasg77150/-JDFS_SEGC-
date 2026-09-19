#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int precioMinimo = INT_MAX;
        int gananciaMaxima = 0;

        for (int precio : prices) {
            precioMinimo = min(precioMinimo, precio);
            gananciaMaxima = max(gananciaMaxima, precio - precioMinimo);
        }

        return gananciaMaxima;
    }
};
