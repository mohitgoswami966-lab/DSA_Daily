class Solution {
private:
    int solve(vector<int> nums,int limit){
        int day=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>limit){
                day++;
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
        }
        return day;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low=INT_MIN;
        int high=0;
        for(int i=0;i<nums.size();i++){
            low=max(low,nums[i]);
            high += nums[i];
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(nums,mid)<=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};