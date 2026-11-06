class Solution {
private:
    bool bfs(int node,int color,vector<vector<int>> &graph,vector<int> &visited){
        queue<int> q;
        visited[node]=color;
        q.push(node);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto i:graph[front]){
                if(visited[i]==-1){
                    visited[i]=!visited[front];
                    q.push(i);
                }
                else if(visited[i]==visited[front]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                if(!bfs(i,0,graph,visited)) return false;
            }
        }
        return true;
    }
};