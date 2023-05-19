#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = n - 1; i >= 0; i--)
        {
            int skip_points = dp[i + 1];
            int solve_points = (i + questions[i][1] < n) ? dp[i + questions[i][1] + 1] : 0;
            dp[i] = max(dp[i + 1], questions[i][0] + solve_points);
        }

        return dp[0];
    }
};

int main()
{
    vector<vector<int>> questions = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    Solution s;
    cout << s.maxPoints(questions) << endl; // Output: 5
    return 0;
}
