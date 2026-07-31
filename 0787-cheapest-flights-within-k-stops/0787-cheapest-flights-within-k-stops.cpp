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
        vector<int> dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int d=q.front().second.second;
            q.pop();
            if(stops>k) continue;
            for(auto i:adj[node]){
                int a=i.first;
                int dt=i.second;
                if(d+dt<dist[a] && stops<=k){
                    dist[a]=d+dt;
                    q.push({stops+1,{a,d+dt}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};