#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Dota2Senate
{
public:
    string predictPartyVictory(string senate)
    {
        int n = senate.size();
        queue<int> radiant, dire;
        for (int i = 0; i < n; i++)
        {
            if (senate[i] == 'R')
            {
                radiant.push(i);
            }
            else
            {
                dire.push(i);
            }
        }
        while (!radiant.empty() && !dire.empty())
        {
            int r_index = radiant.front();
            radiant.pop();
            int d_index = dire.front();
            dire.pop();
            if (r_index < d_index)
            {
                radiant.push(r_index + n);
            }
            else
            {
                dire.push(d_index + n);
            }
        }
        return radiant.empty() ? "Dire" : "Radiant";
    }
};

int main()
{
    Dota2Senate dota;
    string senate = "RDRRDDR";
    cout << dota.predictPartyVictory(senate) << endl; // Output: Radiant
    return 0;
}
