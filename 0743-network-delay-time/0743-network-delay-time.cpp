class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
        vector<long long> dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,k});
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
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            if(ans<dist[i]) ans=dist[i];
        }
        return ans;
    }
};