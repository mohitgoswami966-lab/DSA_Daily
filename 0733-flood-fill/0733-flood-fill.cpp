class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int n=image.size();
        int m=image[0].size();
        if(image[sr][sc]==color) return image;
        vector<vector<int>> ans=image;
        vector<vector<int>> visited(n,vector<int>(m,0));
        q.push({sr,sc});
        visited[sr][sc]=1;
        int a=image[sr][sc];
        ans[sr][sc]=color;
        int aRow[]={1,0,-1,0};
        int aCol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+aRow[i];
                int ncol=c+aCol[i];
                if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && !visited[nrow][ncol] &&
                image[nrow][ncol]==a){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                    ans[nrow][ncol]=color;
                }
            }
        }
        return ans;
    }
};