class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<int> inDegree(numCourses);
        for(vector<int> i:adj){
            for(int j:i){
                inDegree[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(int i:adj[front]){
                inDegree[i]--;
                if(inDegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(ans.size()==numCourses) return ans;
        return {};
    }
};