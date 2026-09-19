#include "solution.cpp"
#include <iostream>
using namespace std;

void imprimir(vector<int> nums, int target) {
    Solution s;
    vector<int> r = s.twoSum(nums, target);
    cout << "nums = [";
    for (size_t i = 0; i < nums.size(); ++i) cout << nums[i] << (i+1<nums.size()?",":"");
    cout << "], target = " << target << "  ->  [" << r[0] << "," << r[1] << "]\n";
}

int main() {
    cout << "=== Pruebas Two Sum ===\n";
    imprimir({2,7,11,15}, 9);
    imprimir({3,2,4}, 6);
    imprimir({3,3}, 6);
    return 0;
}
