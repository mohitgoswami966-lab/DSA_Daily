class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int longest=0;
        for(auto n:st){
            if(st.find(n-1)==st.end()){
                int len=1;
                int curr=n;
                while(st.find(curr+1)!=st.end()){
                    curr++;
                    len++;
                }
                longest=max(len,longest);
            }
        }
        return longest;
    }
};