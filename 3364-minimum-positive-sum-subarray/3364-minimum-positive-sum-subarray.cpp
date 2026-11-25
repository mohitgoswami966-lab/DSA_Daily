class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = l; j <= r; j++) {
                int sum = 0;
                if (i + j <= nums.size()) {
                    for (int k = i; k < i + j; k++) {
                        sum += nums[k];
                    }
                    if (sum > 0) {
                        mini = min(mini, sum);
                    }
                }
            }
        }
        if (mini == INT_MAX)
            return -1;
        return mini;
    }
};