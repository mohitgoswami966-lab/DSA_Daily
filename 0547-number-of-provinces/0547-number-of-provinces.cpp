class Solution {
private:
    void dfs(int node,vector<vector<int>> &adj,vector<bool> &visited){
        visited[node]=true;
        for(auto i:adj[node]){
            if(!visited[i]){
                dfs(i,adj,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        int ans=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs(i,adj,visited);
            }
        }
        return ans;
    }
};