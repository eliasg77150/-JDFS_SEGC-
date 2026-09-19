#include "solution.cpp"
#include <iostream>
using namespace std;

void imprimir(vector<int> prices) {
    Solution s;
    cout << "prices = [";
    for (size_t i = 0; i < prices.size(); ++i) cout << prices[i] << (i+1<prices.size()?",":"");
    cout << "]  ->  ganancia maxima = " << s.maxProfit(prices) << "\n";
}

int main() {
    cout << "=== Pruebas Best Time to Buy and Sell Stock ===\n";
    imprimir({7,1,5,3,6,4});
    imprimir({7,6,4,3,1});
    imprimir({2,4,1});
    return 0;
}
