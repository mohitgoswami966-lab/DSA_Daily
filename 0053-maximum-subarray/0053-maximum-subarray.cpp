class Solution {
private:
    int solve(vector<int> &nums,int L,int R){
        if(L>R) return INT_MIN;
        int leftSum=0,rightSum=0;
        int mid=L+(R-L)/2;
        for(int i=mid-1,currSum=0;i>=L;i--){
            currSum+=nums[i];
            leftSum=max(leftSum,currSum);
        }
        for(int i=mid+1,currSum=0;i<=R;i++){
            currSum+=nums[i];
            rightSum=max(rightSum,currSum);
        }
        return max({solve(nums,L,mid-1),solve(nums,mid+1,R),leftSum+nums[mid]+rightSum});
    }
public:
    int maxSubArray(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};