#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> vistos; // valor -> indice

        for (int i = 0; i < (int)nums.size(); ++i) {
            int complemento = target - nums[i];
            if (vistos.count(complemento)) {
                return {vistos[complemento], i};
            }
            vistos[nums[i]] = i;
        }

        return {};
    }
};
