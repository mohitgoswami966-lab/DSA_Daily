class Solution {
private:
    void makeSet(int n, vector<int> &parent,vector<int> &rank){
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int> parent(n);
        vector<int> rank(n);
        makeSet(n,parent,rank);
        unordered_map<string,int> mapMail;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mapMail.find(mail)==mapMail.end()){
                    mapMail[mail]=i;
                }
                else{
                    unionSet(i,mapMail[mail],parent,rank);
                }
            }
        }
        vector<vector<string>> mergeMail(n);
        for(auto i:mapMail){
            string m=i.first;
            int node=findParent(i.second,parent);
            mergeMail[node].push_back(m);
        }
        vector<vector<string>> result;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0) continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto j:mergeMail[i]){
                temp.push_back(j);
            }
            result.push_back(temp);
        }
        return result;
    }
};