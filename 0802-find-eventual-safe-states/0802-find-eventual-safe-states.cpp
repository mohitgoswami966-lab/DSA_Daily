class Solution {
private:
    bool dfs(int node,vector<vector<int>> &graph,vector<bool> &visited,vector<bool> &pathVis,
    vector<int> &check){
        visited[node]=true;
        pathVis[node]=true;
        for(int i:graph[node]){
            if(!visited[i]){
                if(dfs(i,graph,visited,pathVis,check)) return true;
            }
            else if(pathVis[i]){
                return true;
            }
        }
        check[node]=1;
        pathVis[node]=false;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        vector<bool> visited(n,false);
        vector<bool> pathVis(n,false);
        vector<int> check(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,graph,visited,pathVis,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]==1) ans.push_back(i);
        }
        return ans;
    }
};