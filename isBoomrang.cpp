#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isBoomerang(vector<vector<int>> &points)
    {
        return (points[0][0] - points[1][0]) * (points[0][1] - points[2][1]) !=
               (points[0][0] - points[2][0]) * (points[0][1] - points[1][1]);
    }
};

int main()
{
    Solution s;

    vector<vector<int>> points1 = {{1, 1}, {2, 3}, {3, 2}};
    bool isBoomerang1 = s.isBoomerang(points1);
    cout << boolalpha << isBoomerang1 << endl; // expected output: true

    vector<vector<int>> points2 = {{1, 1}, {2, 2}, {3, 3}};
    bool isBoomerang2 = s.isBoomerang(points2);
    cout << boolalpha << isBoomerang2 << endl; // expected output: false

    return 0;
}
