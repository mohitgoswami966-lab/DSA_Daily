class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<richer.size();i++){
           int u=richer[i][0];
           int v=richer[i][1];
           adj[u].push_back(v); 
        }
        vector<int> inDegree(n,0);
        for(auto i:adj){
            for(auto j:i){
                inDegree[j]++;
            }
        }
        queue<int> q;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=i;
        }
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto i:adj[node]){
                if(quiet[ans[node]]<quiet[ans[i]]){
                    ans[i]=ans[node];
                }
                inDegree[i]--;
                if(inDegree[i]==0){
                    q.push(i);
                }
            }
        }
        return ans;
    }
};