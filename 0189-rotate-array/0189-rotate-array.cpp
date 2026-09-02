class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int s=nums.size();
        k=k%s;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};