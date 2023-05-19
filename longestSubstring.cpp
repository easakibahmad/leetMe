#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int n = s.length();
        std::unordered_set<char> hashSet;
        int i = 0, j = 0, maxLength = 0;
        while (i < n && j < n)
        {
            if (hashSet.find(s[j]) == hashSet.end())
            {
                hashSet.insert(s[j]);
                j++;
                maxLength = std::max(maxLength, j - i);
            }
            else
            {
                hashSet.erase(s[i]);
                i++;
            }
        }
        return maxLength;
    }
};
int main()
{
    Solution solution;
    std::string s = "abcabcbb";
    int maxLength = solution.lengthOfLongestSubstring(s);
    std::cout << "Longest substring length: " << maxLength << std::endl;
    return 0;
}