class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> visited(n,vector<int>(n,0));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({grid[0][0],0,0});
        visited[0][0]=1;
        int aRow[]={0,1,0,-1};
        int aCol[]={1,0,-1,0};
        while(!pq.empty()){
            vector<int> curr=pq.top();
            pq.pop();
            int time=curr[0];
            int r=curr[1];
            int c=curr[2];
            if(r==n-1 && c==n-1) return time;
            for(int i=0;i<4;i++){
                int nrow=r+aRow[i];
                int ncol=c+aCol[i];
                if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<n) && !visited[nrow][ncol]){
                    visited[nrow][ncol]=1;
                    pq.push({max(time,grid[nrow][ncol]),nrow,ncol});
                }
            }
        }
        return -1;
    }
};