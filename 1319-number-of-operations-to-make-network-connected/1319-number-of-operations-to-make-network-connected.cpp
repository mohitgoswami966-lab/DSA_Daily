class Solution {
private:
    void makeSet(int n,vector<int> &parent,vector<int> &rank){
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    int findParent(int node,vector<int> &parent){
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node],parent);
    }
    void unionSet(int u,int v,vector<int> &parent,vector<int> &rank){
        u=findParent(u,parent);
        v=findParent(v,parent);
        if(u==v) return;
        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[v]<rank[u]){
            parent[v]=u;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        vector<int> rank(n);
        makeSet(n,parent,rank);
        int count=0;
        for(int i=0;i<connections.size();i++){
            int u=findParent(connections[i][0],parent);
            int v=findParent(connections[i][1],parent);
            if(u==v) count++;
            else{
                unionSet(u,v,parent,rank);
            }
        }
        int countC=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i) countC++;
        }
        int ans=countC-1;
        if(count>=ans) return ans;
        return -1;
    }
};