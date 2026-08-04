class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st[nums[i]]=1;
        }
        int a=INT_MAX;
        int b=INT_MIN;
        for(int i=0;i<n;i++){
            a=min(a,nums[i]);
            b=max(b,nums[i]);
        }
        vector<int> ans;
        for(int i=a;i<=b;i++){
            if(st.find(i)==st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};