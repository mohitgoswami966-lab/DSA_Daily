class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,INT_MAX);
        while(!q.empty()){
            int stop=q.front().first;
            int n=q.front().second.first;
            int d=q.front().second.second;
            q.pop();
            if(stop>k) continue;
            for(auto i:adj[n]){
                int node=i.first;
                int wt=i.second;
                if(d+wt<dist[node] && stop<=k){
                    dist[node]=d+wt;
                    q.push({stop+1,{node,d+wt}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};