class Solution {
public:
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }
        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans = nums;
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(ans, n, i);
        }
        for (int i = n - 1; i > 0; i--) {
            swap(ans[0], ans[i]);
            heapify(ans, i, 0);
        }
        return ans;
    }
};