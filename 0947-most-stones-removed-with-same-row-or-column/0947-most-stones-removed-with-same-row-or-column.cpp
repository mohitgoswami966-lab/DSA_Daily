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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxRow=0;
        int maxCol=0;
        for(int i=0;i<n;i++){
            maxRow=max(maxRow,stones[i][0]);
            maxCol=max(maxCol,stones[i][1]);
        }
        vector<int> parent(maxRow+maxCol+2);
        vector<int> rank(maxRow+maxCol+2);
        unordered_map<int,int> stoneNode;
        makeSet(maxRow+maxCol+2,parent,rank);
        for(int i=0;i<n;i++){
            int r=stones[i][0];
            int c=stones[i][1]+maxRow+1;
            unionSet(r,c,parent,rank);
            stoneNode[r]=1;
            stoneNode[c]=1;
        }
        int count=0;
        for(auto i:stoneNode){
            if(findParent(i.first,parent)==i.first) count++;
        }
        return n-count;
    }
};