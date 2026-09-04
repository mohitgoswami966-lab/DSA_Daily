class Solution {
private:
    int solve(vector<int> &nums,int s,int e){
        if(s>e) return INT_MIN;
        int leftSum=0;
        int RightSum=0;
        int mid=s+(e-s)/2;
        int currSum=0;
        for(int i=mid-1;i>=s;i--){
            currSum +=nums[i];
            leftSum=max(leftSum,currSum);
        }
        currSum=0;
        for(int i=mid+1;i<=e;i++){
            currSum +=nums[i];
            RightSum=max(RightSum,currSum);
        }
        return max({solve(nums,s,mid-1),solve(nums,mid+1,e),leftSum+nums[mid]+RightSum});
    }
public:
    int maxSubArray(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};