class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==1 && (nums[0]==0 || nums[0]==1)) return true;
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
                if (currentEnd >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};