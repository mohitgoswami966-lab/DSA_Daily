class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int target=1;
        for(auto n:nums){
            if(n==target){
                target++;
                continue;
            }
            else if(n>target){
                return target;
            }
        }
        return target;
    }
};