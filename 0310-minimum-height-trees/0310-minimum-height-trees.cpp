class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> inDegree(n);
        for(auto i:adj){
            for(auto j:i){
                inDegree[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==1){
                q.push(i);
            }
        }
        int count=n;
        while(count>2){
            count -= q.size();
            int b=q.size();
            while(b){
                int node=q.front();
                q.pop();
                for(auto i:adj[node]){
                    inDegree[i]--;
                    if(inDegree[i]==1){
                        q.push(i);
                    }
                }
                b--;
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            ans.push_back(a);
        }
        return ans;
    }
};