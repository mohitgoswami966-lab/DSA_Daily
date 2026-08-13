class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> let(n);
        for(int i=0;i<n;i++){
            let[i]=start+2*i;
        }
        int ans=let[0];
        for(int i=1;i<n;i++){
            ans ^=let[i];
        }
        return ans;
    }
};