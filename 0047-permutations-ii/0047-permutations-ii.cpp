class Solution {
private:
    void sol(int i,vector<vector<int>>& ans,vector<int>& nums){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            sol(i+1,ans,nums);
            swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sol(0,ans,nums);
        set<vector<int>> st(ans.begin(),ans.end());
        vector<vector<int>> res(st.begin(),st.end());
        return res;
    }
};