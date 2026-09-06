class Solution {
public:
    int countRotations(string s, int k) {
        string m=s+s;
        int n=s.size();
        int ans=0;
        for(int i=0;i<s.size();i++){
            string word=m.substr(i,n);
            int score=0;
            for(int i=1;i<word.size();i++){
                if(word[i-1]==word[i]) score++;
            }
            if(score==k){
                ans++;
            }
        }
        return ans;
    }
};