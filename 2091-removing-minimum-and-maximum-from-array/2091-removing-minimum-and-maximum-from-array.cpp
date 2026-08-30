class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int miniIndex = 0;
        int maxiIndex = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < mini) {
                mini = nums[i];
                miniIndex = i;
            }

            if (nums[i] > maxi) {
                maxi = nums[i];
                maxiIndex = i;
            }
        }

        int n = nums.size();

        int first = min(miniIndex, maxiIndex);
        int last = max(miniIndex, maxiIndex);

        int fromStart = last + 1;
        int fromEnd = n - first;
        int fromBoth = first + 1 + n - last;

        return min({fromStart, fromEnd, fromBoth});
    }
};