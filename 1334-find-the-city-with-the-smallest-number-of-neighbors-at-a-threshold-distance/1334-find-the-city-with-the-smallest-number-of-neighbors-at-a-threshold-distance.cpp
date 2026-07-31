class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int city=-1;
        int minCount=INT_MAX;
        for(int src=0;src<n;src++){
            vector<int> dist(n,INT_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,src});
            dist[src]=0;
            while(!pq.empty()){
                int d=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(auto i:adj[node]){
                    int adjn=i.first;
                    int wt=i.second;
                    if(d+wt<dist[adjn]){
                        dist[adjn]=d+wt;
                        pq.push({d+wt,adjn});
                    }
                }
            }
            int cnt=0;
            for(int i=0;i<n;i++){
                if(dist[i]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=minCount){
                minCount=cnt;
                city=src;
            }
        }
        return city;
    }
};