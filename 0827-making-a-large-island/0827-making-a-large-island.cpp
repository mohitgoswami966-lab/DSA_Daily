class Solution {
private:
    void makeSet(int n,vector<int> &parent,vector<int> &size){
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findParent(int node,vector<int> &parent){
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node],parent);
    }
    void unionSet(int u,int v,vector<int> &parent,vector<int> &size){
        u=findParent(u,parent);
        v=findParent(v,parent);
        if(u==v) return;
        if(size[u]<size[v]){
            parent[u]=v;
            size[v] += size[u];
        }
        else{
            parent[v]=u;
            size[u] += size[v];
        }
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> parent(n*n);
        vector<int> size(n*n);
        int aRow[]={-1,0,1,0};
        int aCol[]={0,1,0,-1};
        makeSet(n*n,parent,size);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                for(int k=0;k<4;k++){
                    int adjr=i+aRow[k];
                    int adjc=j+aCol[k];
                    if((adjr>=0 && adjr<n) && (adjc>=0 && adjc<n) && grid[adjr][adjc]==1){
                        int u=i*n+j;
                        int v=adjr*n+adjc;
                        unionSet(u,v,parent,size);
                    }
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                set<int> components;
                for(int k=0;k<4;k++){
                    int adjr=i+aRow[k];
                    int adjc=j+aCol[k];
                    if((adjr>=0 && adjr<n) && (adjc>=0 && adjc<n) && grid[adjr][adjc]==1){
                        components.insert(findParent(adjr*n+adjc,parent));
                    }
                }
                int sizeTotal=0;
                for(auto it:components){
                    sizeTotal += size[it];
                }
                mx=max(mx,sizeTotal+1);
            }
        }
        for(int col=0;col<n*n;col++){
            mx=max(mx,size[findParent(col,parent)]);
        }
        return mx;
    }
};