#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> runningSums;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            runningSums.push_back(sum);
        }
        return runningSums;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> runningSums = solution.runningSum(nums);
    for (int i = 0; i < runningSums.size(); i++)
    {
        cout << runningSums[i] << " ";
    }
    cout << "" << endl;
    return 0;
}
