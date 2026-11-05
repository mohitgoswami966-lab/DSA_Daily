class Solution {
private:
    void solve(int node,vector<vector<int>> &adj,vector<bool> &visited){
        visited[node]=true;
        for(int i:adj[node]){
            if(!visited[i]){
                solve(i,adj,visited);
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
        vector<bool> visited(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                solve(i,adj,visited);
            }
        }
        return ans;
    }
};