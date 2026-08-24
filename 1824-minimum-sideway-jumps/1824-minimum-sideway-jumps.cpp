class Solution {
private:
    int solve(vector<int> &obstacles){
        int n=obstacles.size();
        vector<int> curr(4,INT_MAX);
        vector<int> next(4,INT_MAX);
        next[0]=0;
        next[1]=0;
        next[2]=0;
        next[3]=0;
        for(int cpos=n-2;cpos>=0;cpos--){
            for(int clane=1;clane<=3;clane++){
                if(obstacles[cpos+1]!=clane){
                    curr[clane]=next[clane];
                }
                else{
                    int ans=1e9;
                    for(int i=1;i<=3;i++){
                        if(clane!=i && obstacles[cpos]!=i){
                            ans=min(ans,1+next[i]);
                        }
                    }
                    curr[clane]=ans;
                }
            }
            next=curr;
        }
        return min(next[2],min(1+next[1],1+next[3]));
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles);
    }
};