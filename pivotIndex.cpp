#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        int leftSum = 0, rightSum = 0;
        for (int i = 0; i < n; i++)
        {
            rightSum += nums[i];
        }
        for (int i = 0; i < n; i++)
        {
            rightSum -= nums[i];
            if (leftSum == rightSum)
            {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int pivotIndex = solution.pivotIndex(nums);
    cout << pivotIndex << endl;
    return 0;
}
