class Solution {
private:
    void dfs(int node,int parent,int &timer,vector<int> &low,vector<int> &disc,
    vector<vector<int>> &result,vector<vector<int>> &adj,vector<bool> &visited){
        visited[node]=true;
        low[node]=disc[node]=timer++;
        for(auto i:adj[node]){
            if(i==parent) continue;
            else if(!visited[i]){
                dfs(i,node,timer,low,disc,result,adj,visited);
                low[node]=min(low[node],low[i]);
                if(low[i]>disc[node]){
                    vector<int> ans(2);
                    ans[0]=node;
                    ans[1]=i;
                    result.push_back(ans);
                }
            }
            else{
                low[node]=min(low[node],disc[i]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> low(n,-1);
        vector<int> disc(n,-1);
        vector<vector<int>> result;
        vector<bool> visited(n,false);
        int parent=-1;
        int timer=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,parent,timer,low,disc,result,adj,visited);
            }
        }
        return result;
    }
};