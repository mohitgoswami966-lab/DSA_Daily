class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int b=0;
        int ans=INT_MIN;
        vector<int> mp(26,0);
        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
            while(mp[s[i]-'a']>2){
                mp[s[b]-'a']--;
                b++;
            }
            ans=max(ans,i-b+1);
        }
        return ans;
    }
};