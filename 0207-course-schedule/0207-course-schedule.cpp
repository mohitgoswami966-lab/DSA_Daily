class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<n;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<int> inDegree(numCourses,0);
        for(auto i:adj){
            for(auto j:i){
                inDegree[j]++;
            }
        }
        vector<int> topo;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int Front=q.front();
            q.pop();
            topo.push_back(Front);
            for(auto i:adj[Front]){
                inDegree[i]--;
                if(inDegree[i]==0) q.push(i);
            }
        }
        if(topo.size()==numCourses) return true;
        return false;
    }
};