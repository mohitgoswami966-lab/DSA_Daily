class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        if(image[sr][sc]==color) return image;
        queue<pair<int,int>> q;
        vector<vector<int>> ans=image;
        vector<vector<int>> visited(n,vector<int>(m,0));
        q.push({sr,sc});
        int a=image[sr][sc];
        visited[sr][sc]=1;
        ans[sr][sc]=color;
        int aRow[]={-1,0,1,0};
        int aCol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+aRow[i];
                int ncol=c+aCol[i];
                if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && !visited[nrow][ncol] && image[nrow][ncol]==a){
                    ans[nrow][ncol]=color;
                    visited[nrow][ncol]=true;
                    q.push({nrow,ncol});
                }
            }
        }
        return ans;
    }
};