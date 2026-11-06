class Solution {
private:
    bool dfs(int node, int color, vector<vector<int>>& graph,
             vector<int>& visited) {
        visited[node] = color;
        for (auto i : graph[node]) {
            if (visited[i] == -1) {
                if(!dfs(i,!color,graph,visited)) return false;
            } else if (visited[i] == color) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                if (!dfs(i, 0, graph, visited))
                    return false;
            }
        }
        return true;
    }
};