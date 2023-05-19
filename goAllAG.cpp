#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // List to signify if the vertex has an incoming edge or not.
        vector<bool> isIncomingEdgeExists(n, false);
        for (vector<int>& edge : edges) {
            isIncomingEdgeExists[edge[1]] = true;
        }
        
        vector<int> requiredNodes;
        for (int i = 0; i < n; i++) {
            // Store all the nodes that don't have an incoming edge.
            if (!isIncomingEdgeExists[i]) {
                requiredNodes.push_back(i);
            }
        }
        
        return requiredNodes;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Sample input
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};

    // Call the findSmallestSetOfVertices function
    vector<int> result = solution.findSmallestSetOfVertices(n, edges);

    // Print the result
    cout << "Required nodes: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
