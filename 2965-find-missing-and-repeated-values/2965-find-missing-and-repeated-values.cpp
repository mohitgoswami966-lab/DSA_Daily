class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> all;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                all.push_back(grid[i][j]);
            }
        }
        int duplicate=-1;
        int missing=-1;
        int a=1;
        sort(all.begin(),all.end());
        for(int i=0;i<all.size()-1;i++){
            if(all[i]==all[i+1]) duplicate=all[i];
            if(a==all[i]) a++;
        }
        if(a==all[all.size()-1]) a++;
        missing =a;
        return {duplicate,missing};
    }
};