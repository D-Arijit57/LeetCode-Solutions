class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        
        // Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Root tree at node 0
        vector<int> subtreeXor(n);
        vector<int> parent(n, -1);
        vector<int> startTime(n), endTime(n);
        int timer = 0;
        
        function<void(int, int)> dfs = [&](int node, int par) {
            parent[node] = par;
            startTime[node] = timer++;
            subtreeXor[node] = nums[node];
            
            for (int child : adj[node]) {
                if (child != par) {
                    dfs(child, node);
                    subtreeXor[node] ^= subtreeXor[child];
                }
            }
            
            endTime[node] = timer - 1;
        };
        
        dfs(0, -1);
        
        int totalXor = subtreeXor[0];
        int minScore = INT_MAX;
        
        // Try all pairs of edges
        for (int i = 0; i < edges.size(); i++) {
            for (int j = i + 1; j < edges.size(); j++) {
                // Find child nodes (deeper nodes) for each edge
                int child1 = (parent[edges[i][1]] == edges[i][0]) ? edges[i][1] : edges[i][0];
                int child2 = (parent[edges[j][1]] == edges[j][0]) ? edges[j][1] : edges[j][0];
                
                int xor1 = subtreeXor[child1];
                int xor2 = subtreeXor[child2];
                int xor3;
                
                // Use DFS timestamps to check ancestor relationship efficiently
                bool child1ContainsChild2 = (startTime[child1] <= startTime[child2] && 
                                           endTime[child2] <= endTime[child1]);
                bool child2ContainsChild1 = (startTime[child2] <= startTime[child1] && 
                                           endTime[child1] <= endTime[child2]);
                
                if (child1ContainsChild2) {
                    // child2 is inside child1's subtree
                    xor1 ^= xor2;  // Remove child2's XOR from child1
                    xor3 = totalXor ^ subtreeXor[child1];  // Rest of the tree
                } else if (child2ContainsChild1) {
                    // child1 is inside child2's subtree
                    xor2 ^= xor1;  // Remove child1's XOR from child2
                    xor3 = totalXor ^ subtreeXor[child2];  // Rest of the tree
                } else {
                    // Independent subtrees
                    xor3 = totalXor ^ xor1 ^ xor2;
                }
                
                int maxXor = max({xor1, xor2, xor3});
                int minXor = min({xor1, xor2, xor3});
                
                minScore = min(minScore, maxXor - minXor);
            }
        }
        
        return minScore;
    }
};