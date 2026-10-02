class Solution {
private:
    void solve(int open,int close,int n,string let,vector<string> &ans){
        if(let.size()==2*n){
            ans.push_back(let);
            return;
        }
        if(open<n){
            solve(open+1,close,n,let+"(",ans);
        }
        if(close<open){
            solve(open,close+1,n,let+")",ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0,0,n,"",ans);
        return ans;
    }
};