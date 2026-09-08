class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set st(nums.begin(),nums.end());
        int ans=0;
        for(auto i:st){
            if(st.find(i-1)==st.end()){
                int len=1;
                int curr=i;
                while(st.find(curr+1)!=st.end()){
                    len++;
                    curr++;
                }
                ans=max(len,ans);
            }
        }
        return ans;
    }
};