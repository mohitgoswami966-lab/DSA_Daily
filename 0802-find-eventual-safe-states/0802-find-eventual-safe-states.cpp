class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adjRev(n);
        for(int i=0;i<n;i++){
            for(auto j:graph[i]){
                adjRev[j].push_back(i);
            }
        }
        vector<int> inDegree(n,0);
        for(auto i:adjRev){
            for(auto j:i){
                inDegree[j]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto i:adjRev[front]){
                inDegree[i]--;
                if(inDegree[i]==0){
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};