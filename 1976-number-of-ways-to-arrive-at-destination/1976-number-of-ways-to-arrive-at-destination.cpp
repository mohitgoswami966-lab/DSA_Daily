class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        int mod=(int)1e9+7;
        while(!pq.empty()){
            long long d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(d>dist[node]) continue;
            for(auto i:adj[node]){
                int an=i.first;
                int wt=i.second;
                if(d+wt<dist[an]){
                    dist[an]=d+wt;
                    pq.push({dist[an],an});
                    ways[an]=ways[node];
                }
                else if(d+wt==dist[an]){
                    ways[an]=(ways[an]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};