class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();

        int swap = 1;
        int noswap = 0;

        for (int i = 1; i < n; i++) {

            int currswap = INT_MAX;
            int currnoswap = INT_MAX;

            // Don't swap current
            if (nums1[i] > nums1[i - 1] &&
                nums2[i] > nums2[i - 1]) {

                currnoswap = min(currnoswap, noswap);
                currswap = min(currswap, swap + 1);
            }

            // Swap current
            if (nums1[i] > nums2[i - 1] &&
                nums2[i] > nums1[i - 1]) {

                currnoswap = min(currnoswap, swap);
                currswap = min(currswap, noswap + 1);
            }

            swap = currswap;
            noswap = currnoswap;
        }

        return min(swap, noswap);
    }
};