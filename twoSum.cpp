#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    if (result.size() == 2) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
        cout << "Numbers: " << nums[result[0]] << ", " << nums[result[1]] << endl;
    } else {
        cout << "No two elements found that add up to the target." << endl;
    }

    return 0;
}
