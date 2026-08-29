class Solution {
private:
    int solve(string s, string revStr){
        vector<int> curr(s.size()+1,0);
        vector<int> next(s.size()+1,0);
        for(int i=s.size()-1;i>=0;i--){
            for(int j=revStr.size()-1;j>=0;j--){
                int ans=0;
                if(s[i]==revStr[j]){
                    ans = 1+next[j+1];
                }
                else{
                    ans=max(next[j],curr[j+1]);
                }
                curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
    }
public:
    int longestPalindromeSubseq(string s) {
        string revStr=s;
        reverse(revStr.begin(),revStr.end());
        return solve(s,revStr);
    }
};