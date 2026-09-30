class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cmin=nums[0];
        int cmax=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(cmin,cmax);
            }
            cmin=min(nums[i],cmin*nums[i]);
            cmax=max(nums[i],cmax*nums[i]);
            ans=max(ans,cmax);
        }
        return ans;
    }
};