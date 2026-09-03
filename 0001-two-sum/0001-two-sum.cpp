class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int required=target-nums[i];
            if(mp.find(required)!=mp.end() && mp[required]!=i) return{i,mp[required]};
        }
        return {};
    }
};